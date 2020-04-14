#include "snake.h"

/*
	定义蛇头，因为是链表，有蛇头就能够访问整个蛇
*/
Node *head;

/*
	当前蛇的长度
*/
int body;

/*
	蛇头的方向
*/
direction dir = R;

/*
	获得蛇头
*/
Node* get_head()
{
	return head;
}

/*
	获得蛇身长度
*/
int get_body()
{
	return body;
}

/*
	设置蛇身长度
*/
void set_body(int l)
{
	body = l;
}

/*
	获得蛇头方向
*/
direction get_dir()
{
	return dir;
}

/*
	设置蛇头方向
*/
void set_dir(direction d)
{
	dir = d;
}

/*
	初始化蛇身的某一个结点
*/
void init_node(Node *node, int x_cor, int y_cor)
{
	node->x = x_cor;
	node->y = y_cor;
	node->next = (Node *)malloc( sizeof(Node) );
}

/*
	初始化蛇身
*/
void init_snake()
{
	// 游标cur从蛇头开始，遍历整个蛇身
	// 界面是 600*600 的，一个单元格是20为边长的，整个界面也就是 30*30的
	// 蛇的初始位置在 （6，6），一条横向的蛇，蛇头向右
	// 把蛇的蛇身长度设置为初始长度
	// 蛇尾的下一个结点是空

	Node *cur;
	int init_x = 7 * SIDE;
	int init_y = 7 * SIDE;
	int count = 0;

	body = INITLENGTH;
	head = (Node *)malloc( sizeof(Node) );
	
	cur = head;
	while ( count < INITLENGTH )
	{
		init_node(cur, init_x, init_y);
		init_x -= SIDE;
		cur = cur->next;
		count++;
	}

	cur->next = NULL;
}

/*
	绘制贪吃蛇蛇身
*/
void paint_snake()
{
	// 遍历蛇身，把每个点用矩形画出来

	int left;
	int right;
	int top;
	int bottom;

	int count = 0;

	Node *cur;
	cur = head;

	while ( count < body )
	{
		left = cur->x;
		top = cur->y;
		right = cur->x + SIDE;
		bottom = cur->y + SIDE;

		setfillcolor(GREEN);
		fillrectangle(left, top, right, bottom);

		cur = cur->next;
		count++;
	}
}

/*
	重置贪吃蛇
*/
void reset_snake(int new_x, int new_y)
{
	// 蛇头的新位置就是传进来的参数
	// 蛇身是链表，旧蛇头的每一个点的坐标都设置为它们前一项的点的坐标

	Node *cur;

	int setx = new_x;
	int sety = new_y;
	int savex;
	int savey;

	int count = 0;

	cur = head;
	while (count < body)
	{
		// 重置的过程
		// 每次都是先保存，再赋值，然后把这次保存的置为下次赋值的
		// 保存的坐标用savex，savey，赋值的坐标用setx，sety
		savex = cur->x;
		savey = cur->y;
		cur->x = setx;
		cur->y = sety;
		setx = savex;
		sety = savey;

		cur = cur->next;
		count++;
	}
}

/*
	移动贪吃蛇
*/
void move_snake()
{
	// 根据当前方向重置蛇头坐标

	int head_x = head->x;
	int head_y = head->y;

	switch (dir)
	{
	case L:
		head_x -= SIDE;
		break;
	case R:
		head_x += SIDE;
		break;
	case T:
		head_y -= SIDE;
		break;
	case B:
		head_y += SIDE;
		break;
	default:
		break;
	}

	reset_snake(head_x, head_y);
}

/*
	增加蛇的长度
*/
void add_snake()
{
	// 找到蛇的最后两个结点
	// 根据最后两个结点的坐标关系决定新增结点的坐标

	Node *cur;
	int tail_x;
	int tail_y;
	int front_x;
	int front_y;
	int new_x;
	int new_y;
	int count = 0;

	// 找到最后两个点
	cur = head;
	while ( count < body )
	{
		if ( count == (body-2) )
		{
			front_x = cur->x;
			front_y = cur->y;
		}

		if (count == (body - 1))
		{
			tail_x = cur->x;
			tail_y = cur->y;
			cur->next = (Node*)malloc(sizeof(Node));
		}

		cur = cur->next;
		count++;
	}

	// 决定新增节点的坐标
	if ( tail_x == front_x )
	{
		new_x = tail_x;
		if ( tail_y > front_y )
		{
			new_y = tail_y + SIDE;
		}
		else if ( tail_y < front_y )
		{
			new_y = tail_y - SIDE;
		}
	}
	else if (tail_y == front_y)
	{
		new_y = tail_y;
		if ( tail_x < front_x )
		{
			new_x = tail_x - SIDE;
		}
		else if (tail_x > front_x)
		{
			new_x = tail_x + SIDE;
		}
	}

	// 新增节点
	cur->x = new_x;
	cur->y = new_y;
	cur->next = NULL;
	body++;
}
