/*
	绘制苹果的头文件
*/

#pragma once

#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>

#include "snake.h"
#include "background.h"

/*
	生成苹果
*/
void create_apple();

/*
	绘制苹果
*/
void paint_apple();

/*
	返回苹果变量的坐标
*/
void get_apple(int *apple_x, int *apple_y);