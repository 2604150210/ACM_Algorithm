#include <iostream>
#include <cstdio>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a, b;
        cin>>a>>b;
        for(int i = 0; i <= a / 2; i ++ ){
            for(int j = 0; j < a - i;j++){
                if(i == j || i + j == a -1){
                    cout <<'X';
                }
                else cout <<" ";
            }
            cout<<endl;
        }
        for(int i = a / 2 + 1; i < a; i ++ ){
            for(int j = 0; j <= i;j++){
                if(i == j || i + j == a -1){
                    cout <<'X';
                }
                else cout <<" ";
            }
            cout<<endl;
        }
        while(--b){
        for(int i = 1; i <= a / 2; i ++ ){
            for(int j = 0; j < a - i;j++){
                if(i == j || i + j == a -1){
                    cout <<'X';
                }
                else cout <<" ";
            }
            cout<<endl;
        }
        for(int i = a / 2 + 1; i < a; i ++ ){
            for(int j = 0; j <= i;j++){
                if(i == j || i + j == a -1){
                    cout <<'X';
                }
                else cout <<" ";
            }
            cout<<endl;
        }
        }
        cout << endl;
    }
}
