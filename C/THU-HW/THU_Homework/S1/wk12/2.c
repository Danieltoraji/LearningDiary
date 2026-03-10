#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
//宇宙安全声明
struct student {
	int id;
	char name[20];
	int scores[5];
	int scoresum;
};

int main(void) {
	//声明变量
	void calc_sum(int,struct student**);
	void sort(int, const struct student*, int[]);
	int stunum;
	int i,t,flag;
	int stuarr[20] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };

	//生成动态表格空间
	printf("请输入学生的数量！\n");
	scanf("%d", &stunum);
	struct student* students = (struct student*)malloc(stunum * sizeof(struct student));
	if (students == NULL) {
			printf("程序完蛋了！");
			return 1;
		}

	//信息输入
	{
		printf("请开始输入学生信息。输入格式：【学号 姓名 成绩1 成绩2 成绩3 成绩4 成绩5】。\n");
		for (i = 0;i < stunum;i++) {
			scanf("%d", &(students[i].id));
			scanf("%s", students[i].name);
			for (t = 0;t < 5;t++) scanf("%d", &students[i].scores[t]);
			printf("请检查输入：学生%d的信息如下：学号%d，姓名%s，5门成绩是%d %d %d %d %d。\n"
				, i, students[i].id, students[i].name, students[i].scores[0], students[i].scores[1],
				students[i].scores[2], students[i].scores[3], students[i].scores[4]);
		}
		printf("输入完成！");
	}

	//数据处理
	calc_sum(stunum, &students);
	sort(stunum, students, stuarr);
	{
		printf("已经对输入的学生按分数降序排序。结果是\n");
		for (i = 0;i < stunum;i++) {
			t = stuarr[i];
			printf("学号%d，姓名%s，5门成绩是%d %d %d %d %d。总分为%d。\n"
				, students[t].id, students[t].name, students[t].scores[0], students[t].scores[1],
				students[t].scores[2], students[t].scores[3], students[t].scores[4], students[t].scoresum);
		}
	}

	//查询系统
	flag = 0;
	while (flag == 0) {
		int stuid, t, isstudent = 0;
		printf("这是信息查询系统，很不高兴为您服务！请输入学号。退出请输入-1.");
		scanf("%d", &stuid);
		if (stuid == -1) {
			printf("感谢使用，再见。");
			flag = 1;
			continue;
		}
		for (t = 0;(t < stunum+1)&&(isstudent==0);t++) {
			if (students[t].id == stuid) isstudent = 1;
		}
		t--;
		if (t == stunum) {
			printf("查无此人！请重新输入。");
			continue;
		}
		printf("学号%d，姓名%s，5门成绩是%d %d %d %d %d。总分为%d。\n"
			, students[t].id, students[t].name, students[t].scores[0], students[t].scores[1],
			students[t].scores[2], students[t].scores[3], students[t].scores[4], students[t].scoresum);
	}
	
}

//求和程序
void calc_sum(int stunum, struct student** students) {
	int i, j, temp;
	for (i = 0;i < stunum;i++) {
		temp = 0;
		for (j = 0;j < 5;j++) temp += (*students)[i].scores[j];
		(*students)[i].scoresum = temp;
	}
}
//排序程序
void sort(int stunum, const struct student* students,int p[]) {
	int i,looptime,t;
	for (looptime = 0;looptime < stunum-1;looptime++) {
		for (i = 0;i < stunum - 1;i++) {
			if (students[p[i]].scoresum < students[p[i + 1]].scoresum) {
				t = p[i];
				p[i] = p[i + 1];
				p[i + 1] = t;
			}
		}
	}
}