/// Olee vai josh

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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
vector <int> v[1500];
int n, match[1500];
bool flag[1500], have[1500];

class DATA
{
public:
    int time, xx, yy, st;
    DATA(int a=0, int b=0, int c=0, int d=0) : time(a), xx(b), yy(c), st(d){};
    bool operator < (const DATA &p) const
    {
        return time<p.time;
    }
};

bool DFS(int x)
{
    int i;
    for(i=0; i<v[x].size(); i++)
    {
        //deb(v[x][i]);
        if(flag[v[x][i]]==1) continue;
        flag[v[x][i]] = 1;
        if(match[v[x][i]]==-1)
        {
            match[v[x][i]] = x;
            return true;
        }
        if(DFS(match[v[x][i]]))
        {
            match[v[x][i]] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y, p, q;
    takei(t);
    while(t--)
    {
        takei(n);
        CLR1(match);
        CLR(v);
        CLR(have);
        vector < DATA > ar;
        for(i=0; i<n; i++)
        {
            sf("%d:%d %d%d%d%d", &x, &y, &a, &b, &c, &d);
            p = x*60+y;
            q = p + abs(a-c)+abs(b-d);
            //v[p].pb(q);
            //deb(p, q);
            ar.pb(DATA(p, a, b, 0));
            ar.pb(DATA(q, c, d, 1));
            have[q] = 1;
        }
        sort(all(ar));
        l = ar.size();
        for(i=0; i<l; i++)
        {
            if(ar[i].st==0) continue;
            for(j=i+1; j<l; j++)
            {
                if(ar[j].st==1) continue;
                if(ar[i].time==ar[j].time) continue;
                //ydeb("*", ar[i].time, ar[j].time);
                if(ar[i].time+abs(ar[i].xx-ar[j].xx)+abs(ar[i].yy-ar[j].yy)<ar[j].time)
                    v[i].pb(j);
            }
        }
        a = 0;
        for(i=0; i<2*n; i++)
        {
            //if(have[i])
            {
                //deb(i);
                CLR(flag);
                if(DFS(i))
                    a++;
            }
        }
        csi;
        pf("%d\n", n-a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



