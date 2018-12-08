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
#define SIZE 100
int n, indegree[SIZE], mark, mat[SIZE][SIZE];
string ans, v;
vector <string> allo;
bool flag[SIZE];

bool CHECK(int p)
{
    for(int i=0; i<n; i++)
    {
        if(mat[p][i]==1)
        {
            if(flag[i])
                return false;
        }
    }
    return true;
}

void DFS(int x)
{
    if(x==n)
    {
        allo.pb(ans);
        return;
    }
    for(int i=0; i<v.size(); i++)
    {
        if(!flag[i] and CHECK(i))
        {
            flag[i] = 1;
            ans+=" ";
            ans+=v[i];
            DFS(x+1);
            ans.pop_back();
            ans.pop_back();
            flag[i] = 0;
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
    char st[10000];
    takei(t);
    //getchar();
    map <char, int> mp;
    while(t--)
    {
        getchar();
        getchar();
        sf("%[^\n]", st);
        n = 0;
        mp.clear();
        l = strlen(st);
        v = "";
        for(i=0; i<l; i++)
        {
            if(isupper(st[i]))
            {
                mp[st[i]] = n++;
                v.pb(st[i]);
            }
        }
        CLR(mat);
        CLR(flag);
        getchar();
        sf("%[^\n]", st);
        l = strlen(st);

        for(i=0; i<l; i+=4)
        {
            mat[mp[st[i]]][mp[st[i+2]]] = 1;
        }
        allo.clear();
        ans = "";
        DFS(0);
        sort(all(allo));
        if(allo.size()==0)
        {
            puts("NO");
            continue;
        }
        for(i=0; i<allo.size(); i++)
        {
            cout << allo[i].substr(1) << endl;
        }

        if(t) NL;

    }
            /* Coding is FUN  */

    ///                                    ENDD
    return 0;
}


