#pragma once
#include<iostream>
#include<cstring>
#include<Windows.h>
#include<string>
#include<iomanip>
#include<cstdlib>
#include<ctime>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ESC_KEY 27
#define ENTER_KEY 97
#define HELP_KEY 98

using namespace std;

struct position {
	int x, y;
};

struct player {
	string name = "";
	int point;
};

struct CELL1
{
	int i, j;
	char letter = ' ';
	bool isNotEmpty = true;
	bool isSelected = false;
	void drawBox(int);
	void deleteBox();
	void drawBG();
	void highlightMove(int);
};

struct CELL2
{
	int i, j;
	char letter = ' ';
	bool isSelected = false;
	CELL2* pNext;
	void drawBox(int);
	void deleteBox();
};

struct Node
{
	char path;
	Node* next;
};