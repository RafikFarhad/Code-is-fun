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
#define csi                                     pf("Case %d:\n", ++keis)
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
#define SIZE 100002
int tree[SIZE*4], prop[SIZE*4], start, last, n, val, ar[SIZE];

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] += (j-i+1)*val;
        prop[node] += val;
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = tree[left]  + tree[right] + prop[node] * (j-i+1);
    return;
}
int QUERY(int i, int j, int node, int carry)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        return tree[node] + (j-i+1)*carry;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left, carry+prop[node]);
    int p2 = QUERY(mid+1, j, right, carry+prop[node]);
    //deb(i, j, p1, p2);
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
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, ar[100005];
    int in[100005], out[100005];
    pair <int, int> my[55000];
    map <int, int> mp;
    set <int> st;
    set <int> :: iterator  it;
    takei(t);
    while(t--)
    {
        CLR(tree);
        CLR(prop);
        CLR(in);
        CLR(out);
        mp.clear();
        st.clear();
        takei(n);
        takei(k);
        for(i=0; i<n; i++)
        {
            takei(a);
            takei(b);
            //ar[i<<1] = a;
            //ar[(i<<1)|1] = b;
            if(b<a)
                swap(a, b);
            st.insert(a);
            st.insert(b);
            my[i] = pair<int, int> (a, b);
        }
        st.insert(100000009);
        b = 0;
        l = st.size() + 5;
        for(it=st.begin(); it!=st.end(); it++)
        {
            //deb(*it);
            //deb(*it, b+1);
            mp[*it] = ++b;
        }
        for(i=0; i<n; i++)
        {
            start = mp[my[i].xx];
            last = mp[my[i].yy];
            in[start]++;
            out[last]++;
            val = 1;
            UPDATE(1, l, 1);
        }
        csi;
        for(i=0; i<k; i++)
        {
            takei(a);
            if(mp.count(a)){
                start = last = mp[a];
                x = QUERY(1, l, 1, 0);
            }
            else
            {
                start = last = mp[*st.upper_bound(a)];
                x = QUERY(1, l, 1, 0) - in[last];
            }
            //if(mp.count(a)) x-=in[mp[a]];
            pf("%d\n", x);
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



