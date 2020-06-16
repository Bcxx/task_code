#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

struct xixi {
    double x, r;
}p[50];

int n;
double minn = 0xffff;
double date[50];//最小圆排列顺序


double center(int a)
{
    double temp = 0;
    for (int i = 1; i < a; i++)//遍历所有排好序的圆
    {
        double xxx = p[i].x + 2.0 * sqrt(p[a].r * p[i].r); //当前圆和这个圆相切后的圆心；
        if (xxx > temp)
            temp = xxx;
    }
    return temp;
}
void compute()
{
    double low = 0, high = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i].x - p[i].r < low)
            low = p[i].x - p[i].r;
        if (p[i].x + p[i].r > high)
            high = p[i].x + p[i].r;
    }
    if (high - low < minn){
        minn = high - low;
        for (int i = 1; i <= n; i++)
            date[i] = p[i].r;
    }
    return;
}
void dfs(int a)
{
    if (a > n)
    {
        compute();
    }
    else
    {
        for (int i = a; i <= n; i++)
        {
            double t = p[a].r;
            p[a].r = p[i].r;
            p[i].r = t;
            double centerx = center(a);
            if (centerx + p[a].r + p[1].r < minn)
            {
                p[a].x = centerx;
                dfs(a + 1);
            }
            p[i].r = p[a].r;
            p[a].r = t;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    printf("输入圆的数量：\n");
    cin >> n;
    printf("每个圆的半径分别为：\n");
    for (int i = 1; i <= n; i++)
        cin >> p[i].r;
    
    dfs(1);

    cout << "最小排列长度为：" << minn << endl;
    
    cout << "最优排列：";

    for (int i = 1; i <= n; ++i)
        cout << date[i] << ' ';


    return 0;
}