/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
int ad[55][55], par[55];
class DATA
{
public:
    int u, v, w;
    DATA(int _u=0, int _v=0, int _w=0)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const DATA a) const
    {
        return a.w > w;
    }
};

void INIT(int node)
{
    for(int i=0; i<node; i++)
        par[i] = i;
    return;
}

 int CHECK_PARENTS(int k)
 {
     if(par[k]==k) return k;
     return par[k] = CHECK_PARENTS(par[k]);
 }

 void JOINT(int i, int j)
 {
     par[i] = j;
     return;
 }
 int MST(vector<DATA> p, int node)
 {
     int i, x, y, u, v, w, cost=0, s = p.size(), cow = 0;
     for(i=0; i<s; i++)
     {
         u = p[i].u;
         v = p[i].v;
         w = p[i].w;
         x = CHECK_PARENTS(u);
         y = CHECK_PARENTS(v);
         if(x!=y)
         {
             JOINT(x, y);
             cow++;
             cost += w;
             if(cow==node-1) return cost;
         }
     }
     return -55;
 }

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, l, m, node, cost;
    vector <DATA> v;
    map <string, int> mp;
    string a, b;
    takei(t);
    while(t--)
    {
        takei(m);
        mp.clear();
        v.clear();
        node = 0;
        memset(ad, -1, sizeof ad);
        for(i=0; i<m; i++)
        {
            cin >> a >> b >> cost;
            if(mp.find(a)==mp.end()) mp[a] = node++;
            if(mp.find(b) == mp.end()) mp[b] = node++;
            //deb(mp[a], mp[b]);
            ad[mp[a]][mp[b]] = ad[mp[a]][mp[b]]!=-1?MIN(cost, ad[mp[a]][mp[b]]):cost;
            ad[mp[b]][mp[a]] = ad[mp[b]][mp[a]]!=-1?MIN(cost, ad[mp[b]][mp[a]]):cost;
        }
        INIT(node);
        for(i=0; i<node; i++)
            for(j=i+1; j<node; j++)
                if(ad[i][j]!=-1)
                    v.pb(DATA(i, j, ad[i][j]));

        sort(v.begin(), v.end());
        k = MST(v, node);
        if(k<0) pf("Case %d: Impossible\n", ++keis);
        else pf("Case %d: %d\n",++keis, k);
        /*for(i=0; i<v.size(); i++)
            deb(v[i].w);

        cout << endl << endl;
        /*cout << " node " << node << endl;
        for(i=0; i<node; i++, cout << endl)
            for(j=0; j<node; j++)
                cout << ad[i][j] << "      ";*/
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

