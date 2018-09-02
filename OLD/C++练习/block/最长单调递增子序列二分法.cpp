#include <cstring>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 100010;
int dp[N];
int a[N];
int binarysearch(int ai,int top){
    int left=1,right=top;
    int mid=(left+top)>>2;
    while(left <= right){
        if(ai == dp[mid])
            return mid;
        if(ai > dp[mid])
            left = mid+1;
        else
            right = mid - 1;
        mid = (right + left) >> 1;
    }
    return left;
}
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d",&a[i]);

        }
        dp[1]=a[1];
        int top = 1;
        for(int i = 2; i <= n; i++){
            int d = binarysearch(a[i], top);
            dp[d] = a[i];
            if(d>top){
                top = d;
            }

        }
        printf("%d\n",top);
    }
}
