#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int v1, v2, v3;
int vis[105][105][105];
struct status
{
    int first, second, third, step;
} bg, ed;
void BFS(status s)
{
    queue<status> que;
    memset(vis, 0, sizeof(vis));
    que.push(s);
    vis[s.first][0][0] = 1;
    while (!que.empty())
    {
        status s1, s2;
        s1 = que.front();
        que.pop();
        if (s1.first == ed.first && s1.second == ed.second &&
                s1.third == ed.third)
        {
            cout << s1.step << endl;
            return;
        }
        if (s1.first != 0 && s1.second != v2)    // 1->2
        {
            if (s1.first + s1.second > v2)    //倒满
            {
                s2.first = s1.first - (v2 - s1.second);
                s2.second = v2;
            }
            else      //到不满
            {
                s2.first = 0;
                s2.second = s1.first + s1.second;
            }
            s2.third = s1.third;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
        if (s1.first != 0 && s1.third != v3)    // 1 3
        {
            if (s1.first + s1.third > v3)    //倒满
            {
                s2.first = s1.first - (v3 - s1.third);
                s2.third = v3;
            }
            else      //到不满
            {
                s2.first = 0;
                s2.third = s1.first + s1.third;
            }
            s2.second = s1.second;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
        if (s1.second != 0 && s1.first != v1)    // 2 1
        {
            if (s1.first + s1.second > v1)    //倒满
            {
                s2.second = s1.second - (v1 - s1.first);
                s2.first = v1;
            }
            else      //到不满
            {
                s2.second = 0;
                s2.first = s1.first + s1.second;
            }
            s2.third = s1.third;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
        if (s1.second != 0 && s1.third != v3)    // 2 3
        {
            if (s1.third + s1.second > v3)    //倒满
            {
                s2.second = s1.second - (v3 - s1.third);
                s2.third = v3;
            }
            else      //到不满
            {
                s2.second = 0;
                s2.third = s1.third + s1.second;
            }
            s2.first = s1.first;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
        if (s1.third != 0 && s1.first != v1)    // 3 1
        {
            if (s1.first + s1.third > v1)    //倒满
            {
                s2.first = v1;
                s2.third = s1.third - (v1 - s1.first);
            }
            else      //到不满
            {
                s2.third = 0;
                s2.first = s1.first + s1.third;
            }
            s2.second = s1.second;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
        if (s1.third != 0 && s1.second != v2)    // 3 2
        {
            if (s1.third + s1.second > v2)    //倒满
            {
                s2.third = s1.third - (v2 - s1.second);
                s2.second = v2;
            }
            else      //到不满
            {
                s2.third = 0;
                s2.second = s1.third + s1.second;
            }
            s2.first = s1.first;
            if (vis[s2.first][s2.second][s2.third] == 0)
            {
                s2.step = s1.step + 1;
                vis[s2.first][s2.second][s2.third] = 1;
                que.push(s2);
            }
        }
    }
    cout << "-1" << endl;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> v1 >> v2 >> v3 >> ed.first >> ed.second >> ed.third;
        if (v1 != ed.first + ed.second + ed.third) cout << "-1" << endl;
        bg.first = v1;
        bg.second = 0;
        bg.third = 0;
        bg.step = 0;
        BFS(bg);
    }
}
