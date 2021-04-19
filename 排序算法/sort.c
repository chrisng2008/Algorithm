#include<stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
        key = a [i];
        j=i-1;//每一次都从i前面的数开始比较
        for(j=i-1;a[j]>key&&j>=0;j--)
        {
            a[j+1]=a[j];//在遇到比key小的数前，数组部分后移，得出一个空位，最后填补
        }
        a[j+1]=key;
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    int i,j,k;
    i=0;
    j=begin;
    k=mid+1;
    while(j<=mid&&k<=end)
    {
        if(a[j]<
           a[k])
        {
            temp[i]=a[j];
            i++;
            j++;
        }
        else
        {
            temp[i]=a[k];
            i++;
            k++;
        }
    }
    //处理剩余的
    while(j<=mid)
    {
        temp[i]=a[j];
        j++;
        i++;
    }
    while(k<=end)
    {
        temp[i]=a[k];
        k++;
        i++;
    }

    //复位
    for(i=0;i<end-begin+1;i++)
        a[begin+i]=temp[i];
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
 //temp应该和a一样大小
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin<end)
    {
        int middle = (begin + end) / 2; //求出中间的位置
        MergeSort(a, begin, middle, temp);
        MergeSort(a, middle + 1, end, temp);  //分别对两个分开的数组再分
        MergeArray(a, begin, middle, end, temp);//合并两个数组
    }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */

void QuickSort_Recursion(int *a, int begin, int end)
{
    int pivot;//哨兵
    //整个数组可以分成三部分[begin,pivot-1],pivot,[pivot+1,end]
    if(begin<end){
        pivot=Partition(a,begin,end);
        QuickSort_Recursion(a,begin,pivot-1);//递归实现左边排序
        QuickSort_Recursion(a,pivot+1,end);//递归实现右边排序
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
/*
void QuickSort(int *a,int size)
{
   int begin,end;//设置头尾两端点，确保成对压入栈
   begin=0;
   end=size-1;
   //入栈,由于栈先进后出，所以我们先将尾端点入栈
   LinkStackPtr s;
   initLStack(&s);//初始化栈


}
*/
/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
 //在这里需要做一次排序，并且返回中间枢纽
int Partition(int *a, int begin, int end)
{
    int pivot;
    pivot=a[begin];
    while(begin<end)
    {
        while(begin<end && a[end]>=pivot)
            end--;
        int temp;
        swap((a+begin),(a+end));
        while(begin<end&&*(a+begin)<=pivot)
            begin ++;
        swap((a+begin),(a+end));
    }
    return begin;//返回枢纽的下标
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
    int *CountArray = (int*)malloc(sizeof(int)*(max+1));
    int *SortArray = (int*)malloc(sizeof(int)*size);
    int i,j;

    //计数数组初始化
    for(i=0;i<max+1;i++)
        CountArray[i]=0;

    //计数数组计数
    for(i=0;i<size;i++)
        CountArray[a[i]] += 1;
    //计数位置求和

    for(i=1;i<=max+1;i++)
        CountArray[i] += CountArray[i-1];

    for(i=size-1;i>=0;i--)//从末尾开始赋值
    {
        SortArray[CountArray[a[i]]-1] = a[i];
        CountArray[a[i]] -= 1;
    }
    //复原
    for(i=0;i<size;i++)
        a[i]=SortArray[i];

    free(CountArray);
    free(SortArray);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */

void RadixCountSort(int *a,int size)
{
    int* array[10];
    for (int i = 0; i < 10; i++)
    {
        array[i] = (int*)malloc(sizeof(int) * (size + 1));
        array[i][0] = 0;
    }

     for (int pos = 1; pos <= 5; pos++)
    {
        for (int i = 0; i < size; i++)
        {
            int num = Knum(a[i], pos);
            int index = array[num][0]+1;
            array[num][index] = a[i];
            array[num][0]++;//计数器长度增加
        }


        for (int i = 0, j = 0; i < 10; i++)
        {
            for (int k = 1; k <= array[i][0]; k++)
                a[j++] = array[i][k];
            array[i][0] = 0;
        }
    }
}


int Knum(int num, int k)
{
    int n = 1;
    for (int i = 0; i < k - 1; i++)
        n *= 10;
    num=num/n;
    num=num%10;//去除个位
    return num;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{

}

/**
 *  @name        : int GetNumTop(int num, int k,int size)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
 /*复制一个数组，然后排序后即可*/
int GetNumTop(int *a,int k,int size)
{
    int *c= (int*)malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)//复制数组
        c[i]=a[i];
    insertSort(c,size);
    int max=c[size-k];
    free(c);
    return max;
}

/**
 *  @name        : void MakeRand(int arr[], int count)
 *  @description : 使数组乱序
 *  @param       : 数组的大小size,array
 */
void MakeRand(int arr[], int size)
{
	srand((unsigned int)time(NULL)); //随机数种子;
	for (int i = 0; i<size - 1; i++)
	{
		int num = i + rand() % (size - 1 - i); // 取随机数
		int temp = arr[i];
		arr[i] = arr[num];
		arr[num] = temp; //交换
	}
}



void getcolorArray(int array[], int size)
{
    int i;
    srand((unsigned int) time(NULL));
    for (i = 0; i < size; i++)
    {
        array[i] = rand()%3;
    }
}


void Display(int array[],int size)
{
	int i,j;
	printf("\n");
    for(i=0; i<size/10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%-5d",array[i*10+j]);
        }
        printf("\n");
    }
    printf("\n");
}

void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}


/*生成随机数列写到文件*/
int WriteArray(int size)
{
    int i,j;
    FILE *pf = NULL;
    int* arr = (int*)malloc(sizeof(int)*size);
    srand((unsigned)time(NULL));//随机种子
    pf = fopen("sort.txt","a");
    //生成数列
    for(i=0; i<size; i++)
    {
        arr[i] = rand()%1000;
    }
    //格式化输出到文件中
    for(i=0; i<size/10; i++)
    {
        for(j=0; j<10; j++)
        {
            fprintf(pf,"%-5d",arr[i*10+j]);
        }
        fprintf(pf,"\n");
    }
    fclose(pf);
    return 0;
}
//读取生成数列
void ReadArray(int size,int* arr)
{
    int i,j;
    FILE *pf;
    if((pf = fopen("sort.txt","r"))==NULL)
    {
        printf("Error\n");
        system("PAUSE");
        exit(1);
    }
    //读取文件内容到数列
    for(i=0; i<size/10; i++)
    {
        for(j=0; j<10; j++)
        {
            fscanf(pf,"%d",&arr[i*10+j]);
        }
        fscanf(pf,"\n");
    }
    fclose(pf);
}


