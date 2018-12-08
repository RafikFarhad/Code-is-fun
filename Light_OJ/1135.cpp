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
#define SIZE 100009
class DATA
{
public:
    int n0, n1, n2, prop;
    DATA()
    {
        n0 = n1 = n2 = prop = 0;
    }
};

DATA tree[4*SIZE+100];
int start, last, n, val;
void INIT(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node].n0 = 1;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node].n0 = tree[left].n0  + tree[right].n0;// + prop[node] * (j-i+1);
    return;
}
void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node].prop++;
        int a = tree[node].n2;
        tree[node].n2 = tree[node].n1;
        tree[node].n1 = tree[node].n0;
        tree[node].n0 = a;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node].n0 = tree[left].n0  + tree[right].n0;
    tree[node].n1 = tree[left].n1  + tree[right].n1;
    tree[node].n2 = tree[left].n2  + tree[right].n2;;
   if(tree[node].prop%3==0)
    {
        ;
    }
    else if(tree[node].prop%3==1)
    {
        swap(tree[node].n0, tree[node].n1);
        swap(tree[node].n0, tree[node].n2);
    }
    else
    {
        swap(tree[node].n0, tree[node].n1);
        swap(tree[node].n1, tree[node].n2);
    }
    return;
}

int QUERY(int i, int j, int node, int prop)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        //return tree[node].n0;
        int a = (prop)%3;
        if(a==0) return tree[node].n0;
        else if(a==1) return tree[node].n2;
        else return tree[node].n1;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left, prop+tree[node].prop);//, carry+prop[node]);
    int p2 = QUERY(mid+1, j, right, prop+tree[node].prop);//, carry+prop[node]);
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
    int i, t, j, k, q, l,  keis=0, a, b, c, d, x, y;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(q);
        CLR(tree);
        for(i=1; i<=n; i++)
        {
            start = last = i;
            INIT(1, n, 1);
        }
        csi;NL;
        while(q--)
        {
            takei(a);
            takei(b);
            takei(c);
            b++;
            c++;
            //deb(a, b, c);
            if(a==0)
            {
                start = b;
                last = c;
                UPDATE(1, n, 1);
            }
            else
            {
                start = b;
                last = c;
                _(QUERY(1, n, 1, 0));
            }
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



