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
    puts("欢迎来到排序算法测试系统");
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
    puts("##  0.退出程序        ##");
    puts("##  1.插入排序        ##");
    puts("##  2.归并排序        ##");
    puts("##  3.快速排序(递归)  ##");
    puts("##  4.快速排序(非递归)##");
    puts("##  5.计数排序        ##");
    puts("##  6.基数排序        ##");
    puts("##  7.颜色排序        ##");
    puts("##  8.找第k大的数     ##");
    puts("##  9.遍历打印数组    ##");
    puts("##  10.数组乱序       ##");
    puts("##  11.清空屏幕       ##");
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
        printf("请输入数字\n");
        scanf("%s", num);
        if (i = strspn(num, "0123456789"))
        {
            value = atoi(num);
            break;
        }
        else
            printf("输入错误，");
    } while (i == 0);
    return value;
}

void select(int *array,int *temp,int size)
{
    puts("请选择功能");
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
                    puts("归并排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",insert_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入10使数组乱序");
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
                    puts("归并排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",MergeSort_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入10使数组乱序");
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
                    puts("快速排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",QuickSort_Recursion_time);
                    isRandom = 0;

                }
                else
                    puts("请排序前输入10使数组乱序");
                break;
            }

        case 4:

            //QuickSort(array,size);
            puts("快速排序非递归完成，请按9查看排序后的数组");
            break;
        case 5:
        {
            if(isRandom==1)
            {
                    clock_t start,end;
                    start = clock();
                    int max=GetKTop(array,1,size); //获取最大的数;
                    CountSort(array,size,max);
                    end = clock();
                    double CountSort_time = (double)(end - start) / CLOCKS_PER_SEC;
                    puts("计数排序非递归完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",CountSort_time);
                    isRandom = 0;
            }
            else
                puts("请排序前输入10使数组乱序");
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
                    puts("基数排序完成，请按9查看排序后的数组");
                    printf("所消耗的时间为 %f secs\n",RadixCountSort_time);
                    isRandom = 0;
                }
                else
                    puts("请排序前输入10使数组乱序");
                break;
            }

        case 7:
            if(isRandom==1)
            {
                    printf("我们将为你生成一个大小为%d的只含有0，1，2的数组\n",size);
                    int *colorarray = (int *)calloc(size, sizeof(int));
                    getcolorArray(colorarray,size);
                    clock_t start,end;
                    start = clock();
                    ColorSort(colorarray,size);
                    end = clock();
                    double ColorSort_time = (double)(end-start)/ CLOCKS_PER_SEC;
                    puts("颜色排序完成，现在我们开始打印排序后的数组");
                    Display(colorarray,size);
                    printf("所消耗的时间为 %f secs\n",ColorSort_time);
                    isRandom = 0;
                    free(colorarray);
            }
            else
                puts("请排序前输入10使数组乱序");
            break;
        case 8:
            puts("请输入你需要找的第几大的数：");
            int k =read();
            int max=GetKTop(array,k,size);
            printf("第%d大的数为%d\n",k,max);
            break;
        case 9:
            Display(array,size);
            puts("遍历打印数组完成，输入11清空屏幕");
            break;
        case 10:
            MakeRand(array, size);
            puts("数组乱序成功！");
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
            puts("输入错误，请输入0-11之间的整数");
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
