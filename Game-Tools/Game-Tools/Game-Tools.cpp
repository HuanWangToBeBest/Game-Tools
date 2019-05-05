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
	MainMenu();
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
