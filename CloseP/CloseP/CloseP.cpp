#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

struct point
{
	double x, y;
	
}a[100], b[100];
double dis(point &a,point &b) {
	return sqrt((b.x-a.x)* (b.x - a.x)+ (b.y - a.y) * (b.y - a.y));
}
bool cmpa(point a, point b) {
	return a.x<b.x;
}
bool cmpb(point a, point b) {
	return a.y<b.y;
}

double ppp(int l,int r) {
	if ((r - l) == 1)return dis(a[l], a[r]);
	double d = min(ppp(l,(l+r)/2),ppp((l+r+1)/2,r));
	double date = (a[r].x - a[l].x) / 2;
	int ll = (l + r) / 2,x=0;
	while (1) {
		if (date - a[ll].x < d) {
			b[x++] = a[ll--];
			if (ll < l)break;
		}
		else break;
	}
	ll = (l + r + 1) / 2;
	while (1) {
		if (a[ll].x-date < d) {
			b[x++] = a[ll++];
			if (ll > r)break;
		}
		else break;
	}
	sort(b, b+x, cmpb);
	for (int i = 0; i < x; i++) {
		int j = i+1;
		while (1) {
			if (j >= x)break;
			double dd = dis(b[i], b[j++]);
			if (dd >= d)break;
			d = min(d, dd);
		}
	}
	return d;
}



int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a, a+n, cmpa);
	cout << ppp(0, n - 1) << endl;

	return 0;
}