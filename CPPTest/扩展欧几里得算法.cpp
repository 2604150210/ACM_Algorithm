#include<iostream>
using namespace std;
typedef  long long ll;
ll ex_gcd(ll a, ll b, ll& x, ll& y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    /*ll r = ex_gcd(b, a%b, x,y);
    ll t = x;
    x = y;
    y = t - a / b * y;
    */

    ll r = ex_gcd(b, a%b, y,x);
    y -=a / b * x;



    return r;
}
int main(){
    ll a,b,c,x,y;
    while(cin>>a>>b){
            c = 1;
        if(a < 0){
            a = -a;
            c = -1;
        }
        ll r = ex_gcd(a,b,x,y);
        if( c%r ){
            cout<<"sorry"<<endl;
        }else{
            //cout<<"x:"<<x<<"y:"<<y<<"r:"<<r<<endl;
            x *= c/r;
            ll t = b/r;
            if(x >= 0){
                x %= t;
            }else{
                x = x%t + t;
            }
            y = (1-a*x)/b;
            cout<<x<<" "<<y<<endl;

        }
    }

}
