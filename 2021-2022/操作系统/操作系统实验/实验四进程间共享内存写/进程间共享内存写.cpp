// ���̼乲���ڴ�д.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

int main(int argc, char* argv[])
{
	HANDLE lhShareMemory;  
	char* lpBuffer = NULL;  
	  
	//����һ���������ļ��޹ص��ڴ�ӳ���ļ����󣨻���ʱʹ��ҳ�ļ�����
    /*
      HANDLE   CreateFileMapping(HANDLE   hFile,   
                                 LPSECURITY_ATTRIBUTES   lpFileMappingAttributes,   
                                 DWORD   flProtect,   
                                 DWORD   dwMaximumSizeHigh,   
                                 DWORD   dwMaximumSizeLow,   
                                 LPCTSTR   lpName);  
           hFile:ָ���������д���ӳ���һ���ļ������
                 0xFFFFFFFF��-1����INVALID_HANDLE_VALUE����ʾ����ʱʹ��ҳ�ļ���  
           dwMaximumSizeHigh:�ļ�ӳ�����󳤶ȵĸ�32λ��
           dwMaximumSizeLow:�ļ�ӳ�����󳤶ȵĵ�32λ��
		   ������������������㣬���ô����ļ���ʵ�ʳ��ȡ�
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
	 
	 //���ļ����ļ���һ����ӳ�䵽���̵������ַ�ռ䡣
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
	 std::cout << "����ͨ�ţ����ù����ڴ�" << std::endl; 
	 std::cout << "д����" << std::endl;
	 std::cout << "д������:"<< std::endl<<lpBuffer << std::endl;  

	 getchar();  
	 UnmapViewOfFile(lpBuffer); 
	 
	 return 0;


}
