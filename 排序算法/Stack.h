typedef int Elemtype;
typedef struct Stack
{
	Elemtype* data;
	int top;//Õ»¶¥
	int capacity;//ÈÝÁ¿
}Stack;

typedef enum Status
{
	ERROR=0,
	SUCCESS=1,
}Status;

void StackInit(Stack* ps);
void DestoryStack(Stack* ps);

void StackPush(Stack* ps, Elemtype x);


void StackPop(Stack* ps);

Elemtype StackTop(Stack* ps);


Status StackEmpty(Stack* ps);
