#include <stdio.h>
int main(void)
{double x=97.6875; float y=97.6875f;
unsigned char *p;
p = (unsigned char *)&x; /* p指向双精度数8个字节的第1个字节 */
printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
p = (unsigned char *)&y; /* p指向单精度数4个字节的第1个字节 */
printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3));
} /* 说明：%02X 是以两位十六进制方式输出指针所指的字节中的值 */