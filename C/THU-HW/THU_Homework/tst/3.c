#include <stdio.h>
int main(void){

    long long_a = 100;
    long long_b = -100;
    int int_a = 100;
    int int_b = -100;


    unsigned char *p;

    p = (unsigned char *)&long_a; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
    p = (unsigned char *)&long_b; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));

    p = (unsigned char *)&int_a; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
    p = (unsigned char *)&int_b; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));

    return 0;
}