#include <iostream>
#include <cstdio>
using namespace std;
int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}
int main(){
    int T,num = 0;
    cin>>T;
    while(T--){
        int n,a,b;
        cin>>n>>a>>b;
        if(a<b)swap(a,b);
        printf("Case #%d: ",++num);
        int r = gcd(a,b);
        if(n/r %2 ){
            cout<<"Yuwgna"<<endl;
        }else{
        cout<<"Iaka"<<endl;
        }
    }

}
