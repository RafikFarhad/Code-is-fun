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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%lld", &a)
#define takellu(a)                               scanf("%llu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()
#define csi                                         pf("Case %d: ", ++keis)
#define csll                                         pf("Case %lld: ", ++keis)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
typedef long long unsigned llu;
string a, b;
long long unsigned lcs,dp[35][35], ddp[75][35][35], len1, len2, length;

llu LCS(llu i, llu j)
{
    if(i==len1 or j==len2)
    {
        return 0;
    }
    if(dp[i][j]!=-1) return dp[i][j];

    if(a[i]==b[j])
    {
        return dp[i][j] = 1 + LCS(i+1, j+1);
    }
    return dp[i][j] = max(LCS(i+1,j), LCS(i, j+1));
}

llu FIND_STRING_NUMBER(llu l, llu p, llu q)
{
    if(l==0)
    {
        if(p==len1 and q==len2)
            return 1;
        return 0;
    }
    if(ddp[l][p][q]!=-1) return ddp[l][p][q];
    if(p==len1)
        return ddp[l][p][q]=FIND_STRING_NUMBER(l-1, p, q+1);
    if(q==len2)
        return ddp[l][p][q]=FIND_STRING_NUMBER(l-1, p+1, q);
    if(a[p]==b[q])
        return ddp[l][p][q]=FIND_STRING_NUMBER(l-1, p+1, q+1);
    return ddp[l][p][q]= (FIND_STRING_NUMBER(l-1, p+1, q) + FIND_STRING_NUMBER(l-1, p, q+1));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long unsigned i, j, k, l, t;
    int keis=0;
    takell(t);
    getchar();
    while(t--)
    {
        cin >> a >> b;
        len1 = a.size();
        len2 = b.size();
        CLR1(dp);
        CLR1(ddp);
        lcs = LCS(0,0);
        length = len1+len2-lcs;
        csi;
        //deb(lcs);
        pf("%llu ", length);

        lcs = FIND_STRING_NUMBER(length, 0,0);
        pf("%llu\n", lcs);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


