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
#define csi                                     pf("Case %d:", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
long long tree[4*SIZE+7], prop[4*SIZE+7], start, last, n, val, ar[SIZE];
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 0;
        prop[node] = -1;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left]  + tree[right];
    prop[node] = -1;
    return;
}
void UPDATE(int i, int j, int node, int carry)
{
    if(carry==-1)
    {
        carry = prop[node];
    }
    else
    {
        prop[node] = carry;
        tree[node] = (j-i+1)*carry;
    }
    int a = max(i, (int)start), b = min(j, (int)last);
    if(a>b) return;
    if(i==a and j==b)
    {
        tree[node] = (j-i+1)*val;
        prop[node] = val;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left,prop[node]==0?carry:prop[node]);
    UPDATE(mid+1, j, right, prop[node]==0?carry:prop[node]);
    prop[node] = -1;
    tree[node] = tree[left] + tree[right];
    return;
}
ll QUERY(int i, int j, int node, int carry)
{
    if(carry==-1)
    {
        carry = prop[node];
    }
    else
    {
        prop[node] = carry;
        tree[node] = (j-i+1)*carry;
    }
    int a = max(i, (int)start), b = min(j, (int)last);
    if(a>b) return 0;
    if(i==a and j==b)
    {
        return tree[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    prop[node] = -1;
    int p1 = QUERY(i, mid, left, carry);
    int p2 = QUERY(mid+1, j, right, carry);
    return p1+p2;
}
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, q, j, k, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takell(n);
        takei(q);
        CLR(tree);
        INIT(1, n, 1);
        csi;NL;
        while(q--)
        {
            takei(a);
            takei(b);
            takei(c);
            //deb(b, c);
            b++;
            c++;
            if(a==1)
            {
                takell(val);
                start = b;
                last = c;
                UPDATE(1, n, 1, -1);
            }
            else
            {
                start = b;
                last = c;
                start = QUERY(1, n, 1, -1);
                last = __gcd(start, (ll)c-b+1);
                //deb(start, last);
                if(start%(c-b+1)==0)
                    pf("%lld\n",start/last);
                else
                    pf("%lld/%lld\n",start/last, (c-b+1)/last);
            }
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



