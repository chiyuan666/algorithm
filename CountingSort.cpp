#include <iostream>
#include <math.h>
using namespace std;

/// <summary>
/// 计数排序 适用于非负整数排序 时间复杂度为o(k)+o(n)是线性的 如果k>=nlgn那么这个算法就
/// 不如归并 推排序 好了 但是k=o(n) 复杂度就是o(n)是线性的复杂度 效果比较好 
/// </summary>
/// <param name="Array"></param>
/// <param name="n">数组长度</param>
/// <param name="k">数组里面最大的整数+1</param>//0记为第一个整数
void CountingSout(int *Array,int n,int k)
{
	int *CountArray = new int[k];//用来计数用的数组
	//初始化
	for (int i = 0;i < k; i++)//下标0 记录0出现的位置 下标1 记录1出现的位置
	{
		CountArray[i] = 0;
	}
	//Count
	for (int j = 0; j < n; j++)
	{
		CountArray[Array[j]] = CountArray[Array[j]] + 1;//减1 因为从位置0 记录第一个
	}
	//deal Count
	for (int i = 1; i < k; i++)
	{
		CountArray[i] = CountArray[i] + CountArray[i-1];
	}
	//Sort SortedArray就是排好序的数组
	int *SortedArray = new int[n];
	for (int j = n - 1; j >= 0; j--)
	{
		CountArray[Array[j]] = CountArray[Array[j]] - 1;
		SortedArray[CountArray[Array[j]]] = Array[j];
		
	}

	//将排好的数组赋值给原来的数组
	for (int i = 0; i < n; i++)
	{
		Array[i] =SortedArray[i];
	}
	delete[]SortedArray;
	delete[]CountArray;
}

/// <summary>
/// 这里自己找出最大值 确定k值
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
	CountingSout(Array,n,max+1);//比如最大值为3 则count的数字有 0 1 2 3 k值为4
}

void Merge(int a[], int p, int q, int r)
{
	//记录数组的长度
	int length1 = q - p + 1;
	int length2 = r - q;
	//新建两个数组 并赋值
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

	delete[]LeftArray;
	delete[]RightArray;
}
//归并排序 时间复杂度：nlgn
void MergeSort(int a[], int left, int right)
{
	//1.if length = 1 return;
	if (left == right)return;
	//2.将数组分为两个部分 [0,(left+right)/2] [(left+right)/2+1,right] 来解决
		//递归执行
	MergeSort(a, left, (left + right) / 2);
	MergeSort(a, (left + right) / 2 + 1, right);
	//3.将两个数组Merge 
	Merge(a, left, (left + right) / 2, right);
}

//复合排序 o(k)>=o(nlgn) 就用归并 否则用Counting Sourt
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
		cout<< "使用了归并排序"<<endl;
		//使用归并排序
		MergeSort(Array,0,n-1);
	}
	else
	{
		cout << "使用了计数排序" << endl;
		//使用计数排序
		CountingSout(Array,n,k);
	}
}
int main()
{
	int a[8] = { 4,3,1,0,1,8,7,5 };//n =5 k=5 {0,1,2,3,4}
	//CountingSout(a,6,5);
	//CountingSout2(a,8);
	complexSort(a,8);//好的话就是线性的时间 最差也有nlgn的运行时间
	for (int i = 0; i < 8; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}