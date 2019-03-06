
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

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int man[25][4], mem[25][5], n;

int DO(int now, int cl, int tot)
{
    //deb(now, cl, tot);
    if(now==n)
        return tot;
    int &rent = mem[now][cl];
    if(rent !=-1)
    {
        return rent;
    }

    int i, j, k = 1<<30;

    for(i=0; i<3; i++)
    {
        if(cl==i ) continue;
        k = min(k, DO(now+1, i, tot) + man[now][cl]);
    }
    rent = k;
    return k;
}


int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, keis =0, ans;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            takei(man[i][0]);
            takei(man[i][1]);
            takei(man[i][2]);
        }
        CLR1(mem);
        ans = DO(0,0,0);
        ans = min(ans, DO(0,1,0));
        ans = min(ans, DO(0,2,0));
//        deb(mem[0][0], mem[0][1],mem[0][2] );
        pf("Case %d: %d\n", ++keis, ans);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

