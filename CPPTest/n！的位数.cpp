#include <iostream>
#include <cmath>
#include <cstdio>
#define E 2.718281828459
#define PI acos(-1)
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        double sum = 0.0;
        if(n == 0){
            printf("1\n");
            continue;
        }
        sum = log(sqrt(2*PI*n))/log(8) + n*log(n/E)/log(8);
        
        int s  = (int)sum+1;
        printf("%d\n",s );
    }

}