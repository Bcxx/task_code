#include<iostream>
using namespace std;
int j = 0, x, T[100], n = 0;

void divide(int l, int r) {
	if (l == r&&T[l] == x) {
		j = l;
		return;
	}
	else {
		int num = T[(l + r) / 2];
		if (num > x)divide(l, (l + r) / 2);
		else if (num == x) {
			j = (l + r) / 2;
			return;
		}
		else divide((l + r) / 2 + 1, r);
	}
	return;
}

int main() {
	cout << "���������鳤�ȣ�";
	cin >> n;
	cout << "�������������飺";

	for (int i = 1; i <= n; i++) {
		cin >> T[i];
	}
	cout << "���������Ԫ�أ�";
	cin >> x;
	cout << "�������ң�";
	for (int i = 1; i <= n; i++) {
		if (T[i] == x) {
			j = i;
			break;
		}
	}
	if (!j)cout << "j=0\n";
	else cout << "j=" << j << '\n';
	cout << "���ֲ��ң�";
	j = 0;
	divide(1, n);
	if (!j)cout << "j=0\n";
	else cout << "j=" << j << '\n';
	return 0;
}