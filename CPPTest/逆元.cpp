//
// Created by jal on 2018/1/31 0031.
//
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ex_gcd(ll a,ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    else{
        ll r = ex_gcd(b, a%b, x,y);
        ll t = y;
        y = x - a/b*y;
        x = t;
        return r;
    }
}
//a模的n逆元
ll ine(ll a,ll n){
    ll x = 0, y = 0;
    ex_gcd(a, n, x, y);
    return (x % n + n ) % n;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        ll n, B;
        cin>>n>>B;
        ll b = ine(B,9973);

        cout<<n*b%9973<<endl;
    }
}
/*

sample input:
2
1000 53
87 123456789

sample output:
7922
6060


*/