// ʵ�������.cpp : Defines the entry point for the console application.


#include "stdafx.h"
# include <windows.h>
# include <iostream>

HANDLE hMutexValue;
//�ӷ��̺߳ͼ����̲߳����Ĺ��������
int Value[2];   

DWORD WINAPI IncThreadProc(LPVOID lpParam)
{
	int Count;

	Count=(int)lpParam;

	while (1)
	{
		// �ȴ�������ֵ
		:: WaitForSingleObject(hMutexValue, INFINITE);

		// �ı䲢��ʾ��ֵ
		Value[0]+=Count;
		Value[1]+=Count;

		std :: cout << "thread:" << :: GetCurrentThreadId()
					<<"  Value[0]:"<<Value[0]<<"  Value[1]:" << Value[1] << std :: endl;
				
		:: Sleep(2000);

		// �ͷŻ����ź���
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
		// �ȴ�������ֵ
		:: WaitForSingleObject(hMutexValue, INFINITE);

		// �ı䲢��ʾ��ֵ
		Value[0]-=Count;
		Value[1]-=Count;

		std :: cout << "thread:" << :: GetCurrentThreadId()
					<<"  Value[0]:"<<Value[0]<<"  Value[1]:" << Value[1] << std :: endl;
				
		:: Sleep(2000);

		// �ͷŻ����ź���
		:: ReleaseMutex(hMutexValue);	
	}
	return(0);
}

int main(int argc, char* argv[])
{
	HANDLE hThreadInc;
    HANDLE hThreadDec;
    DWORD  dwThreadID[2];//���ڴ洢�̵߳�ID
	 
		
	Value[0]=100;
	Value[1]=200;
		
	// �������������ڷ�����ֵ
	hMutexValue=::CreateMutex(
					NULL,	// ȱʡ�İ�ȫ��
					FALSE,	// ��ʼʱ��ӵ�С�
					        //һ��Mutex��û���κ��߳�ӵ�е�ʱ�������ź�״̬��
					NULL);  // �����ģ������̼߳䡣
					
	//�����ӷ��߳�			
	hThreadInc=::CreateThread(
					NULL,			// ȱʡ�İ�ȫ��
					0,				// ȱʡ��ջ
					IncThreadProc,	// �߳̿��ƺ�����
					(LPVOID)10,     //�̲߳�����ÿ�μ�10
					0,				// ������ı�־
					&dwThreadID[0]);// ���Է��ص�id
					
	//���������߳�
    hThreadDec=::CreateThread(
					NULL,			// ȱʡ�İ�ȫ��
					0,				// ȱʡ��ջ
					DecThreadProc,	// �߳̿��ƺ���
					(LPVOID)5,      //�̲߳�����ÿ�μ�5
					0,				// ������ı�־
					&dwThreadID[1]);// ���Է��ص�id
		
	
	// �������޵ȴ������߳̽�����
	// Ҳ���Ե���WaitForMultiObject()ͬʱ�ȴ��������
	if (hThreadInc!=INVALID_HANDLE_VALUE && hThreadDec!=INVALID_HANDLE_VALUE)
	{
	    ::WaitForSingleObject(hThreadInc, INFINITE);
		::WaitForSingleObject(hThreadDec, INFINITE);
	}

	return 0;
}


/*
˼���⣺
1.���main()��û�����WaitForSingleObject()�����ʲô����Ϊʲô��
2.Ϊʲô�����߳�ʹ��ͬһ����������û����壿
3.Windows���ĸ�API��Ӧ�������P�������ĸ�API��Ӧ�������V������
4.��ȡ���ͷŻ�����ĵ���λ����ʲô�ص㣿
5.��ָ����ʵ���еĹ�����Դ���ٽ�����
6.�����߳�hThreadInc��hThreadDec�����һ���߳����е�:: Sleep()����
  ��һ�̺߳ܿ������е��ĸ��ط�������ʲô״̬��
*/