/*
	绘制贪吃蛇游戏的背景
*/

#include "background.h"

/*
	游戏记分器
*/
int score = 0;

/*
	获得游戏分数
*/
int get_score()
{
	return score;
}

/*
	设置游戏分数
*/
void set_score(int s)
{
	score = s;
}

/*
	绘制边界线
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
	绘制游戏分数
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
	重新绘制背景
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
	初始化背景
*/
void init()
{
	cleardevice();

	// 画边界
	paint_frontier();

	// 初始化蛇
	init_snake();
	paint_snake();

	// 初始化苹果
	create_apple();
	paint_apple();

	// 初始化分数
	paint_score();
}

/*
	欢迎界面
*/
void welcome()
{
	TCHAR sentence1[] = "welcome to snake";
	TCHAR sentence2[] = "conduction:use 'wsad' to control directory";
	TCHAR sentence3[] = "press any key to continue……";

	setcolor(GREEN);
	settextstyle(16, 0, _T("Consolas"));
	outtextxy(10 * SIDE, 10 * SIDE, sentence1);
	outtextxy(10 * SIDE, 11 * SIDE, sentence2);
	outtextxy(10 * SIDE, 12 * SIDE, sentence3);
}

/*
	创建画布
*/
void create_picture()
{
	// 画背景
	initgraph(LENGTH, WIDTH);
	setbkcolor(BLACK);
	cleardevice();
}

/*
	游戏结束
*/
void end_game()
{
	TCHAR sentence1[] = "Game over";

	setcolor(RED);
	settextstyle(72, 0, _T("Consolas"));
	outtextxy(10 * SIDE, 10 * SIDE, sentence1);
}
