#include "snake.h"

/*
	������ͷ����Ϊ����������ͷ���ܹ�����������
*/
Node *head;

/*
	��ǰ�ߵĳ���
*/
int body;

/*
	��ͷ�ķ���
*/
direction dir = R;

/*
	�����ͷ
*/
Node* get_head()
{
	return head;
}

/*
	���������
*/
int get_body()
{
	return body;
}

/*
	����������
*/
void set_body(int l)
{
	body = l;
}

/*
	�����ͷ����
*/
direction get_dir()
{
	return dir;
}

/*
	������ͷ����
*/
void set_dir(direction d)
{
	dir = d;
}

/*
	��ʼ�������ĳһ�����
*/
void init_node(Node *node, int x_cor, int y_cor)
{
	node->x = x_cor;
	node->y = y_cor;
	node->next = (Node *)malloc( sizeof(Node) );
}

/*
	��ʼ������
*/
void init_snake()
{
	// �α�cur����ͷ��ʼ��������������
	// ������ 600*600 �ģ�һ����Ԫ����20Ϊ�߳��ģ���������Ҳ���� 30*30��
	// �ߵĳ�ʼλ���� ��6��6����һ��������ߣ���ͷ����
	// ���ߵ�����������Ϊ��ʼ����
	// ��β����һ������ǿ�

	Node *cur;
	int init_x = 7 * SIDE;
	int init_y = 7 * SIDE;
	int count = 0;

	body = INITLENGTH;
	head = (Node *)malloc( sizeof(Node) );
	
	cur = head;
	while ( count < INITLENGTH )
	{
		init_node(cur, init_x, init_y);
		init_x -= SIDE;
		cur = cur->next;
		count++;
	}

	cur->next = NULL;
}

/*
	����̰��������
*/
void paint_snake()
{
	// ����������ÿ�����þ��λ�����

	int left;
	int right;
	int top;
	int bottom;

	int count = 0;

	Node *cur;
	cur = head;

	while ( count < body )
	{
		left = cur->x;
		top = cur->y;
		right = cur->x + SIDE;
		bottom = cur->y + SIDE;

		setfillcolor(GREEN);
		fillrectangle(left, top, right, bottom);

		cur = cur->next;
		count++;
	}
}

/*
	����̰����
*/
void reset_snake(int new_x, int new_y)
{
	// ��ͷ����λ�þ��Ǵ������Ĳ���
	// ��������������ͷ��ÿһ��������궼����Ϊ����ǰһ��ĵ������

	Node *cur;

	int setx = new_x;
	int sety = new_y;
	int savex;
	int savey;

	int count = 0;

	cur = head;
	while (count < body)
	{
		// ���õĹ���
		// ÿ�ζ����ȱ��棬�ٸ�ֵ��Ȼ�����α������Ϊ�´θ�ֵ��
		// �����������savex��savey����ֵ��������setx��sety
		savex = cur->x;
		savey = cur->y;
		cur->x = setx;
		cur->y = sety;
		setx = savex;
		sety = savey;

		cur = cur->next;
		count++;
	}
}

/*
	�ƶ�̰����
*/
void move_snake()
{
	// ���ݵ�ǰ����������ͷ����

	int head_x = head->x;
	int head_y = head->y;

	switch (dir)
	{
	case L:
		head_x -= SIDE;
		break;
	case R:
		head_x += SIDE;
		break;
	case T:
		head_y -= SIDE;
		break;
	case B:
		head_y += SIDE;
		break;
	default:
		break;
	}

	reset_snake(head_x, head_y);
}

/*
	�����ߵĳ���
*/
void add_snake()
{
	// �ҵ��ߵ�����������
	// ��������������������ϵ����������������

	Node *cur;
	int tail_x;
	int tail_y;
	int front_x;
	int front_y;
	int new_x;
	int new_y;
	int count = 0;

	// �ҵ����������
	cur = head;
	while ( count < body )
	{
		if ( count == (body-2) )
		{
			front_x = cur->x;
			front_y = cur->y;
		}

		if (count == (body - 1))
		{
			tail_x = cur->x;
			tail_y = cur->y;
			cur->next = (Node*)malloc(sizeof(Node));
		}

		cur = cur->next;
		count++;
	}

	// ���������ڵ������
	if ( tail_x == front_x )
	{
		new_x = tail_x;
		if ( tail_y > front_y )
		{
			new_y = tail_y + SIDE;
		}
		else if ( tail_y < front_y )
		{
			new_y = tail_y - SIDE;
		}
	}
	else if (tail_y == front_y)
	{
		new_y = tail_y;
		if ( tail_x < front_x )
		{
			new_x = tail_x - SIDE;
		}
		else if (tail_x > front_x)
		{
			new_x = tail_x + SIDE;
		}
	}

	// �����ڵ�
	cur->x = new_x;
	cur->y = new_y;
	cur->next = NULL;
	body++;
}
