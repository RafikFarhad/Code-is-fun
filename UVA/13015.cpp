#include<bits/stdc++.h>
using namespace std;
#define sf scanf
#define printf pf
#define xx first
#define  yy second
vector <int> v[5005], v2[5005];
int n, m, flag[5005],flag2[5005], times, level[5005],level2[5005];
pair <int, int> du[5005];

int BFS(int x)
{
    flag[x] = 1;
    queue <int> qu;
    qu.push(x);
    level[x] = times;
    int found = 1;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            if(level[v[u][i]]==times);
            else
            {
                level[v[u][i]] = times;
                qu.push(v[u][i]);
                found++;
            }
        }
    }
    return found;
}


int BFS_REVERSE(int x)
{
    flag[x] = 1;
    queue <int> qu;
    qu.push(x);
    level2[x] = times;
    int found = 1;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0; i<v2[u].size(); i++)
        {
            if(level2[v2[u][i]]==times);
            else
            {
                level2[v2[u][i]] = times;
                qu.push(v2[u][i]);
                found++;
            }
        }
    }
    return found;
}

int main()
{
    freopen("000.txt", "r", stdin);
    int i, j, k, a, b, c, x, y, z, mark[5005], aa, bb;
    while(cin >> aa >> bb >> n >> m)
    {

        for(i=0; i<n; i++)
        {
            flag[i] = 0;
            level[i] = 1<<30;
            level2[i] = 1<<30;
            mark[i] = 0;
            v[i].clear();
            v2[i].clear();
        }
        while(m--)
        {
            cin >> a >> b;
            v[a].push_back(b);
            v2[b].push_back(a);
        }
        times = 0;
        int x = 0, y = 0, z = 0;

        for(i=0; i<n; i++)
        {
           // cout << "OK" << endl;
            a = BFS(i);
            if(n-a+1<=aa) x++;
            if(n-a+1<=bb) y++;
            b = BFS_REVERSE(i);
            if(b>bb) z++;
            times++;
        }
        cout << x << endl << y << endl << z << endl;
    }
}



