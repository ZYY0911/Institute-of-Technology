// �����ڴ����.cpp : Defines the entry point for the console application.
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

	//1G��С
	DWORD c_dwGigabyte = 1 << 30;
	//1M��С
	DWORD c_dwMegabyte = 1 << 20;
	
	//��������4�������ڴ���䷽ʽ���ֱ����FillZero������
	//�൱��ʹ����Щ�ڴ棬�����ڴ�����Ƿ�ɹ���

	//�����ڴ���䷽ʽ1
	pBlock = :: malloc(c_dwGigabyte) ;
	:: FillZero (pBlock, c_dwMegabyte) ;
	:: free(pBlock) ;
	
	//�����ڴ���䷽ʽ2
	pBlock = :: VirtualAlloc(
	NULL,		      // ��ָ����ʼ��ַ
	c_dwGigabyte,	  // Ҫ��1GB
	MEM_COMMIT,	      // ����ҳ��ӳ�䵽��档
	                  // �˴�ָӳ�䵽ҳ�ļ�������û�з������ռ䣬������ʱ�ŷ�����档
	                  // ��ʱҲû�з��������ڴ棬ֻ�е���������ⲿ�����ַʱ�Ż��������������ڴ档
	PAGE_READWRITE) ; // ��д����
	
	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;
	
	//�����ڴ���䷽ʽ3
	pBlock = :: VirtualAlloc(
	NULL,			  // ��ָ����ʼ��ַ
	c_dwGigabyte,	  // Ҫ��1GB
	MEM_RESERVE,	  // �������ַ��ʼ�������ڴ�����Ҫʹ�ã�
					  // �����������������ڴ�Ĳ�������ʹ������ڴ档
					  // ��û��ӳ�䵽��档
	PAGE_READWRITE) ; // ��д����
	
	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;
	
	//�����ڴ���䷽ʽ4
	pBlock = :: VirtualAlloc(
	NULL,		      // ��ָ����ʼ��ַ
	c_dwGigabyte,	  // Ҫ��1GB
	MEM_RESERVE,	  // �������ַ��ʼ�������ڴ�����Ҫʹ�ã�
					  // �����������������ڴ�Ĳ�������ʹ������ڴ档
					  // ��û��ӳ�䵽��档
	PAGE_READWRITE) ; // ��д����
	
	//�������ڴ������档
	:: VirtualAlloc(
	pBlock,           // ָ����ʼ��ַ
	c_dwMegabyte,
	MEM_COMMIT,       // ����ҳ��ӳ�䵽��档
	                  // �˴�ָӳ�䵽ҳ�ļ�������û�з������ռ䣬������ʱ�ŷ�����档
	                  // ��ʱҲû�з��������ڴ棬ֻ�е���������ⲿ�����ַʱ�Ż��������������ڴ档
	PAGE_READWRITE) ;

	:: FillZero(pBlock, c_dwMegabyte) ;
	:: VirtualFree(pBlock, 0, MEM_RELEASE) ;

	return 0;
}

/*
˼���⣺
1.����û���ύ�Ľ��̿ռ��ܳɹ���
2.ʹ��MEM_COMMIT��־����VirtualAlloc�����ɹ��������ڴ��Ѿ���������
3.���á������ڴ�ļ�⡱���������������ڴ���䷽ʽ4�����������ַ�����Ϣ��
*/