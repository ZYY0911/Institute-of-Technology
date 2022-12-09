// ʵ��һ�鿴����������Ϣ.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

// ��ʾ���̺Ͳ���ϵͳ��Ϣ�ļ�ʾ��
int main(int argc, char* argv[])
{
    // ��ȡ������̵�ID��
    DWORD dwIdThis=:: GetCurrentProcessId();
    
	// ��ú���ʾ��һ��������İ汾��Ҳ������0��ʾ��ǰ����
    DWORD dwVerReq=:: GetProcessVersion(dwIdThis);
    WORD wMajorReq=(WORD)(dwVerReq>16) ;
    WORD wMinorReq=(WORD)(dwVerReq & 0xffff) ;
    std :: cout << "Process ID: "<< dwIdThis
                   <<", requires OS: " << wMajorReq <<"." 
                   << wMinorReq << std :: endl ;
    
	// ���ð汾��Ϣ�����ݽṹ���Ա㱣�����ϵͳ�İ汾��Ϣ
    OSVERSIONINFOEX osvix;
    :: ZeroMemory(&osvix, sizeof(osvix) ) ;
    osvix.dwOSVersionInfoSize=sizeof(osvix) ;
   
	// ��ȡ�汾��Ϣ����ʾ
    :: GetVersionEx(reinterpret_cast < LPOSVERSIONINFO > (&osvix)) ;
    std :: cout << "Running on OS:" << osvix.dwMajorVersion <<"."
                << osvix.dwMinorVersion << std :: endl;
    
	
	//��ʾ��ǰ���̵����ȼ���
	//GetCurrentProcess()���ص�ǰ���̵ľ������ʵ���������Ŀǰֻ�Ǽ򵥵ķ���-1���ֵ��
	//����Ϊ�˼����Կ��ǣ�������ò�Ҫֱ��ʹ��-1����Ϊ�����ܱ�֤�Ժ����ֵ����ı䡣
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
    
      // �����NTS(Windows 2000) ϵͳ�������������Ȩ
      if (osvix.dwPlatformId==VER_PLATFORM_WIN32_NT && osvix.dwMajorVersion >= 5)
      {
        if(dwProcessP!=HIGH_PRIORITY_CLASS)
		{
			// �����ǰ���ȼ�����high����ı����ȼ�Ϊhigh
			:: SetPriorityClass(
			:: GetCurrentProcess() ,			
			HIGH_PRIORITY_CLASS);
    
			//������û�
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
˼���⣺
1.���̵����ȼ���������
*/