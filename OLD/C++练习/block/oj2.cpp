#include<iostream>
#include<cstdio>
using namespace std;
const int MAXN = 1000000;
int f[MAXN];
const int MOD = 998244353;
int main(){
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for(int i = 4; i < MAXN; i ++){
        f[i] = (f[i-1] % MOD + f[i -2] % MOD)%MOD + f[i-3] % MOD;
    }
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        cout<<f[n] % MOD <<endl;
    }
}
