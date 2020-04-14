/*
	���������ͷ�ļ�
*/

#pragma once

#include <graphics.h>
#include <stdlib.h>

/*
	̰����ʹ������ʵ��
	�������һ��һ���ĵ�������
	ÿһ����Ķ�������
	x���꣬y�����Լ�����һ�����ָ��
*/
typedef struct snake_node
{
	int x;
	int y;
	snake_node *next;
}Node;

/*
	�������ߵķ���: L-left R-right T-top B-bottom D-δ��ֵ
*/
enum direction {L, R, T, B, D};

/*
	̰���ߵ�ÿһ������������ʵ��
	���������εı߳�SIDE
*/
#define SIDE 20

/*
	��ʼ����INITLENGTH
*/
#define INITLENGTH 5

/*
	�����ͷ
*/
Node* get_head();

/*
	���������
*/
int get_body();

/*
	����������
*/
int get_body();

/*
	������ͷ����
*/
void set_dir(direction d);

/*
	�����ͷ����
*/
direction get_dir();

/*
	��ʼ������
*/
void init_snake();

/*
	�滭����
*/
void paint_snake();

/*
	����̰����
*/
void reset_snake(int new_x, int new_y);

/*
	�ƶ�̰����
*/
void move_snake();

/*
	�����ߵĳ���
*/
void add_snake();