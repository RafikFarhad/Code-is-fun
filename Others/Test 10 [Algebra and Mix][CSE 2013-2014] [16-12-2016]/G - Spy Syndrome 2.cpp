
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
#define MOD 1000000007
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}
string in, tt[100005], aa;
int n,ar[1100], m;
vector <string> ans;
map <ll, string> mm;
bool mark;

void GO(int a)
{
    if(mark) return;
    if(a==n)
    {
        for(int i=0; i<ans.size(); i++)
        {
            if(i) pf(" ");
            pf("%s", ans[i].c_str());
        }
        NL;
        mark = 1;
        return;
    }
    //deb(a);
    ll h = 0,k = 0, i, x;
    for(i=a; i<n and !mark; i++)
    {
        if(mm.count(h)==1)
        {
            ans.push_back(mm[h]);
            //deb(i, mm[h]);
            GO(i);
            ans.pop_back();
        }
        x = toascii(in[i]) - 'a' + 1;
        h+=(x*ar[k]);
        h%=MOD;
        k++;
        //deb(i, in[i], h);
    }
    if(!mark and mm.count(h)==1)
    {
        ans.pb(mm[h]);
        GO(i);
    }
    else
    {
        return;
    }
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0);
    ll base=100003ll,  c, d, x, y, a, b,  h;
    ar[0] = base;
    for(i=1; i<1001; i++)
    {
        ar[i] = ar[i-1]*base;
        ar[i]%=MOD;
    }
//    char pp[100];
//    fgets(pp, 100, stdin);

    takei(n);
    cin >> in;
    takei(m);
    for(i=0; i<m; i++)
    {
        cin >> tt[i];
        l = tt[i].size();
        h = 0;
        //deb(tt[i]);
        for(j=l-1, k=0; j>=0; j--, k++)
        {
            x = toascii(tolower(tt[i][j])) - 'a' + 1;
            h+=(x*ar[k]);
            h%=MOD;
            //deb(tt[i][j], h);
        }
        mm[h] = tt[i];
    }
    ans.clear();
    mark = false;
    GO(0);
//    h=0;
//    k = 0;
//    for(i=0; i<n; i++)
//    {
//        if(mm.count(h)==1)
//        {
//            pf("%s ", mm[h].c_str());
//            i--;
//            h = 0;
//            k = 0;
//            continue;
//        }
//        x = toascii(in[i]) - 'a' + 1;
//        h+=(x*ar[k]);
//        h%=MOD;
//        //deb(in[i], h);
//        k++;
//    }
//    if(mm.count(h)==1)
//    {
//        pf("%s", mm[h].c_str());
//        i--;
//    }
//    NL;
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


