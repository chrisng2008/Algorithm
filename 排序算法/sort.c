#include<stdio.h>
#include "sort.h"
#include <stdlib.h>
#include <time.h>
#include "Stack.h"
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
    int key,i,j;
    for(i=1;i<n;i++)
    {
        key = a [i];
        j=i-1;//ÿһ�ζ���iǰ�������ʼ�Ƚ�
        for(j=i-1;a[j]>key&&j>=0;j--)
        {
            a[j+1]=a[j];//��������keyС����ǰ�����鲿�ֺ��ƣ��ó�һ����λ������
        }
        a[j+1]=key;
    }
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
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
    //����ʣ���
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

    //��λ
    for(i=0;i<end-begin+1;i++)
        a[begin+i]=temp[i];
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
 //tempӦ�ú�aһ����С
void MergeSort(int *a,int begin,int end,int *temp)
{
    if(begin<end)
    {
        int middle = (begin + end) / 2; //����м��λ��
        MergeSort(a, begin, middle, temp);
        MergeSort(a, middle + 1, end, temp);  //�ֱ�������ֿ��������ٷ�
        MergeArray(a, begin, middle, end, temp);//�ϲ���������
    }
}

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */

void QuickSort_Recursion(int *a, int begin, int end)
{
    int pivot;//�ڱ�
    //����������Էֳ�������[begin,pivot-1],pivot,[pivot+1,end]
    if(begin<end){
        pivot=Partition(a,begin,end);
        QuickSort_Recursion(a,begin,pivot-1);//�ݹ�ʵ���������
        QuickSort_Recursion(a,pivot+1,end);//�ݹ�ʵ���ұ�����
    }
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
/*
void QuickSort(int *a,int size)
{
   int begin,end;//����ͷβ���˵㣬ȷ���ɶ�ѹ��ջ
   begin=0;
   end=size-1;
   //��ջ,����ջ�Ƚ���������������Ƚ�β�˵���ջ
   LinkStackPtr s;
   initLStack(&s);//��ʼ��ջ


}
*/
/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
 //��������Ҫ��һ�����򣬲��ҷ����м���Ŧ
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
    return begin;//������Ŧ���±�
}

/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
    int *CountArray = (int*)malloc(sizeof(int)*(max+1));
    int *SortArray = (int*)malloc(sizeof(int)*size);
    int i,j;

    //���������ʼ��
    for(i=0;i<max+1;i++)
        CountArray[i]=0;

    //�����������
    for(i=0;i<size;i++)
        CountArray[a[i]] += 1;
    //����λ�����

    for(i=1;i<=max+1;i++)
        CountArray[i] += CountArray[i-1];

    for(i=size-1;i>=0;i--)//��ĩβ��ʼ��ֵ
    {
        SortArray[CountArray[a[i]]-1] = a[i];
        CountArray[a[i]] -= 1;
    }
    //��ԭ
    for(i=0;i<size;i++)
        a[i]=SortArray[i];

    free(CountArray);
    free(SortArray);
}

/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
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
            array[num][0]++;//��������������
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
    num=num%10;//ȥ����λ
    return num;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{

}

/**
 *  @name        : int GetNumTop(int num, int k,int size)
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
 */
 /*����һ�����飬Ȼ������󼴿�*/
int GetNumTop(int *a,int k,int size)
{
    int *c= (int*)malloc(sizeof(int)*size);
    for (int i=0;i<size;i++)//��������
        c[i]=a[i];
    insertSort(c,size);
    int max=c[size-k];
    free(c);
    return max;
}

/**
 *  @name        : void MakeRand(int arr[], int count)
 *  @description : ʹ��������
 *  @param       : ����Ĵ�Сsize,array
 */
void MakeRand(int arr[], int size)
{
	srand((unsigned int)time(NULL)); //���������;
	for (int i = 0; i<size - 1; i++)
	{
		int num = i + rand() % (size - 1 - i); // ȡ�����
		int temp = arr[i];
		arr[i] = arr[num];
		arr[num] = temp; //����
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


/*�����������д���ļ�*/
int WriteArray(int size)
{
    int i,j;
    FILE *pf = NULL;
    int* arr = (int*)malloc(sizeof(int)*size);
    srand((unsigned)time(NULL));//�������
    pf = fopen("sort.txt","a");
    //��������
    for(i=0; i<size; i++)
    {
        arr[i] = rand()%1000;
    }
    //��ʽ��������ļ���
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
//��ȡ��������
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
    //��ȡ�ļ����ݵ�����
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


