#include"Stack.h"
#include<stdio.h>
void StackInit(Stack* ps)
{
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;
}
void DestorySatck(Stack* ps)
{
	ps->data = NULL;
	ps->capacity = 0;
	ps->top = 0;

}

void StackPush(Stack* ps, Elemtype x)
{
	if (ps->top == ps->capacity)
	{
		size_t newcapacity = ps->capacity == 0 ? sizeof(int) : ps->capacity * 2;
		ps->data = (Elemtype*)realloc(ps->data, sizeof(Elemtype)*newcapacity);//¿ª±ÙÄÚ´æ
		ps->capacity = newcapacity;
	}
	ps->data[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	ps->top--;
}
Elemtype StackTop(Stack* ps)
{
	return ps->data[ps->top - 1];
}
Status StackEmpty(Stack* ps)
{
	return ps->top == 0 ? 0 : 1;
}

