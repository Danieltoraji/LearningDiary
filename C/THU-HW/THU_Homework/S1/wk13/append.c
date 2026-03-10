#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
struct people {
	int id;
	struct people* next;
};
typedef struct people people;

int main(void) {
	int m, n, i,flag=0,ans;
	people* p = NULL, * head = NULL, * q = NULL, * r = NULL;
	void cut(people*, people**, people*);

	printf("请输入总人数m，暗号n。");
	scanf("%d%d", &m, &n);
	//生成环形链表。id为：0,1,2,...,m-1.
	for (i = 0; i < m; i++) {
		p = malloc(sizeof(people));
		if (p == NULL) {
			printf("ERROR\n");
			return -1;
		}
		p->id = i;
		p->next = NULL;
		if (head == NULL) {
			head = p;
			q = p;
		}
		else {
			q->next = p;
			q = p;
		}
	}
	
	p->next = head;
	
	//遍历表。
	p = head;
	while (flag == 0) {
		for (i = 0; i < n-1; i++) {
			q = p;
			p = p->next;
			printf("a");
		}
		r = p;
		p = p->next;
		cut(q, &r, p);
		if (p->next == p) flag = 1;
	}
	ans = (p->id) + 1;
	printf("%d", ans);

	//free
	free(p);

}
void cut(people*a, people**b, people*c){
	a->next = c;
	//free(*b);
	*b = NULL;
}