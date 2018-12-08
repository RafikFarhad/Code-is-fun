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
#define SIZE INT_MAX

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    vector <int> v;
    int n, qu, i, mid, hi, lo, index1, index2, a, b;
    takei(n);
    i = n;
    while(i--)
    {
        takei(a);
        v.pb(a);
    }
    takei(qu);
//    deb(v.size());
    while(qu--)
    {
        takei(a);

        hi = n; lo = 0;
        while(hi>=lo)
        {
            mid = (hi+lo)>>1;
//            deb(mid+1);
            if(v[mid]>a)
            {
                hi = mid-1;
            }
            else if(v[mid]<a)
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        index1 = lo;
        hi = n; lo = 0;
        while(hi>=lo)
        {
            mid = (hi+lo)>>1;
//            deb(mid+1);
            if(v[mid]>a)
            {
                hi = mid-1;
            }
            else if(v[mid]<a)
            {
                lo = mid+1;
            }
            else
            {
                lo = mid+1;
            }
        }
        index2 = lo;
//        deb(index1, index2);
        if(index1) pf("%d ", v[index1-1]);
        else pf("X ");
        if(index2<=n-2)
        {
           pf("%d\n", v[index2]);
        }
        else if(index2<n)
        {
            if(v[index2]!=a)
                pf("%d\n", v[index2]);
            else pf("X\n");
        }
        else pf("X\n");
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
