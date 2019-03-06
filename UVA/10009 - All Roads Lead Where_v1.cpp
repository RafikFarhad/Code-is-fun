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
#define CLR(a, b) for(int o=0; o<b; o++) a[o] = 0
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
#define INF 26
vector <int> v[INF+5];
bool flag[INF+5];
int path[INF+5];
map <char, int> mp;
map <int, char> mp2;

void BFS(int start, int endd)
{
    CLR(flag, INF);
    CLR(path, INF);
    int u, w;
    queue <int> qu;
    qu.push(start);
    flag[start]=1;
    path[start] = start;
    while(qu.size())
    {
        u = qu.front(); qu.pop();
        for(w=0; w<v[u].size(); w++)
        {
            //MyDebug(u, v[u][w]);
            if(!flag[v[u][w]])
            {
                flag[v[u][w]] = 1;
                path[v[u][w]] = u;
                if(v[u][w]==endd) return;
                qu.push(v[u][w]);
            }
        }
    }
    return;
}
void PRINT_PATH(int s, int e)
{
    if(s==e)
    {
        //cout << mp2[s];
        return;
    }
    PRINT_PATH(s, path[e]);
    cout << mp2[path[e]];
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10009.inp","r",stdin);
#endif
    ///                                    MAIN
    int node, i, j, t, p, edge, q;
    sf("%d", &t);
    while(t--)
    {
        getchar();
        char a[100000], b[100000];
        sf("%d %d ", &edge, &q);
        mp.clear();
        mp2.clear();
        for(i=0; i<INF; i++) v[i].clear();
        node=0;
        for(i=0; i<edge; i++)
        {
            sf("%s %s", a, b);
            if(mp.count(a[0])==0)
            {
                mp[a[0]] = node;
                mp2[node++] = a[0];
                //cout << mp2[node-1] << endl;
            }
            if(mp.count(b[0])==0)
            {
                mp[b[0]] = node;
                mp2[node++] = b[0];
               // cout << mp2[node-1] << endl;
            }
            if(a[0]==b[0]) continue;
            v[mp[a[0]]].pb(mp[b[0]]);
            v[mp[b[0]]].pb(mp[a[0]]);
        }

        //cout << node << endl;
       for(i=0; i<q; i++)
       {
           sf("%s %s", a, b);
           BFS(mp[a[0]], mp[b[0]]);
           PRINT_PATH(mp[a[0]], mp[b[0]]);
           cout << b[0] << endl;
       }
       if(t) pf("\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
