#include "snake.h"

int draw(int row, int col, char content[row][col]) {
	char temp[row * col + row];
	int index = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			temp[index] = content[i][j];
			index++;
		}
		temp[index] = '\n';
		index++;
	}
	temp[index - 1] = '\0';
	printf(temp); 
	return 0;
}
 
// SnakeNode* 表示返回值类型是指针（指向SnakeNode类型变量）
SnakeNode* initSnake(int row, int col, char pattern, Dir dir) {
	SnakeNode* head = (SnakeNode*) malloc(sizeof(SnakeNode)); // *head 解引用 -> 根据 head 中保存的地址，找到对应位置，然后取出内容  
	// SnakeNode node; 也可以声明一个 SnakeNode 类型变量，操作系统自动分配内存。但是，在这个函数执行完后，这块内存就会被释放 
	head->row = row; // == (*head).row = row;
	head->col = col;
	head->pattern = pattern;
	head->dir = dir;
	head->next = head;
	head->before = head;
	return head;
}

int drawSnake(int row, int col, char content[row][col], SnakeNode * head) {
	SnakeNode * p = head;
	do {
		content[p->row][p->col] = p->pattern;
	} while (p != head);
}

SnakeNode* moveSnake(int row, int col, char content[row][col], SnakeNode * head) {
	SnakeNode * tail = head->before;
	content[tail->row][tail->col] = ' ';
	Dir dir = head->dir;
	if (dir == RIGHT) {
		tail->row = head->row;
		tail->col = head->col + 1;
	} else if (dir == LEFT) {
		tail->row = head->row;
		tail->col = head->col - 1;
	} else if (dir == UP) {
		tail->row = head->row - 1;
		tail->col = head->col;
	} else if (dir == DOWN) {
		tail->row = head->row + 1;
		tail->col = head->col;
	} 
	tail->dir = head->dir;
	if (content[tail->row][tail->col] == FOOD) {
		grow(tail);
		productFood(row, col, content);
	}
	if (content[tail->row][tail->col] == '*' || content[tail->row][tail->col] == tail->pattern) {
		tail = NULL;
	}
	return tail;
}

int alterSnakeDir(SnakeNode * head, int input) {
	if (input == 'w') {
		head->dir = UP;	
	} else if (input == 's') {
		head->dir = DOWN;	
	} else if (input == 'a') {
		head->dir = LEFT;	
	} else if (input == 'd') {
		head->dir = RIGHT;	
	}
}

int productFood(int row, int col, char content[row][col]) {
	// (unsigned int) 强制类型转换成 unsigned int
	// NULL == 0
	srand((unsigned int)time(NULL));
	// rand() 随机生成一个数字
	// % 取余 3 % 2 == 1  4 % 2 == 0 n % 2 [0, 1]
	int x = (rand() % (row - 1)) + 1; // x 属于 [1, row - 1]
	int y = (rand() % (col - 1)) + 1; // y 属于 [1, col - 1]
	while(content[x][y] != ' ') {
		x = (rand() % (row - 1)) + 1;
		y = (rand() % (col - 1)) + 1;
	}
	content[x][y] = FOOD;
}

int grow(SnakeNode * head) {
	SnakeNode * node = (SnakeNode *) malloc(sizeof(SnakeNode));
	SnakeNode * tail = head->before;
	Dir dir = tail->dir;
	if (dir == RIGHT) {
		node->row = tail->row;
		node->col = tail->col - 1;
	} else if (dir == LEFT) {
		node->row = tail->row;
		node->col = head->col + 1;
	} else if (dir == UP) {
		node->row = head->row + 1;
		node->col = head->col;
	} else if (dir == DOWN) {
		node->row = head->row - 1;
		node->col = head->col;
	} 
	node->dir = dir;
	node->pattern = tail->pattern;
	node->before = tail;
	node->next = head;
	tail->next = node;
	head->before = node;
}
