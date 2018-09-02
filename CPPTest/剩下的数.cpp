/*
author : Ji Ailing
*/
#include<iostream>
#include <cstring>
using namespace std;
int a[10000+2];
int main(){
    int n,m;
    while(cin>>n>>m){
        if(n == 0 && m == 0)break;
        for(int i = 0; i <= n; i++)a[i] = 1;
        for(int i = 0; i < m; i++){
            int l,r;
            cin>>l>>r;
            for(int j = l; j <= r; j++)a[j] = 0;
        }
        int sum=0;
        for(int i = 0; i <= n; i++){
            sum+=a[i];
        }
        cout<<sum<<endl;
    }
}
