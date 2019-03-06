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
#define SIZE 1000006
bool *p;
vector <int> prime;
int ss;

void SEIEVE()
{
    long long i, j, l = sqrt(SIZE)+5;
    p = new bool[l+5];
    for(i=2; i<l; i++)
    {
        if(!p[i])
        {
            for(j=i*i; j<l; j+=i)
                p[j] = 1;
        }
    }
    prime.clear();
    for(i=2; i<l; i++)
        if(!p[i])
            prime.pb(i);
    ss = prime.size();
    //deb(l, ss, prime[ss-1]);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
 //   freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long n, t, ans, i, div, l;
    SEIEVE();
    while(sf("%lld", &n)==1 and n)
    {
        t = n;;
        div = 0;
        for(i=0; i<ss and t>1; i++)
        {
            if(t%prime[i]==0)
            {
                while(t%prime[i]==0)
                {
                    t/=prime[i];
                }
                div++;
                //deb(div, l, prime[i]);
            }
        }
        if(t>1)
        {
            div++;
        }
     //   deb(ans, div);
        pf("%lld : %lld\n", n, div);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

