#include <iostream>
using namespace std;

void Merge(int a[], int p, int q, int r);
//归并排序 时间复杂度：nlgn
void Sort(int a[],int left,int right)
{
	//1.if length = 1 return;
	if (left == right)return;
	//2.将数组分为两个部分 [0,(left+right)/2] [(left+right)/2+1,right] 来解决
	    //递归执行
	Sort(a,left, (left + right) / 2);
	Sort(a, (left + right) / 2 +1,right);
	//3.将两个数组Merge 
	Merge(a,left, (left + right) / 2,right);
}
// / <summary>
// / 合并两个排好序的数组[p..q] [q+1,r]
// / </summary>
// / <param name="a">待排数组</param>
// / <param name="p">第一个区域数组的起始下标</param>
// / <param name="q">第一个区域数组的结束下标</param>
// / <param name="r">第二个区域数组的结束下标</param>
// / <returns></returns>
void Merge(int a[],int p,int q,int r)
{
	//记录数组的长度
	int length1 = q - p + 1;
	int length2 = r - q;
	//新建两个数组 并赋值
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
		if (LeftArray[index1] <= RightArray[index2])//左边的数小 就取左边 左边下标加一
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
	if (index1 >= length1)//将右边数组添加上去
	{
		for (; index2 < length2; index2++)
		{
			a[k] = RightArray[index2];
			k++;
		}
	}
	else if (index2 >= length2)//将左边的数组添加上去
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