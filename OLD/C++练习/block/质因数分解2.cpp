#include <iostream>
#include<cstdio>
using namespace std;
const int MAX = 32768 + 1;
int prime[MAX];
int isPrime[10000];
int main(){
    int n;
    cin>>n;
    for(int i = 2; i * i <= n; i++){
        if(prime[i] == 0){
            for(int j = i *i ; j<=n; j+=i){
                prime[j] = 1;
            }
        }
    }

    int t = 0;
    for(int i = 2; i <= n; i++){
        if(prime[i] == 0){
            isPrime[t++] = i;
        }
    }
    int cnt = 0;
    int tmp = n;
    for(int i = 0; i < t; i++){

        while(tmp >= isPrime[i] && tmp % isPrime[i] == 0){
            tmp = tmp / isPrime[i];
            cnt ++ ;
            printf("%d ",isPrime[i]);

        }

    }
    cout<<endl<<cnt<<endl;
}
