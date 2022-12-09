// 实验二同步.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
# include <windows.h>
# include <iostream>

// 事件名称
static LPCTSTR g_szContinueEvent ="event.Continue";

// 创建子进程，与父进程执行相同的程序。
BOOL CreateChild()
{
	// 获取当前进程的可执行文件名
	TCHAR szFilename[MAX_PATH];
    ::GetModuleFileName(NULL, szFilename, MAX_PATH) ;
    
	// 格式化用于创建新进程的命令行，包括EXE文件名和字符串“child”。
    TCHAR szCmdLine[MAX_PATH];
    ::sprintf(szCmdLine, "\"%s\" child" , szFilename) ;
	std::cout << szCmdLine << std::endl;
	
    // 新进程的启动信息结构
    STARTUPINFO si;
    ::ZeroMemory(reinterpret_cast<void*>(&si), sizeof(si)) ;
    si.cb = sizeof(si);		// 本结构的大小

    // 返回的新进程的进程信息结构
    PROCESS_INFORMATION pi;

    // 使用同一可执行文件和带有“child”的命令行创建新进程。
    BOOL bCreateOK = ::CreateProcess(
		szFilename,			// 新进程的可执行文件名
		szCmdLine,        	// 传给新进程的命令行参数
        NULL,				// 缺省的进程安全性
        NULL,				// 缺省的线程安全性
        FALSE,				// 不继承句柄
        CREATE_NEW_CONSOLE,	// 特殊的创建标志
        NULL,				// 新环境
        NULL,				// 当前目录
        &si,				// 启动信息结构
        &pi ) ;				// 返回的进程信息结构

    // 释放对子进程的引用
    if (bCreateOK)
	{
        :: CloseHandle(pi.hProcess);
        :: CloseHandle(pi.hThread);
    }
	return(bCreateOK) ;
}

// 创建一个事件和一个子进程，然后等待子进程向事件发出信号
void WaitForChild()
{
    // 创建一个事件对象
    HANDLE hEventContinue = ::CreateEvent(
        NULL,				// 缺省的安全性，子进程将具有访问权限
        TRUE,				// 是否是人工复位事件
        FALSE,			    // 事件的初始值是非接受信号状态
        g_szContinueEvent);	// 事件名称，用于父子进程间共享。
    if (hEventContinue != NULL)
	{
		std :: cout << "event created " << std :: endl;
		// 创建子进程
        if (::CreateChild())
        {
			std::cout << " chlid created" << std::endl;

            // 等待，直到子进程发出信号
		    std::cout << "Parent waiting on child." << std::endl;
		
		    while(1)
		    {
                ::WaitForSingleObject(hEventContinue, INFINITE);
              	
			    std::cout << "parent received the event signaled from child"
					       << std::endl;
			    //实际应用中可在此进行事件处理。
					    
			    :: Sleep(1000);
			}
        }

        // 清除句柄
        ::CloseHandle(hEventContinue);
        hEventContinue=INVALID_HANDLE_VALUE;
    }
}

// 以下函数在子进程中被调用，其功能是向父进程发出信号
void SignalParent()
{   
	std::cout << "child process begining......" << std :: endl;

	// 尝试打开句柄
    HANDLE hEventContinue = ::OpenEvent(
        EVENT_MODIFY_STATE,			// 所要求的最小访问权限
        FALSE,						// 不是可继承的句柄
        g_szContinueEvent);			// 事件名称
    if(hEventContinue != NULL)
	{
	  getchar();	
	  //子进程发送事件，通知父进程。
      :: SetEvent(hEventContinue);
	  std :: cout << "event signaled" << std :: endl;
				
	  getchar();
	  //子进程将事件设置为无信号状态。
	  ResetEvent(hEventContinue);
	  std :: cout << "event reset" << std :: endl;
			
	  getchar();
    }

    // 清除句柄
    :: CloseHandle(hEventContinue) ;
    hEventContinue = INVALID_HANDLE_VALUE;
}

int main(int argc, char* argv[])
{
    // 检查是父进程还是子进程。
    if (argc>1 && :: strcmp(argv[1] , "child" )== 0)
    {   
		// 为子进程，向父进程创建的事件发出信号。        
        :: SignalParent(); 
        std :: cout << "Child released." << std :: endl;   
    }
    else
    {
		// 为父进程，创建一个事件和一个子进程，并等待子进程发出信号。
        :: WaitForChild();
        std :: cout << "Parent released." << std :: endl;       
    }
    return 0;
}

/*
思考题：
1.本实验中事件是如何在父子进程间共享的？
2.Windows的哪个API对应事件的P操作？哪个API对应事件的V操作？
3.本实验中是哪个进程向哪个进程发送事件的？
4.获取和发送事件的调用位置有什么特点？
5.请通过修改程序并对比运行结果来说明Windows的自动复位事件和人工复位事件的区别。
6.Windows旳事件是计数的吗？
*/