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

long long *tree, *prop, start, last, n, val, ar[SIZE];

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 0ll;
        prop[node] = 0ll;
        return;
    }
    int left = node<<1;
    int right = (node*2) + 1;
    int mid = (i+j)>>1;

    INIT(i, mid, left);
    INIT(mid+1, j, right);

    tree[node] = 0ll;
    prop[node] = 0ll;
    return;
}

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] += (long long)(j-i+1)*val;
        prop[node] += val;
        return;
    }
    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (i+j)>>1;

    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);

    tree[node] = tree[left]  + tree[right] +  prop[node] * (long long)(j-i+1);
    return;
}

long long QUERY(int i, int j, int node, long long carry)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        return tree[node] + (long long)(j-i+1)*carry;
    }
    int left = node<<1;
    int right = (node<<1) + 1;
    int mid = (i+j)>>1;
    long long p1 = QUERY(i, mid, left, carry+prop[node]);
    long long p2 = QUERY(mid+1, j, right, carry+prop[node]);
    return p1+p2;
}

int main()
{
    tree = new long long[4*SIZE];
    prop = new long long[4*SIZE];
    							/// INPUT
    int c, i, j, k, p, m, t;
    takei(t);
    while(t--)
    {
        sf("%lld %d", &n, &c);
        INIT(1, n, 1);
        while(c--)
        {
            takei(m);
            takell(start);
            takell(last);
            if(m==0)
            {
                takell(val);
                UPDATE(1, n, 1);
            }
            else
            {
                cout << QUERY(1, n, 1, 0)<< endl;
            }
        }
    }
							/// END
    delete(tree);
    delete(prop);
}
