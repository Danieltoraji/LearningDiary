#include <stdio.h>
#include<math.h>
#pragma warning(disable:4996)
main() {
	int n = 1, a, b, c, d, e, i, x , flag = 0;
	while (flag == 0){
		n = n + 5;
		for (x = n, i = 1,flag = 1;(i <= 5)&&(flag==1);i++) {//实验五次能不能整除成功
			if ((x - 1) % 5 == 0) {
				x = (x - 1) / 5 * 4;}
			else flag = 0;//不能整除，标志位置0（失败）
		}
	}
	printf("the least number is %d\n",n);
	a = (n - 1) / 5;
	b = (4 * a - 1) / 5;
	c = (4 * a - 1) / 5;
	d = (4 * a - 1) / 5;
	e = (4 * a - 1) / 5;
	printf("the number is %d,%d,%d,%d,%d\n", a, b, c, d, e);//计算分配
}