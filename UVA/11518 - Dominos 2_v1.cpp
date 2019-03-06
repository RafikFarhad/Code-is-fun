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
int  cow, n;
vector <int> fall[10010];
bool flag[10010];

void DFS(int i)
{
    if(flag[i]) return;
    cow++;
    flag[i] = 1;
    for(int k=0; k<fall[i].size(); k++)
        DFS(fall[i][k]);
    return;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("11518.inp","r",stdin);
#endif
    ///                                    MAIN
    int t, m,  l, i, j, a, b;
    sf("%d", &t);
    while(t--)
    {
        CLR(fall);
        CLR(flag);
        sf("%d %d %d", &n, &m, &l);
        for(i=0; i<m; i++)
        {
            sf("%d %d", &a, &b);
            fall[a].pb(b);
        }
        int sum=0;
        for(i=0; i<l; i++)
        {
            sf("%d", &a);
            //CLR(flag);
            cow = 0;
            DFS(a); //MyDebug(cow, sum);
            sum+=cow;
        }
            cout << sum << endl;
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
