//AC
//http://blog.csdn.net/jkay_wong/article/details/7259374
//素数筛选——爱拉托逊斯筛选法
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<cstdlib>
using namespace std;
const int MAXN = 2000010;
int f[MAXN];

int main()
{
    int m = ceil(sqrt(MAXN));
    for(int i = 2; i <= m; i++){
        if(f[i]==0){//用0标记素数
            for(int j=i*i;j<=MAXN;j+=i){
                f[j]=1;//用1表示不是素数
            }
        }
    }
   int n;
    while(~scanf("%d",&n)){
            if(n==0)break;
        for(int i=2;i<=n;i++){
            if(f[i]==0){
                printf("%d ",i);
            }

        }
        cout<<endl;
    }
}


