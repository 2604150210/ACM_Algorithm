#include <iostream>
using namespace std;

long long dp[21];//全排错
long long A(int n, int m){
    long long ret = 1;
    for(int i = n ; i>=n-m+1; i--){
        ret*= i;
    }
    return ret;
}

long long C(int n, int m){
    return A(n,m)/A(m,m);
}
int main(){

    dp[1] = 0;
    dp[2] = 1;
    for(int i = 3; i <= 20; i++){
        dp[i] = (dp[i-1] + dp[i-2] ) *(i-1);
    }
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        cout<<dp[m]*C(n,m)<<endl;
    }
}