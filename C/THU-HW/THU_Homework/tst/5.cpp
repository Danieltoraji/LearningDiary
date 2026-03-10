#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double n;
    cin>>n;
    double a=floor(n);
    double b=n-a;
    cout<<"整数部分是"<<a<<",小数部分是"<<fixed<<setprecision(6)<<b<<"。"<<endl;
    return 0;
}