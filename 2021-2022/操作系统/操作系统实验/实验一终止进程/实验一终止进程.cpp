// ʵ��һ��ֹ����.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>

//�����ӽ��̣��븸����ִ����ͬ�ĳ���
void StartClone(int nCloneID)
{
	
    // ��ȡ��ǰ���̵Ŀ�ִ���ļ���ȡ��ǰ���̵Ŀ�ִ���ļ���
    TCHAR szFilename[MAX_PATH] ;
    :: GetModuleFileName(
		          NULL, //һ��ģ��ľ����ģ������һ��ľ����һ����
				        //ģ����ָ��ľ���EXE��DLL���������ַ�ռ��λ�á�
                        //����ò���ΪNULL���ú������ظ�Ӧ�ó���ȫ·����
				  szFilename,
				  MAX_PATH) ;
   
    // ��ʽ�����ڴ����½��̵������У�����EXE�ļ�������¡ID�͵�ǰ���̵�ID��
    TCHAR szCmdLine[MAX_PATH];
	:: sprintf(szCmdLine,"\"%s\"%d %d",szFilename,nCloneID,::GetCurrentProcessId());
	  
	// �����½��̵�STARTUPINFO�ṹ
    STARTUPINFO si;
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// �����Ǳ��ṹ�Ĵ�С
    // ���ص������½��̵Ľ�����Ϣ
    PROCESS_INFORMATION pi;
    
    // ʹ��ͬһ��ִ���ļ��ʹ��п�¡ID����ǰ����ID�������д����½��̡�
    BOOL bCreateOK=::CreateProcess(
        szFilename,					// �½��̵Ŀ�ִ���ļ���
        szCmdLine,					// �����½��̵������в���
        NULL,						// ȱʡ�Ľ��̰�ȫ��
        NULL,						// ȱʡ���̰߳�ȫ��
        FALSE,					  	// ���̳о��
        CREATE_NEW_CONSOLE,	        // ʹ���µĿ���̨
        NULL,						// �µĻ���
        NULL,						// ��ǰĿ¼
        &si,						// ������Ϣ
        &pi) ;					    // ���صĽ�����Ϣ
   
    //��ʹ�õľ����ùص�
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

//ĳ���ӽ���ɾ���������ĸ����̡�
int main(int argc, char* argv[] )
{
    // ���̵Ŀ�¡ID
    int nClone(0) ;
    // ���游���̵Ľ���ID
	int ProcessId(0);
    
    //��һ������argcΪ1���Ժ�ÿ��������������3��������
    //���е�3���Ǹ�����ID��
    if (argc > 1)
    {
        // �ӵ�2����������ȡ��¡ID
        :: sscanf(argv[1] , "%d" , &nClone) ;

		// �ӵ�3����������ȡ������ID
        :: sscanf(argv[2] , "%d" , &ProcessId) ;

    }
    
    // ��ʾ����ID�Ϳ�¡ID
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;

	//��ֹ������
	if(nClone==3)
	{
		::TerminateProcess(OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId),1);
		std::cout<<"Terminate Process  Clone ID=2"
			     << std :: endl;
	}

    
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
    :: Sleep(1000) ;
    return 0;
}

/*
˼���⣺
1.һ��������ֹ�丸��������ľ������λ�ȡ�ģ�
2.Windows�µĽ���ID�ͽ��̾����ʲô����
3.��ͨ���޸ĳ�����˵����һ������OpenProcess������Σ�
  ���صľ��ֵ�Ƿ���ͬ��
*/
