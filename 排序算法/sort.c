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
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
    {
        int i=begin;  //������a[0,10]�е�a[0,4]��a[5,9]�ϲ�����������һ��Ԫ���±��i,j
        int j=mid+1;
        int end1=mid;  //�����һ��Ԫ�ظ�ֵ��end1,end2
        int end2=end;
        int k=0;
        while(i<=end1&&j<=end2)   //��������Ԫ�ؽ��бȽϣ�����ֵ��temp��
        {
            if(a[i]<a[j])
                temp[k++]=a[i++];
            else
                temp[k++]=a[j++];
        }
        while(i<=end1)
            temp[k++]=a[i++];   //�������һ��Ԫ����ʣ�࣬��˵��ʣ�µĶ��Ǵ���ˣ�ֱ�Ӹ�ֵ��temp��
        while(j<=end2)
            temp[k++]=a[j++];
        for(i=0;i<k;i++)
            a[begin+i]=temp[i];//��temp�е����ݸ�A
    }
}

/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
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
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
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
		if (div + 1 <end)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st, end);
			StackPush(&st, div+1);
		}
		//[begin,div-1]

		if (begin < div - 1)//�ڴ�������Ԫ�ؾͽ�ջ
		{
			StackPush(&st,div-1);
			StackPush(&st, begin);
		}
	}
}



/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
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
    return begin;//������Ŧ���±�
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
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
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
    int* radixArrays[10];    //ָ������
    for (int i = 0; i < 10; i++)
    {
        radixArrays[i] = (int*)malloc(sizeof(int) * (size + 1));
        radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
    }

    for (int pos = 1; pos <= 10; pos++)    //�Ӹ�λ��ʼ��31λ
    {
        for (int i = 0; i < size; i++)    //�������
        {
            int num = GetNumInPos(a[i], pos);
            int index = ++radixArrays[num][0];
            radixArrays[num][index] = a[i];
        }

        for (int i = 0, j = 0; i < 10; i++)    //�ռ�
        {
            for (int k = 1; k <= radixArrays[i][0]; k++)
                a[j++] = radixArrays[i][k];
            radixArrays[i][0] = 0;    //��λ
        }
    }
}


// �ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int GetNumInPos(int num, int pos)
{
    int temp = 1;
    for (int i = 0; i < pos - 1; i++)
        temp *= 10;

    return (num / temp) % 10;
}

/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
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
 *  @description : ��һ�������������ҵ���K��/С����
 *  @param       : ����ָ��a�����鳤��size
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

void swap(int a, int b)
{
    int temp;
    temp=a;
    a=b;
    b=temp;
}


/*�����������д���ļ�*/
int WriteArray(int size)
{
    int i,j;
    FILE *pf = NULL;
    int* arr = (int*)malloc(sizeof(int)*size);
    srand((unsigned)time(NULL));//�������
    pf = fopen_s("sort.txt", "a");
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
            fscanf_s(pf,"%d",&arr[i*10+j]);
        }
        fscanf_s(pf,"\n");
    }
    fclose(pf);
}

