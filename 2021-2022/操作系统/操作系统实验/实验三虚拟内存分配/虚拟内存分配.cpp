// 虚拟内存分配.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

void FillZero(LPVOID pBlock, DWORD dwSize)
{
	_try
	{
		BYTE* arFill = (BYTE *) pBlock;
		for (DWORD dwFill = 0; dwFill < dwSize; ++dwFill)
		{
		  arFill [dwFill] = 0; 
		}
		std :: cout << "Memory zeroed." << std :: endl;
	}
    _except(EXCEPTION_EXECUTE_HANDLER)
	{
	   std :: cout << "Could not zero memory. " << std :: endl;
	}
}

int main(int argc, char* argv[])
{
	LPVOID pBlock;

	//1G大小
	DWORD c_dwGigabyte = 1 << 30;
	//1M大小
	DWORD c_dwMegabyte = 1 << 20;
	
	//以下运行4种虚拟内存分配方式，分别调用FillZero（），
	//相当于使用这些内存，测试内存操作是否成功。

	//虚拟内存分配方式1
	pBlock = :: malloc(c_dwGigabyte) ;
	:: FillZero (pBlock, c_dwMegabyte) ;
	:: free(pBlock) ;
	
	//虚拟内存分配方式2
	pBlock = :: VirtualAlloc(
	NULL,		      // 不指定起始地址
	c_dwGigabyte,	  // 要求1GB
	MEM_COMMIT,	      // 虚拟页面映射到外存。
	                  // 此处指映射到页文件，但还没有分配外存空间，当换出时才分配外存。
	                  // 此时也没有分配物理内存，只有当程序访问这部分虚地址时才会真正分配物理内存。
	PAGE_READWRITE) ; // 读写操作
	
	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;
	
	//虚拟内存分配方式3
	pBlock = :: VirtualAlloc(
	NULL,			  // 不指定起始地址
	c_dwGigabyte,	  // 要求1GB
	MEM_RESERVE,	  // 以这个地址开始的虚拟内存块程序要使用，
					  // 进程其他分配虚拟内存的操作不得使用这段内存。
					  // 还没有映射到外存。
	PAGE_READWRITE) ; // 读写操作
	
	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;
	
	//虚拟内存分配方式4
	pBlock = :: VirtualAlloc(
	NULL,		      // 不指定起始地址
	c_dwGigabyte,	  // 要求1GB
	MEM_RESERVE,	  // 以这个地址开始的虚拟内存块程序要使用，
					  // 进程其他分配虚拟内存的操作不得使用这段内存。
					  // 还没有映射到外存。
	PAGE_READWRITE) ; // 读写操作
	
	//给虚拟内存调配外存。
	:: VirtualAlloc(
	pBlock,           // 指定起始地址
	c_dwMegabyte,
	MEM_COMMIT,       // 虚拟页面映射到外存。
	                  // 此处指映射到页文件，但还没有分配外存空间，当换出时才分配外存。
	                  // 此时也没有分配物理内存，只有当程序访问这部分虚地址时才会真正分配物理内存。
	PAGE_READWRITE) ;

	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;

	return 0;
}

/*
思考题：
1.访问没有提交的进程空间能成功吗？
2.使用MEM_COMMIT标志调用VirtualAlloc（）成功后物理内存已经分配了吗？
3.利用“虚拟内存的检测”程序检测上述虚拟内存分配方式4所分配虚拟地址块的信息。
*/