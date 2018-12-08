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

string mat[600];
int leftt[600][600], up[600][600], h, w;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, q, l, t, keis=0, r1, c1, r2, c2;
    while(cin >> h >> w)
    {
        getchar();
        for(i=0; i<h; i++)
            cin >> (mat[i]);
        ////CLR(leftt);
       // CLR(up);
        for(i=0; i<h; i++)
        {
            t = 0;
            //if(mat[i][0]=='.')
              //  leftt[i][0] = ++t;
            for(j=0; j<w-1; j++)
            {
                if(mat[i][j]=='.' and mat[i][j+1]=='.')
                {
                    leftt[i][j] = ++t;
                }
                else if(mat[i][j]=='#' and mat[i][j+1]=='.')
                {
                    leftt[i][j] = t;
                }
                else if(mat[i][j]=='.' and mat[i][j+1]=='#')
                {
                    leftt[i][j] = t;
                }
                else if(mat[i][j]=='#' and mat[i][j+1]=='#')
                {
                    leftt[i][j] = t;
                }
            }
            leftt[i][j] = t;
            /*for(j=0; j<w; j++)
                cout << leftt[i][j] << " ";
            NL;*/
        }

        for(j=0; j<w; j++)
        {
            t = 0;
            //if(mat[i][0]=='.')
              //  leftt[i][0] = ++t;
            for(i=0; i<h-1; i++)
            {
                if(mat[i][j]=='.' and mat[i+1][j]=='.')
                {
                    up[i][j] = ++t;
                }
                else if(mat[i][j]=='#' and mat[i+1][j]=='.')
                {
                    up[i][j] = t;
                }
                else if(mat[i][j]=='.' and mat[i+1][j]=='#')
                {
                    up[i][j] = t;
                }
                else if(mat[i][j]=='#' and mat[i+1][j]=='#')
                {
                    up[i][j] = t;
                }
            }
            up[i][j] = t;
            /*for(i=0; i<h; i++)
                cout << up[i][j] << " ";
            NL;/**/
        }
        takei(q);
        while(q--)
        {
            takei(r1);
            takei(c1);
            takei(r2);
            takei(c2);
            r1--;
            r2--;
            c1--;
            c2--;

            t = 0;
            for(i=r1; i<=r2; i++)
            {
                //deb(i, c2, i, c1);
                t+=( leftt[i][c2-1] - (c1>0?leftt[i][c1-1]:0));
                //deb(t);
            }
            for(j=c1; j<=c2; j++)
            {
               // deb(r2, j, r1, j);
                t+=(up[r2-1][j] - (r1>0?up[r1-1][j]:0));
                //deb(t);
            }
            _(t); NL;
        }

    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

