/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0;
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}
map <string, int> mp;
map <int, string> mp2;
vector <int> v[1000];
int level[1000];
int node, path[1000];

int BFS(int s, int e)
{
    bool flag[1000];
    CLR(flag, 1000);
    if(s==e) return 0;
    queue<int> qu;
    qu.push(s);
    flag[s] = 1;
    level[s] = 0;
    path[s] = s;
    while(qu.size())
    {
        int u = qu.front();
        qu.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            if(flag[v[u][i]]==0)
            {
                flag[v[u][i]] = 1;
                path[v[u][i]] = u;
                qu.push(v[u][i]);
            }
        }
    }
}

void PRINT_PATH(int s, int e)
{
    if(s==e) return;
    PRINT_PATH(s, path[e]);
    cout << mp2[path[e]] << " " << mp2[e] << endl;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("762.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, t, n, k, p, q;
    string a, b;
    bool li = false;
    while(sf("%d ", &t)!=EOF)
    {
        if(li) pf("\n"); li = true;
        node = 0;
        mp.clear();
        mp2.clear();
        for(i=0; i<1000; i++)
        {
            path[i] = -1;
            v[i].clear();
        }

        for(i=0; i<t; i++)
        {
            cin >> a >> b;
            if(mp.count(a)!=1)
            {
                //cout << a << i << endl; ok
                mp[a] = node;
                mp2[node++] = a;
            }
            if(mp.count(b)==0)
            {
                // cout << i << endl;
                mp[b] = node;
                mp2[node++] = b;
            }
            v[mp[a]].pb(mp[b]);
            v[mp[b]].pb(mp[a]);
        }
        cin >> a >> b;
        if(a==b)
        {
            cout << a << " " << b << endl;
            continue;
        }
        if(mp.count(a)==1 && mp.count(b)==1)
        {
            BFS(mp[a], mp[b]);
            i = path[mp[b]];
        }
        else i = -1;
        if(i==-1) pf("No route\n");
        else PRINT_PATH(mp[a], mp[b]);
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
