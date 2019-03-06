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
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int xx[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy[] = {0, -1, 1, 0, -1, 1, 1, -1};   // diagonal -> 8 horizontal/vertical->4
vector <int> v[1005];
bool flag[1005];
int level[1005];

void BFS()
{
    int i, u, va;
    queue <int> qu;
    while(qu.size()) qu.pop();
    qu.push(0);
    flag[0] = 1;
    level[0] = 0;
    while(qu.size())
    {
        u = qu.front(); qu.pop();
        for(i=0; i<v[u].size(); i++)
        {
            va = v[u][i];
            if(!flag[va])
            {
                flag[va] = 1;
                level[va] = level[u]+1;
                qu.push(va);
            }
        }
    }
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10959.inp","r",stdin);
#endif
    ///                                    MAIN
    int i, j, k, l, n, m, t;
    sf("%d", &t);
    while(t--)
    {
        //sf("\n");
        sf("%d %d", &n, &m);
        for(i=0; i<n; i++)
        {
            v[i].clear();
            flag[i] = 0;
        }

        for(i=0; i<m; i++)
        {
            sf("%d %d", &k, &l);
            v[k].push_back(l);
            v[l].push_back(k);
        }
        BFS();
        for(i=1; i<n; i++)
        {
            cout << level[i] << endl;
        }
        if(t) pf("\n");
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
