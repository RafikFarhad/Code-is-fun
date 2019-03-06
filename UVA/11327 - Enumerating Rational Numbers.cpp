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
#define all(o)                                      o.begin(), o.end()

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 200005
long long phi[SIZE+5];

void PHI()
{
    long long i, j, k;
    for(i=0; i<SIZE; i++)
        phi[i]=i;
    phi[0] = 1;
    phi[1] = 2;
    for(i=2; i<SIZE; i++)
    {
        if(phi[i]==i)
        {
            for(j=i; j<SIZE; j+=i)
                phi[j]-=(phi[j]/i);
        }
        phi[i] += phi[i-1];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long n ,i, j, k, l, t, keis=0;

    PHI();
    //deb(phi[2], phi[3], phi[4]);
    while(sf("%lld", &n)==1 and n)
    {
        i=0;
        if(n==1)
        {
            pf("0/1\n");
            continue;
        }
        while(phi[i]<n) i++;
        i--;
        k = 0;
        //deb("**", n, phi[i]);
        for(j=1; ; j++)
        {
//            if(j==i+1)
//            {
//                i = i+1;
//                j = 1;
//            }
            if(__gcd(j, i+1)==1) k++;
            if(k+phi[i]==n) break;
        }
        //deb(j, i+1);
        pf("%lld/%lld\n", j, i+1);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

