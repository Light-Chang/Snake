/*
	���Ʊ�����ͷ�ļ�
*/

#pragma once

#include <graphics.h>
#include <stdio.h>

#include "snake.h"
#include "apple.h"

// ������Ϸ����ĳ��Ϳ�
#define LENGTH 32*SIDE
#define WIDTH 32*SIDE

/*
	�����Ϸ����
*/
int get_score();

/*
	������Ϸ����
*/
void set_score(int s);

/*
	�ػ汳��
*/
void redraw();

/*
	��ʼ������
*/
void init();

/*
	��ӭ����
*/
void welcome();

/*
	��������
*/
void create_picture();

/*
	��Ϸ����
*/
void end_game();
