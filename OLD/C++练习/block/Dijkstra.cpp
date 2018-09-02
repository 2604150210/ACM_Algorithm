#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
 #include<cstdlib>
using namespace std;
const int N=100;
const int M=100;
const int MAX=9999;
struct MGraph{
    int matrix[N][N];
    int n;
    int e;
};
void DijkstraPath(MGraph g,int *dist,int *path,int v0){

    bool*visited=(bool *)malloc(sizeof(bool)*g.n);
    for(int i=1;i<=g.n;i++){
        if(g.matrix[v0][i]>0&&i!=v0){
            dist[i]=g.matrix[v0][i];
            path[i]=v0;//path记录最短路径上从v0到i的前一个顶点
        }
        else{
            dist[i]=MAX;//若i不与v0直接相邻，则权值置为无穷大
            path[i]=-1;
        }
        visited[i]=false;
        path[v0]=v0;
        dist[v0]=0;
    }
    for(int i=1;i<g.n;i++){//循环扩展n-1个点
        int min=MAX;
        int u;
        for(int j=1;j<=g.n;j++){
            if(visited[j]==false&&dist[j]<min){
                min=dist[j];
                u=j;
            }
        }
        visited[u]=true;
        for(int k=1;k<=g.n;k++){
            if(visited[k]==false&&dist[k]>dist[u]+g.matrix[u][k]){
                dist[k]=dist[u]+g.matrix[u][k];
                path[k]=u;
            }
        }
    }
}
int main(){
        int n,m;
        while(~scanf("%d%d",&n,&m)){
            if(n==0&&m==0)break;
            MGraph g;
            g.n=n;
            g.e=m;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++)
                    g.matrix[i][j]=MAX;
            }
            int x,y,e;
            for(int i=1;i<=m;i++){
                scanf("%d %d %d",&x,&y,&e);
                g.matrix[x][y]=e;
                g.matrix[y][x]=e;
            }
            int dist[n];
            int path[n];
            DijkstraPath(g,dist,path,1);
            printf("%d\n",dist[n]);
        }
}
