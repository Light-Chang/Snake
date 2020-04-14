/*
	����ƻ��
*/

#include "apple.h"

/*
	����һ��ƻ����ƻ��ֻ������������
*/
struct Apple
{
	int x;
	int y;
}apple;

/*
	����һ��ƻ�����������
*/
void create_apple()
{
	// �������� 0~29 �����������Ϊƻ�����Ͻǵ������
	// �����������������е�ĳһ���㣬��ô��������

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

		// ֱ���������һ��λ�ö��������ɵ������غϣ���ôcount�Ż�ӵ�body
		if (count == get_body())
		{
			break;
		}
	}

	apple.x = apple_x * SIDE;
	apple.y = apple_y * SIDE;
}

/*
	��ƻ��������Ϊ���λ��Ƴ���
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
	����ƻ������
*/
void get_apple(int *apple_x, int *apple_y)
{
	*apple_x = apple.x;
	*apple_y = apple.y;
}