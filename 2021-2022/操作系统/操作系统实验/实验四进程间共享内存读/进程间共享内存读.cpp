// 进程间共享内存读.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
	 HANDLE lhShareMemory;  
	 char* lpcBuffer;  
	   
	 lhShareMemory = OpenFileMapping(FILE_MAP_READ, false, "mySharedMemory");  
	 if (NULL == lhShareMemory)  
	 {  	  
	    std::cout << "Open share memory unsuccessfully!" << std::endl;  
	    DWORD ldwError = GetLastError();  
	    std::cout << ldwError;  
	    return 0;  
	 }  
	   
	 //把文件或文件的一部分映射到进程的虚拟地址空间。
	 /* 
       LPVOID   MapViewOfFile(HANDLE   hFileMappingObject,   
                              DWORD   dwDesiredAccess,   
                              DWORD   dwFileOffsetHigh,   
                              DWORD   dwFileOffsetLow,   
                              DWORD   dwNumberOfBytesToMap); 
     */
	 lpcBuffer = (char*)MapViewOfFile(lhShareMemory, FILE_MAP_READ, 0, 0, 100);  
	 if (NULL == lpcBuffer)  
	 {  
	    std::cout << "Open share memory unsuccessfully!";  
	    return 0;  
	 }  
	 std::cout << "进程通信：采用共享内存" << std::endl;  
	 std::cout << "读进程" << std::endl;  
	 std::cout << "读入数据:" << std::endl;  
	 for (int i = 0; i < 100; ++i)  
	 {  
	    std::cout << *(lpcBuffer + i);  

	 } 

	 getchar();  
	 UnmapViewOfFile(lpcBuffer);  
	 
	 return 0;  

}


/*
思考题:
1.Windows下的进程间共享内存是利用什么机制实现的？
2.对于读写进程，物理内存是什么时候分配的？
3.读写进程之间的同步和互斥在共享内存机制中已经存在了，还是需要用户自己来实现？
4.利用“虚拟内存的检测”程序检测读进程所映射的虚拟地址空间块的信息。
*/
