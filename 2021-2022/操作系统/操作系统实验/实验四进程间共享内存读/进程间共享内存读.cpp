// ���̼乲���ڴ��.cpp : Defines the entry point for the console application.
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
	   
	 //���ļ����ļ���һ����ӳ�䵽���̵������ַ�ռ䡣
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
	 std::cout << "����ͨ�ţ����ù����ڴ�" << std::endl;  
	 std::cout << "������" << std::endl;  
	 std::cout << "��������:" << std::endl;  
	 for (int i = 0; i < 100; ++i)  
	 {  
	    std::cout << *(lpcBuffer + i);  

	 } 

	 getchar();  
	 UnmapViewOfFile(lpcBuffer);  
	 
	 return 0;  

}


/*
˼����:
1.Windows�µĽ��̼乲���ڴ�������ʲô����ʵ�ֵģ�
2.���ڶ�д���̣������ڴ���ʲôʱ�����ģ�
3.��д����֮���ͬ���ͻ����ڹ����ڴ�������Ѿ������ˣ�������Ҫ�û��Լ���ʵ�֣�
4.���á������ڴ�ļ�⡱�������������ӳ��������ַ�ռ�����Ϣ��
*/
