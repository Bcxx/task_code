#include<iostream>
#include<algorithm>
using namespace std;
int d[100][100];

int main() {
	int m, n;//���������������
	cout << "�������:"; cin >> m;
	cout << "�������:"; cin >> n;
	
	for (int i = 1; i <= n; i++) {//��ʼ������
		for (int j = 1; j <= n; j++) {
			if (i == j)d[i][j] = 0;
			else d[i][j] = INT_FAST32_MAX/2;
		}
	}

	for (int i = 0; i < m; i++) {//��������
		int date1, date2,date3;
		cin >> date1 >> date2 >> date3;
		d[date1][date2] = date3;
	}

	for (int i = 1; i <= n; i++) {//�㷨����
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	cout << "���\n";
	for (int i = 1; i <= n; i++) {//�㷨����
		for (int j = 1; j <= n; j++) {
			if (d[i][j] >= INT32_MAX/2)cout << "$ ";
			else cout << d[i][j] << ' ';
		}
		cout << "\n";
	}

	return 0;
}