#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
bool f[maxn+1];//f[i]表示i是否为素数
vector<int>primes;
void prime(){
    memset(f, true, sizeof(f));//假设所有的数都是质数
    f[0] = f[1] = false;//0 1 不是质数
    for(int i = 2; i <= maxn; i++){
        if(f[i]){
            primes.push_back(i);
        }
        for(int j = 0; j < primes.size() && primes[j]*i <= maxn; j++){
                f[primes[j]*i] = false;
        }
    }
}
int main(){
    prime();
    cout << primes.size()<<endl;//100000 50144
}
