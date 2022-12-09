// 实验一创建进程.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>

//创建子进程，与父进程执行相同的程序。
void StartClone(int nCloneID)
{
	
    // 获取当前进程的可执行文件名。
    TCHAR szFilename[MAX_PATH] ;
    :: GetModuleFileName(
		          NULL, //一个模块的句柄。模块句柄跟一般的句柄不一样，
				        //模块句柄指向的就是EXE和DLL等在虚拟地址空间的位置。
                        //如果该参数为NULL，该函数返回该应用程序全路径。
				  szFilename,
				  MAX_PATH) ;
   
    // 格式化用于创建新进程的命令行，包括EXE文件名和克隆ID
    TCHAR szCmdLine[MAX_PATH];
	  :: sprintf(szCmdLine,"\"%s\"%d",szFilename,nCloneID);
	  
	// 用于新进程的STARTUPINFO结构
    STARTUPINFO si;
    :: ZeroMemory(reinterpret_cast <void*> (&si) , sizeof(si) ) ;
    si.cb = sizeof(si) ;				// 必须是本结构的大小
	
    // 返回的用于新进程的进程信息
    PROCESS_INFORMATION pi;
    
    // 使用同一可执行文件和带有克隆ID的命令行创建新进程。
    BOOL bCreateOK=::CreateProcess(
        szFilename,					// 新进程的可执行文件名
        szCmdLine,					// 传给新进程的命令行参数
        NULL,						// 缺省的进程安全性
        NULL,						// 缺省的线程安全性
        FALSE,					  	// 不继承句柄
        CREATE_NEW_CONSOLE,	        // 使用新的控制台
        NULL,						// 新的环境
        NULL,					    // 当前目录
        &si,						// 启动信息
        &pi) ;					 	// 返回的进程信息
   
    //不使用的句柄最好关掉
    if (bCreateOK)
    {
        :: CloseHandle(pi.hProcess) ;
        :: CloseHandle(pi.hThread) ;
    }
}

int main(int argc, char* argv[] )
{
    // 进程的克隆ID
    int nClone(0) ;
    
    //第一个进程argc为1，以后每个进程命令行有两个参数，
    //其中第二个是克隆ID。
    if (argc > 1)
    {
        // 从第二个参数中提取克隆ID
        :: sscanf(argv[1] , "%d" , &nClone) ;
    }
    
    // 显示进程的克隆ID
    std :: cout << "Process ID:" << :: GetCurrentProcessId()
                << ", Clone ID:" << nClone
                << std :: endl;
    
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
    return 0;
}

/*
思考题：
1.运行后在系统任务管理器中查看所创建进程映像名，有什么规律？
2.父子进程使用同一程序，如何进行区别？
3.不同进程的克隆ID是如何获取到的？
4.如果在克隆ID为0的进程中创建克隆ID为1-8的进程，应该如何修改程序？
*/

