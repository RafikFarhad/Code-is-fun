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
char adj[1010][1010];
map <pair <int, int>, int> flag;
map<int, int> mp;

void DO(int i, int j)
{
    flag[make_pair(i,j)] = 1;
    char c = adj[i][j]; //MyDebug(i, j);
    if(adj[i][j+1]==c && !flag[make_pair(i,j+1)])
        DO(i, j+1);
    if(adj[i][j-1]==c && !flag[make_pair(i,j-1)])
        DO(i, j-1);
    if(adj[i+1][j]==c && !flag[make_pair(i+1,j)])
        DO(i+1, j);
    if(adj[i-1][j]==c && !flag[make_pair(i-1,j)])
        DO(i-1, j);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10336.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, i, j, h, w, mazi;
    char a[500];
    sf("%d", &t);
    for(int k=0; k<t; k++)
    {
        sf("%d %d ", &h, &w);
        flag.clear();
        mp.clear();
        for(i=1; i<=h; i++)
        {
            gets(a);
            for(j=1; j<=w; j++)
                adj[i][j] = a[j-1];
        }
        int maxi = 0;
        for(i=1; i<=h; i++)
        {
            for(j=1; j<=w; j++)
                {
                    if(!flag[make_pair(i,j)])
                    {
                        mp[adj[i][j]]++;
                        DO(i, j);
                        //MyDebug(adj[i][j], 'C');
                        if(mp[adj[i][j]]>maxi)
                            maxi = mp[adj[i][j]];
                    }
                }
        }
        pf("World #%d\n", k+1);
        for(i=maxi; i>0; i--)
        {
            for(j='a'; j<='z'; j++)
                if(i==mp[j])
                    pf("%c: %d\n", j, i);
        }
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
