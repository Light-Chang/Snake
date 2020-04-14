/*
	绘制背景的头文件
*/

#pragma once

#include <graphics.h>
#include <stdio.h>

#include "snake.h"
#include "apple.h"

// 定义游戏界面的长和宽
#define LENGTH 32*SIDE
#define WIDTH 32*SIDE

/*
	获得游戏分数
*/
int get_score();

/*
	设置游戏分数
*/
void set_score(int s);

/*
	重绘背景
*/
void redraw();

/*
	初始化背景
*/
void init();

/*
	欢迎界面
*/
void welcome();

/*
	创建画布
*/
void create_picture();

/*
	游戏结束
*/
void end_game();
