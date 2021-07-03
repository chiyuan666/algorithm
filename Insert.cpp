#include <iostream>
using namespace std;

//插入排序 时间复杂度：n^2
void InsertSort(int a[],int length)
{
	int current;
	for (int i = 1; i < length; i++)
	{
		current = a[i];
		int j = i - 1;
		while (j >= 0 && a[j] > current)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = current;
	}
}

int main()
{
	int a[10] = {1,3,4,10,6,50,-4,9,7,10};
	InsertSort(a,10);
	for (int i = 0; i < 10; i++)
	{
		cout<<a[i]<<endl;
	}
	return 0;
}

