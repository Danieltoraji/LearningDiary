#include<string.h>
#include<stdlib.h>
#include<stdio.h>
int main(void) {
	char strset[][20] = {"zhang","gou","xu","zheng","mao","zhao","li","bai","qing"};
	int rows = (sizeof(strset) / 20);
	void warp(char**, char**);
	int i = 0;
	int warptrial, warpprocess;
	/*接下来创建指针数组并进行指派*/
	char *pointerset = (char **)malloc(sizeof(char*) * rows);
	if (pointerset == NULL) {
		printf("Failed to allocate!ERROR");
		return 1;
	}
	for (;i < rows;i++) {
		pointerset[i] = strset[i];
	}
	/*接下来构建遍历循环*/
	for (warptrial = 0;warptrial < rows-1;warptrial++) {//n-1次的遍历
		for (warpprocess = 0;warpprocess < rows - 1;warpprocess++) {//n-1次的比较
			if (strcmp(pointerset[warpprocess], pointerset[warpprocess + 1]) > 0) {
				warp(&pointerset[warpprocess], &pointerset[warpprocess + 1]);
			}
		}
	}
	
	for (i = 0;i < rows;i++) {
		puts(pointerset[i]);
	}
}
void warp(char** p, char** q) {
	char* z = *p;
	*p = *q;*q = z;
}