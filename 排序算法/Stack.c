#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define NULL 0
#include "Stack.h"

Status initLStack(LinkStack* s)//初始化栈
{
	LinkStackPtr S = (LinkStackPtr)malloc(sizeof(StackNode));
	S->next = NULL;
	s->top = S;
	s->count = 0;
}


Status isEmptyLStack(LinkStack* s)//判断栈是否为空
{
	if (s->count == 0)
		return SUCCESS;
	return ERROR;
}


Status getTopLStack(LinkStack* s, ElemType* e)//得到栈顶元素
{
	if (s->count == 0)
		return ERROR;
	else
		*e = s->top->data;
	return SUCCESS;
}


Status clearLStack(LinkStack* s)//清空栈
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
Status pushLStack(LinkStack* s, ElemType data)//入栈
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("动态分配内存失败!\n");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}




Status popLStack(LinkStack* s, ElemType* data)//出栈
{
	*data = s->top->data;
	LinkStackPtr p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


Status destroyLStack(LinkStack* s)//销毁栈
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

