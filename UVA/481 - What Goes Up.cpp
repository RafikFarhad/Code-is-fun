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
vector <int> ar;
int n=0, hi, mem[100000], dir[100000];

int LIS(int x)
{
    if(mem[x]!=-1) return mem[x];
    int i, maxi = 0;
    for(i=x-1; i>=0; i--)
    {
        if(ar[i]<ar[x])
        {
            if(LIS(i)>maxi)
            {
                maxi = LIS(i);
//                deb(i, x);
                dir[x] = i;
            }
        }
    }
    mem[x] = ++maxi;
    return maxi;
}

void PRINT(int a)
{
//    deb(a, dir[a]);
    if(dir[a]==-1) return;
    PRINT(dir[a]);
    pf("%d\n", ar[dir[a]]);
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
    int t, i, j;
    while(scanf("%d", &j)!=EOF)
    {
        n++;
        ar.pb(j);
    }
    CLR1(mem);
    CLR1(dir);
    for(i=hi=0; i<n; i++)
    {
        if(LIS(i)>=hi)
        {
            hi = LIS(i);
            j = i;
        }
    }
    pf("%d\n", hi);
    if(hi)
    {
        pf("-\n");
        PRINT(j);
        pf("%d\n", ar[j]);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
