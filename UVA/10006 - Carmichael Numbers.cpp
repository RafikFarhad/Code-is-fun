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
#include <bitset>
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

int BIGMOD(int b, int p, int mod)
{
    if(p==1) return b%mod;
    int r = (BIGMOD(b, p>>1, mod) * BIGMOD(b, p>>1, mod))%mod;
    if(p&1) r = ((r%mod)*b)%mod;
    return r;
}
int p[66000];
void SEIEVE()
{
    int i, j, l = sqrt(66000) + 1;
    for(i=2; i<=l; i++)
    {
        if(p[i]==0)
        {
            for(j=i*i; j<65500; j+=i)
                p[j] = 1;
        }
    }
    p[1] = 1;
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0, n;
//    SEIEVE();
    while(sf("%d", &n) and n)
    {
        //deb(n);
        if(n==561||n==1105||n==1729||n==2465||n==2821||n==6601||n==8911||n==10585||n==15841||n==29341||n==41041||n==46657||n==52633||n==62745||n==63973)
        {
            pf("The number %d is a Carmichael number.\n", n);
            continue;
        }
//        for(i=2; i<n; i++)
//        {
//            //deb(BIGMOD(i, n, n), i);
//            if(BIGMOD(i, n, n) !=i )
//                break;
//        }
//        if(i==n)
//            pf("The number %d is a Carmichael number.\n", n);
        else
            pf("%d is normal.\n", n);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

