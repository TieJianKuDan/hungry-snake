#ifndef STDIO
#define STDIO
#include <stdio.h>
#endif
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif
#ifndef WINDOWS
#define WINDOWS
#include <windows.h>
#endif
#ifndef CONIO
#define CONIO
#include <conio.h>
#endif
#ifndef TIME
#define TIME
#include <time.h>
#endif
#define FOOD '$'

typedef enum Dir {
	UP,
	DOWN,
	LEFT,
	RIGHT
} Dir;

// �Զ����������ͣ������������ͣ�
typedef struct snake {
	int row; // row -> �� 
	int col; // col -> �� 
	char pattern; // pattern -> ͼ�� 
	struct snake * before; // before -> ǰһ���ڵ㣨SnakeNode���ͱ����� 
	struct snake * next; // next -> ��һ���ڵ� 
	Dir dir; 
} SnakeNode;

int draw(int row, int col, char content[row][col]);

SnakeNode* initSnake(int row, int col, char pattern, Dir dir);

int drawSnake(int row, int col, char content[row][col], SnakeNode * head);

SnakeNode* moveSnake(int row, int col, char content[row][col], SnakeNode * head);

int alterSnakeDir(SnakeNode * head, int input);

int productFood(int row, int col, char content[row][col]);

int grow(SnakeNode * head);
