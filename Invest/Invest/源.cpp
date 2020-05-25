#include<iostream>
using namespace std;
int a[50][50], b[50][50], c[50][50];
int main()
{
    int n, m;
    cout << "请输入投资额和项目的个数:";
    cin >> m >> n;
    cout << "请输入矩阵：\n";
    for (int i = 0; i < n; i++) {
        cout << "第" << i + 1 << "个项目：";
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
                            c[i][j] = k;//记录
                        }
                    }
                    else {
                        break;
                    }

                }
            }
        }
    }
    cout << "最大利润为" << b[n-1][m] << endl;

    for (int i = n - 1; i >= 0; i--) {
        cout << "第" << i + 1 << "个项目投资额为" << c[i][m] << endl;
        m -= c[i][m];

    }
}