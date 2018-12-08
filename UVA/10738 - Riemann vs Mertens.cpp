
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
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
vector <int> prime;
int s, *mu, *m;;
bool p[SIZE];

void SEIEVE()
{
    long long i, j, lim = sqrt(SIZE) + 1;
    for(i=2; i<=lim ; i++)
    {
        if(p[i]==0)
        {
            mu[i] = 1;
            for(j=2; i*j<SIZE; j++)
            {
                p[i*j] = 1;
                if(j&1) mu[i*j] = -1;
                else
                    mu[i*j] = 0;
            }
        }
    }
//    for(i=2; i<100; i++)
//        if(p[i]==0)
//           cout << i << endl;
//    s = prime.size();
    return;
}

int MU(int n)
{
    int i, j, fact=0;
    for(i=0; i<s and n>1; i++)
    {
        if(n%prime[i]==0)
        {
            fact++;
            n/=prime[i];
            if(n%prime[i]==0)
            {
                return 0;
            }
        }
    }
    if(fact&1) return -1;
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j;
    mu = new int[1000006];
    m = new int[1000006];
    SEIEVE();

    mu[1] = m[1] = 1;
    for(i=2; i<1000001; i++)
    {
        //mu[i] = MU(i);
        m[i] = mu[i]+m[i-1];
    }

    for(i=1; i<20; i++)
        deb(i, mu[i], m[i]);

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

