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
    freopen("10305.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, m, i, j, k, u,va;
    vector<int> v[101];
    int indegree[101];
    bool flag[101];
    while(sf("%d %d", &n, &m)==2 && n+m)
    {
        bool flag[101] = {0};
        int indegree[101] = {0};
        vector<int> v[101];
        for(i=0; i<m; i++)
        {
            sf("%d %d", &u, &va);
            //MyDebug(u, va);
            v[u].push_back(va);
            indegree[va]++;
        }
        //for(j=1; j<=n; j++) pf("in %d -> %d\n", j, indegree[j] );
        bool t = false;
        for(k=0; k<n; k++)
        {
            for(i=1; i<=n; i++)
            {
                if(indegree[i]==0 && flag[i]==0)
                {
                    flag[i] = 1;
                    if(t) pf(" "); t = true;
                    pf("%d", i);
                    for(j=0; j<v[i].size(); j++)
                        {
                            //MyDebug(i, j, v[i][j]);
                            indegree[v[i][j]]--;
                        }
                    break;
                }
            }
        }
        cout << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
