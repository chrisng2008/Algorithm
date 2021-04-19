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
typedef long clock_t;
int isRandom = 1;

int main()
{
    puts("��ӭ���������㷨����ϵͳ");
    int * array;
    GetArray(array);
    int *temp = (int *)calloc(size, sizeof(int));
    menu();
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
        scanf("%s", num);
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
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    insertSort(array,size);
                    end = clock();
                    double insert_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("�鲢������ɣ��밴9�鿴����������");
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",insert_time);
                    isRandom = 0;
                }
                else
                    puts("������ǰ����10ʹ��������");
                break;

            }
        case 2:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    MergeSort(array,0,size-1,temp);
                    end = clock();
                    double MergeSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("�鲢������ɣ��밴9�鿴����������");
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",MergeSort_time);
                    isRandom = 0;
                }
                else
                    puts("������ǰ����10ʹ��������");
                break;
            }

        case 3:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    QuickSort_Recursion(array,0,size-1);
                    end = clock();
                    double QuickSort_Recursion_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("����������ɣ��밴9�鿴����������");
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",QuickSort_Recursion_time);
                    isRandom = 0;

                }
                else
                    puts("������ǰ����10ʹ��������");
                break;
            }

        case 4:

            //QuickSort(array,size);
            puts("��������ǵݹ���ɣ��밴9�鿴����������");
            break;
        case 5:
        {
            if(isRandom==1)
            {
                    clock_t start,end;
                    start = clock();
                    int max=GetKTop(array,1,size); //��ȡ������;
                    CountSort(array,size,max);
                    end = clock();
                    double CountSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("��������ǵݹ���ɣ��밴9�鿴����������");
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",CountSort_time);
                    isRandom = 0;
            }
            else
                puts("������ǰ����10ʹ��������");
            break;

        }
        case 6:
            {
                if(isRandom==1)
                {
                    clock_t start,end;
                    start = clock();
                    RadixCountSort(array,size);
                    end = clock();
                    double RadixCountSort_time = (double)(end-start)/ CLOCKS_PER_SEC;
                    puts("����������ɣ��밴9�鿴����������");
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",RadixCountSort_time);
                    isRandom = 0;
                }
                else
                    puts("������ǰ����10ʹ��������");
                break;
            }

        case 7:
            if(isRandom==1)
            {
                    printf("���ǽ�Ϊ������һ����СΪ%d��ֻ����0��1��2������\n",size);
                    int *colorarray = (int *)calloc(size, sizeof(int));
                    getcolorArray(colorarray,size);
                    clock_t start,end;
                    start = clock();
                    ColorSort(colorarray,size);
                    end = clock();
                    double ColorSort_time = (double)(end-start)/ CLOCKS_PER_SEC;
                    puts("��ɫ������ɣ��������ǿ�ʼ��ӡ����������");
                    Display(colorarray,size);
                    printf("�����ĵ�ʱ��Ϊ %f secs\n",ColorSort_time);
                    isRandom = 0;
                    free(colorarray);
            }
            else
                puts("������ǰ����10ʹ��������");
            break;
        case 8:
            puts("����������Ҫ�ҵĵڼ��������");
            int k =read();
            int max=GetKTop(array,k,size);
            printf("��%d�����Ϊ%d\n",k,max);
            break;
        case 9:
            Display(array,size);
            puts("������ӡ������ɣ�����11�����Ļ");
            break;
        case 10:
            MakeRand(array, size);
            puts("��������ɹ���");
            isRandom = 1;
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
    int size;
    size = getInt();
    return size;
}
