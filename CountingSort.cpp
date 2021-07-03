#include <iostream>
#include <math.h>
using namespace std;

/// <summary>
/// �������� �����ڷǸ��������� ʱ�临�Ӷ�Ϊo(k)+o(n)�����Ե� ���k>=nlgn��ô����㷨��
/// ����鲢 ������ ���� ����k=o(n) ���ӶȾ���o(n)�����Եĸ��Ӷ� Ч���ȽϺ� 
/// </summary>
/// <param name="Array"></param>
/// <param name="n">���鳤��</param>
/// <param name="k">����������������+1</param>//0��Ϊ��һ������
void CountingSout(int *Array,int n,int k)
{
	int *CountArray = new int[k];//���������õ�����
	//��ʼ��
	for (int i = 0;i < k; i++)//�±�0 ��¼0���ֵ�λ�� �±�1 ��¼1���ֵ�λ��
	{
		CountArray[i] = 0;
	}
	//Count
	for (int j = 0; j < n; j++)
	{
		CountArray[Array[j]] = CountArray[Array[j]] + 1;//��1 ��Ϊ��λ��0 ��¼��һ��
	}
	//deal Count
	for (int i = 1; i < k; i++)
	{
		CountArray[i] = CountArray[i] + CountArray[i-1];
	}
	//Sort SortedArray�����ź��������
	int *SortedArray = new int[n];
	for (int j = n - 1; j >= 0; j--)
	{
		CountArray[Array[j]] = CountArray[Array[j]] - 1;
		SortedArray[CountArray[Array[j]]] = Array[j];
		
	}

	//���źõ����鸳ֵ��ԭ��������
	for (int i = 0; i < n; i++)
	{
		Array[i] =SortedArray[i];
	}
	delete[]SortedArray;
	delete[]CountArray;
}

/// <summary>
/// �����Լ��ҳ����ֵ ȷ��kֵ
/// </summary>
/// <param name="Array"></param>
/// <param name="n"></param>
void CountingSout2(int* Array, int n)
{
	int max = Array[0];
	for (int i = 1; i < n; i++)
	{
		if (max < Array[i])
			max = Array[i];
	}
	CountingSout(Array,n,max+1);//�������ֵΪ3 ��count�������� 0 1 2 3 kֵΪ4
}

void Merge(int a[], int p, int q, int r)
{
	//��¼����ĳ���
	int length1 = q - p + 1;
	int length2 = r - q;
	//�½��������� ����ֵ
	int* LeftArray = new int[length1];
	int* RightArray = new int[length2];

	for (int i = 0; i < length1; i++)
	{
		LeftArray[i] = a[p + i];
	}
	for (int j = 0; j < length2; j++)
	{
		RightArray[j] = a[q + 1 + j];
	}
	int index1 = 0;
	int index2 = 0;
	int k = 0;
	for (k = p; k < p + length1 + length2; k++)
	{
		if (LeftArray[index1] <= RightArray[index2])//��ߵ���С ��ȡ��� ����±��һ
		{
			a[k] = LeftArray[index1];
			index1++;
		}
		else
		{
			a[k] = RightArray[index2];
			index2++;
		}
		if (index1 >= length1 || index2 >= length2)
		{
			k++;
			break;
		}
	}
	if (index1 >= length1)//���ұ����������ȥ
	{
		for (; index2 < length2; index2++)
		{
			a[k] = RightArray[index2];
			k++;
		}
	}
	else if (index2 >= length2)//����ߵ����������ȥ
	{
		for (; index1 < length1; index1++)

		{
			a[k] = LeftArray[index1];
			k++;
		}
	}

	delete[]LeftArray;
	delete[]RightArray;
}
//�鲢���� ʱ�临�Ӷȣ�nlgn
void MergeSort(int a[], int left, int right)
{
	//1.if length = 1 return;
	if (left == right)return;
	//2.�������Ϊ�������� [0,(left+right)/2] [(left+right)/2+1,right] �����
		//�ݹ�ִ��
	MergeSort(a, left, (left + right) / 2);
	MergeSort(a, (left + right) / 2 + 1, right);
	//3.����������Merge 
	Merge(a, left, (left + right) / 2, right);
}

//�������� o(k)>=o(nlgn) ���ù鲢 ������Counting Sourt
void complexSort(int *Array,int n)
{
	int max = Array[0];
	for (int i = 1; i < n; i++)
	{
		if (max < Array[i])
			max = Array[i];
	}
	int k = max + 1;
	if (k > n*(log(n) / log(2)))
	{
		cout<< "ʹ���˹鲢����"<<endl;
		//ʹ�ù鲢����
		MergeSort(Array,0,n-1);
	}
	else
	{
		cout << "ʹ���˼�������" << endl;
		//ʹ�ü�������
		CountingSout(Array,n,k);
	}
}
int main()
{
	int a[8] = { 4,3,1,0,1,8,7,5 };//n =5 k=5 {0,1,2,3,4}
	//CountingSout(a,6,5);
	//CountingSout2(a,8);
	complexSort(a,8);//�õĻ��������Ե�ʱ�� ���Ҳ��nlgn������ʱ��
	for (int i = 0; i < 8; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}