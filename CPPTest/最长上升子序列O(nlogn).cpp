#include<bits/stdc++.h>
using namespace std;
int main(){

        int n;
        while(cin>>n){
        int a[n],h[n];
        int len = 0;
        int x;
        while(n--){
                scanf("%d",&x);
            a[len++] = x;
        };
        reverse(a,a+len);
        int top = 0;
        h[top] = a[0];
        for(int i = 1; i < len; i++){
            if(a[i] >= h[top]){
                h[++top] = a[i];
            }else{
                int j=lower_bound(h,h+top,a[i])-h;
                h[j]=a[i];
            }
        }
        printf("%d\n",top+1);

        }
}
