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
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
#define SIZE 10000005
vector <int> all_prime;
int pp[] = {1,3,7,9};
void GO(int pos, int mask, int sixe);
bool IS_PRIME(int a)
{
    for(int i=2; i<=sqrt(a); i++)
        if(a%i==0) return false;
    return true;
}
bool CHECK(int a);

int main()
{
    ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    for(i=2; i<8; i++)
        GO(0,0,i);
    all_prime.pb(2);
    all_prime.pb(3);
    all_prime.pb(5);
    all_prime.pb(7);
    //deb(all_prime.size());
    sort(all(all_prime));
    //for(i=0; i<all_prime.size()-1; i++)
        //if(all_prime[i]!=all_prime[i+1]) deb(all_prime[i]);


    //NL;/**/
    all_prime.pb(1<<29);
    while(1)
    {
        takei(a);
        if(!a) break;
        if(a>all_prime[all_prime.size()-1])
        {
            puts("0");
            continue;
        }
        b = pow(10, floor(log10(a)+1));
        //deb(b);
        k = 0;
        c = upper_bound(all(all_prime), a) - all_prime.begin();
        if(all_prime[c]==1<<29) ;
        else if(all_prime[c]<b)
            k = all_prime[c];
        pf("%d\n", k);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


bool CHECK(int a)
{
    vector <int> p;
    int i, j=0, k = a;
    while(k)
    {
        p.pb(k%10);
        k/=10;
        j++;
    }
    sort(all(p));
    do
    {
        k = 0;
        for(i=0; i<j; i++)
            k = (k*10)+p[i];
        if(!IS_PRIME(k))
            return false;
    }while(next_permutation(all(p)));
    return true;
}
void GO(int pos, int mask, int sixe)
{
    if(pos==sixe)
    {
        if(mask and CHECK(mask)) all_prime.pb(mask);
        return;
    }
    GO(pos+1, mask, sixe);
    for(int i=0; i<4; i++)
    {
        GO(pos+1, mask*10+pp[i], sixe);
    }
    return;
}



