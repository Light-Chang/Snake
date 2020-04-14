/*
	����̰������Ϸ�ı���
*/

#include "background.h"

/*
	��Ϸ�Ƿ���
*/
int score = 0;

/*
	�����Ϸ����
*/
int get_score()
{
	return score;
}

/*
	������Ϸ����
*/
void set_score(int s)
{
	score = s;
}

/*
	���Ʊ߽���
*/
void paint_frontier()
{
	setlinecolor(GREEN);
	line(SIDE, SIDE, SIDE, 31 * SIDE);
	line(SIDE, SIDE, 31 * SIDE, SIDE);
	line(SIDE, 31 * SIDE, 31 * SIDE, 31 * SIDE);
	line(31 * SIDE, SIDE, 31 * SIDE, 31 * SIDE);
	setlinecolor(WHITE);
}

/*
	������Ϸ����
*/
void paint_score()
{
	TCHAR s[5];
	_stprintf_s(s, _T("%d"), score);
	setcolor(WHITE);
	settextstyle(24, 0, _T("Consolas"));
	outtextxy(31 * SIDE, 0, s);
}

/*
	���»��Ʊ���
*/
void redraw()
{
	cleardevice();
	paint_frontier();
	paint_apple();
	paint_snake();
	paint_score();
}

/*
	��ʼ������
*/
void init()
{
	cleardevice();

	// ���߽�
	paint_frontier();

	// ��ʼ����
	init_snake();
	paint_snake();

	// ��ʼ��ƻ��
	create_apple();
	paint_apple();

	// ��ʼ������
	paint_score();
}

/*
	��ӭ����
*/
void welcome()
{
	TCHAR sentence1[] = "welcome to snake";
	TCHAR sentence2[] = "conduction:use 'wsad' to control directory";
	TCHAR sentence3[] = "press any key to continue����";

	setcolor(GREEN);
	settextstyle(16, 0, _T("Consolas"));
	outtextxy(10 * SIDE, 10 * SIDE, sentence1);
	outtextxy(10 * SIDE, 11 * SIDE, sentence2);
	outtextxy(10 * SIDE, 12 * SIDE, sentence3);
}

/*
	��������
*/
void create_picture()
{
	// ������
	initgraph(LENGTH, WIDTH);
	setbkcolor(BLACK);
	cleardevice();
}

/*
	��Ϸ����
*/
void end_game()
{
	TCHAR sentence1[] = "Game over";

	setcolor(RED);
	settextstyle(72, 0, _T("Consolas"));
	outtextxy(10 * SIDE, 10 * SIDE, sentence1);
}
