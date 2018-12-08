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
int x, ar[] = {0,1,2,3,4,5,6,7,8,9};
vector <int> v;

class DATA
{
public:
    int num, den, n;
    DATA(int a, int b, int c) : num(a), den(b), n(c){};
    bool operator < (const DATA &a) const
    {
        if(n==a.n)
        {
            return num<a.num;
        }
        return n<a.n;
    }
};
vector <DATA> ans;
void CHECK(int mask)
{
    int i, j, k, a=0, b, c, mask2;
    for(i=0; i<5; i++)
        a = (a*10)+v[i];
    for(i=2; i<80; i++)
    {
        b = i*a;
        if(b>99999) break;
        c = b;
        mask2=0;
        for(j=0; j<5; j++)
        {
            k = c%10;
            c/=10;
            if(mask&(1<<k) or mask2&(1<<k))
                break;
            mask2|=(1<<k);
        }
        if(j==5)
        {
            //deb(b, a, i);
            ans.pb(DATA(a, b, i));
        }
    }
    return;
}

void GO(int mask, int taken)
{
    if(taken==5)
    {
        CHECK(mask);
        return;
    }
    int i, j, k, l;
    for(i=0; i<10; i++)
    {
        if(!(mask&(1<<i)))
        {
            v.pb(i);
            GO(mask|(1<<i), taken+1);
            v.pop_back();
        }
    }
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k=0, l,  keis=0, a, b, c, d;
    GO(0, 0);
    l = ans.size();
    sort(all(ans));
    /*for(i=0; i<l; i++)
        deb(ans[i].num, ans[i].den, ans[i].n);
    */
    while(sf("%d", &a) and a)
    {
        if(k++) NL;
        b = 0;
        for(i=0; i<l; i++)
        {
            if(ans[i].n==a)
            {
                pf("%05d / %05d = %d\n", ans[i].den, ans[i].num, a);
                b++;
            }
        }
        if(!b)
            pf("There are no solutions for %d.\n", a);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


