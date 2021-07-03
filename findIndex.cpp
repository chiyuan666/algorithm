#include <iostream>
#include <ctime>
using namespace std;
//生成随机数[min,max] 包括最小值 和最大值
int CreateRandom(int min,int max)
{
	int random=0;
	srand((int)time(0));
	random = rand() % (max-min+1)+min;
	return random;
}
void exchange(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Partition(int* a, int p, int r)
{
	int x = a[p];
	int i = p;//i表示最终的主元的位置

	int j = p+1;
	for (;j<=r;j++)
	{
		if (a[j] <= x)
		{
			i = i + 1;
			exchange(a+i,a+j);
		}
	}
	exchange(a+p,a+i);
	return i;
}
int Partition2(int* a, int p, int r)
{
	int x = a[r];//主元元素选定为最右边的元素
	int i = p - 1;//i记录的是主元的最后下标-1
	int j = p;
	for (; j <= r-1; j++)
	{
		if (a[j] <= x)
		{
			i++;
			exchange(a+i,a+j);
		}
	}
	exchange(a + i + 1, a + r);
	return i+1;
}
void QuickSort(int *a,int p,int r)
{
	if (p < r)
	{
		int q = Partition(a, p, r);
		QuickSort(a, p, q - 1);
		QuickSort(a, q + 1, r);
	}
}
int RandomizedPartition(int* a, int p, int r)
{
	int i = CreateRandom(p,r);
	exchange(a+i,a+p);
	return Partition2(a, p, r);
}
void RandomQuickSort(int *a,int p,int r)
{
	if (p < r)
	{
		int q = RandomizedPartition(a,p,r);
		RandomQuickSort(a,p,q-1);
		RandomQuickSort(a,q+1,r);
	}
}//随机化的快速排序 期望运行时间比较好
//选出数组中第k小的元素 从0开始计下标
int Select(int *a,int k,int p,int r)
{
	//if (p == r)return a[p];
	int index = RandomizedPartition(a,p,r);
	int SortIndex = index-p;
	if (SortIndex == k)return a[index];
	else if (SortIndex > k)return Select(a, k, p, index - 1);
	else return Select(a, k - SortIndex - 1, index + 1, r);
}

int main()
{
	int a[10] = { 23,5,67,3,12,89,10,34,6,45};
	RandomQuickSort(a, 0, 9);
	for (int i = 0; i < 10; i++)
		cout<<a[i]<<endl;
	int num = Select(a,5, 0, 9);
	cout << "-----------------------------------------"<< endl;
	cout<<num<<endl;
	return 0;
}

