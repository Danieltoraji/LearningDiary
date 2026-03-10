#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
typedef struct word {
	char wordstr[64];
	unsigned int wordcount;
	struct word* next;
} word;


int compare(word* a, word* b) {//判断：a应该在b的前面吗？
	if (strcmp(a->wordstr, b->wordstr) == 0) return 0;
	if (a->wordcount > b->wordcount) return 1;
	if (a->wordcount < b->wordcount) return 0;
	if (strcmp(a->wordstr, b->wordstr) > 0) return 0;
	if (strcmp(a->wordstr, b->wordstr) < 0) return 1;
}

int main(void) {
	FILE *fp;
	short readend = 0;
	char nowread[64];
	char nowchar;
	short wordend;
	short i;
	short okay;
	short validword=0;
	int wordcount=0;
	word* head = NULL;
	word* nowword = NULL;
	word* nowcheck;
	word* pastcheck;
	word* nowprint;
	fp = fopen("input.txt", "r");//打开文件
	if (fp == NULL) {
		printf("File Not Found Error");
		return -9;
	}

	while (!readend) {//划分单词。大写转小写，-'保留，<sp>,.作划分，其余忽略。有字母的才会算作有效单词。
		validword = 0;
		for (i = 0;i < 64;i++) {
			nowread[i] = '\0';
		}
		for (i = 0, wordend = 0;!wordend;i++) {
			nowchar = fgetc(fp);
			if (nowchar == -1) {
				wordend = 1;
				readend = 1;
			}
			else if ((nowchar >= 'A') && (nowchar <= 'Z')) {
				nowchar += 'a' - 'A';
				nowread[i] = nowchar;
				validword = 1;
			}
			else if ((nowchar >= 'a') && (nowchar <= 'z')) {
				nowread[i] = nowchar;
				validword = 1;
			}
			else if ((nowchar == 39) || (nowchar == 45)) {
				nowread[i] = nowchar;
			}
			else {
				wordend = 1;
			}
		}

		if (validword) {//逐个查找：该单词是否存在了？
			wordcount++;
			okay = 0;
			nowcheck = head;
			pastcheck = head;
			while ((nowcheck != NULL) && (!okay)) {
				if (strcmp(nowcheck->wordstr, nowread) == 0) {
					nowcheck->wordcount++;
					okay = 1;
				}
				else {
					pastcheck = nowcheck;
					nowcheck = nowcheck->next;
				}

			}
			if (!okay) {//如果不存在，那就创建一个新的单词
				word* newword = (word*)malloc(sizeof(word));
				if (newword == NULL) {
					printf("ERROR");return -1;
				}
				newword->wordcount = 1;
				strcpy(newword->wordstr, nowread);
				newword->next = NULL;
				if (head == NULL)  head = newword;
				else pastcheck->next = newword;
			}

		}
	}

	int count = 0;//统计词汇数量
	word* p = head;
	while (p) { count++; p = p->next; }

	p = head;//构建一个指针构成的数组，用来排序。
	word **wordlist=(word**)malloc(count * sizeof(word*));
	for (i = 0;i < count;i++) {
		wordlist[i] = p;
		if (p!=NULL) p = p->next;
	}
	word* temp;
	for (i = 0;i < count;i++) {//使用冒泡排序，交换数组的元素。
		for (int j = 0;j < count-1;j++) {
			if (compare(wordlist[j + 1], wordlist[j])) {
				temp = wordlist[j];
				wordlist[j] = wordlist[j + 1];
				wordlist[j + 1] = temp;
			}
		}
	}
	printf("-------------统计数据列表-------------\n");
	for (i = 0;i < count;i++) {
		nowprint = wordlist[i];
		printf("%s\t%u\n", nowprint->wordstr, nowprint->wordcount);
	}
	printf("-------------总单词数:%d-------------", wordcount);

	//free环节
	for (i = 0;i < count;i++) {
		free(wordlist[i]);
	}
	free(wordlist);
	fclose(fp);
}