#include<iostream>
using namespace std;
int p[100],date[50];
void binsort(int l,int r) {
	if (l == r) 
		return;
	int mid = (l + r) / 2;
	binsort(l, mid);
	binsort(mid + 1, r);
	int sub = 0;
	for (int i = l; i <= mid; i++) {
		date[sub++] = p[i];
	}
	for (int i = 0, j = mid + 1,k=l; i < sub && j <= r&&k<=r;k++) {
		if (date[i] <= p[j]) {
			p[k] = date[i++];
			if (i == sub) {
				for (j; j <= r; j++) {
					p[++k] = p[j];
				}
				break;
			}
		}
		else {
			p[k] = p[j++];
			if (j > r) {
				for (i; i < sub; i++) {
					p[++k] = date[i];
				}
				break;
			}
		}
	}
	return;
}

int main() {
	int n;
	cout << "输入数组长度：";
	cin >> n;
	cout << "输入数组：";
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	binsort(0, n - 1);
	cout << "输出数组：";
	for (int i = 0; i < n; i++) {
		cout << p[i]<<' ';
	}
	return 0;
}