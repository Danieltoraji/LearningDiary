#include<stdio.h>
#include<math.h>
int main(void){
    double a,b,c;
    printf("Enter a, b, and c!\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    double p = (a+b+c);
    p = p/2;
    double s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%lf",s);
    return 0;
}