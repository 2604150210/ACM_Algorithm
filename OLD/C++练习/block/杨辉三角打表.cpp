#include<algorithm>
#include<map>
#include <cstdio>
#include<iostream>
#include<string>
using namespace std;
int yh[21][21];
int main(){
    yh[1][1] = 1;
    for(int i = 2; i < 21;i++){
        for(int j = 1; j <=i;j++){
            yh[i][j] = yh[i-1][j-1] + yh[i-1][j];
        }
    }
    int n;
    while(cin>>n){
        for(int i = 1; i <=n;i++){
            int flag = 1;
            for(int j = 1; j<=i;j++){
                if(flag ==1){
                    printf("%d",yh[i][j]);
                    flag = 0;
                }
                else {
                    printf(" %d",yh[i][j]);
                }
            }
            printf("\n");
        }
        printf("\n");
    }
}

