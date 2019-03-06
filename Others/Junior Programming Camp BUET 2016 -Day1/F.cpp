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
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csll                                    pf("Case %lld: ", ++keis)
#define _(o)                                    pf("%d", o)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
vector<int>  in, out;
bool mark;
int n, ar[1005][5];

bool IS_STACK()
{
    stack <int> st;
    int i, j=0, k=0;
    for(i=0; i<n and j<out.size(); i++)
    {
        //deb(ar[i][0], ar[i][1]);
        if(ar[i][0]==1)
            st.push(ar[i][1]);
        else
        {
            if(st.empty())
            {
                mark = 1;
                return 0;
            }
            if(out[j]!=st.top())
                return 0;
            st.pop();
            j++;
        }
    }
    return 1;
}

bool IS_QUEUE()
{
    queue <int> st;
    int i, j=0, k=0;
    for(i=0; i<n and j<out.size(); i++)
    {
        //deb(ar[i][0], ar[i][1]);
        if(ar[i][0]==1)
            st.push(ar[i][1]);
        else
        {
            if(st.empty())
            {
                mark = 1;
                return 0;
            }
            if(out[j]!=st.front())
                return 0;
            st.pop();
            j++;
        }
    }
    return 1;
}

bool IS_OK()
{
    if(out.size()>in.size()) return 1;
    int chk[1005], i, j, k, l;
    CLR(chk);
    for(i=0; i<n; i++)
    {
        //deb(ar[i][0], ar[i][1]);
        if(ar[i][0]==1)
            chk[ar[i][1]]++;
        else
        {
            if(chk[ar[i][1]]==0)
            {
                mark = 1;
                return 1;
            }
            else chk[ar[i][1]]--;
        }
    }
    return 0;

}

bool IS_P_QUEUE()
{
    priority_queue <int> st;
    int i, j=0, k=0;
    for(i=0; i<n and j<out.size(); i++)
    {
        //deb(ar[i][0], ar[i][1]);
        if(ar[i][0]==1)
            st.push(ar[i][1]);
        else
        {
            if(st.empty())
            {
                mark = 1;
                return 0;
            }
            if(out[j]!=st.top())
                return 0;
            st.pop();
            j++;
        }
    }
    return 1;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, t, x;
    while(sf("%d", &n)!=EOF)
    {
        in.clear();
        out.clear();
        for(i=0; i<n; i++)
        {
            takei(ar[i][0]);
            takei(ar[i][1]);
            if(ar[i][0]==1)
                in.pb(ar[i][1]);
            else
                out.pb(ar[i][1]);
        }
        //deb("*", out.size());
        int st=0, qu=0, pq=0;
        mark = 0;
        st = IS_STACK();
        qu = IS_QUEUE();
        pq = IS_P_QUEUE();
        if(st+qu+pq==0)
            cout << "impossible";
        else if(st+qu+pq>1)
            cout << "not sure";
        else if(st)
            cout << "stack";
        else if(pq)
            cout << "priority queue";
        else if(qu)
            cout << "queue";
        NL;
        //deb(qu, pq, st);


    }
    ///                                    ENDD
    return 0;
}

