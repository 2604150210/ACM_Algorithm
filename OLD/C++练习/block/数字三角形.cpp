#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=110;
int a[MAXN][MAXN],s[MAXN][MAXN];
int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i;j++){
            scanf("%d",&a[i][j]);
        }
    }
    s[1][1]=a[1][1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                s[i][j] = a[i][j] + s[i-1][j];
            }
            else if(j == i){
                s[i][j] = a[i][j] + s[i-1][j-1];
            }
            else {
                s[i][j] = a[i][j] + max(s[i-1][j],s[i-1][j-1]);
            }
        }
    }
    sort(s[n]+1,s[n]+n+1);
    printf("%d\n",s[n][n]);
}
