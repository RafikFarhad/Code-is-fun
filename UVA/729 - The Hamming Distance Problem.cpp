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
int n, h, zero, ar[20];
bool flag[20];
string res;
map <string, bool> mp;
void BT(int start);
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    WRITE("output.txt");
#endif
    ///                                    MAIN
    int i, j, t, k =0;
    takei(t);
    while(t--)
    {
        if(k++) pf("\n");
        sf("%d %d", &n, &h);
        zero = n-h;
        i = zero;
        j = 0;
        while(i--)
            ar[j++] = 0;
        i = h;
        while(i--)
            ar[j++] = 1;
        CLR(flag);
        //res = "";
        mp.clear();
        //res += ar[0]  + '0';
        flag[0] = 1;
        BT(1);
        i = h;
        j = 0;
        while(i--)
            ar[j++] = 1;
        i = n-h;
        while(i--)
            ar[j++] = 0;
         CLR(flag);
        res = "";
        //mp.clear();
        //res += ar[0]  + '0';
        //flag[0] = 1;
        BT(1);
        map <string, bool> :: iterator it;
        for(it=mp.begin(); it!=mp.end(); it++)
            cout << it->first << endl;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

void BT(int start)
{
    //deb(res.size());
    if(res.size()==n)
    {
        if(mp[res]) return;
        mp[res] = 1;
        //cout << res;
        //pf("\n");
        return;
    }
    for(int i=0;i<n; i++)
    {
        if(flag[i]) continue;
        flag[i] = 1;
        res += ar[i]+'0';
        BT(i);
        flag[i] = 0;
        //deb(res);
        res.erase(res.size()-1);
        //deb(res);
    }
    return;
}
