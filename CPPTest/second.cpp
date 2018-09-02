#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int m,n;
int temp[100][100];
void f(char ch){

    if(ch == 'A'){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[n-1-j][i];
            }
        }
        swap(m,n);
    }
    else if(ch == 'B'){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[n-i-1][i];
            }
        }
        swap(m,n);
    }
    else if(ch == 'C'){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[m-i-1][j];
            }
        }

    }
    else if(ch == 'D'){
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = a[i][n-j-1];
            }
        }
    }
}
void print(){
    cout << "*******************" << endl;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }
cout <<"********************"<<endl;

}
int main() {

    cin>>m>>n;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin>>a[i][j];
        }
    }
    string str;
    cin>>str;
    for(int i = 0; i < str.size(); i++){
        f(str[i]);
        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                a[i][j] = temp[i][j];
            }
        }
        print();
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cout << a[i][j]<< " ";
        }
        cout << endl;
    }

}
