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
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
string c;
char a[105], b[105];
int l1, l2;
map <pair <int, int> , string> mp;

bool COMPA(string a, string b)
{
    if(a.size()==b.size())
    {
        return a<b;
    }
    return (int)a.size() > (int)b.size();
}

string LCS(int x, int y)
{
    if(x==l1 or y==l2) return "";
    //int &ret = mem[x][y];
    pair <int, int> pi = make_pair(x, y);
    if(mp.count(pi)) return mp[pi];
    string ci = "";
    if(a[x]==b[y])
    {
        ci = a[x] + LCS(x+1, y+1);
    }
    else
    {
        string p = LCS(x+1, y);
        string q = LCS(x, y+1);
        //deb("**", p, q, max(p, q));
        if(COMPA(p, q))
            ci = p;
        else
            ci = q;
    }
    //ret = ans;
    mp[pi] = ci;
    return ci;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, keis=0;
    takei(t);
    while(t--)
    {
        getchar();
        scanf("%s %s", a, b);
        l1 = strlen(a);
        l2 = strlen(b);
        mp.clear();
        c = LCS(0,0);
        //deb("c = ", c);
        if(c.size()==0) pf("Case %d: :(\n", ++keis);
        else pf("Case %d: %s\n", ++keis, c.c_str());

    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


