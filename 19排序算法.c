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

	ѡ�������˼��:
	ÿһ��(�����i��,i = 0,1,...,n-2)�ں���n-i�����ŵ�����������ѡ���ؼ�����С��Ԫ��,��Ϊ�������еĵ�i��Ԫ��;

	�������:
	����ͨ��n-1�ιؼ��ֱȽ�,��n����¼���ҳ��ؼ�����С�ļ�¼,�����͵�һ����¼����;
	��ͨ��n-2�ιؼ��ֱȽ�,��n-1����¼���ҳ��ؼ�����С�ļ�¼,�����͵ڶ�����¼����;
	�ظ���������,������n-1����������.
	T(N^2 )
*/
void selectSort(int arr[],int len){

	int k = 0, i = 0,j = 0;

	for (i = 0; i < len;i++)
	{
		k = i;//k��ÿ�˱Ƚϵĵ�һ��Ԫ��,���������еĵ�һ��Ԫ��
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
	ֱ�Ӳ��������㷨:
	1.Ԫ���ó���������λ
	2.����������Ԫ�غ���


*/

void insertSort(int arr[], int len){

	//j��������������±�
	int i = 0,j = 0;
	int temp = -1,k = -1;

	for (i = 1; i < len;i++)
	{
		k = i;
		temp = arr[k];
		for (j = i-1; (j >= 0) && (temp < arr[j]);j--)
		{
			arr[j+1] = arr[j];
			//��¼����λ��k
			k = j;
		}
		arr[k] = temp;
	}

}


void bubbleSort(int arr[], int len){

	int i = 0, j = 0;
	int exchange = 1;//��־λ,0��ʾ�Ѿ��ź���,1��ʾû���ź���

	for (i = 0; i < len && exchange;i++)
	{
		exchange = 0;
		for (j = 1; j < len;j++)
		{
			//ֻҪ�н�����˵��û���ź���
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