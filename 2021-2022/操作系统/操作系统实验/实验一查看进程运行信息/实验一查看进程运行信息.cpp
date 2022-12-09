// 实验一查看进程运行信息.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

// 显示进程和操作系统信息的简单示例
int main(int argc, char* argv[])
{
    // 获取这个进程的ID号
    DWORD dwIdThis=:: GetCurrentProcessId();
    
	// 获得和显示这一进程所需的版本，也可以用0表示当前进程
    DWORD dwVerReq=:: GetProcessVersion(dwIdThis);
    WORD wMajorReq=(WORD)(dwVerReq>16) ;
    WORD wMinorReq=(WORD)(dwVerReq & 0xffff) ;
    std :: cout << "Process ID: "<< dwIdThis
                   <<", requires OS: " << wMajorReq <<"." 
                   << wMinorReq << std :: endl ;
    
	// 设置版本信息的数据结构，以便保存操作系统的版本信息
    OSVERSIONINFOEX osvix;
    :: ZeroMemory(&osvix, sizeof(osvix) ) ;
    osvix.dwOSVersionInfoSize=sizeof(osvix) ;
   
	// 获取版本信息和显示
    :: GetVersionEx(reinterpret_cast < LPOSVERSIONINFO > (&osvix)) ;
    std :: cout << "Running on OS:" << osvix.dwMajorVersion <<"."
                << osvix.dwMinorVersion << std :: endl;
    
	
	//显示当前进程的优先级。
	//GetCurrentProcess()返回当前进程的句柄，事实上这个函数目前只是简单的返回-1这个值。
	//但是为了兼容性考虑，我们最好不要直接使用-1，因为并不能保证以后这个值不会改变。
	DWORD dwProcessP=::GetPriorityClass(GetCurrentProcess());
 	std::cout<<"Current process priority is :";
	    switch(dwProcessP) 
		{
            case HIGH_PRIORITY_CLASS:
			     std::cout<<"High";
			     break;
            case NORMAL_PRIORITY_CLASS:
			     std::cout<<"Normal";
			     break;
            case IDLE_PRIORITY_CLASS:
			     std::cout<<"Idle";
		     	 break;
            case REALTIME_PRIORITY_CLASS:
			     std::cout<<"Realtime";
			     break;
            default:
			     std::cout<<"<unknow>";
			     break;
		}
	    std::cout<<std::endl;
    
      // 如果是NTS(Windows 2000) 系统，则提高其优先权
      if (osvix.dwPlatformId==VER_PLATFORM_WIN32_NT && osvix.dwMajorVersion >= 5)
      {
        if(dwProcessP!=HIGH_PRIORITY_CLASS)
		{
			// 如果当前优先级不是high，则改变优先级为high
			:: SetPriorityClass(
			:: GetCurrentProcess() ,			
			HIGH_PRIORITY_CLASS);
    
			//报告给用户
			DWORD dwProcessP = GetPriorityClass(GetCurrentProcess());
			std::cout<<"The Process priority have been changed to ";
			switch(dwProcessP) 
			{
				 case HIGH_PRIORITY_CLASS:
					 std::cout<<"High";
					 break;
				 case NORMAL_PRIORITY_CLASS:
					 std::cout<<"Normal";
					 break;
				 case IDLE_PRIORITY_CLASS:
					 std::cout<<"Idle";
		     		 break;
				 case REALTIME_PRIORITY_CLASS:
					 std::cout<<"Realtime";
					 break;
				 default:
					 std::cout<<"<unknow>";
					 break;
			}
			std::cout<<std::endl;
		}
	}
	return 0;
}

/*
思考题：
1.进程的优先级存放在哪里？
*/