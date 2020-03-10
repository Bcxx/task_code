#include<iostream>
using namespace std;
int a[100], d[100][100];
int main() {
	int m, n;
	cout << "输入边数："; cin >> m;
	cout << "输入点数："; cin >> n;
	for (int i = 1; i <= n; i++) {//初始化
		a[i] = INT32_MAX;
		for (int j = 1; j <= n; j++) {
			if (i == j)d[i][j] = 0;
			else d[i][j] = INT32_MAX;
		}
	}
	a[1] = 0;

	for (int i = 0; i < m; i++) {//输入
		char date1, date2;
		int date3;
		cin >> date1 >> date2 >> date3;
		d[date1 - 'a' + 1][date2 - 'a' + 1] = date3;
	}

	for (int i = 1; i < n; i++) {//核心算法
		int date1 = INT32_MAX, date2, date3;
		for (int j = 1; j <= n; j++) {
			if (a[j] != INT32_MAX) {
				for (int k = 1; k <= n; k++) {
					if (a[k]==INT32_MAX&&d[j][k] < date1) {
						date1 = d[j][k];
						date2 = j; date3 = k;
					}
				}
			}
		}
		a[date3] = a[date2] + date1;
	}

	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}

	return 0;
}