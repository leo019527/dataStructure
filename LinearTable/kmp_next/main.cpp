#include<iostream>
#include <math.h>
#include <stdio.h>
const long long mod=1e9+7;
long long f(int n);

int dt[1000001] = {};

int main()
{
    dt[1]=1;
    dt[2]=2;
    dt[3]=4;
    int num;
    long long count;
    scanf("%d", &num);
    count=f(num)%1000000007;
    printf("%lld", count);
    return 0;
}


long long f(int n)
{
//    if(dt[n]!=0)
//    {
//        return dt[n];
//    }
//    else
//    {
//        dt[n] = (f(n-1)+ f(n-2)+f(n-3))%mod;
//        return dt[n];
//    }
    if(n<=0){
        return 0;
    }
    if(n<=2){
        return n;
    }
    if(n==3){
        return 4;
    }
    long long a=1,b=2,c=4,tmp;
    for(int i=4;i<n+1;i++){
        tmp = (a+b+c);
        a = b;
        b = c;
        c = tmp;
    }
    return c;
}