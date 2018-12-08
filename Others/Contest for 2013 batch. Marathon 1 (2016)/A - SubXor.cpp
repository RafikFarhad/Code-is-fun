///Only Sakibul Mowla vai is real :P



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
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

///Helper
using namespace std;
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void __(T1 p)
{
    cout << p << endl;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

class DATA
{
public:
    int ar[3], prefixl, prefixr;
    DATA()
    {
        CLR1(ar);
        prefixr = prefixl = 0;
    }
};

vector <DATA> tree;
int current, n, mini;

void ADD_TO_TREE(int num, int pos, int root)
{
    if(pos==-1)
    {
        return;
    }
    int k = (num>>pos) & 1;
    //k^=1;
    if(tree[root].ar[k]==-1)
    {
        tree.pb(DATA());
        tree[root].ar[k] = current;
        current++;
    }
    if(k) tree[root].prefixr++;
    else tree[root].prefixl++;
    ADD_TO_TREE(num, pos-1, tree[root].ar[k]);
    return;

}

ll FIND(int num)
{
    int i, j, k, root = 0;
    ll ans = 0;
    for(i=20; i>=0; i--)
    {
        k = (mini>>i)&1;
        j = (num>>i)&1;
        //j^=1;
        if(k)
        {
            if(j)
            {
                ans+=tree[root].prefixr;
                if(tree[root].ar[0]==-1)
                    return ans;
                root = tree[root].ar[0];
            }
            else
            {
                ans+=tree[root].prefixl;
                if(tree[root].ar[1]==-1)
                    return ans;
                root = tree[root].ar[1];
            }
        }
        else
        {
            if(tree[root].ar[j]==-1)
                return ans;
            root = tree[root].ar[j];
        }
    }
    return ans;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, k, l, sumxor,  keis=0, a, b, c, d;
    takei(t);
    ll ans;
    while(t--)
    {
        takei(n);
        takei(mini);
        tree.clear();
        tree.pb(DATA());
        current = 1;
        sumxor = 0;
        ADD_TO_TREE(sumxor, 20, 0);
        ans = 0ll;
        for(i=0; i<n; i++)
        {
            takei(a);
            sumxor = sumxor^a;
            ans+= FIND(sumxor);
            ADD_TO_TREE(sumxor, 20, 0);
        }
        pf("%lld\n", ans);
    }



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


