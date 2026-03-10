#include <stdio.h>
#include<math.h>
#pragma warning(disable:4996)
main() {
	int a, b, c, d, e, f;
	for (a = 0; a <= 1; a++) {
		for (b = 0; b <= 1; b++) {
			for (c = 0; c <= 1; c++) {
				for (d = 0; d <= 1; d++) {
					for (e = 0; e <= 1; e++) {
						for (f = 0; f <= 1; f++) {
							if (
								(!((c == 0) && (b == 1))) &&//条件1
								((c + d) == 1) &&//条件2
								(d == e) &&//条件3
								((a + b + f) == 2) &&
								(!((c==1)&&(f==1))) &&
								(!((e == 0) && (f == 0)))
								)
							printf("a%d b%d c%d d%d e%d f%d", a, b, c, d, e, f);
						}
					}
				}
			}
		}
	}
}