#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;


struct xixi {
	int begin, end;
	int len;
}p[100];

int cmp(xixi &a, xixi  &b) {
	return a.end < b.end;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	printf("����������\n");
	cin >> n;
	printf("���뿪ʼ����ֹʱ�䣺\n");
	for (int i = 0; i < n; i++) {
		cin >> p[i].begin >> p[i].end;
		p[i].len= p[i].end - p[i].begin;
	}
	sort(p, p + n, cmp);

	printf("���ţ�\n");
	int date = p[0].end, sum = 1;

	printf("%d---%d\n",p[0].begin,p[0].end);
	for (int i = 1; i < n; i++) {
		if (p[i].begin > date) {
			printf("%d---%d\n", p[i].begin, p[i].end);
			sum++;
			date = p[i].end;
		}
	}


	return 0;
}