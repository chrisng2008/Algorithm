#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define NULL 0
#include "Stack.h"

Status initLStack(LinkStack* s)//��ʼ��ջ
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
	S->next = NULL;
	s->top = S;
	s->count = 0;
}


Status isEmptyLStack(LinkStack* s)//�ж�ջ�Ƿ�Ϊ��
{
	if (s->count == 0)
		return SUCCESS;
	return ERROR;
}


Status getTopLStack(LinkStack* s, ElemType* e)//�õ�ջ��Ԫ��
{
	if (s->count == 0)
		return ERROR;
	else
		*e = s->top->data;
	return SUCCESS;
}


Status clearLStack(LinkStack* s)//���ջ
{
	if (s->count == 0)
		return ERROR;
	ElemType e;
	for (int i = s->count; i > 0; i--)
	{
		popLStack(s, &e);
	}
	return SUCCESS;
}
Status pushLStack(LinkStack* s, ElemType data)//��ջ
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("��̬�����ڴ�ʧ��!\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}




Status popLStack(LinkStack* s, ElemType* data)//��ջ
{
	*data = s->top->data;
	LinkStackPtr p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


Status destroyLStack(LinkStack* s)//����ջ
{
	if (isEmptyLStack(&s))
		return ERROR;
	while (s->top!=NULL)
	{
		LinkStackPtr p = s->top;
		s->top = s->top->next;
		free(p);
	}
	s->count = 0;
	return SUCCESS;
}


#endif

