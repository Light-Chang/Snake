/*
	������Ϸ�߼�
*/

#include "brain.h"

/*
	��Ϸ�����ı�־������Ϊ1������Ϊ0
*/
int end = 0;

/*
	������뷽��
*/
int check_direction(direction dir)
{
	// ���������ǵ�ǰ�ķ����򣬷���0

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
	�����Ϸ��������
*/
void check_end()
{
	// ��ͷ�������������������ĳһ����ͬ������
	// ����ĺ������곬�� 29*SIDE ������

	Node *cur;
	int count = 0;
	int head_x;
	int head_y;

	cur = get_head();
	head_x = cur->x;
	head_y = cur->y;
	while ( count < get_body() )
	{
		// ǰ������Խ�磬���һ����ײ������
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
	����Ƿ�÷�
*/
void check_score()
{
	// ƻ������������ͷ��ͬ
	// ������ʾ�÷֣�������������ƻ��

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
	�ı���ͷ����
*/
void change_direction()
{
	direction dir = D;
	char inputch;

	// �û����̲�ִ���������
	if ( _kbhit() )
	{
		inputch = _getch();

		// ���ݼ������� w��s��a��d ����dir������ֵ
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

		// �����෴����������
		if (!check_direction(dir))
		{
			return;
		}


		// ���ƶ������÷����ƶ������Ƿ�÷֣�����Ϸ�Ƿ����
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
	������Ϸ
*/
void reset_game()
{
	end = 0;
	set_score(0);
}

/*
	������Ϸ
*/
void play()
{
	while (1)
	{
		// ��������
		create_picture();

		// ��ӭ����
		welcome();
		_getch();

		// ��ʼ��ҳ��
		init();

		// ִ����Ϸ
		while (1)
		{
			// �ı���ͷ����
			change_direction();

			// û�������Զ���ǰ�ƶ�
			Sleep(250);
			move_snake();
			check_score();
			check_end();
			
			// �ж��Ƿ������Ϸ
			if (end)
			{
				break;
			}

			redraw();
		}

		// ��Ϸ����
		end_game();
		_getch();

		reset_game();

		closegraph();
	}
}
