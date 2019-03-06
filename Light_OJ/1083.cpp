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
int n, ar[30005];

int CALL()
{
    int i, j, k, area[n];
    stack <int> st;
    for(i=0; i<n; i++)
    {
        while(st.size())
        {
            if(ar[st.top()] >=ar[i])
            {
                st.pop();
            }
            else break;
        }
        if(st.empty()) j =-1;
        else j = st.top();
        area[i] = i - j - 1;
        st.push(i);
    }
    while(st.size()) st.pop();
    for(i=n-1; i>=0; i--)
    {
        while(st.size())
        {
            if(ar[i]<=ar[st.top()])
            {
                st.pop();
            }
            else break;
        }
        if(st.empty()) j = n;
        else j = st.top();
        area[i] += j - i - 1;
        st.push(i);
    }
    int maxi = 0;
    for(i=0; i<n; i++)
    {
        maxi = MAX(maxi, ar[i]*(area[i]+1));
    }
    return maxi;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<n; i++)
            takei(ar[i]);
        j = CALL();
        pf("Case %d: %d\n", ++keis, j);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

