#include<iostream>
#include<algorithm>
using namespace std;

int p[100];
int Aaa( int l, int r);
int Bbb( int l, int r);
int Ccc( int l, int r,int k);

int main()
{
	int k,n;
	cout << "输入数组长度：";
	cin >> n;
	cout << "输入数组：";
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	cout << "输入k：";
	cin >> k;
	cout << "第k小值为：";
	cout << Ccc(0, n - 1,k);

	return 0;
}

int Aaa( int l, int r)
{
	int temp;
	int j;
	for (int i = l + 1; i <= r; i++)
	{
		temp = p[i];
		j = i - 1;
		while (j >= l && p[j] > temp)
			p[j + 1] = p[j--];
		p[j + 1] = temp;
	}

	return ((r - l) >> 1) + l;
}

int Bbb( int left, int right)
{
	if (right - left < 5)
		return Aaa( left, right);

	int sub_right = left - 1;
	for (int i = left; i + 4 <= right; i += 5)
	{
		int index = Aaa( i, i + 4);  
		swap(p[++sub_right], p[index]);   
	}

	return Ccc( left, sub_right, ((sub_right - left + 1) >> 1) + 1);
}

int Ccc( int l, int r, int k)
{
	int Sss = Bbb(l, r);
	swap(p[Sss], p[r]);  
	Sss = l;
	for (int i = l; i < r; i++)
	{
		if (p[i] < p[r])
			swap(p[Sss++], p[i]);
	}
	swap(p[Sss], p[r]);
	
	if ((Sss + 1) == k)
		return p[Sss];
	else if ((Sss + 1) > k)return Ccc( l, Sss - 1, k);
	else return Ccc( Sss + 1, r, k - Sss - 1);
}