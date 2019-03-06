/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define NL printf("\n")
#define PI 2*acos(0)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt", "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
long long unsigned int SIZE = 2147483647;
bool res[1000006], p[47000];
int prime[5000], p_s;
void SEIEVE()
{
    p_s = 0;
    long long unsigned i, j, k =sqrt(SIZE);
    for(i=2; i<=k; i++)
    {
        if(!p[i])
        {
            prime[p_s++] = i;
            for(j=i*i; j<k; j+=i)
                p[j] = 1;
        }
    }
//    deb(p_s);
//    for(i=0; i<15; i++)
//        deb(prime[i]);
}

void SEGMENT(long long unsigned lo, long long unsigned hi)
{
    long long unsigned i, j, k = sqrt(hi);
    //deb(k);
    for(i=0; i<p_s && prime[i]<=k; i++)
    {
        if(lo<10) j = 2;
        else j =  lo/prime[i];
        if(j==1) j++;
        //deb(j); PPP;
        for( ; prime[i]*j <= hi ; j++)
            if(prime[i]*j>=lo)
                res[prime[i]*j-lo] = 1;
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
   READ;
    WRITE;
#endif
    ///                                    MAIN
    SEIEVE();
    long long unsigned hi, lo, i, j, k, a, b, c, d;
    vector <int> v;
    while(sf("%llu %llu", &lo, &hi)!=EOF)
    {
        CLR(res);
        v.clear();
        a =1; b = 1<<30; c = 0; d = 0;
        if(lo<2) lo=2;
        SEGMENT(lo, hi);
        for(i=lo; i<=hi; i++)
        {
            if(!res[i-lo])
                v.pb(i);
        }
        k = v.size(); //deb("====",k);
        for(i=0; i<k-1 && k; i++)
        {
            //deb(v[i]);
            if(v[i+1]-v[i]<b-a)
            {
                b = v[i+1];
                a = v[i];
            }
            if(v[i+1]-v[i]>d-c)
            {
                d = v[i+1];
                c = v[i];
            }
        }
        if(k<2) pf("There are no adjacent primes.\n");
        else pf("%llu,%llu are closest, %llu,%llu are most distant.\n", a, b, c, d);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
