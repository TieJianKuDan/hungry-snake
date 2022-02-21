// 预处理操作（编译时起作用，编译完成后并不存在于代码中）  
#include "snake.h" // 包含 snake.h 文件 -> 将 snake.h 的内容粘贴到此处 
#define ROW 30 // 宏定义：编译时，代码中的 ROW 都会被替换成 30（和常量有什么不一样？） 
#define COL 50 

// 声明一个二维数组
// 一维数组在内存中是一段连续的空间，哪二维数组如何保存？ 
// content[] 保存的是二维数组中每一个数组的首地址 
char content[ROW][COL] = {
	"**************************************************",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"*                                                *",
	"**************************************************"
};

// main函数程序的入口，名字不能变 
int main() {
	// system -> 函数名 -> 保存函数在内存中的首地址
	// () 表示函数调用 
	// () 里面是传入参数
	system("mode con cols=50 lines=30"); // “ctr + 左击 ” 查看函数声明 
	
	// 初始化蛇
	/* 
	   多行注释 
	*/ 
	// SnakeNode 变量类型
	/* SnakeNode* 指针类型 
		-> 保存地址 (内存单元的编号(整数)) 
		-> 1byte就是一个单元
		-> 指向了 SnakeNode 类型的变量所在的内存单元 
	*/ 
	// head -> 变量名
	SnakeNode* head = initSnake(5, 5, '@', RIGHT);
	productFood(ROW, COL, content);
	while(1) {
		system("cls");
		if (kbhit()) { // kbhit() 如果有键盘输入返回真，否则为假 
			int input = getch(); // 从标准输入流所在缓冲区中拿到一个字符并返回（非阻塞） 
			alterSnakeDir(head, input);
		}
		head = moveSnake(ROW, COL, content, head);
		if (head == NULL) {
			break;
		}
		drawSnake(ROW, COL, content, head);
		draw(30, 50, content);
		Sleep(200);
	}
	printf("****************** Game Over *********************");
}
