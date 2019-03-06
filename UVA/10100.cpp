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
#define SIZE INT_MAX
map <int, string> a, b;
int la, lb, dp[200][200];
bool last;
int LCS(int x, int y)
{
    if(x==la or y==lb) return 0;
    int &ret = dp[x][y];
    if(~ret)
    {
        return ret;
    }
    if(a[x]==b[y])
    {
        ret = 1 + LCS(x+1, y+1);
        return ret;
    }
    int p , q;
    p = LCS(x+1, y);
    q = LCS(x, y+1);
    if(p>q)
    {
        ret = p;
    }
    else
    {
        ret = q;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0,   c, d;
    string aa, p;
    while(getline(cin, aa))
    {
        la = 0;
        lb = 0;
        l = aa.size();
        a.clear();
        b.clear();
       // deb(aa);
        p = "";
        for(i=0; i<l; i++)
        {
            //deb(i, aa[i], isalpha(aa[i]));
            if(isalpha(aa[i]) or (aa[i]>='0' and aa[i]<='9'))
            {
                p+=aa[i];
            }
            else if(p.size())
            {
                a[la++] = p;
                p = "";
            }
        }
        if(p.size())
            a[la++] = p;
        getline(cin, aa);
        //deb(aa);
        l = aa.size();
        p = "";
        for(i=0; i<l; i++)
        {
            if(isalpha(aa[i]) or (aa[i]>='0' and aa[i]<='9'))
            {
                p+=aa[i];
            }
            else if(p.size())
            {
                b[lb++] = p;
                p = "";
            }
        }
        if(p.size())
            b[lb++] = p;
        //deb(la, lb);
        pf("%2d. ", ++keis);
        if(!la or !lb)
        {
            pf("Blank!\n");
            continue;
        }
        CLR1(dp);
        l = (LCS(0,0));
        pf("Length of longest match: %d", l);
        NL;
    }



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


