#include<cstdio>
#include <iostream>
#include<map>
using namespace std;
const int MAX = 9989899 + 1;
int prime[MAX];
int hw[1000];
bool hw1(int n){
    int n1 = n;
    int ret = 0;
    while(n1){
        ret = ret * 10 + n1 % 10;
        n1 /= 10;
    }
    return n == ret;
}

int main(){

    for(int i = 2; i *i<= MAX; i++){
        if(prime[i] == 0)
            for(int j = i * i; j <= MAX; j+=i){
                prime[j] = 1;
            }
    }

    int t = 0;
    for(int i = 2; i <=MAX; i++){
        if( prime[i] == 0  && hw1(i)){
            hw[t++] = i;
        }
    }
    int a,b;
    while(scanf("%d %d",&a, &b) != EOF){
        for(int i = 0; i < t; i++){
            if(hw[i] >= a && hw[i] <= b){
                printf("%d\n",hw[i]);
            }
        }
        printf("\n");
    }
}
