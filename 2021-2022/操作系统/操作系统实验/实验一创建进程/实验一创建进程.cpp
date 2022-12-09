// ʵ��һ��������.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>

//�����ӽ��̣��븸����ִ����ͬ�ĳ���
void StartClone(int nCloneID)
{
	
    // ��ȡ��ǰ���̵Ŀ�ִ���ļ�����
    TCHAR szFilename[MAX_PATH] ;
    :: GetModuleFileName(
		          NULL, //һ��ģ��ľ����ģ������һ��ľ����һ����
				        //ģ����ָ��ľ���EXE��DLL���������ַ�ռ��λ�á�
                        //����ò���ΪNULL���ú������ظ�Ӧ�ó���ȫ·����
				  szFilename,
				  MAX_PATH) ;
   
    // ��ʽ�����ڴ����½��̵������У�����EXE�ļ����Ϳ�¡ID
    TCHAR szCmdLine[MAX_PATH];
	  :: sprintf(szCmdLine,"\"%s\"%d",szFilename,nCloneID);
	  
	// �����½��̵�STARTUPINFO�ṹ
    STARTUPINFO si;
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// �����Ǳ��ṹ�Ĵ�С
	
    // ���ص������½��̵Ľ�����Ϣ
    PROCESS_INFORMATION pi;
    
    // ʹ��ͬһ��ִ���ļ��ʹ��п�¡ID�������д����½��̡�
    BOOL bCreateOK=::CreateProcess(
        szFilename,					// �½��̵Ŀ�ִ���ļ���
        szCmdLine,					// �����½��̵������в���
        NULL,						// ȱʡ�Ľ��̰�ȫ��
        NULL,						// ȱʡ���̰߳�ȫ��
        FALSE,					  	// ���̳о��
        CREATE_NEW_CONSOLE,	        // ʹ���µĿ���̨
        NULL,						// �µĻ���
        NULL,					    // ��ǰĿ¼
        &si,						// ������Ϣ
        &pi) ;					 	// ���صĽ�����Ϣ
   
    //��ʹ�õľ����ùص�
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

int main(int argc, char* argv[] )
{
    // ���̵Ŀ�¡ID
    int nClone(0) ;
    
    //��һ������argcΪ1���Ժ�ÿ������������������������
    //���еڶ����ǿ�¡ID��
    if (argc > 1)
    {
        // �ӵڶ�����������ȡ��¡ID
        :: sscanf(argv[1] , "%d" , &nClone) ;
    }
    
    // ��ʾ���̵Ŀ�¡ID
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;
    
    // �����½���,��nCloneΪ1-8
    const int c_nCloneMax=8;
    if (nClone < c_nCloneMax)
    { 
        :: Sleep(1000) ;
        StartClone(++nClone) ;
    }
    
    // �ȴ�����һ���ַ����Ա�۲졣����һ���ַ��󣬳��������
    std::cout<<"input a char:";
    getchar();
    std::cout<<"I'm stopped ... Bye-Bye";
    return 0;
}

/*
˼���⣺
1.���к���ϵͳ����������в鿴����������ӳ��������ʲô���ɣ�
2.���ӽ���ʹ��ͬһ������ν�������
3.��ͬ���̵Ŀ�¡ID����λ�ȡ���ģ�
4.����ڿ�¡IDΪ0�Ľ����д�����¡IDΪ1-8�Ľ��̣�Ӧ������޸ĳ���
*/

