#include<iostream>
using namespace std;
int main(){
    int n,m;
    while(cin>>n>>m){
    int a[n];
    for(int i = 0; i < n; i++){
        cin>>a[i];
    }
    for(int i = 0; i < n; i++){
        int s = -1;
        for(int j = 0; j < n; j++){
            if(a[j] == a[i]){
                s++;
            }
        }
        if(s > 0){
            cout<<s<<endl;
        }
        else{
            cout<<"BeiJu"<<endl;
        }
    }
    }
}
