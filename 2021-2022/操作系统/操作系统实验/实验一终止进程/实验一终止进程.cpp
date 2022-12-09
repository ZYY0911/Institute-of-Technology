// 实验一终止进程.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>

//创建子进程，与父进程执行相同的程序。
void StartClone(int nCloneID)
{
	
    // 获取当前进程的可执行文件名取当前进程的可执行文件名
    TCHAR szFilename[MAX_PATH] ;
    :: GetModuleFileName(
		          NULL, //一个模块的句柄。模块句柄跟一般的句柄不一样，
				        //模块句柄指向的就是EXE和DLL等在虚拟地址空间的位置。
                        //如果该参数为NULL，该函数返回该应用程序全路径。
				  szFilename,
				  MAX_PATH) ;
   
    // 格式化用于创建新进程的命令行，包括EXE文件名、克隆ID和当前进程的ID。
    TCHAR szCmdLine[MAX_PATH];
	:: sprintf(szCmdLine,"\"%s\"%d %d",szFilename,nCloneID,::GetCurrentProcessId());
	  
	// 用于新进程的STARTUPINFO结构
    STARTUPINFO si;
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// 必须是本结构的大小
    // 返回的用于新进程的进程信息
    PROCESS_INFORMATION pi;
    
    // 使用同一可执行文件和带有克隆ID、当前进程ID的命令行创建新进程。
    BOOL bCreateOK=::CreateProcess(
        szFilename,					// 新进程的可执行文件名
        szCmdLine,					// 传给新进程的命令行参数
        NULL,						// 缺省的进程安全性
        NULL,						// 缺省的线程安全性
        FALSE,					  	// 不继承句柄
        CREATE_NEW_CONSOLE,	        // 使用新的控制台
        NULL,						// 新的环境
        NULL,						// 当前目录
        &si,						// 启动信息
        &pi) ;					    // 返回的进程信息
   
    //不使用的句柄最好关掉
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

//某个子进程删除创建它的父进程。
int main(int argc, char* argv[] )
{
    // 进程的克隆ID
    int nClone(0) ;
    // 保存父进程的进程ID
	int ProcessId(0);
    
    //第一个进程argc为1，以后每个进程命令行有3个参数，
    //其中第3个是父进程ID。
    if (argc > 1)
    {
        // 从第2个参数中提取克隆ID
        :: sscanf(argv[1] , "%d" , &nClone) ;

		// 从第3个参数中提取父进程ID
        :: sscanf(argv[2] , "%d" , &ProcessId) ;

    }
    
    // 显示进程ID和克隆ID
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;

	//终止父进程
	if(nClone==3)
	{
		::TerminateProcess(OpenProcess(PROCESS_TERMINATE,FALSE,ProcessId),1);
		std::cout<<"Terminate Process  Clone ID=2"
			     << std :: endl;
	}

    
    // 创建新进程,其nClone为1-8
    const int c_nCloneMax=8;
    if (nClone < c_nCloneMax)
    {
		:: Sleep(1000) ;
        StartClone(++nClone) ;
    }
    
    // 等待输入一个字符，以便观察。输入一个字符后，程序结束。
    std::cout<<"input a char:";
    getchar();
    std::cout<<"I'm stopped ... Bye-Bye";
    :: Sleep(1000) ;
    return 0;
}

/*
思考题：
1.一个进程终止其父进程所需的句柄是如何获取的？
2.Windows下的进程ID和进程句柄有什么区别？
3.试通过修改程序来说明对一个进程OpenProcess（）多次，
  返回的句柄值是否相同？
*/
