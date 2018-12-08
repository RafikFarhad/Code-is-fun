/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define NL printf("\n")
#define PI 2*acos(0)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt", "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 5104
vector <int> v[SIZE];
int par[SIZE], level[SIZE], spars[SIZE][20], n;
bool visited[SIZE];

void DFS(int pa, int x, int lev)
{
    if(visited[x]) return;
    visited[x] = 1;
    par[x] = pa;
    level[x] = lev;
    for(int i=0; i<v[x].size(); i++)
        DFS(x, v[x][i], lev+1);
    return;
}

void SPARS()
{
    int i, j, lev = log2(n)+1;
    CLR1(spars);
    for(i=1; i<=n; i++)
    {
        spars[i][0] = par[i];
    }
    for(i=1; (1<<i) <=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(spars[j][i-1]!=-1)
            {
                spars[j][i] = spars[spars[j][i-1]][i-1];
            }
        }
    }
    return;
}

int FIND_LCA(int a, int b)
{
    if(level[b]<level[a]) swap(a, b);
    int i, h = log2(n)+1, diff = level[b]-level[a];
    for(i=h; i>=0; i--)
    {
        if(level[b] - (1<<i) >= level[a])
            b = spars[b][i];
    }
    if(b==a) return b;
    for(i=h; i>=0; i--)
        if(spars[b][i]!=-1 && spars[b][i]!=spars[a][i])
        {
            a = spars[a][i];
            b = spars[b][i];
        }
//    deb(b);
    return spars[b][0];
}
int GET_MEET_POINT(int a, int b, int dis, int val);   // get the meet point from the root a to b
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, a,b, qu;
    while(1)
    {
        takei(n);
        if(!n) break;
        for(i=0; i<=n; i++)
            v[i].clear();
        for(i=1; i<n; i++)
        {
            takei(a);
            takei(b);
            v[a].pb(b);
            v[b].pb(a);
        }
        CLR(visited);
        CLR(level);
        DFS(-1,1, 0);
        SPARS();
        takei(qu);
        while(qu--)
        {
            takei(a);
            takei(b);
            int lca = FIND_LCA(a, b);
            int dis = level[a] + level[b] - 2*level[lca];
//            deb(a, b, lca, dis);
            if(dis & 1) //if distance is even then there must be a node where they can meet
            {
                i = GET_MEET_POINT(a, b, dis/2+1, lca);
                j = GET_MEET_POINT(b, a, dis/2+1, lca);
                pf("The fleas jump forever between %d and %d.\n", min(i, j), max(i, j));
            }
            else
                pf("The fleas meet at %d.\n", GET_MEET_POINT(b, a, dis/2+1, lca));
        }



//        for(i=1; i<=n; i++, NL)
//            for(j=0; j<3; j++)
//                pf("%d \t", spars[i][j]);
//        for(i=1; i<=n; i++)
//            pf("%d -> par = %d level = %d\n", i, par[i], level[i]);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

int GET_MEET_POINT(int a, int b, int dis, int lca)
{
    if(level[a] - level[lca]==dis-1) return lca;
    int i, laaf=0, h, dd;
    if(level[a] - level[lca] >= dis)
    {
        h = log2(level[a]) + 1;
        for(i=h; i>=0; i--)
        {
            if(laaf + (1<<i) <= dis-1)
            {
                a = spars[a][i];
                laaf+= (1<<i);
            }
        }
        return a;
    }

//    deb(dis, level[a], level[lca]);
    dis = dis + level[lca]  - level[a] -1;
//    deb(dis);
    dis = (level[b]-level[lca]) - dis;
//    deb(dis);
        h = log2(level[b]) + 1;
        for(i=h; i>=0; i--)
        {
            if(laaf + (1<<i) <= dis)
            {
                b = spars[b][i];
                laaf+= (1<<i);
            }
        }
        return b;
}
