#include<cstdio>
#include <iostream>
#include<map>
using namespace std;
int prime[2000010];
int main(){


    int n ;
    long long sum = 0;
    scanf("%d", &n);

    for(int i = 2; i * i<= n; i++){
        if(prime[i] == 0){
            for(int j = i * i; j<= n; j+= i){
                prime[j] = 1;
            }
        }
    }
    for(int i = 2; i <= n; i++){
        if(prime[i]== 0){
            sum+=i;
           // printf("%d, ",i);
        }
    }
    printf("%lld\n",sum);
}
