#include<math.h>
#include<iostream>
using namespace std;
int n,m,s;

int main(){
    while(cin>>m>>n){
        if(m==0&&n==0)break;
        int left = m,right = m;
        int f = 1;
        while(right < n){
            left = left * 2;
            right = right * 2 + 1;
            f++;
        }
        int s = 0;
        if(right / 2 <= n && left > n){
            s = pow(2,f-1) - 1 ;
        }
        else if(n <= right && n >= left){
            s = pow(2,f) - 1 - (right - n);
        }

        cout<<s<<endl;
    }
}
