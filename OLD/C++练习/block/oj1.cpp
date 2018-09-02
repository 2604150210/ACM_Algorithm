#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
const int N=1000000;
int c[N][2];
int fun1(int x){
    int a[6]={0};
    int i=0;
    while(x){
        a[i++]=x%10;
        x/=10;
    }
    int f5=0,f2=0,f1=0;
    for(int k=0;k<6;k++){
        if(a[k]==1)
            f1=1;
        else if(a[k]==2)
            f2=1;
        else if(a[k]==5)
            f5=1;
    }
    if(f1==1&&f2==1&&f5==1){
        return 1;
    }
    else return 0;
}

int fun2(int x){
    if(x%1000000/1000==521||x%100000/100==521||x%10000/10==521||x%1000==521)
        return 1;
    else return 0;
}
//http://acm.nyist.net/JudgeOnline/problem.php?pid=975
int main(){
    for(int i =1;i<N;i++){
        if(fun1(i))c[i][0]=1;
        if(fun2(i))c[i][1]=1;
    }

    int a,b;
    int k=1;
    while(scanf("%d%d",&a,&b)!=EOF){
            if(a>b)swap(a,b);
        int s1=0,s2=0;
        for(int i=a;i<=b;i++){
            if(c[i][0])s1++;
            if(c[i][1])s2++;
        }
        printf("Case %d:%d %d\n",k++,s1,s2);
    }
}
