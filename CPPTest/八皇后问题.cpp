#include <bits/stdc++.h>
using namespace std;
int n;
int cnt = 0;
int out[1000][10],vis[10];///out[][i] = c��ʾ��i�з�����c��,vis[i] = c��ʾ��i�з����ڵ�c��
bool check(int r, int c){//��r�е�c���Ƿ���ԷŻʺ�
    for(int i = 0; i < r; i++){
        if(vis[i] == c)return false;
        if(vis[i] - c == i - r || vis[i] - c == r - i)return false;
    }
    return true;
}
void dfs(int r){
    if( r >= n){
        for(int i = 0; i < n; i++)
        out[cnt][i] = vis[i];
        cnt++;
    }
    for(int i = 0; i < n; i++){
        if(check(r, i)){
            vis[r] = i;
            dfs(r+1);
            //vis[r] = -1;
        }
    }
}
int main(){
    cin>>n;
    cnt = 0;
    dfs(0);
    cout<<cnt<<endl;
    for(int i = 0; i < cnt; i++){
        for(int j = 0; j < n; j++){
            printf("%d",out[i][j]);
        }
        printf("\n");
    }
}
