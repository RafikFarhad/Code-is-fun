/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11060.inp","r",stdin);
    //freopen("out.txt", "w", stdout);
#endif
    ///                                    MAIN
    int n, m, i, j, k, u,va, keis=0;
    string a, b;
    map <string, int> mp;
    map <int, string> mp2;
    while(sf("%d", &n)!=EOF)
    {
        //cout << n << endl;
        bool flag[101] = {0};
        int indegree[101] = {0};
        vector<int> v[101];
        memset(flag, false, sizeof(flag));
        memset(indegree, 0, sizeof(indegree));
        mp.clear(); mp2.clear();
        for(i=0; i<n; i++) v[i].clear();
        for(i=0; i<n; i++)
        {
            cin >> a;
            mp[a] = i;
            mp2[i] = a;
        }
        sf("%d", &m);
        for(i=0; i<m; i++)
        {
            cin >> a >> b;
            //MyDebug(u, va);
            v[mp[a]].push_back(mp[b]);
            indegree[mp[b]]++;
        }
        //for(j=1; j<=n; j++) pf("in %d -> %d\n", j, indegree[j] );
        //bool t = false;
        //cout << mp2[0] <<".\n\n"; cout << n << endl;
       // if(n==1){pf("Case #%d: Dilbert should drink beverages in this order: ", ++keis); cout << mp2[0] <<".\n\n";continue;}
        pf("Case #%d: Dilbert should drink beverages in this order:", ++keis);
        for(k=0; k<n; k++)
        {
            for(i=0; i<n; i++)
            {
                if(indegree[i]==0 && flag[i]==0)
                {
                    flag[i] = 1;
                    cout << " " << mp2[i];
                    for(j=0; j<v[i].size(); j++)
                    {
                        indegree[v[i][j]]--;
                    }
                    break;
                }
            }
        }
        pf(".\n\n");
        getchar();
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
