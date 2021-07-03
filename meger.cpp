#include <iostream>
using namespace std;

void Merge(int a[], int p, int q, int r);
//�鲢���� ʱ�临�Ӷȣ�nlgn
void Sort(int a[],int left,int right)
{
	//1.if length = 1 return;
	if (left == right)return;
	//2.�������Ϊ�������� [0,(left+right)/2] [(left+right)/2+1,right] �����
	    //�ݹ�ִ��
	Sort(a,left, (left + right) / 2);
	Sort(a, (left + right) / 2 +1,right);
	//3.����������Merge 
	Merge(a,left, (left + right) / 2,right);
}
// / <summary>
// / �ϲ������ź��������[p..q] [q+1,r]
// / </summary>
// / <param name="a">��������</param>
// / <param name="p">��һ�������������ʼ�±�</param>
// / <param name="q">��һ����������Ľ����±�</param>
// / <param name="r">�ڶ�����������Ľ����±�</param>
// / <returns></returns>
void Merge(int a[],int p,int q,int r)
{
	//��¼����ĳ���
	int length1 = q - p + 1;
	int length2 = r - q;
	//�½��������� ����ֵ
	int *LeftArray = new int[length1];
	int* RightArray = new int[length2];

	for (int i = 0; i < length1; i++)
	{
		LeftArray[i] = a[p+i];
	}
	for (int j = 0; j < length2; j++)
	{
		RightArray[j] = a[q+1+j];
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

	delete []LeftArray;
	delete []RightArray;
}

int main()
{
	int a[10] = {10,7,24,90,0,5,67,23,90,46};
	Sort(a,0,9);
	for (int i = 0; i < 10; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}