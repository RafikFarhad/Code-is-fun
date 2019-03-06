/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
vector <int> v[30009];
bool flag[30009];
int level[30009];
map <pair <int, int>, int> mp;

void DFS(int start)
{
    //if(flag[start]) return;

    flag[start] = 1;
    int i, j, k;
    for(i=0; i<v[start].size(); i++)
    {
        if(flag[v[start][i]]==0)
        {
            level[v[start][i]] = level[start] + mp[make_pair(v[start][i], start)];
            DFS(v[start][i]);
        }
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, n, u, va, w, i, j, mini;
    takei(t);
    while(t--)
    {
        takei(n);
        j = n-1;
        for(i=0; i<n; i++) v[i].clear();
        mp.clear();
        for(i=0; i<j; i++)
        {
            takei(u);
            takei(va);
            takei(w);
            v[u].pb(va);
            v[va].pb(u);
            mp[make_pair(u, va)] = w;
            mp[make_pair(va, u)] = w;
        }
        //deb(v[0].size());
        CLR(level);
        CLR(flag);
        DFS(0);
        mini = 0;
        for(i=0; i<n; i++)
        {
            if(mini<level[i])
            {
                mini = level[i];
                j = i;
            }
        }
        //deb(mini);
        CLR(level);
        CLR(flag);
        DFS(j);
        mini = 0;
        for(i=0; i<n; i++)
        {
            if(mini<level[i])
            {
                mini = level[i];
            }
        }
        pf("Case %d: %d\n", ++keis, mini);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
