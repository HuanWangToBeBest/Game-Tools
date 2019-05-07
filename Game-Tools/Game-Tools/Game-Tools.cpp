// Game-Tools.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <windows.h>

void MainMenu()
{
	printf("==========菜单==========\n");
	printf("       1.修改阳光\n");
	printf("       2.修改金币\n");
	printf("       3.退出\n");
	printf("========================\n");
}
int DisplaySun()
{
	//974488891
	HWND hGame = ::FindWindow(NULL, L"Plants vs. Zombies 1.2.0.1073 RELEASE");
	//得到线程或进程的ID
	DWORD ProcessId;
    //传出参数得到窗口的线程的Id
	::GetWindowThreadProcessId(hGame,&ProcessId);
	//根据id得到进程句柄
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS,false,ProcessId);
	//windows 参数 返回值
	LPVOID pBase = (LPVOID)6987456;//基值 CE
	int sun = 0;
	LPVOID rbuffer = (LPVOID)&sun;
	//hook
	DWORD byred;
	::ReadProcessMemory(hProcess, pBase,rbuffer,4,&byred);

	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);

	::ReadProcessMemory(hProcess, pBase, rbuffer, 4, &byred);
}
int main()
{
	//根据窗口名字得到句柄
	HWND hGame = ::FindWindow(NULL,L"Plants vs. Zombies 1.2.0.1073 RELEASE");
	//得到窗口的详细信息
	RECT r;
	::GetWindowRect(hGame,&r);
	printf("游戏的信息 : %d, %d, %d, %d",r.left,r.top,r.right,r.bottom);
	//得到鼠标的点击位置
	POINT P;
	::GetCursorPos(&P);
	printf("鼠标位置 ：%d %d\n\n\n",P.x,P.y);
	if (NULL == hGame)
	{
		printf("你得先运行游戏植物大战僵尸，在开启外挂！");
		Sleep(30000);
		return 0;
	}

	
	MainMenu();
	int op = 0;
	while (1)
	{
		MainMenu();
		scanf("%d",&op);
		int temp = 0;
		switch (op)
		{
		case 1:
		{
			DisplaySun();
		}
		case 2:
		default:
			break;
		}

	}
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
