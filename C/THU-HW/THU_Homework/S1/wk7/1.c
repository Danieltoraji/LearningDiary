#include<stdio.h>
#include<math.h>
int main(){
    int n, test_max, test_process, dual_factor, flag;
    flag = 0;
    scanf("%d",&n);
    test_max = (int)sqrt(n);
    for(test_process = 2; (test_process<= test_max)&&(flag ==0); test_process++){
        if(n%test_process==0){
            dual_factor = n/test_process;
            if (test_process != dual_factor) printf("%d%d",test_process,dual_factor);
            else printf("%d",test_process);
            flag = 1;
        }
    }
    if (flag == 1) printf("%d",n);
    return 0;
}