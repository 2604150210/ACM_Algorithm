#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int sum = 0;
int a,b;
int len1,len2;
const int MAXN = 36;
int C[MAXN][MAXN] = {0};
int binaryA[MAXN], binaryB[MAXN];

int calculate(int *arr,int len);
void play_table();
int main(){
    play_table();
    scanf("%d %d",&a,&b);
        int a1 = a;
        int i = 0;
        while(a1){
            binaryA[i++] = a1 % 2;
            a1 /= 2;
        }
        len1 = i;
        int b1 = b+1;
        i = 0;
        while(b1){
            binaryB[i++] = b1 % 2;
            b1 /= 2;
        }
        len2 = i;
        int sumA = calculate(binaryA, len1);
        //printf("sumA : %d \n",sumA);
        int sumB = calculate(binaryB, len2);
       // printf("sumB : %d \n",sumB);
        sum = sumB - sumA ;
        printf("%d\n",sum);

}


int calculate(int *arr,int len){

    int ret = 0;
    for(int i = 1; i < len-1; i ++){

        for(int j = i/2+1; j <= i  ; j++){
            ret += C[i][j];
        }
    }
    int zero = 0;
    for(int i = len - 2; i >= 0; i--){
        if(arr[i] == 1){
            for(int j = (len+1)/2 -(zero + 1); j <= i; j++){
                ret += C[i][j];
            }
        }
        else zero ++ ;
    }

    return ret;
}
void play_table(){
//    C[0][0] = 1;
//    for(int i = 1; i < MAXN; i++){
//        C[i][1] = 1;
//        C[i][i] = 1;
//        for(int j = 2; j < i; j++){
//            C[i][j] = C[i-1][j-1] + C[i-1][j];
//        }
//    }

    for(int i=0;i<=32;i++)
    for(int j=0;j<=i;j++)
        if(!j || i==j)
            C[i][j]=1;
        else
            C[i][j]=C[i-1][j-1]+C[i-1][j];
}
