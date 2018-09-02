//ji ai ling
#include <iostream>
#include <cstdio>
using namespace std;
int n;
int a[21][21];
int booky[21];
int s = 0;
int minx = 999999;
void dfs(int line){
    if(line == n){
        if(minx > s) minx = s;

        return;
    }
    for(int i = 0; i < n; i++){
        if(booky[i] == 0){
            booky[i] = 1;
            s += a[line][i];
            dfs(line + 1);
            s -= a[line][i];
            booky[i] = 0;
        }
    }
    return;
}
int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j ++){
            scanf("%d",&a[i][j]);
        }
    }
    dfs(0);
    printf("%d\n",minx);
}
