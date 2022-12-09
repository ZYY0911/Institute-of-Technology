// ʵ���ͬ��.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
# include <windows.h>
# include <iostream>

// �¼�����
static LPCTSTR g_szContinueEvent ="event.Continue";

// �����ӽ��̣��븸����ִ����ͬ�ĳ���
BOOL CreateChild()
{
	// ��ȡ��ǰ���̵Ŀ�ִ���ļ���
	TCHAR szFilename[MAX_PATH];
    ::GetModuleFileName(NULL, szFilename, MAX_PATH) ;
    
	// ��ʽ�����ڴ����½��̵������У�����EXE�ļ������ַ�����child����
    TCHAR szCmdLine[MAX_PATH];
    ::sprintf(szCmdLine, "\"%s\" child" , szFilename) ;
	std::cout << szCmdLine << std::endl;
	
    // �½��̵�������Ϣ�ṹ
    STARTUPINFO si;
    ::ZeroMemory(reinterpret_cast<void*>(&si), sizeof(si)) ;
    si.cb = sizeof(si);		// ���ṹ�Ĵ�С

    // ���ص��½��̵Ľ�����Ϣ�ṹ
    PROCESS_INFORMATION pi;

    // ʹ��ͬһ��ִ���ļ��ʹ��С�child���������д����½��̡�
    BOOL bCreateOK = ::CreateProcess(
		szFilename,			// �½��̵Ŀ�ִ���ļ���
		szCmdLine,        	// �����½��̵������в���
        NULL,				// ȱʡ�Ľ��̰�ȫ��
        NULL,				// ȱʡ���̰߳�ȫ��
        FALSE,				// ���̳о��
        CREATE_NEW_CONSOLE,	// ����Ĵ�����־
        NULL,				// �»���
        NULL,				// ��ǰĿ¼
        &si,				// ������Ϣ�ṹ
        &pi ) ;				// ���صĽ�����Ϣ�ṹ

    // �ͷŶ��ӽ��̵�����
    if (bCreateOK)
	{
        :: CloseHandle(pi.hProcess);
        :: CloseHandle(pi.hThread);
    }
	return(bCreateOK) ;
}

// ����һ���¼���һ���ӽ��̣�Ȼ��ȴ��ӽ������¼������ź�
void WaitForChild()
{
    // ����һ���¼�����
    HANDLE hEventContinue = ::CreateEvent(
        NULL,				// ȱʡ�İ�ȫ�ԣ��ӽ��̽����з���Ȩ��
        TRUE,				// �Ƿ����˹���λ�¼�
        FALSE,			    // �¼��ĳ�ʼֵ�Ƿǽ����ź�״̬
        g_szContinueEvent);	// �¼����ƣ����ڸ��ӽ��̼乲��
    if (hEventContinue != NULL)
	{
		std :: cout << "event created " << std :: endl;
		// �����ӽ���
        if (::CreateChild())
        {
			std::cout << " chlid created" << std::endl;

            // �ȴ���ֱ���ӽ��̷����ź�
		    std::cout << "Parent waiting on child." << std::endl;
		
		    while(1)
		    {
                ::WaitForSingleObject(hEventContinue, INFINITE);
              	
			    std::cout << "parent received the event signaled from child"
					       << std::endl;
			    //ʵ��Ӧ���п��ڴ˽����¼�����
					    
			    :: Sleep(1000);
			}
        }

        // ������
        ::CloseHandle(hEventContinue);
        hEventContinue=INVALID_HANDLE_VALUE;
    }
}

// ���º������ӽ����б����ã��书�����򸸽��̷����ź�
void SignalParent()
{   
	std::cout << "child process begining......" << std :: endl;

	// ���Դ򿪾��
    HANDLE hEventContinue = ::OpenEvent(
        EVENT_MODIFY_STATE,			// ��Ҫ�����С����Ȩ��
        FALSE,						// ���ǿɼ̳еľ��
        g_szContinueEvent);			// �¼�����
    if(hEventContinue != NULL)
	{
	  getchar();	
	  //�ӽ��̷����¼���֪ͨ�����̡�
      :: SetEvent(hEventContinue);
	  std :: cout << "event signaled" << std :: endl;
				
	  getchar();
	  //�ӽ��̽��¼�����Ϊ���ź�״̬��
	  ResetEvent(hEventContinue);
	  std :: cout << "event reset" << std :: endl;
			
	  getchar();
    }

    // ������
    :: CloseHandle(hEventContinue) ;
    hEventContinue = INVALID_HANDLE_VALUE;
}

int main(int argc, char* argv[])
{
    // ����Ǹ����̻����ӽ��̡�
    if (argc>1 && :: strcmp(argv[1] , "child" )== 0)
    {   
		// Ϊ�ӽ��̣��򸸽��̴������¼������źš�        
        :: SignalParent(); 
        std :: cout << "Child released." << std :: endl;   
    }
    else
    {
		// Ϊ�����̣�����һ���¼���һ���ӽ��̣����ȴ��ӽ��̷����źš�
        :: WaitForChild();
        std :: cout << "Parent released." << std :: endl;       
    }
    return 0;
}

/*
˼���⣺
1.��ʵ�����¼�������ڸ��ӽ��̼乲��ģ�
2.Windows���ĸ�API��Ӧ�¼���P�������ĸ�API��Ӧ�¼���V������
3.��ʵ�������ĸ��������ĸ����̷����¼��ģ�
4.��ȡ�ͷ����¼��ĵ���λ����ʲô�ص㣿
5.��ͨ���޸ĳ��򲢶Ա����н����˵��Windows���Զ���λ�¼����˹���λ�¼�������
6.Windows�A�¼��Ǽ�������
*/