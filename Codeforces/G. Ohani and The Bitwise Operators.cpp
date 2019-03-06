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
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/******************************************/
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
#define csi                                     pf("Case %d:\n", ++keis)
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
#define MX INT_MAX
#define MOD 1000000007
#define MY INT_MIN
#define SIZE 100005
class DATA
{
public:
    int a, b, c, val;
    DATA(int p = 0, int q = 0, int r = 0)
    {
        a = p;
        b = q;
        c = r;
    }
    DATA operator + (const DATA& q) const
    {
        DATA t;
        t.a = a+q.a;
        t.b = b+q.b;
        t.c = c+q.c;
        return t;
    }
};

DATA tree[4*SIZE], prop[4*SIZE];

int start, last, n, val, ar[SIZE], aa, bb, cc;
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = DATA(0,0,0);
        tree[node].a = (ar[i]/4)%2;
        tree[node].b = (ar[i]/2)%2;
        tree[node].c = ar[i]%2;
        prop[node] = DATA(0,0,0);
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = tree[left] + tree[right];
    prop[node] = DATA();
    return;
}

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        int m = j-i+1;
        if(aa==1)
        {
            tree[node].a = m-tree[node].a;
            prop[node].a++;
        }
        if(bb==1)
        {
            tree[node].b = m-tree[node].b;
            prop[node].b++;
        }
        if(cc==1)
        {
            tree[node].c = m-tree[node].c;
            prop[node].c++;
        }
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] =  tree[left] + tree[right];;
    return;
}

DATA QUERY(int i, int j, int node, DATA carry)
{
    if(i>last or j<start) return DATA();
    if(i>=start and j<=last)
    {
        int m, a, b, c;
        //carry.a+=prop[node].a;
        //carry.b+=prop[node].b;
        //carry.c+=prop[node].c;
        //deb("->", i, j);
        //deb("->", carry.a);
        m = j-i+1;

        if(carry.a%2!=0) a = m-tree[node].a;
        else a = tree[node].a;

        if(carry.b%2!=0) b = m-tree[node].b;
        else b = tree[node].b;

        if(carry.c%2!=0) c = m-tree[node].c;
        else c = tree[node].c;

        return DATA(a, b, c);
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    DATA p1 = QUERY(i, mid, left, carry+prop[node]);
    DATA p2 = QUERY(mid+1, j, right, carry+prop[node]);
    return p1+p2;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
 freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    /// INPUT
    takei(t);
    DATA temp;
    while(t--)
    {
        takei(n);
        takei(l);
        for(i=1; i<=n; i++)
        {
            takei(ar[i]);
        }
            INIT(1, n, 1);
        csi;
        while(l--)
        {
            takei(k);
            if(k==1)
            {
                takei(start);
                takei(last);
                takei(val);
                aa = (val/4)%2;
                bb = (val/2)%2;
                cc = val%2;
                UPDATE(1, n, 1);
            }
            else
            {
                takei(start);
                takei(last);
                //deb(start, last);
                temp = QUERY(1, n, 1, DATA());
                a = last-start+1;

                if(a==temp.c) x = 1;
                else x = 0;
                if(a==temp.b) x = 2 + x;
                if(a==temp.a) x = 4+x;
                pf("%d ", x);

                if(temp.c) x = 1;
                else x = 0;
                if(temp.b) x = 2 + x;
                if(temp.a) x = 4+x;
                //deb("*x", x);
                pf("%d ", x);

                //_(x);
                if(temp.c%2==1) x = 1;
                else x = 0;
                if(temp.b%2==1) x = 2 + x;
                if(temp.a%2==1) x = 4+x;
                //deb("*x", x);
                //_(x);
                pf("%d\n", x);


                //deb(temp.a, temp.b, temp.c);
            }
        }
    }

//memset(prop, 0, sizeof prop);
    /// END
}
/*
int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    deb((5^6)^7);
    deb(5^6, 6^7, 6^6^6);
    deb((5^6)^(6^7));
    /* Coding is FUN
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


*/
