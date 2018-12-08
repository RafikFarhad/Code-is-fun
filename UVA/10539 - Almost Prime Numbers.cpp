
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
#define takellu(a)                               scanf("%llu", &a)
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
bool *prime;
vector <int> v;

void SEIEVE()
{
    prime = new bool[SIZE];
    long long unsigned i, j, lim = sqrt(SIZE) + 1;
    for(i=2; i<=lim ; i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<SIZE; j+=i)
            {
                prime[j] = 1;
            }
        }
    }
    for(i=2; i<1000000; i++)
        if(prime[i]==0)
            v.pb(i);
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long unsigned i, n, j, k, l, m;
    vector <long long unsigned> almost;
    SEIEVE();
    l = v.size();
    for(i=0; i<l; i++)
    {
        j = v[i];
        k = j*j;
        while(k<1000000000000)
        {
            almost.pb(k);
            k*=j;
        }
    }
//    deb(almost.size());
    sort(almost.begin(), almost.end());
    l = almost.size();
    takellu(i);
    while(i--)
    {
        takellu(j);
        takellu(k);
        n = 0;
        while(almost[n]<j) n++;
        for(m=0; n<l; n++)
        {
            if(almost[n]> k) break;
            m++;
        }
        cout << m << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

