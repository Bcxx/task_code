#include<iostream>
using namespace std;
int a[50][50], b[50][50], c[50][50];
int main()
{
    int n, m;
    cout << "������Ͷ�ʶ����Ŀ�ĸ���:";
    cin >> m >> n;
    cout << "���������\n";
    for (int i = 0; i < n; i++) {
        cout << "��" << i + 1 << "����Ŀ��";
        for (int j = 0; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0) {
                b[i][j] = a[i][j];
                if (a[i][j] > c[i][j]) {
                    c[i][j] = j;
                }
            }
            else {
                int maxnum = 0;
                for (int k = 0; k <= j; k++) {
                    if (j - k >= 0) {
                        if (b[i][j] < a[i][k] + b[i - 1][j - k]) {
                            b[i][j] = a[i][k] + b[i - 1][j - k];
                            c[i][j] = k;//��¼
                        }
                    }
                    else {
                        break;
                    }

                }
            }
        }
    }
    cout << "�������Ϊ" << b[n-1][m] << endl;

    for (int i = n - 1; i >= 0; i--) {
        cout << "��" << i + 1 << "����ĿͶ�ʶ�Ϊ" << c[i][m] << endl;
        m -= c[i][m];

    }
}