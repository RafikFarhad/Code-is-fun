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
int n, depth[35], quan[35], capa, w, memory[35][1005], dir[35][1005];
vector <pair <int, int> > pa;

int COUNT(int d)
{
    return 3*d*w;
}

int DONE(int start, int take)
{
    if(start==n) return 0;
    //deb(start, take);
    if(memory[start][take] != -1) return memory[start][take];
    int p1 = 0, p2 = 0, d = COUNT(depth[start]);
    if(d + take <=capa)
        p1 = quan[start] + DONE(start+1, d + take);
    p2 = DONE(start+1, take);
    if(p1>p2)
    {
        dir[start][take] = 1;
        memory[start][take] = p1;
        return p1;
    }
    else
    {
        dir[start][take] = 2;
        memory[start][take] = p2;
        return p2;
    }

}
int GO_COUNTER(int start, int take)
{
    if(dir[start][take]==-1) return 0;
    if(dir[start][take]==1)
    {
        pa.pb(make_pair(depth[start], quan[start]));
        return 1 + GO_COUNTER(start+1, take+COUNT(depth[start]));
    }
    return GO_COUNTER(start+1, take);
    //return 0;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k;
    while(sf("%d %d", &capa, &w)!=EOF)
    {
        takei(n);
        for(i=0; i<n; i++)
        {
            takei(depth[i]);
            takei(quan[i]);
        }
        if(keis++) pf("\n");
        CLR1(memory);
        CLR1(dir);
        pa.clear();
        j = DONE(0,0);
        pf("%d\n", j);
        j = GO_COUNTER(0,0);
        pf("%d\n", j);
        for(i=0; i<j; i++)
            pf("%d %d\n", pa[i].first, pa[i].second);

    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
