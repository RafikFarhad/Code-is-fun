#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
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
#define xx                                      first
#define yy                                      second

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
#define SIZE INT_MAX
map <string, int> dick[18];
vector <string> mat[18], word;
vector <int> v[100000];
int super,  path[100005], level[100005];

void PRINT(int a)
{
    if(a==path[a])
    {
        pf("%s\n", word[a].c_str());
        return;
    }
    PRINT(path[a]);
    pf("%s\n", word[a].c_str());
    return;
}

bool CHECK(string a, string b, int l)
{
    int i, j;
    for(i=0, j=0; i<l and j<2; i++)
    {
        if(a[i]!=b[i])
            j++;
    }
    if(j==1) return true;
    return false;
}

void PRE_CALC()
{
    int i, j, k, a, b;
    for(i=1; i<18; i++)
    {
        for(j=mat[i].size()-1; j>=0; j--)
        {
            for(k = j-1; k>=0; k--)
            {
                if(CHECK(mat[i][j], mat[i][k], i))
                {
                    a = dick[i][mat[i][j]];
                    b = dick[i][mat[i][k]];
                    v[a].pb(b);
                    v[b].pb(a);
                }
            }
        }
    }
    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    string aa, bb;
    int n = 0;
    queue <int> qu;
    while(getline(cin, aa) and aa.size())
    {
        l = aa.size();
        mat[l].pb(aa);
        dick[l][aa] = n++;
        word.pb(aa);
    }
    PRE_CALC();
    while(cin >> aa >> bb)
    {
        super = aa.size();
        if(keis++) NL;
        if(aa.size()!=bb.size() or dick[super].count(aa)==0 or dick[(int)bb.size()].count(bb)==0)
        {
            pf("No solution.\n");
            continue;
        }
        a = dick[super][aa];
        b = dick[super][bb];
        CLR1(level);
        CLR(path);
        while(qu.size()) qu.pop();
        qu.push(a);
        path[a] = a;
        level[a] = 0;
        x = 0;
        while(qu.size() and !x)
        {
            c = qu.front();
            qu.pop();
            for(i=0; i<v[c].size() and !x;  i++)
            {
                d = v[c][i];
                if(level[d]!=-1) continue;
                level[d] = level[c] + 1;
                path[d] = c;
                if(d==b) x = 1;
                qu.push(d);
            }
        }
        if(level[b]==-1)
        {
            pf("No solution.\n");
            continue;
        }
        PRINT(b);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



