#include<iostream>
#include<fstream>
#include<algorithm>
#include<malloc.h>
#include<queue>
#include<cstdio>
using namespace std;


struct xixi {
	xixi* left, *right;
	int num; char x;
}*p[50];
struct xxx {
	xixi* a;
	xxx* next;
};
int date[100];

void dfs(xixi* a,int sign) {
	if (a->x != '*') {
		for (int i = 0; i < sign; i++) {
			cout << date[i];
		}
		cout << "\t"<<a->x << '\n';
		return;
	}
	date[sign] = 0;
	dfs(a->left, sign+1);
	date[sign] = 1;
	dfs(a->right, sign+1);
	return;
}

int cmp(xixi* a, xixi* b) {
	return a->num < b->num;
}
int main() {
	freopen("input.txt", "r", stdin);
	int n;
	printf("输入字符数量：\n");
	cin >> n;
	printf("输入出现字符及权重：\n");
	for (int i = 0; i < n; i++) {
		xixi* j;
		j = (xixi*)malloc(sizeof(xixi));
		cin >> j->x >> j->num;
		j->left = NULL;
		j->right = NULL;
		p[i] = j;
	}
	sort(p, p + n, cmp);//按照出现频率排序

	xxx head,*end;
	head.a = p[0];
	head.next = NULL;
	end = &head;
	for (int i = 1; i < n; i++) {
		xxx* j;
		j = (xxx*)malloc(sizeof(xxx));
		j->a = p[i];
		j->next = NULL;
		end->next = j;
		end = end->next;
	}

	xxx* beg;
	beg = &head;
	while(1) {
		if (beg->next == NULL)break;
		xixi* x1, * x2, * x3;
		x1 = beg->a;
		x2 = beg->next->a;
		x3= (xixi*)malloc(sizeof(xixi));
		x3->left = x1;
		x3->right = x2;
		x3->num = x1->num + x2->num;
		x3->x = '*';
		xxx* sign=beg;
		while (1)
		{
			if (sign->next == NULL || sign->next->a->num > x3->num) {
				xxx* j;
				j = (xxx*)malloc(sizeof(xxx));
				j->a = x3;
				j->next = sign->next;
				sign->next = j;
				break;
			}
			sign = sign->next;
		}
		beg = beg->next; beg = beg->next;
	}
	dfs(beg->a,0);


	return 0;
}