/*
	绘制蛇身的头文件
*/

#pragma once

#include <graphics.h>
#include <stdlib.h>

/*
	贪吃蛇使用链表实现
	蛇身就是一个一个的点连起来
	每一个点的定义如下
	x坐标，y坐标以及到下一个点的指针
*/
typedef struct snake_node
{
	int x;
	int y;
	snake_node *next;
}Node;

/*
	定义蛇走的方向: L-left R-right T-top B-bottom D-未赋值
*/
enum direction {L, R, T, B, D};

/*
	贪吃蛇的每一个点用正方形实现
	定义正方形的边长SIDE
*/
#define SIDE 20

/*
	初始长度INITLENGTH
*/
#define INITLENGTH 5

/*
	获得蛇头
*/
Node* get_head();

/*
	获得蛇身长度
*/
int get_body();

/*
	设置蛇身长度
*/
int get_body();

/*
	设置蛇头方向
*/
void set_dir(direction d);

/*
	获得蛇头方向
*/
direction get_dir();

/*
	初始化蛇身
*/
void init_snake();

/*
	绘画蛇身
*/
void paint_snake();

/*
	重置贪吃蛇
*/
void reset_snake(int new_x, int new_y);

/*
	移动贪吃蛇
*/
void move_snake();

/*
	增加蛇的长度
*/
void add_snake();