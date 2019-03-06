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
#define SIZE 100000
class NODE
{
public:
    int u, v, w, next;
    NODE(){};// : v(a), w(b) {};
};

NODE mat[SIZE*2];

class DATA
{
public:
    int ar[2];
    DATA()
    {
        CLR1(ar);
    }
};


DATA tree[SIZE*40];
int current, n, head[SIZE], dis[SIZE];

void INSERT_TO_TREE(int ss)
{
    int i, j, root = 0;
    for(i=31; i>=0; i--)
    {
        j = (ss>>i)&1;
        if(tree[root].ar[j]==-1)
        {
            //tree.pb(DATA());
            tree[root].ar[j] = current;
            CLR1(tree[current].ar);
            current++;
        }
        root = tree[root].ar[j];
    }
    return;
}
void ADD(int a, int b, int c)
{
    //mat[a].u = a;
    mat[current].v = b;
    mat[current].w = c;
    mat[current].next = head[a];
    head[a] = (current++);
}


void DFS(int prev=-1, int cur=0, int ss=0)
{
    dis[cur] = ss;
    INSERT_TO_TREE(ss);
    int i, vv;
    for(i=head[cur]; i!=-1; i = mat[i].next)
    {
        vv = mat[i].v;
        if(vv==prev) continue;
        DFS(cur, vv, ss^mat[i].w);
    }
    return;
}

int COUNT(int ss)
{
    int ans, i, k, root = 0;
    for(i=31; i>=0; i--)
    {
        k = (ss>>i) & 1;
        k^=1;
        if(tree[root].ar[k]==-1)
        {
            ans<<=1;
            root = tree[root].ar[k^1];
        }
        else
        {
            root = tree[root].ar[k];
            ans<<=1;
            ans++;
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
    int i, j, k, l,  keis=0, a, b, c, d;
    while(sf("%d", &n)!=EOF)
    {
        //tree.clear();
        CLR1(tree[0].ar);
        current = 0;

        CLR1(head);
        for(i=1; i<n; i++)
        {
            takei(a);
            takei(b);
            takei(c);
            ADD(a, b, c);
            ADD(b, a, c);
        }
        //tree.pb(DATA());
        current = 1;
        DFS();
        for(i=0, a=0; i<n; i++)
        {
            a = max(a, COUNT(dis[i]));
        }
        pf("%d\n", a);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


