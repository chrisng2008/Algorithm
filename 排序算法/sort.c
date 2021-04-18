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
    int i,j,key;
    for (i=1;i<n;i++)
    {
        key = *(a+i);
        j=i-1;
        for(j=i-1;j>=0 && *(a+j)>key;j--)
        {
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    {
        int i=begin;  //把数组a[0,10]中的a[0,4]和a[5,9]合并，把两个第一个元素下标给i,j
        int j=mid+1;
        int end1=mid;  //把最后一个元素赋值给end1,end2
        int end2=end;
        int k=0;
        while(i<=end1&&j<=end2)   //两个数组元素进行比较，并赋值到temp中
        {
            if(a[i]<a[j])
                temp[k++]=a[i++];
            else
                temp[k++]=a[j++];
        }
        while(i<=end1)
            temp[k++]=a[i++];   //如果其中一个元素有剩余，则说明剩下的都是大的了，直接赋值给temp中
        while(j<=end2)
            temp[k++]=a[j++];
        for(i=0;i<k;i++)
            a[begin+i]=temp[i];//把temp中的内容给A
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
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
    int pivot;
    if(begin<end)
    {
        pivot =Partition(a,begin,end);
        QuickSort_Recursion(a,begin,pivot-1);
        QuickSort_Recursion(a,pivot+1,end);
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */

void QuickSort(int *a,int size)
{
    int left=0,right=size-1;
    Stack st;
	StackInit(&st);
	StackPush(&st, right);
	StackPush(&st, left);
	while (StackEmpty(&st) != 0)
	{
		int begin = StackTop(&st);
		StackPop(&st);
		int end = StackTop(&st);
		StackPop(&st);
		int div = Partition(a, begin, end);
		//[div+1,end]
		if (div + 1 <end)//在此区间有元素就进栈
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//在此区间有元素就进栈
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
	}
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
    int pivotkey;
    pivotkey=*(a+begin);
    while(begin<end)
    {
        while(begin<end && *(a+end)>=pivotkey)
            end--;
        int temp;
        temp = *(a+begin);
        *(a+begin)=*(a+end);
        *(a+end)=temp;
        while(begin<end&&*(a+begin)<=pivotkey)
            begin ++;
        temp = *(a+begin);
        *(a+begin)=*(a+end);
        *(a+end)=temp;
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
    int *count_arr = (int *) malloc(sizeof(int) * (max+1));
    int *sorted_arr=(int*)malloc(sizeof(int)*size);
    int i, j, k;
    for (k = 0; k < max+1; k++)
            count_arr[k] = 0;
    for (i = 0; i < size; i++)
        count_arr[a[i]]++;
    for (k = 1; k < max+1; k++)
        count_arr[k] += count_arr[k - 1];
    for (j = size; j > 0; j--)
        sorted_arr[--count_arr[a[j - 1]]] = a[j - 1];
    for(i=0;i<size;i++)
        a[i]=sorted_arr[i];
    free(count_arr);
    free(sorted_arr);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int *a,int size)
{
    int* radixArrays[10];    //指针数组
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int*)malloc(sizeof(int) * (size + 1));
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
    }

    for (int pos = 1; pos <= 10; pos++)    //从个位开始到31位
    {
        for (int i = 0; i < size; i++)    //分配过程
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = a[i];
        }

        for (int i = 0, j = 0; i < 10; i++)    //收集
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //复位
        }
    }
}


// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int *a,int size)
{
    int p0 = 0, p1 = 0;
    int temp;
    for (int i = 0; i < size; ++i) {
        if (a[i] == 1)
        {
            temp=a[i];
            a[i]=a[p1];
            a[p1]=temp;
            ++p1;
        }
        else if (a[i] == 0) {
            temp=a[i];
            a[i]=a[p0];
            a[p0]=temp;
            if (p0 < p1) {
                temp=a[i];
                a[i]=a[p1];
                a[p1]=temp;
            }
            ++p0;
            ++p1;
        }
    }
}

/**
 *  @name        : int GetNumTop(int num, int k,int size)
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int GetNumTop(int *a,int k,int size)
{
    int *c= (int*)malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)
        c[i]=a[i];
    //QuickSort(c,size);
    int max=c[size-k];
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

void swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}


/*生成随机数列写到文件*/
int WriteArray(int size)
{
    int i,j;
    FILE *pf = NULL;
    int* arr = (int*)malloc(sizeof(int)*size);
    srand((unsigned)time(NULL));//随机种子
    pf = fopen_s("sort.txt", "a");
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
            fscanf_s(pf,"%d",&arr[i*10+j]);
        }
        fscanf_s(pf,"\n");
    }
    fclose(pf);
}

