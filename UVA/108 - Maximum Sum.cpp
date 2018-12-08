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
template <class T1> void PP(T1 p) { cout << " " << p <<" ";}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int n;

int GET_MAX_FROM_ARRAY(vector <int> v)
{
    int i, j, buck=0, tank=0, l = v.size();
    for(i=0; i<l; i++)
    {
        //deb(v[i]);
        buck =  buck+v[i];
        if(buck<0)
            buck = 0;
        if(buck>tank)
            tank = buck;
//        deb(tank, 0);
    }
    return tank;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int i, j, k, l, m, a;
    vector <int> v;
    takei(n);
    int mat[n+5][n+5], sum[n+5][n+5];
    CLR(mat);
    CLR(sum);
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
            takei(mat[i][j]);
//    for(j=0; j<n; j++)
//        sum[0][j] = mat[0][j];
    for(i=1; i<=n; i++)
    {
        for(j=0; j<n; j++)
            sum[i][j] = mat[i-1][j] + sum[i-1][j];
    }
    m = a = 0;
    for(i=0; i<n; i++)
    {
        for(j=i; j<n; j++)
         {
             v.clear();
             for(k=0; k<n; k++)
             {
                 v.pb(sum[j+1][k]-sum[i][k]);
//                 PP(v.back());
             }
             a = GET_MAX_FROM_ARRAY(v);
             m = max(m, a);
//             deb(a);
         }
    }
    pf("%d\n", m);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
