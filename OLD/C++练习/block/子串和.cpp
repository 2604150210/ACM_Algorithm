#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=1000010;
int a[MAXN],s[MAXN];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        s[0]=0;
        for(int i = 1;i <= n; i++){
            scanf("%d",&a[i]);
        }
        int min_s = 0;
        int max_s=a[1];
        for(int j = 1; j <= n; j++){
            s[j] = s[j-1] + a[j];
            max_s = max(max_s, s[j] - min_s);
            min_s = min(min_s, s[j]);
        }
        printf("%d\n",max_s);
    }
}
