/// In the name of Almighty Allah
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/** Algorithm  :  NONE                    */
/*****************************************/
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
///def
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define MAX3(a, b, c)                       MAX(a , MAX(b,c))
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)
#define READ                                   freopen("input.txt","r",stdin);
#define WRITE                                 freopen("output.txt", "w", stdout);
///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;} template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif
    ///                                    MAIN
    int i, j, ar[51][51], k, hi, now, t, keis=0,p;
    char li[100];
    takei(t);
    getchar();
    while(t--)
    {
        gets(li);
        if(keis) NL;
        k = strlen(li);
        CLR(ar);
        for(i=now=hi=0; i<k; i++)
        {
            if(li[i]=='R')
            {
                ar[i][now] = 1;
                now++;
            }
            else if(li[i]=='C')
                ar[i][now] = 2;
            else
            {
                now--;
                ar[i][now] = 3;
            }
            hi = max(now, hi);
        }
        vector <pair <int, int> > v[52];
        pf("Case #%d:\n", ++keis);
        for(i=hi; i>=0; i--)
        {
            for(j=0; j<k; j++)
            {
                if(ar[j][i]!=0)
                {
                    v[i].pb({j, ar[j][i]});
                }
            }
            pf("| ");
            for(j=p=0; p<v[i].size();j++)
            {
                if(j==v[i][p].first)
                {
                    p++;
                    hi = v[i][p-1].second;
                    if(hi==1)
                        pf("/");
                    else if(hi==2)
                        pf("_");
                    else
                        pf("\\");
                }
                else
                {
                    pf(" ");
                }
            }
            NL;
        }
        k++;
        k++;
        pf("+");
        while(k--)
            pf("-");
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

