// 实验三虚拟内存的检测.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>
#include <shlwapi.h>
#include <iomanip>
#pragma comment(lib, "Shlwapi.lib")

// 显示内存保护的方法。
// 保护标记指示：允许应用程序对内存进行访问的类型以及操作系统强制访问的类型
inline bool TestSet(DWORD dwTarget, DWORD dwMask)
{
    return ((dwTarget &dwMask) == dwMask) ;
}

//宏定义一个函数
//TestSet为内联函数
# define SHOWMASK(dwTarget, type) \
if (TestSet(dwTarget, PAGE_##type) ) \
    {std :: cout << ", " << #type; }

void ShowProtection(DWORD dwTarget)
{
    SHOWMASK(dwTarget, READONLY) ;
    SHOWMASK(dwTarget, GUARD) ;
    SHOWMASK(dwTarget, NOCACHE) ;
    SHOWMASK(dwTarget, READWRITE) ;
    SHOWMASK(dwTarget, WRITECOPY) ;
    SHOWMASK(dwTarget, EXECUTE) ;
    SHOWMASK(dwTarget, EXECUTE_READ) ;
    SHOWMASK(dwTarget, EXECUTE_READWRITE) ;
    SHOWMASK(dwTarget, EXECUTE_WRITECOPY) ;
    SHOWMASK(dwTarget, NOACCESS) ;
}

// 遍历整个进程虚拟地址空间,并显示虚拟内存块的属性
void WalkVM(HANDLE hProcess)
{
    // 首先获得系统信息
    SYSTEM_INFO si;
    :: ZeroMemory(&si, sizeof(si) ) ;
    :: GetSystemInfo(&si) ;

    // 分配要存放信息的缓冲区
    MEMORY_BASIC_INFORMATION mbi;
    :: ZeroMemory(&mbi, sizeof(mbi) ) ;

    // 循环检查整个进程虚拟地址空间
    LPCVOID pBlock = (LPVOID) si.lpMinimumApplicationAddress;
    while (pBlock < si.lpMaximumApplicationAddress)
    {
        // 获得当前虚拟内存块的信息
        if (:: VirtualQueryEx(
            hProcess,			          // 相关的进程
            pBlock,                       // 虚拟内存块的开始位置
			&mbi,                         // 存放虚拟内存块信息的缓冲区
            sizeof(mbi))==sizeof(mbi) )	  // 大小的确认
        {
            // 计算下一虚拟内存块的起始地址
            LPCVOID pEnd = (PBYTE) pBlock + mbi.RegionSize;
			//保存当前虚拟内存块的长度
			TCHAR szSize[MAX_PATH];
            :: StrFormatByteSize(mbi.RegionSize, szSize, MAX_PATH) ;

            // 显示当前虚拟内存块的地址和大小
            std :: cout.fill ('0') ;
            std :: cout
                << std :: hex << std :: setw(8) << (DWORD) pBlock
                << "-"
                << std :: hex << std :: setw(8) << (DWORD) pEnd
                << (:: strlen(szSize)==7? " (" : " (") << szSize
                << ") " ;

            // 显示当前虚拟内存块的状态
            switch(mbi.State)
            {
                case MEM_COMMIT :
					std :: cout << "Committed" ;//虚拟页面映射到外存。
					break;
                case MEM_FREE :
					std :: cout << "Free" ;     
					break;
                case MEM_RESERVE :
					std :: cout << "Reserved" ; // 以这个地址开始的虚拟内存块程序要使用，
					                            // 进程其他分配虚拟内存的操作不得使用这段内存。
					                            // 还没有映射到外存。
					break;
            }

            //重新调整当前虚拟内存块的保护方式
			if(mbi.Protect==0 && mbi.State!=MEM_FREE)
            {
                mbi.Protect=PAGE_READONLY;
            }
			// 显示当前虚拟内存块的保护方式
			ShowProtection(mbi.Protect);

            // 显示当前虚拟内存块的类型
            switch(mbi.Type){
                case MEM_IMAGE :    //该虚拟内存块映射的是可执行文件，如*.dll，*.exe。
					std :: cout << ", Image" ;
					break;
				case MEM_MAPPED:    //该虚拟内存块映射的是数据文件,用CreateFileMapping（）创建。
					std :: cout << ", Mapped";
					break;
                case MEM_PRIVATE :  //该虚拟内存块不被共享，如堆栈。
					std :: cout << ", Private" ;
					break;
			}

            // 获得可执行的文件名。
            TCHAR szFilename [MAX_PATH] ;
            if (:: GetModuleFileName (
                (HMODULE) pBlock,   // 一个模块的句柄。模块句柄跟一般的句柄不一样，
				                    // 模块句柄指向的就是EXE和DLL等在虚拟地址空间的位置。
		                            // 如果该参数为NULL，该函数返回该应用程序全路径。
				szFilename,         // 文件名称
				MAX_PATH)>0)        // 实际使用的缓冲区大小
            {
                // 除去文件名的路径并将文件名显示出来
                :: PathStripPath(szFilename) ;
                std :: cout << ", Module: " << szFilename;
			}

            std :: cout << std :: endl;
			
			// 移动虚拟内存块指针以获得下一个虚拟内存块
            pBlock = pEnd;
        }
    }
}


int main(int argc, char* argv[])
{
	// 遍历当前进程的虚拟地址空间
	::WalkVM(::GetCurrentProcess());
	return 0;
}

/*
思考题：
1.进程的虚拟地址空间可以映射到哪些文件？
*/