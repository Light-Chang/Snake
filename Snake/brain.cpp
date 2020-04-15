/*
	控制游戏逻辑
*/

#include "brain.h"

/*
	游戏结束的标志，结束为1，否则为0
*/
int end = 0;

/*
	检测输入方向
*/
int check_direction(direction dir)
{
	// 如果输入的是当前的反方向，返回0

	int result = 1;

	switch ( get_dir() )
	{
	case L:
		if ( R == dir )
		{
			result = 0;
		}
		break;
	case R:
		if ( L == dir )
		{
			result = 0;
		}
		break;
	case T:
		if ( B == dir )
		{
			result = 0;
		}
		break;
	case B:
		if ( T == dir )
		{
			result = 0;
		}
		break;
	default:
		break;
	}

	return result;
}

/*
	检测游戏结束条件
*/
void check_end()
{
	// 蛇头的坐标与蛇身链表里的某一点相同，结束
	// 蛇身的横纵坐标超过 29*SIDE ，结束

	Node *cur;
	int count = 0;
	int head_x;
	int head_y;

	cur = get_head();
	head_x = cur->x;
	head_y = cur->y;
	while ( count < get_body() )
	{
		// 前四行是越界，最后一行是撞到身体
		if ( ( cur->x > 30 * SIDE )
		  || ( cur->y > 30 * SIDE ) 
		  || ( cur->x < 1 )
		  || ( cur->y < 1 )
		  || ( ( cur->x == head_x) && ( cur->y == head_y) && ( count > 0 ) )
		)
		{
			end = 1;
			break;
		}

		cur = cur->next;
		count++;
	}
}

/*
	检测是否得分
*/
void check_score()
{
	// 苹果的坐标与蛇头相同
	// 重新显示得分，并且重新生成苹果

	int apple_x;
	int apple_y;
	int score = get_score();
	Node *head = get_head();

	get_apple(&apple_x, &apple_y);
	if ( ( apple_x == head->x ) && ( apple_y == head->y ) )
	{
		score++;
		set_score(score);
		add_snake();
		create_apple();
		redraw();
	}
}

/*
	改变蛇头方向
*/
void change_direction()
{
	direction dir = D;
	char inputch;

	// 敲击键盘才执行以下语句
	if ( _kbhit() )
	{
		inputch = _getch();

		// 根据键盘输入 w，s，a，d 设置dir变量的值
		switch (inputch)
		{
		case 'a':
			dir = L;
			break;
		case 'A':
			dir = L;
			break;
		case 'd':
			dir = R;
			break;
		case 'D':
			dir = R;
			break;
		case 'w':
			dir = T;
			break;
		case 'W':
			dir = T;
			break;
		case 's':
			dir = B;
			break;
		case 'S':
			dir = B;
			break;
		default:
			break;
		}

		// 输入相反方向不做操作
		if (!check_direction(dir))
		{
			return;
		}


		// 蛇移动：设置方向，移动，看是否得分，看游戏是否结束
		if (!(D == dir))
		{
			set_dir(dir);
			move_snake();
			check_score();
			check_end();

			if (end)
			{
				return;
			}

			redraw();
		}
	}
}

/*
	重置游戏
*/
void reset_game()
{
	end = 0;
	set_score(0);
}

/*
	运行游戏
*/
void play()
{
	while (1)
	{
		// 创建画布
		create_picture();

		// 欢迎界面
		welcome();
		_getch();

		// 初始化页面
		init();

		// 执行游戏
		while (1)
		{
			// 改变蛇头方向
			change_direction();

			// 没结束蛇自动向前移动
			Sleep(250);
			move_snake();
			check_score();
			check_end();
			
			// 判断是否结束游戏
			if (end)
			{
				break;
			}

			redraw();
		}

		// 游戏结束
		end_game();
		_getch();

		reset_game();

		closegraph();
	}
}
