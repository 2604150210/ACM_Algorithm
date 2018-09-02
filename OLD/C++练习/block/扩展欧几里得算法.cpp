#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
int x,y;
int exgcd(int a,int b,int &x,int &y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}
int main(){
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF){
        exgcd(a,b,x,y);
        printf("%d %d\n",x,y);
    }
}
