#include <stdio.h>
int main(void){
    double double_a = 97.6875;
    double double_b = -97.6875;
    float float_a = 97.6875;
    float float_b = -97.6875;

    unsigned char *p;
    p = (unsigned char *)&double_a; /* p指向双精度数8个字节的第1个字节 */
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
    p = (unsigned char *)&double_b; /* p指向双精度数8个字节的第1个字节 */
    printf("%02X %02X %02X %02X %02X %02X %02X %02X\n",*p, *(p+1), *(p+2), *(p+3), *(p+4), *(p+5), *(p+6), *(p+7));
    p = (unsigned char *)&float_a; /* p指向单精度数4个字节的第1个字节 */
    printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3));
    p = (unsigned char *)&float_a; /* p指向单精度数4个字节的第1个字节 */
    printf("%02X %02X %02X %02X\n", *p, *(p+1), *(p+2), *(p+3));
    return 0;
}