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
//#define mp                                      make_pair
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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
class DATA
{
public:
    string p;
    DATA()
    {
        p = "";
    }
    DATA(char c)
    {
        p = "111110111100 110000100000";
    }
    bool operator == (const DATA &pp)
    {
        if(p!=pp.p) return false;
        return true;
    }
};

DATA my, src;
map <string, int> mp;
string p = "111110111100 110000100000";;
int BFS(string aa)
{
    string u, v;
    int i, j, k, x, y, dx, dy;
    queue <string> qu;
    qu.push(aa);
    mp[aa] = 1;
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        for(k=0; k<25; k++)
            if(u[k]==' ')
                break;
        x = k/5;
        y = k%5;
        for(i=0; i<8; i++)
        {
            dx = x + kx[i];
            dy = y + ky[i];
            if(dx<0 or dy<0 or dx>=5 or dy>=5) continue;
            v = u;
            j = dx*5+dy;
            v[k] = v[j];
            v[j] = ' ';
            if(mp.count(v)) continue;
            mp[v] = mp[u] + 1;
            if(v==p) return mp[v];
            if(mp[v]==11) ;
            else qu.push(v);
        }
    }
    return -1;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif//Solvable in 7 move(s).
    ///                                    MAIN
    int i, t, j, k, l,  keis=0, a, b, c, d, x, y;
    string aa, bb;
    //my = DATA('c');

    takei(t);
    getchar();
    while(t--)
    {
        //src = DATA();
        mp.clear();
        aa = "";
        getline(cin, aa);
        for(i=1; i<5; i++)
        {
            getline(cin, bb);
            aa+=bb.substr(0,5);
        }
        //deb(aa);
        if(aa==p) k = 1;
        else k = BFS(aa);
        if(k==-1)
            pf("Unsolvable in less than 11 move(s).\n");
        else pf("Solvable in %d move(s).\n", k-1);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}



