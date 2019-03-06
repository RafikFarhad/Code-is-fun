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
#define _(o)                                    pf("%d", o)

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
vector <int> ans;
int x, y;
bool mark;
int dp[901][8105];
int dpp[901][8105];

void GO(int p, int q)
{
    if(!mark) return;

    if(p==0 and q==0)
    {
        mark = 0;
        sort(all(ans));
        for(int i=0; i<ans.size(); i++)
        {
          cout << ans[i];
        }
        NL;//deb(ans.size());
    }
    if(dp[p][q]==0)
    {
        return;
    }
    int m = dp[p][q];
    //deb(p, q, m);
    ans.pb(m);
    GO(p-m, q-m*m);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t;
    CLR(dp);
    for(i=0; i<901; i++)
    {
        for(j=0; j<8101; j++)
        {
            dpp[i][j] = 101;
        }
    }

    dpp[0][0] = 0;
    for(i=0; i<901; i++)
    {
        for(j=0; j<8101; j++)
        {
            for(k=1; k<10; k++)
            {
                x = i+k;
                y = j+k*k;
                if(x>900 or y>8100) continue;
                if(dpp[x][y]>dpp[i][j])
                {
                    dpp[x][y] = dpp[i][j]+1;
                    dp[x][y] = k;
                }
            }
        }
    }
    //deb(dp[1][2], dp[2][4], dp[2][2]);
    mark = 1;
    /*ans.clear();
    deb(dpp[900][8100]);
    deb(dp[900][8100]);
    GO(900, 8100);
    ok*/
    takei(t);
    while(t--)
    {
        takei(x);
        takei(y);
        if(x>900 or y>8100 or x>y or dpp[x][y]>100)
        {
            cout << "No solution\n";
            continue;
        }
        ans.clear();
        mark = true;
        GO(x, y);
        if(mark) cout << "No solution\n";
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

