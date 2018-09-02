#include <iostream>
using namespace std;
int a[500];
int main(){
    int n;
    cin>>n;
    int i;
    for(i = 1; i * i <=n; i ++){
        a[i] = i*i;
    }
    a[i] = i * i;
    i--;
    if(a[i] ==n){
        cout << n << endl;
    }
    else{
        int d1 = n - a[i];
        int d2 = a[i+1] -n;
        if(d1 <= d2){
            cout << a[i]<<endl;
        }
        else cout << a[i+1]<<endl;
    }
}
