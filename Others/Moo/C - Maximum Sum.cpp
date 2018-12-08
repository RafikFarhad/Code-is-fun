
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

int *tree, m1[SIZE<<2], m2[SIZE<<2], start, last, n, val, ar[SIZE], c[5];
vector <int> v;

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = ar[i];
        m1[node] = ar[i];
        m2[node] = -1;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;

    INIT(i, mid, left);
    INIT(mid+1, j, right);
    c[0] = m1[left];
    c[1] = m2[left];
    c[2] = m1[right];
    c[3] = m2[right];
    sort(c, c+4);
    m1[node] = c[3];
    m2[node] = c[2];
    tree[node] = m1[node] + m2[node];
    return;
}

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i==start and j==last)
    {
        tree[node] = val;
        m1[node] = val;
        m2[node] = -1;
        return;
    }

    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;

    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    c[0] = m1[left];
    c[1] = m2[left];
    c[2] = m1[right];
    c[3] = m2[right];
    sort(c, c+4);
    m1[node] = c[3];
    m2[node] = c[2];
    tree[node] = m1[node] + m2[node];
    return;
}

void QUERY(int i, int j, int node)
{
    if(i>last or j<start) return;
    if(i>=start and j<=last)
    {
        v.pb(m1[node]);
        v.pb(m2[node]);
        return;// 0;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    QUERY(i, mid, left);
    QUERY(mid+1, j, right);
    return;
}

int main()
{
    //freopen("000.txt", "r", stdin);
    tree = new int[SIZE<<2];
    							/// INPUT
    takei(n);
    int i, t;
    char cc;
    for(i=1; i<=n; i++)
        takei(ar[i]);
    INIT(1, n, 1);
    takei(t);
    while(t--)
    {
        getchar();
        sf("%c %d%d", &cc, &start, &val);
        if(cc=='U')
        {
            last = start;
            UPDATE(1, n, 1);
        }
        else
        {
            last = val;
            v.clear();
            QUERY(1, n, 1);
            sort(all(v));
            val = v[v.size()-1] + v[v.size()-2];// +
            _(val); ;
        }
    }
							/// END
    delete(tree);
}
