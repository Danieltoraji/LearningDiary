#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#pragma warning(disable:4996)
struct student {
	int num;
	char name[20];
	int grade;
};
typedef struct student student;
struct stunode {
	int num;
	char name[20];
	int grade;
	struct stunode* next;
};
typedef struct stunode stunode;

int main(void) {
	//声明变量
	int stu_num, i;
	static void input_student_info(student*,int);
	static void copy_student_info(student*, stunode*, int);
	static void print_student_info(stunode*);
	struct stunode* head = NULL; struct stunode* newstu = NULL;struct stunode* p = NULL;struct stunode* q = NULL;

	//创建学生表格空间
	printf("请输入学生个数\n");
	scanf("%d", &stu_num);
	struct student* stu_list = malloc(stu_num * sizeof(struct student));
	if (stu_list == NULL) {
		printf("ERROR!\n");
		return 1;
	}
	printf("需要输入学生信息。学号 姓名 成绩。");
	input_student_info(stu_list, stu_num);
	
	//创建学生信息链表
	for (i = 0;i < stu_num;i++) {
		newstu = malloc(sizeof(stunode));
		if (newstu == NULL) {
			printf("ERROR!\n");
			return 1;
		}
		newstu->next = NULL;
		if (head == NULL) {
			head = newstu;
			p = newstu;
		}
		else {
			p->next = newstu;
			p = newstu;
		}
	}
	//拷贝链表信息
	copy_student_info(stu_list, head, stu_num);
	//打印链表信息
	print_student_info(head);
	//逐步释放内存
	/*stunode*/
	p = head;
	q = p;
	while (q != NULL) {
		q = p->next;
		free(p);
		p = q;
	}
	/*stu_list*/
	free(stu_list);
	stu_list = NULL;
}

static void input_student_info(struct student* stu_list, int stu_num) {
	int i;
	for (i = 0;i < stu_num;i++) {
		scanf("%d", &(stu_list[i].num));
		scanf("%s", &(stu_list[i].name));
		scanf("%d", &(stu_list[i].grade));
	}
}
static void copy_student_info(student* stu_list, stunode* head, int stu_num) {
	int i = 0;
	for (;i < stu_num;i++) {
		head->num = stu_list[i].num;
		head->grade = stu_list[i].grade;
		strcpy(head->name, stu_list[i].name);
		head = head->next;
	}
}
static void print_student_info(stunode* head) {
	printf("学号\t姓名\t成绩\n");
	while (head != NULL) {
		printf("%d\t%s\t%d\n", head->num, head->name, head->grade);
		head = head->next;
	}
}