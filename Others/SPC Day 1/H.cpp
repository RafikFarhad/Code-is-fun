
/*Winter is coming*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-03-23-22.06 _ Thursday       */
/****************************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
//#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX 30005
#define MOD 1000000007
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}


int chainNo,chainHead[MX],chainPos[MX],chainInd[MX],chainSize[MX];
int ar[MX], n;
int tree[4*MX], start, last, val;
int baseInd[MX], baseArray[MX], baseNo;;

vector <int> v[MX];
int par[MX], leve[MX], subSize[MX];
int paro[MX][20];
int DFS(int prev, int cur, int lev)
{
    leve[cur] = lev;
    par[cur] = prev;
    int p = 0, i, x;
    for(i = 0; i<v[cur].size(); i++)
    {
        x = v[cur][i];
        if(x==prev) continue;
        subSize[x] = 1+ DFS(cur, x, lev+1);
        p+=subSize[x];
    }
    return p;
}

void HLD(int prev, int cur)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo] = cur;
    chainInd[cur] = chainNo;
    chainPos[cur] = chainSize[chainNo];
    chainSize[chainNo]++;
    baseInd[cur] = baseNo;
    baseNo++;
    int i, ok=-1, special_node = -1;
    for(i=0; i<v[cur].size(); i++)
    {
        if(prev!=v[cur][i] and ok<subSize[v[cur][i]])
        {
            ok = subSize[v[cur][i]];
            special_node = v[cur][i];
        }
    }

    if(ok>=1) HLD(cur, special_node);
    for(i=0; i<v[cur].size(); i++)
    {
        if(special_node!=v[cur][i] and prev!=v[cur][i])
        {
            chainNo++;
            HLD(cur, v[cur][i]);
        }
    }
    return;
}

void UPDATE(int i, int j, int node, int nth)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] = val;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left, nth);
    UPDATE(mid+1, j, right, nth);
    tree[node] = tree[left]  + tree[right];// + prop[node] * (j-i+1);
    return;
}
int QUERY(int i, int j, int node, int nth)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        return tree[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left, nth);
    int p2 = QUERY(mid+1, j, right, nth);
    return p1+p2;
}
void INIT_LCA()
{
    int i, j, k, lg=18;
    for(i=0; i<=n; i++)
    {
        paro[i][0] = par[i];
        for(j=1; j<=lg; j++)
        {
            paro[i][j] = -1;
        }
    }
    for(j=1; j<=lg; j++)
    {
        for(i=0; i<=n; i++)
        {
            if(paro[i][j-1]!=-1)
            {
                paro[i][j] = paro[paro[i][j-1]][j-1];
            }
        }
    }
    return;
}

int FIND_LCA(int a, int b)
{
    int i, j, k, lg=18;
    if(leve[a]<leve[b])
        swap(a, b);
    for(j=18; j>=0; j--)
    {
        if(leve[a]-(1<<j)>=leve[b])
            a = paro[a][j];
    }
    if(a==b)
        return a;
    for(j=18; j>=0; j--)
    {
        if(paro[a][j]!=paro[b][j])
        {
            a = paro[a][j];
            b = paro[b][j];
        }
    }
    return paro[a][0];
}
int FINAL_QUERY(int u, int v)                      /// V must be LCA
{
    int uchain = chainInd[u], vchain = chainInd[v], ans  = 0;
    //deb(u, v, uchain, vchain);
    while(1)
    {
        uchain = chainInd[u];
        if(uchain==vchain)
        {
            last = baseInd[u] + 1;
            start = baseInd[v] + 1;
            ans+=QUERY(1, n, 1, uchain);
            return ans;
        }
        start = baseInd[chainHead[uchain]] + 1;
        last = baseInd[u] + 1;
        //deb("->", start, last);
        ans+= QUERY(1, n, 1, uchain);
        //deb(QUERY(1, n, 1, uchain));
        u = chainHead[uchain];
        u = par[u];
    }

}
int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=1; i<=n; i++)
        {
            takei(ar[i]);
            v[i].clear();
        }
        for(i=0; i<n-1; i++)
        {
            takei(a);
            takei(b);
            a++;
            b++;
            v[a].pb(b);
            v[b].pb(a);
        }
        CLR1(par);
        subSize[1] = 1 + DFS(-1, 1, 0);
        chainNo = 0;
        CLR1(chainHead);
        CLR(chainSize);
        CLR(baseInd);
        baseNo = 0;
        CLR(tree);
        HLD(-1, 1);
        INIT_LCA();
        for(i=1; i<=n; i++)
        {
            start = last = baseInd[i]+1;
            val = ar[i];
            UPDATE(1, n, 1, chainInd[i]);
        }
        csii;
        takei(i);
        while(i--)
        {
            takei(a);
            takei(b);
            takei(c);
            b++;c++;
            if(a==0)
            {
                a = FIND_LCA(b, c);
                x = FINAL_QUERY(c, a);
                y = FINAL_QUERY(b, a);
                pf("%d\n", x+y-ar[a]);
            }
            else
            {
                ar[b] = --c;
                val = c;
                start = last = baseInd[b] + 1;
                UPDATE(1, n, 1, chainInd[b]);
            }
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



