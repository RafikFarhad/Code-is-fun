
/*De La Grandi Mephistopheles*/


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
/** Created on  : 2017-01-21-14.29 _ Saturday      */
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
ll tot[500];
int attempt[500], p, t, solved[500];
vector <int> pos, temp_pos;

int TO_NUM(char a[])
{
    int i, j, k=0, l = strlen(a);
    for(i=0; i<l; i++)
    {
        k = k*10+a[i]-'0';
    }
    return k;
}

class DATA
{

public:
    int s, id;
    ll t;
    DATA(int _s=0, ll _t = 0, int _id=0):s(_s), t(_t), id(_id){};
    bool operator < (const DATA &p) const
    {
        if(s==p.s)
        {
            if(t==p.t)
                return id<p.id;
            return t<p.t;
        }
        return s>p.s;
    }
};

vector <int> COUNT(ll x)
{
    vector <DATA> ans;
    vector <int> temp;
    int i, j, k;
    for(i=0; i<t; i++)
    {
        temp.pb(0);
        ans.pb(DATA(solved[i], tot[i]+(ll) attempt[i]*x, i));
    }
    sort(all(ans));
    for(i=0, j=1; i<t; i++)
    {
        if(!i) temp[ans[i].id] = 0;
        else if(ans[i].s==ans[i-1].s and ans[i].t==ans[i-1].t)
        {
            temp[ans[i].id] = temp[ans[i-1].id];
        }
        else
        {
            temp[ans[i].id] = temp[ans[i-1].id] + 1;
            j++;
        }
    }
    return temp;
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("C:/Users/RafikFarhad/Desktop/000.txt","r",stdin);
    freopen("/home/rafikfarhad/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    char test[10];
    while(sf("%d%d", &t, &p)==2 and t and p)
    {
        CLR(tot);
        CLR(attempt);
        CLR(solved);

        for(i=0; i<t; i++)
        {
            for(j=0; j<p; j++)
            {
                sf("%d", &a);
                getchar();
                sf("%s", test);
                if(test[0]=='-' or a==0) continue;
                sscanf(test, "%d", &b);
                attempt[i]+=(a);
                tot[i]+=(ll)b;
                solved[i]++;
            }
        }
        pos.clear();
        pos = COUNT(20);

        ll s = 1<<29, e=0;
        for(i=20; i>0; i--)
        {
            temp_pos = COUNT(i);
            if(temp_pos==pos)
            {
                s = i;
            }
            else break;
        }
        ll lo = 20, hi = 9000000000ll, mid;

        while(hi>=lo)
        {
            mid = (hi+lo)>>1;
            temp_pos = COUNT(mid);
            if(temp_pos==pos)
            {
                e = max(e, mid);
                //deb(e, mid);
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
        //deb(e);
        if(e==9000000000 or e==-1)
            cout << s << " " << "*" ;
        else cout << s << " " << e ;
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}
