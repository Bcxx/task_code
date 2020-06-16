#include<iostream>
#include<fstream>
#include<algorithm>
#include<malloc.h>
#include<queue>
#include<cstdio>
using namespace std;


struct xixi
{
	int n;
	xixi* next;
}*p[50];
int n, bb, m,num=0,date[50];

void insert(int a, int b) {
	xixi* i;
	i = (xixi*)malloc(sizeof(xixi));
	i->n = b;
	i->next = NULL;
	xixi* j;
	j = p[a];
	if (j == NULL) {
		p[a] = i;
		return;
	}
	while (j->next != NULL) {
		j = j->next;
	}
	j->next = i;
}

void dfs(int a) {
	if (a > n) {//Ҷ�ӽڵ㣬���������ɫ����
		for (int i = 1; i <= n;i++) {
			cout<<i<<':' << (char)(date[i]+'a'-1)<<' ';
		}
		cout << '\n';
		num++;
	}
	else {
		for (int i = 1; i <= m; i++) {
			int flag = 1;
			xixi* j;
			j = p[a];
			while (j!=NULL) {//�鿴���ڽڵ�
				if (date[j->n] == i) {
					flag = 0; break;
				}
				j = j->next;
			}
			if (flag) {//���ڽڵ�û���ù������ɫ
				date[a] = i;
				dfs(a + 1);
			}
			date[a] = 0;
		}
	}
	return;
}

int main() {
	freopen("input.txt", "r", stdin);
	printf("����ͼ�Ľڵ�����,�������ɷ�����ɫ������\n");
	cin >> n >> bb >> m;
	printf("����ͼ��\n");
	for (int i = 0; i <= n; i++)p[i] = NULL;
	for (int i = 0; i < bb; i++) {//�ڽ�������ͼ
		int j, k;
		cin >> j >> k;
		insert(j, k);
		insert(k, j);
	}

	
	printf("������з�����\n");
	dfs(1);
	if (!num)cout << "NO";


	return 0;
}