#include <stdio.h>
#define P(x) printf("%d\n", x)
main(){
    int year,month;
    printf("Enter year and month.");
    scanf("%d%d",&year,&month);
    switch(month){
    case 1:P(31);break;
    case 3:P(31);break;
    case 5:P(31);break;
    case 7:P(31);break;
    case 8:P(31);break;
    case 10:P(31);break;
    case 12:P(31);break;
    case 4:P(30);break;
    case 9:P(30);break;
    case 11:P(30);break;
    case 6:P(30);break;
    case 2:
        if ((year%100!=0&&year%4==0)||(year%400==0))
        P(29);
        else P(28);

}
}