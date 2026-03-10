#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
struct student {
	int num;
	char name[20];
	int grade;
};
typedef struct student student;
struct stunode {
	struct student* data;
	struct stunode* next;
};
typedef struct stunode stunode;

main() {
	//声明变量
	int stu_num, i;
	static void input_student_info(student*, int);
	static void print_student_info(stunode*);
	stunode* head1 = NULL, *head2 = NULL, *head3 = NULL, *p = NULL;
	stunode* last1 = NULL, * last2 = NULL, * last3 = NULL;

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
	//创建学生信息链表，将合适的链入
	for (i = 0;i < stu_num;i++) {
		p = malloc(sizeof(stunode));
		if (p == NULL) {
			printf("ERROR!\n");
			return 1;
		}
		p->next = NULL;
		p->data = &stu_list[i];
		if (stu_list[i].grade >= 90) {
			if (head1 == NULL) {
				head1 = p;
				last1 = p;
			}
			else {
				last1->next = p;
				last1 = p;
			}
		}
		if ((stu_list[i].grade >= 80) && (stu_list[i].grade <= 89)) {
			if (head2 == NULL) {
				head2 = p;
				last2 = p;
			}
			else {
				last2->next = p;
				last2 = p;
			}
		}
		if ((stu_list[i].grade >= 70) && (stu_list[i].grade <= 79)) {
			if (head3 == NULL) {
				head3 = p;
				last3 = p;
			}
			else {
				last3->next = p;
				last3 = p;
			}
		}
	}
	//开始打印列表;
	printf("90+名单\n");
	print_student_info(head1);
	printf("80~89名单\n");
	print_student_info(head2);
	printf("70~79名单\n");
	print_student_info(head3);
}

static void input_student_info(struct student* stu_list, int stu_num) {
	int i;
	for (i = 0;i < stu_num;i++) {
		scanf("%d", &(stu_list[i].num));
		scanf("%s", &(stu_list[i].name));
		scanf("%d", &(stu_list[i].grade));
	}
}
static void print_student_info(stunode* head) {
	printf("学号\t姓名\t成绩\n");
	while (head != NULL) {
		printf("%d\t%s\t%d\n", head->data->num, head->data->name, head->data->grade);
		head = head->next;
	}
}