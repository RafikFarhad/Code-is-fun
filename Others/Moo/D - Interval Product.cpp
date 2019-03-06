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
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

int *tree, *zero, start, last, n, val, ar[SIZE];
bool mark;

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        if(ar[i]<0) tree[node] = 1;
        else tree[node] = 0;
        if(ar[i]==0) zero[node] = 1;
        else zero[node] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;

    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];
    zero[node] = zero[left] | zero[right];
    return;
}

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i==start and j==last)
    {
        if(ar[i]<0) tree[node] = 1;
        else tree[node] = 0;
        if(ar[i]==0) zero[node] = 1;
        else zero[node] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;

    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = tree[left] + tree[right];
    zero[node] = zero[left] | zero[right];
    return;
}

int QUERY(int i, int j, int node)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        mark|=zero[node];
        return tree[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left);
    int p2 = QUERY(mid+1, j, right);
    return p1+p2;
}

int main()
{
    //freopen("000.txt", "r", stdin);
    tree = new int[SIZE<<2];
    zero = new int[SIZE<<2];
    							/// INPUT
    //memset(prop, 0, sizeof prop);
    int t, q, i, j;
    char cc;
    while(sf("%d%d", &n, &q)!=EOF)
    {
        for(i=1; i<=n; i++)
            takei(ar[i]);
        INIT(1, n, 1);
        while(q--)
        {
            getchar();
            sf("%c %d%d", &cc, &start, &val);
            if(cc=='C')
            {
                last = start;
                //ar[start] = val;
                if( (ar[start]<0 and val <0) or (ar[start]>0 and val > 0) or (ar[start]==0 and val ==0) ) ar[start] = val;
                else
                {
                    ar[start] = val;
                    UPDATE(1, n, 1);
                }
            }
            else
            {
                last = val;
                mark = 0;
                val = QUERY(1, n, 1);
                if(mark) pf("0");
                else if(val&1) pf("-");
                else pf("+");
            }
        }
        NL;
    }
							/// END
    delete(tree);
    delete(zero);
}
