// 实验二互斥.cpp : Defines the entry point for the console application.


#include "stdafx.h"
# include <windows.h>
# include <iostream>

HANDLE hMutexValue;
//加法线程和减法线程操作的共享变量。
int Value[2];   

DWORD WINAPI IncThreadProc(LPVOID lpParam)
{
	int Count;

	Count=(int)lpParam;

	while (1)
	{
		// 等待访问数值
		:: WaitForSingleObject(hMutexValue, INFINITE);

		// 改变并显示该值
		Value[0]+=Count;
		Value[1]+=Count;

		std :: cout << "thread:" << :: GetCurrentThreadId()
					<<"  Value[0]:"<<Value[0]<<"  Value[1]:" << Value[1] << std :: endl;
				
		:: Sleep(2000);

		// 释放互斥信号量
		:: ReleaseMutex(hMutexValue);	
	}
	return(0);
}

DWORD WINAPI DecThreadProc(LPVOID lpParam)
{
	int Count;

	Count=(int)lpParam;

	while (1)
	{
		// 等待访问数值
		:: WaitForSingleObject(hMutexValue, INFINITE);

		// 改变并显示该值
		Value[0]-=Count;
		Value[1]-=Count;

		std :: cout << "thread:" << :: GetCurrentThreadId()
					<<"  Value[0]:"<<Value[0]<<"  Value[1]:" << Value[1] << std :: endl;
				
		:: Sleep(2000);

		// 释放互斥信号量
		:: ReleaseMutex(hMutexValue);	
	}
	return(0);
}

int main(int argc, char* argv[])
{
	HANDLE hThreadInc;
    HANDLE hThreadDec;
    DWORD  dwThreadID[2];//用于存储线程的ID
	 
		
	Value[0]=100;
	Value[1]=200;
		
	// 创建互斥体用于访问数值
	hMutexValue=::CreateMutex(
					NULL,	// 缺省的安全性
					FALSE,	// 初始时不拥有。
					        //一个Mutex在没有任何线程拥有的时候处于有信号状态。
					NULL);  // 匿名的，用于线程间。
					
	//创建加法线程			
	hThreadInc=::CreateThread(
					NULL,			// 缺省的安全性
					0,				// 缺省堆栈
					IncThreadProc,	// 线程控制函数。
					(LPVOID)10,     //线程参数，每次加10
					0,				// 无特殊的标志
					&dwThreadID[0]);// 忽略返回的id
					
	//创建减法线程
    hThreadDec=::CreateThread(
					NULL,			// 缺省的安全性
					0,				// 缺省堆栈
					DecThreadProc,	// 线程控制函数
					(LPVOID)5,      //线程参数，每次减5
					0,				// 无特殊的标志
					&dwThreadID[1]);// 忽略返回的id
		
	
	// 依次无限等待两个线程结束。
	// 也可以调用WaitForMultiObject()同时等待多个对象。
	if (hThreadInc!=INVALID_HANDLE_VALUE && hThreadDec!=INVALID_HANDLE_VALUE)
	{
	    ::WaitForSingleObject(hThreadInc, INFINITE);
		::WaitForSingleObject(hThreadDec, INFINITE);
	}

	return 0;
}


/*
思考题：
1.如果main()中没有语句WaitForSingleObject()会出现什么现象？为什么？
2.为什么两个线程使用同一个句柄来引用互斥体？
3.Windows的哪个API对应互斥体的P操作？哪个API对应互斥体的V操作？
4.获取和释放互斥体的调用位置有什么特点？
5.请指出本实验中的共享资源和临界区。
6.两个线程hThreadInc和hThreadDec，如果一个线程运行到:: Sleep()处，
  另一线程很可能运行到哪个地方？处于什么状态？
*/