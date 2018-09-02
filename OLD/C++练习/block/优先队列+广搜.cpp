#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int visit[110][110];
char a[110][110];
int n, m;
struct node
{
    int x, y, cost;
    friend bool operator< (node a, node b)
    {
        return a.cost > b.cost;
    }
} bg;

int BFS()
{
    const  int next[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    memset(visit, 0, sizeof(visit));
    priority_queue<node> que;
    que.push(bg);
    visit[bg.x][bg.y] = 1;
    while (!que.empty())
    {
        node u = que.top(), v;
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u.x + next[i][0];
            int y = u.y + next[i][1];
            if (x < n && x >= 0 && y < m && y >= 0 && a[x][y] != '#' &&
                    !visit[x][y])
            {
                v = u;
                v.x = x;
                v.y = y;
                if(a[x][y] == 'l')return v.cost;
                v.cost = v.cost + a[v.x][v.y] - 'A' + 1;
                que.push(v);
                visit[v.x][v.y] = 1;
            }
        }

    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (a[i][j] == 's')
                {
                    bg.x = i;
                    bg.y = j;
                    bg.cost = 0;
                }
            }
        }

        cout << BFS() << endl;
    }
}
