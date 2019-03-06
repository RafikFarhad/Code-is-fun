/// Heil Hydra :P
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
bool flag[100];
int n, k;
bool prime[100];
vector <int> res;


void DO()
{
    if(res.size()==n)
    {
        if(prime[res[0]+res[n-1]]==0) return;
        for(int i=0; i<n; i++)
            if(i) cout << " " << res[i];
            else cout << res[i];
        cout << endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(flag[i]) continue;
        int j = res.size();
        if(prime[res[j-1]+i]==0) continue;
        flag[i] = 1;
        res.pb(i);
        DO();
        flag[i] = 0;
        res.pop_back();
        //while(line[i]==line[i+1]) i++;
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int keis = 0;
    prime[2] = prime[3] = prime[2] = prime[5] = prime[7] = prime[11] = prime[13] = prime[17] = prime[19] = prime[23] = prime[29] = prime[31] = 1;
    while(sf("%d", &n)!=EOF)
    {
        CLR(flag);
        res.clear();
        if(keis) cout << endl;
        pf("Case %d:\n", ++keis);
        res.pb(1);
        flag[1] = 1;
        DO();
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
