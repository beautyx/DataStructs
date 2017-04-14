#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>



void printArray(int arr[],int len){

	int i = 0;
	for (i = 0; i < len;i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");
}

void swap(int arr[],int m,int n){

	int temp = 0;
	temp = arr[m];
	arr[m] = arr[n];
	arr[n] = temp;
}

/*

	选择排序的思想:
	每一趟(例如第i趟,i = 0,1,...,n-2)在后面n-i个待排的无序序列中选出关键字最小的元素,作为有序序列的第i个元素;

	排序过程:
	首先通过n-1次关键字比较,从n个记录中找出关键字最小的记录,让它和第一个记录交换;
	再通过n-2次关键字比较,从n-1个记录中找出关键字最小的记录,让它和第二个记录交换;
	重复上述操作,共进行n-1趟排序后结束.
	T(N^2 )
*/
void selectSort(int arr[],int len){

	int k = 0, i = 0,j = 0;

	for (i = 0; i < len;i++)
	{
		k = i;//k是每趟比较的第一个元素,即无序序列的第一个元素
		for (j = i + 1; j < len;j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}

		swap(arr,i,k);
	}

}


/*
	直接插入排序算法:
	1.元素拿出来留出空位
	2.符合条件的元素后移


*/

void insertSort(int arr[], int len){

	//j是有序序列里的下标
	int i = 0,j = 0;
	int temp = -1,k = -1;

	for (i = 1; i < len;i++)
	{
		k = i;
		temp = arr[k];
		for (j = i-1; (j >= 0) && (temp < arr[j]);j--)
		{
			arr[j+1] = arr[j];
			//记录待插位置k
			k = j;
		}
		arr[k] = temp;
	}

}


void bubbleSort(int arr[], int len){

	int i = 0, j = 0;
	int exchange = 1;//标志位,0表示已经排好序,1表示没有排好序

	for (i = 0; i < len && exchange;i++)
	{
		exchange = 0;
		for (j = 1; j < len;j++)
		{
			//只要有交换就说明没有排好序
			if (arr[j] < arr[j-1])
			{
				swap(arr, j, j - 1);
				exchange = 1;
			}
		}
	}

}

int main(){

	int array[] = {49,38,65,97,76,13,27};
	int len = sizeof(array) / sizeof(array[0]);

	printArray(array, len);

	//selectSort(array, len);
	//insertSort(array, len);
	bubbleSort(array, len);

	printArray(array, len);


	system("pause");
	return EXIT_SUCCESS;
}