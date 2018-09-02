#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 20000+5;
        int a[MAXN],b[MAXN];
int main(){
    int n,m;
    while(scanf("%d%d",&n,&m)==2&&n&&m){
        for(int i = 0; i < n; i++) scanf("%d",&a[i]);

        for(int j = 0; j < m; j++) scanf("%d",&b[j]);
        sort(a,a+n);
        sort(b,b+m);
        int s=0;
        int cur=0;
        for(int i = 0; i < m; i++){
            if(b[i] >= a[cur]){
                s+=b[i];
            }
            if(++cur==n){
                break;
            }
        }
        if(cur>=n){
            printf("%d\n",s);
        }
        else{
            printf("Loowater is doomed!\n");
        }
    }
}

/*
2 3
5
4
7
8
4
2 1
5
5
10
0 0
*/
