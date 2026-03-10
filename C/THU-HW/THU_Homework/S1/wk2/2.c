#include <stdio.h>
int main(void){
    double double_a = 100;
    double double_b = -100;
    float float_a = 100;
    float float_b = -100;
    long long_a = 100;
    long long_b = -100;
    int int_a = 100;
    int int_b = -100;
    short short_a = 100;
    short short_b = -100;
    char char_a = 100;
    char char_b = -100;

    unsigned char *p;
    p = (unsigned char *)&double_a; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
    p = (unsigned char *)&double_b; 
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));

    p = (unsigned char *)&float_a;
    printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3));
    p = (unsigned char *)&float_b;
    printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3));

    p = (unsigned char *)&long_a; 
    printf("%02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3));
    p = (unsigned char *)&long_b; 
    printf("%02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3));

    p = (unsigned char *)&int_a; 
    printf("%02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3));
    p = (unsigned char *)&int_b; 
    printf("%02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3));

    p = (unsigned char *)&short_a; 
    printf("%02X %02X\n", *p, *(p+1));
    p = (unsigned char *)&short_b; 
    printf("%02X %02X\n", *p, *(p+1));

    p = (unsigned char *)&char_a; 
    printf("%02X\n", *p);
    p = (unsigned char *)&char_b; 
    printf("%02X\n", *p);
    return 0;
}