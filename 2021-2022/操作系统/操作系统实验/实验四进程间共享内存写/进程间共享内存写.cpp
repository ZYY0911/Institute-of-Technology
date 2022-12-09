// 进程间共享内存写.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
	HANDLE lhShareMemory;  
	char* lpBuffer = NULL;  
	  
	//创建一个和物理文件无关的内存映射文件对象（换出时使用页文件）。
    /*
      HANDLE   CreateFileMapping(HANDLE   hFile,   
                                 LPSECURITY_ATTRIBUTES   lpFileMappingAttributes,   
                                 DWORD   flProtect,   
                                 DWORD   dwMaximumSizeHigh,   
                                 DWORD   dwMaximumSizeLow,   
                                 LPCTSTR   lpName);  
           hFile:指定欲在其中创建映射的一个文件句柄。
                 0xFFFFFFFF（-1，即INVALID_HANDLE_VALUE）表示换出时使用页文件。  
           dwMaximumSizeHigh:文件映射的最大长度的高32位，
           dwMaximumSizeLow:文件映射的最大长度的低32位，
		   如果这两个参数都是零，就用磁盘文件的实际长度。
    */ 

	 lhShareMemory = CreateFileMapping(HANDLE(0xFFFFFFFF), NULL, PAGE_READWRITE,  
	                                   0, 100, "mySharedMemory");  
	   
	 if (NULL == lhShareMemory)  
	 {  
	    if (ERROR_ALREADY_EXISTS == GetLastError())  
		{  
	       std:: cout << "Already exists!"<<std:: endl;
		}  
	    else  
		{  
	       std::cout << "Create Sheared Memory unsuccessfully!"<< std::endl; 
		}  
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
	 lpBuffer = (char*)MapViewOfFile(lhShareMemory, FILE_MAP_WRITE, 0, 0, 100);  
	 if (NULL == lpBuffer)  
	 {  
	    std::cout << "Get Share memory unsuccessfully!"<< std::endl;  
	    return 0;  
	 }  
   
     strcpy(lpBuffer, "Hello,every students,please study hard! ");  
	 std::cout << "进程通信：采用共享内存" << std::endl; 
	 std::cout << "写进程" << std::endl;
	 std::cout << "写入数据:"<< std::endl<<lpBuffer << std::endl;  

	 getchar();  
	 UnmapViewOfFile(lpBuffer); 
	 
	 return 0;


}
