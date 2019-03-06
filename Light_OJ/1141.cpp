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
#define CLR(o) memset(o, 0x00, sizeof o)
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
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << ", " << q << ", " << r << ", " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
const int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37};
int s, t;

vector <int> GET(int s)
{
    vector <int> v;
    v.clear();
    int i, j=s;
    for(i=0; i<12 && s!=1 && prime[i]<s; i++)
        if(s%prime[i]==0)
        {
            //deb(s, 1,1,1);
            v.push_back(prime[i]);
            while(s%prime[i]==0)
                s/=prime[i];
        }
    if(s>1) v.pb(s);
    //deb(j, v.size(), v[0], 2);
    if(!v.size() || j==v[v.size()-1]) v.clear();
    //for(i=0; i<v.size(); i++) cout << v[i] <<"\t";
    return v;
}

int BFS(int s, int t)
{
    if(s==t) return 0;
    if(s>t) return -1;
    //deb(s, t,0,0);
    bool flag[1005];
    CLR(flag);
    int cow = 0, i, j, k, l;
    queue <pair <int, int> > qu;
    pair <int, int> temp;
    vector <int> v;
    qu.push(make_pair(s, 0));
    //deb(qu.size(),0,0,0);
    while(qu.size())
    {
        temp = qu.front();
        k = temp.first;
        l = temp.second;
        v = GET(k);
       // deb(k, l, v.size(), t);
        for(j=0; j<v.size(); j++)
            if(k+v[j] < t && !flag[k+v[j]])
            {
                qu.push(make_pair(k+v[j], l+1));
                flag[k+v[j]]= 1;
            }
            else if(k+v[j]==t) return l+1;
        qu.pop();
    }
    return -1;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int tt, keis=0;
    takei(tt);
    while(tt--)
    {
        takei(s);
        takei(t);
        pf("Case %d: %d\n", ++keis, BFS(s, t));
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

