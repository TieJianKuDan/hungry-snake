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

// 自定义数据类型（复杂数据类型）
typedef struct snake {
	int row; // row -> 行 
	int col; // col -> 列 
	char pattern; // pattern -> 图案 
	struct snake * before; // before -> 前一个节点（SnakeNode类型变量） 
	struct snake * next; // next -> 下一个节点 
	Dir dir; 
} SnakeNode;

int draw(int row, int col, char content[row][col]);

SnakeNode* initSnake(int row, int col, char pattern, Dir dir);

int drawSnake(int row, int col, char content[row][col], SnakeNode * head);

SnakeNode* moveSnake(int row, int col, char content[row][col], SnakeNode * head);

int alterSnakeDir(SnakeNode * head, int input);

int productFood(int row, int col, char content[row][col]);

int grow(SnakeNode * head);
