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

template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << ", " << q << ", " << r << ", " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
int *tree, ar[SIZE+5], lo;

void INIT(int a, int b, int node)
{
    if(a==b)
    {
        tree[node] = ar[b];
        return;
    }
    int left = node*2, right = node*2+1, mid = (a+b)>>1;
    INIT(a, mid, left);
    INIT(mid+1, b, right);
    tree[node] = tree[left]+tree[right];
    return;
}

void UPDATE(int a, int v, int i, int j, int node)
{
    //deb(a, i, j, node);
    if(a < i || j < a) return;
    if(i==j)
        {
           // lo = tree[node];
            if(v) tree[node] += v;
            else tree[node] = v;
            //deb(tree[node],i,0,0);
            return;
        }
    int left = node*2, right = node*2+1, mid = (i+j)>>1;
    UPDATE(a, v, i, mid, left);
    UPDATE(a, v, mid+1, j, right);
    tree[node] = tree[left]+tree[right];
    return;
}

int QUERY(int a, int b, int i, int j, int node)
{
    //deb(i, j, node, 0);
    if(i>b || j < a) return 0;
    if(i>=a && j<=b)
    {
        return tree[node];
    }
    int left = node*2, right = node*2+1, mid = (i+j)>>1, s1, s2;
    s1 = QUERY(a, b, i, mid, left);
    s2 = QUERY(a, b, mid+1, j, right);
    return s1+s2;
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
    int t, keis=0, i, j, n, q, l;
    tree = new int[3*SIZE+15];
    takei(t);
    while(t--)
    {
        CLR(tree);
        pf("Case %d:\n", ++keis);
        takei(n);
        takei(q);
        for(i=1; i<=n; i++)
            takei(ar[i]);
        INIT(1, n, 1);
       // for(i=1; i<9; i++) deb(i, tree[i], 0, 0);
        while(q--)
        {
            takei(i);
            //deb(n, q,i,0);
            if(i==1)
                {
                    takei(l);
                    pf("%d\n", ar[l+1]);
                    ar[l+1] = 0;
                    UPDATE(l+1, 0, 1, n, 1); //for(i=1; i<9; i++) deb(i, tree[i], 0, 0);
                }
            else if(i==2)
            {
                takei(j);
                takei(l);
                ar[j+1] += l;
                UPDATE(j+1, l, 1, n, 1);
            }
            else if(i==3)
            {
                takei(j);
                takei(l);
                pf("%d\n", QUERY(j+1, l+1, 1, n, 1));
            }
        }
    }
    delete(tree);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
