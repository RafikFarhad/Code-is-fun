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
#define SIZE 100005
int *tree, ar[SIZE];

void INIT(int node, int start, int last)
{
    if(start==last)
    {
        tree[node] = ar[start];
        return;
    }
    int left = node*2, right = node*2+1, mid = (start+last)>>1;
    INIT(left, start, mid);
    INIT(right, mid+1, last);
    tree[node] = MIN(tree[left], tree[right]);
    return;
}

int QUERY(int node, int i, int j, int start, int last)
{
    if(i>last || j<start) return SIZE;
   // deb(start, last);
    if(start>=i && last<=j)
    {
        return tree[node];
    }
    int left = node*2, right = node*2+1, mid = (start+last)>>1;
    int l1 = QUERY(left, i, j, start, mid);
    int l2 = QUERY(right, i, j, mid+1, last);
    return MIN(l1, l2);
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    tree = new int[3*SIZE];
    int t, keis=0, n, q, node, i, j;
    sf("%d", &t);
    while(t--)
    {
        sf("%d %d", &n, &q);
       // deb(n, q, t);
        pf("Case %d:\n", ++keis);
        for(i=1; i<=n;i++)
            takei(ar[i]);
        INIT(1, 1, n);
        ////for(i=1; i<9; i++) deb(i, tree[i]);
        while(q--)
        {
            takei(i);
            takei(j);
            pf("%d\n", QUERY(1, i, j, 1, n));
        }
    }
    delete(tree);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
