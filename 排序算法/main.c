#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>
#include <ctype.h>
#include "sort.h"
#include <time.h>

int getInt();
void menu();
void select(int *array,int *temp,int size);
int getInt();
char* s_gets(char* st, int n);
void RandonArray(int array[],int size);
int setSize();
int* array;
int main()
{
    puts("��ӭ���������㷨����ϵͳ");
    puts("������Ҫ���Ե������㷨��");
    puts("��Ϊ�㴴��һ�������������!");
    puts("����������Ҫ����������Ĵ�С��a. 10000  b.50000  c. 200000");
    int size = setSize();
    printf("%d",size);
    //int *array = (int *)calloc(size, sizeof(int));
    int *temp = (int *)calloc(size, sizeof(int));
    array = (int*)malloc(sizeof(int)*size);
    menu();
    WriteArray(size);
    ReadArray(size,array);
    select(array,temp,size);
    return 0;
    system("pause");
}



void menu()
{
    printf("\n");
    puts("########################");
    puts("##  0.�˳�����        ##");
    puts("##  1.��������        ##");
    puts("##  2.�鲢����        ##");
    puts("##  3.��������(�ݹ�)  ##");
    puts("##  4.��������(�ǵݹ�)##");
    puts("##  5.��������        ##");
    puts("##  6.��������        ##");
    puts("##  7.��ɫ����        ##");
    puts("##  8.�ҵ�k�����     ##");
    puts("##  9.������ӡ����    ##");
    puts("##  10.��������       ##");
    puts("##  11.�����Ļ       ##");
    puts("########################");
    printf("\n");
}

int read()
{
    int i;
    int value;
    char num[100];
    do
    {
        printf("����������\n");
        scanf_s("%s", num);
        if (i = strspn(num, "0123456789"))
        {
            value = atoi(num);
            break;
        }
        else
            printf("�������");
    } while (i == 0);
    return value;
}

void select(int *array,int *temp,int size)
{
    puts("��ѡ����");
    int n;
    switch (getInt())
    {
        case 1:
            insertSort(array,size);
            puts("�鲢������ɣ��밴9�鿴����������");
            break;
        case 2:
            MergeSort(array,0,size-1,temp);
            puts("�鲢������ɣ��밴9�鿴����������");
            break;
        case 3:
            QuickSort_Recursion(array,0,size-1);
            Display(array,size);
            break;
        case 4:
            QuickSort(array,size);
            puts("��������ǵݹ���ɣ��밴9�鿴����������");
            break;
        case 5:
        {
            int max=GetNumTop(array,1,size);
            CountSort(array,size,max);
            puts("��������ǵݹ���ɣ��밴9�鿴����������");
            break;
        }
        case 6:
            RadixCountSort(array,size);
            puts("����������ɣ��밴9�鿴����������");
            break;
        case 7:
            printf("���ǽ�Ϊ������һ����СΪ%d��ֻ����0��1��2������\n",size);
            int *colorarray = (int *)calloc(size, sizeof(int));
            getcolorArray(colorarray,size);
            printf("������ɵ�����Ϊ��");
            Display(colorarray,size);
            ColorSort(colorarray,size);
            puts("��ɫ������ɣ��������ǿ�ʼ��ӡ����������");
            Display(colorarray,size);
            free(colorarray);
            break;
        case 8:
            puts("����������Ҫ�ҵĵڼ��������");
            int k =read();
            int max=GetNumTop(array,k,size);
            printf("��%d�����Ϊ%d\n",k,max);
            break;
        case 9:
            Display(array,size);
            puts("������ӡ������ɣ�����11�����Ļ");
            break;
        case 10:
            MakeRand(array, size);
            puts("��������ɹ���");
            break;
        case 11:
            system("cls");
            menu();
            break;
        case 0:
            exit(0);
            break;
        default:
            puts("�������������0-11֮�������");
            break;
    }
    select(array,temp,size);
}

int getInt()
{
    char in[11];
    int t;

    s_gets(in, 11);
    t = atoi(in);
    if (t == 0) {
        if (in[1] != 0 || in[2] != '\0')
        {
            t = getInt();
        }
    }
    return t;
}

char* s_gets(char* st, int n)
{
    char* ret_val;
    char* find;

    fflush(stdin);
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;

}

int setSize()
{
    char c[2];
    int i=0;
    int size;
    do
    {
        scanf_s("%s",&c);
        fflush(stdin);
        if(c[0]=='a'&&c[1]=='\0')
        {
            size=10000;
            i=1;
            printf("��ʼ���ɹ������ǽ�Ϊ�㴴��һ����СΪ%d���������\n",size);
        }
        else if(c[0]=='b'&&c[1]=='\0')
        {
            size=50000;
            i=1;
            printf("��ʼ���ɹ������ǽ�Ϊ�㴴��һ����СΪ%d���������\n",size);
        }
        else if(c[0]=='c'&&c[1]=='\0')
        {
            size=200000;
            i=1;
            printf("��ʼ���ɹ������ǽ�Ϊ�㴴��һ����СΪ%d���������\n",size);
        }
        else
        {
            puts("�Բ�����������������ַ� a �� b �� c");
        }
    }while(i==0);
    return size;
}
