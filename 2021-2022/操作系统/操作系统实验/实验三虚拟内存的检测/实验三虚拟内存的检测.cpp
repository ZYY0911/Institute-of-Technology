// ʵ���������ڴ�ļ��.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <shlwapi.h>
#include <iomanip>
#pragma comment(lib, "Shlwapi.lib")

// ��ʾ�ڴ汣���ķ�����
// �������ָʾ������Ӧ�ó�����ڴ���з��ʵ������Լ�����ϵͳǿ�Ʒ��ʵ�����
inline bool TestSet(DWORD dwTarget, DWORD dwMask)
{
    return ((dwTarget &dwMask) == dwMask) ;
}

//�궨��һ������
//TestSetΪ��������
# define SHOWMASK(dwTarget, type) \
if (TestSet(dwTarget, PAGE_##type) ) \
    {std :: cout << ", " << #type; }

void ShowProtection(DWORD dwTarget)
{
    SHOWMASK(dwTarget, READONLY) ;
    SHOWMASK(dwTarget, GUARD) ;
    SHOWMASK(dwTarget, NOCACHE) ;
    SHOWMASK(dwTarget, READWRITE) ;
    SHOWMASK(dwTarget, WRITECOPY) ;
    SHOWMASK(dwTarget, EXECUTE) ;
    SHOWMASK(dwTarget, EXECUTE_READ) ;
    SHOWMASK(dwTarget, EXECUTE_READWRITE) ;
    SHOWMASK(dwTarget, EXECUTE_WRITECOPY) ;
    SHOWMASK(dwTarget, NOACCESS) ;
}

// �����������������ַ�ռ�,����ʾ�����ڴ�������
void WalkVM(HANDLE hProcess)
{
    // ���Ȼ��ϵͳ��Ϣ
    SYSTEM_INFO si;
    :: ZeroMemory(&si, sizeof(si) ) ;
    :: GetSystemInfo(&si) ;

    // ����Ҫ�����Ϣ�Ļ�����
    MEMORY_BASIC_INFORMATION mbi;
    :: ZeroMemory(&mbi, sizeof(mbi) ) ;

    // ѭ������������������ַ�ռ�
    LPCVOID pBlock = (LPVOID) si.lpMinimumApplicationAddress;
    while (pBlock < si.lpMaximumApplicationAddress)
    {
        // ��õ�ǰ�����ڴ�����Ϣ
        if (:: VirtualQueryEx(
            hProcess,			          // ��صĽ���
            pBlock,                       // �����ڴ��Ŀ�ʼλ��
			&mbi,                         // ��������ڴ����Ϣ�Ļ�����
            sizeof(mbi))==sizeof(mbi) )	  // ��С��ȷ��
        {
            // ������һ�����ڴ�����ʼ��ַ
            LPCVOID pEnd = (PBYTE) pBlock + mbi.RegionSize;
			//���浱ǰ�����ڴ��ĳ���
			TCHAR szSize[MAX_PATH];
            :: StrFormatByteSize(mbi.RegionSize, szSize, MAX_PATH) ;

            // ��ʾ��ǰ�����ڴ��ĵ�ַ�ʹ�С
            std :: cout.fill ('0') ;
            std :: cout
                << std :: hex << std :: setw(8) << (DWORD) pBlock
                << "-"
                << std :: hex << std :: setw(8) << (DWORD) pEnd
                << (:: strlen(szSize)==7? " (" : " (") << szSize
                << ") " ;

            // ��ʾ��ǰ�����ڴ���״̬
            switch(mbi.State)
            {
                case MEM_COMMIT :
					std :: cout << "Committed" ;//����ҳ��ӳ�䵽��档
					break;
                case MEM_FREE :
					std :: cout << "Free" ;     
					break;
                case MEM_RESERVE :
					std :: cout << "Reserved" ; // �������ַ��ʼ�������ڴ�����Ҫʹ�ã�
					                            // �����������������ڴ�Ĳ�������ʹ������ڴ档
					                            // ��û��ӳ�䵽��档
					break;
            }

            //���µ�����ǰ�����ڴ��ı�����ʽ
			if(mbi.Protect==0 && mbi.State!=MEM_FREE)
            {
                mbi.Protect=PAGE_READONLY;
            }
			// ��ʾ��ǰ�����ڴ��ı�����ʽ
			ShowProtection(mbi.Protect);

            // ��ʾ��ǰ�����ڴ�������
            switch(mbi.Type){
                case MEM_IMAGE :    //�������ڴ��ӳ����ǿ�ִ���ļ�����*.dll��*.exe��
					std :: cout << ", Image" ;
					break;
				case MEM_MAPPED:    //�������ڴ��ӳ����������ļ�,��CreateFileMapping����������
					std :: cout << ", Mapped";
					break;
                case MEM_PRIVATE :  //�������ڴ�鲻���������ջ��
					std :: cout << ", Private" ;
					break;
			}

            // ��ÿ�ִ�е��ļ�����
            TCHAR szFilename [MAX_PATH] ;
            if (:: GetModuleFileName (
                (HMODULE) pBlock,   // һ��ģ��ľ����ģ������һ��ľ����һ����
				                    // ģ����ָ��ľ���EXE��DLL���������ַ�ռ��λ�á�
		                            // ����ò���ΪNULL���ú������ظ�Ӧ�ó���ȫ·����
				szFilename,         // �ļ�����
				MAX_PATH)>0)        // ʵ��ʹ�õĻ�������С
            {
                // ��ȥ�ļ�����·�������ļ�����ʾ����
                :: PathStripPath(szFilename) ;
                std :: cout << ", Module: " << szFilename;
			}

            std :: cout << std :: endl;
			
			// �ƶ������ڴ��ָ���Ի����һ�������ڴ��
            pBlock = pEnd;
        }
    }
}


int main(int argc, char* argv[])
{
	// ������ǰ���̵������ַ�ռ�
	::WalkVM(::GetCurrentProcess());
	return 0;
}

/*
˼���⣺
1.���̵������ַ�ռ����ӳ�䵽��Щ�ļ���
*/