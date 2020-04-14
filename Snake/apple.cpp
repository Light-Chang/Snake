/*
	绘制苹果
*/

#include "apple.h"

/*
	定义一个苹果，苹果只包含横纵坐标
*/
struct Apple
{
	int x;
	int y;
}apple;

/*
	生成一个苹果，用随机数
*/
void create_apple()
{
	// 生成两个 0~29 的随机数，作为苹果左上角点的坐标
	// 如果这个坐标是蛇身中的某一个点，那么重新生成

	int unit_length = (LENGTH - 2*SIDE) / SIDE;
	int apple_x;
	int apple_y;
	int count = 0;
	Node *cur;

	while (1)
	{
		apple_x = rand() % unit_length + 1;
		apple_y = rand() % unit_length + 1;

		cur = get_head();
		while ( count < get_body() )
		{
			if ( ( apple_x * SIDE == cur->x ) 
			  && ( apple_y * SIDE == cur->y ) )
			{
				break;
			}
			cur = cur->next;
			count++;
		}

		// 直到蛇身最后一个位置都不与生成的坐标重合，那么count才会加到body
		if (count == get_body())
		{
			break;
		}
	}

	apple.x = apple_x * SIDE;
	apple.y = apple_y * SIDE;
}

/*
	把苹果变量作为矩形绘制出来
*/
void paint_apple()
{
	int left = apple.x;
	int top = apple.y;
	int right = apple.x + SIDE;
	int bottom = apple.y + SIDE;

	setfillcolor(RED);
	fillrectangle(left, top, right, bottom);
}

/*
	返回苹果坐标
*/
void get_apple(int *apple_x, int *apple_y)
{
	*apple_x = apple.x;
	*apple_y = apple.y;
}