

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
/** Created on  : 2017-03-21-22.37 _ Tuesday       */
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
#define ok                                      cout << "OKA" <<endl;
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
#define MX
#define MOD
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

#define SIZE 100005
ll ar[SIZE];

class SEGMENT_TREE
{
public:
    long long *tree;
    int val;
    int n=SIZE, start, last;
    SEGMENT_TREE(){};
    void SET_SIZE(int sz)
    {
        n = sz;
        tree = new long long[n<<2];
    }

    void INIT(int i, int j, int node)
    {
        if(i==j)
        {
            tree[node] = -1;
            return;
        }
        int left = node<<1;
        int right = left | 1;
        int mid = (i+j)>>1;
        INIT(i, mid, left);
        INIT(mid+1, j, right);
        tree[node] = max(tree[left] , tree[right]);
        return;
    }
    void UPDATE(int i, int j, int node)
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
        UPDATE(i, mid, left);
        UPDATE(mid+1, j, right);
        tree[node] = max(tree[left]  , tree[right]);
        return;
    }
    long long QUERY(int i, int j, int node)
    {
        if(i>last or j<start) return -1;
        if(i>=start and j<=last)
        {
            return tree[node];
        }
        int left = node<<1;
        int right = left | 1;
        int mid = (i+j)>>1;
        ll p1 = QUERY(i, mid, left);
        ll p2 = QUERY(mid+1, j, right);
        return max(p1,p2);
    }

} tree;

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
    int ar[100005], br[100005], n;
    map <int, int> mmp;
    takei(n);
    for(i=0; i<n; i++)
    {
        takei(ar[i]);
        br[i] = ar[i];
    }
    sort(br, br+n);
    int tot = 0;
    mmp[br[0]] = ++tot;
    for(i=1; i<n; i++)
    {
        if(br[i]!=br[i-1])
            mmp[br[i]] = ++tot;
    }
    tree.SET_SIZE(tot);
    tree.INIT(1, tot, 1);
    for(i=n-1; i>=0; i--)
    {
        b = mmp[ar[i]];
        tree.start = 1;
        tree.last = b-1;
        a = (int) tree.QUERY(1, tot, 1);
//        deb(i, a);
        if(a==-1)
        {
            br[i] = -1;
        }
        else
        {
            br[i] = a-i-1;
        }
        tree.start = tree.last = b;
        a = (int) tree.QUERY(1, tot, 1);
        if(a==-1)
        {
//            deb("###########", i, b);
            tree.start = tree.last = b;
            tree.val = i;
            tree.UPDATE(1, tot, 1);
        }
    }
    for(i=0; i<n; i++)
    {
        if(i) pf(" ");
        pf("%d", br[i]);
    }
    NL;

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


