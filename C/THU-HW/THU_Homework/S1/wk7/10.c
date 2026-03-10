#include <stdio.h>
#include<math.h>
#pragma warning(disable:4996)
main() {
	//根据我对题目的理解，需要分别列出最大和最小的十个素数。如果有不足十个素数，则只列出所有的素数。
	//如果最大和最小的素数有重复的，则只在最小的中列出一次。
	//重复的数字在最后求和时只计算一次。
//在本实例中，num可以指定为任何一个大于等于2的偶数。
	int num, test, test_process, test_final, flag, prime_sum,
		min_count, max_count, smallmax;
	num = 1000;
	test_final = 0;
	prime_sum = 2;
	min_count = 1;
	max_count = 0;
	smallmax = 0;
	//计算最小的十个质数
	printf("最小素数：2");//理由，一.保证逗号的数量正确，二.排除唯一的偶奇数，后续步长可为2
	for (test = 3;(test <= num) && (min_count < 10);test += 2) {//确定最小的十个质数。test是测试对象。
		test_final = (int)sqrt(test);
		flag = 1;//初始地假定test是质数
		for (test_process = 2;(test_process <= test_final) && (flag == 1);test_process++)
			if (test % test_process == 0) flag = 0;
		if (flag == 1) {
			printf(",%d", test);
			min_count++;
			prime_sum += test;
			smallmax = test;//记录下最小的十个质数中的最大值
		}
	}
	printf("\n最大素数：");
	for (test = (num - 1);(test >= 2) && (max_count < 10) && (test > smallmax);test = test - 2) {
		test_final = (int)sqrt(test);
		flag = 1;//初始地假定test是质数
		for (test_process = 2;(test_process <= test_final) && (flag == 1);test_process++)
			if (test % test_process == 0) flag = 0;
		if (flag == 1) {
			if (max_count != 9) {
				printf("%d,", test);
			}
			else {
				printf("%d", test);
			}
			max_count++;
			prime_sum += test;
		}
	}
	printf("\n素数和：%d\n", prime_sum);
}