#include <iostream>
#include <cstring>
using namespace std;
long long f[41][3] = {{0}};

int main(){
   // f[1] = {0,1,1};
    f[1][0] = 0;f[1][1] = 1;f[1][2] =1;
    //f[2] = {3,0,4};
    f[2][0] = 3;f[2][1] = 0; f[2][2] = 4;
    for(int i = 3; i <= 40; i++){
        f[i][0] = f[i-1][1] + f[i-2][2] + f[i-2][0];
        f[i][1] = f[i-1][0] + f[i-2][1];
        f[i][2] = f[i][0] + f[i-2][2];
    //f[i][1] = f[i-1][2] ;
       // f[i][2] = f[i][0] + f[i-1][1];
    }
    int n;
    while(cin>>n){
        if(n == -1)break;
        if(n == 0)cout<<1<<endl;
        else if(n % 2)cout<<0<<endl;
        else
        cout<<f[n][0]<<endl;
    }
    return 0;
}