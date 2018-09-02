
#include <cmath>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

int main()
{

    std::vector<int> v;
    int n;
    cin >> n;
    priority_queue<int, vector<int>, greater<int> > q;
    int x;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        q.push(x);
    }
    int s = 0;
    while (q.size()!= 1)
    {
        int m;
        int a = q.top();
        q.pop();

        int b = q.top();
        q.pop();

        m = a + b;

        q.push(m);


        s += m;
    }
    cout << s<< endl;
    return 0;
}
