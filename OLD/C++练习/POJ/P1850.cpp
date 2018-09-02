#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int s1 = 0;
int c[27][27]={0};
char str[10];

void play_table(){
    for(int i = 0; i <=26; i++){
        for(int j = 0; j <= i; j++){
            if(!j|| i==j)c[i][j] = 1;
            else
                c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }
    c[0][0] = 0;
}


int main(){
    play_table();
    while(cin >>str){
        int len = strlen(str);
        for(int i = 1; i < len; i++){

            if(str[i] <= str[i-1]){
                printf("0\n");

            }
        }
        int sum = 0;

        for(int i = 1; i < len; i++){
            sum+=c[26][i];
        }

        for(int i = 0; i < len ; i++){

            for(int j = (i == 0)?'a':str[i-1] + 1; j <= str[i] -1; j++){
                sum += c['z' - j][len - 1 - i];
            }
        }

        sum +=  1;
        printf("%d\n",sum);
    }
return 0;
}
