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
#define SIZE 100005
int ar[25], n, br[25], mem[25];

int LIS(int x)
{
    if(mem[x]!=-1) return mem[x];
    int maxi = 0, i;
    for(i=x+1; i<n; i++)
    {
        if(br[i]>br[x])
        {
            if(LIS(i)>maxi)
                maxi = LIS(i);
        }
    }
    mem[x] = ++maxi;
    return maxi;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int t, keis=0, i, j;
    takei(n);
    for(i=0; i<n; i++)
    {
        takei(j);
        ar[i] = j;
    }
//    deb(ar[2]); return 0;
    while(sf("%d", &j)!=EOF)
    {
        br[j-1] = ar[0];
        for(i=1; i<n; i++)
        {
            takei(j);
            br[j-1] = ar[i];
//            deb(br[j-1]);
        }
//       for(i=0; i<n; i++) pf("%d ", br[i]); NL;
        for(i=j=0; i<n; i++)
        {
            CLR1(mem);
            //deb(i, LIS(i));
            if(LIS(i)>j)
            {
                j = LIS(i);
                t = i;
            }
        }
        pf("%d\n",  j);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
