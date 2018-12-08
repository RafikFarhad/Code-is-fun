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
#define _(o)                                    pf("%d", o)

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
//#define SIZE 1000

int tree[SIZE<<2][3], start, last, n, val, ar[SIZE];
int lazy[SIZE<<2];

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node][0] = 1;
        tree[node][1] = tree[node][2] = 0;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;

    INIT(i, mid, left);
    INIT(mid+1, j, right);

    tree[node][0] = tree[left][0] + tree[right][0];
    tree[node][1] = tree[left][1] + tree[right][1];
    tree[node][2] = tree[left][2] + tree[right][2];

    return;
}

void PROP(int i, int j, int node)
{
    int left = node<<1;
    int right = left|1;
    if(i!=j)
    {
        lazy[left] = (lazy[node]+lazy[left])%3;
        lazy[right] = (lazy[node]+lazy[right])%3;
    }
    if(lazy[node]==1)
    {
        int a = tree[node][0], b = tree[node][1], c = tree[node][2];
        tree[node][0] = c;
        tree[node][1] = a;
        tree[node][2] = b;
    }
    else if(lazy[node]==2)
    {
        int a = tree[node][0], b = tree[node][1], c = tree[node][2];
        tree[node][0] = b;
        tree[node][1] = c;
        tree[node][2] = a;
    }
    lazy[node] = 0;
    return;
}

void UPDATE(int i, int j, int node)
{
    if(lazy[node]) PROP(i, j, node);

    if(i>last || j<start) return;
    //deb(i, j, node);

    int left = node<<1;
    int right = left | 1;

    if(i>=start and j<=last)
    {
        if(i!=j)
        {
            lazy[left] = (1+lazy[left])%3;
            lazy[right] = (1+lazy[right])%3;
        }
        int a = tree[node][0], b = tree[node][1], c = tree[node][2];
        tree[node][0] = c;
        tree[node][1] = a;
        tree[node][2] = b;
        return;
    }

    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node][0] = tree[left][0] + tree[right][0];
    tree[node][1] = tree[left][1] + tree[right][1];
    tree[node][2] = tree[left][2] + tree[right][2];
    return;
}

int QUERY(int i, int j, int node)
{
    if(i>last or j<start) return 0;

    if(lazy[node]) PROP(i, j, node);

    if(i>=start and j<=last)
    {
        return tree[node][0];
    }
    int left = node<<1;
    int right = (node<<1) | 1;
    int mid = (i+j)>>1;

    int p1 = QUERY(i, mid, left);
    int p2 = QUERY(mid+1, j, right);

    return p1+p2;
}

int main()
{
    //freopen("000.txt", "r", stdin);
    							/// INPUT
    int c, i, j, k, p, m, t;
    //takei(t);
    //while(t--)

        sf("%d %d", &n, &c);
        INIT(1, n, 1);
        //deb(state[1]);
        while(c--)
        {
            takei(t);
            takei(start);
            takei(last);
            start++;
            last++;
            if(t==0)
            {
                UPDATE(1, n, 1);
            }
            else
            {
                m = QUERY(1, n, 1);
                _(m); NL;
            }
        }

							/// END

}

