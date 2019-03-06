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
#define PI 2*acos(0)
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
int n, capa, l[25], mem[25][SIZE], dir[25][SIZE], total; bool use[SIZE];
int DO(int start, int take);
void GO(int start, int take);
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k;
    while(sf("%d", &capa)!=EOF)
    {
        takei(n);
        for(i=0; i<n; i++)
            takei(l[i]);
        CLR1(mem);
        CLR1(dir);
        CLR(use);
        total = 0;
        j = DO(0, 0);
        GO(0,0);
        for(i=0; i<n; i++)
            if(use[i])
                pf("%d ", l[i]);
        pf("sum:%d\n", j);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
int DO(int start, int take)
{
    if(start==n) return 0;
    if(mem[start][take]!=-1) return mem[start][take];
    int p1=0, p2=0;
    if(l[start]+take<=capa)
        p1 = l[start] + DO(start+1, l[start]+take);
    p2 = DO(start+1, take);
    if(p1>p2)
    {
        dir[start][take] = 1;
        mem[start][take] = p1;
        return p1;
    }
    dir[start][take] = 2;
    mem[start][take] = p2;
    return p2;
}

void GO(int start, int take)
{
    if(dir[start][take]==-1) return;
    if(dir[start][take] == 1)
    {
        total++;
        use[start] = 1;
        GO(start+1, l[start]+take);
        return;
    }
    GO(start+1, take);
    return;
}
