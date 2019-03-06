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
#include <deque>
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

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    deque<int> dq;
    string pl = "pushLeft", pr = "pushRight",  pol = "popLeft", por = "popRight", in;
    int n, m, i, j, t, keis=0;
    takei(t);
    while(t--)
    {
        while(dq.size()) dq.pop_back();
        takei(n);
        takei(m);
        pf("Case %d:\n", ++keis);
        while(m--)
        {
            cin >> in;
            if(in==pl)
            {
                cin >> j;
                if(dq.size()<n)
                {
                    dq.push_front(j);
                    pf("Pushed in left: %d\n", j);
                }
                else
                {
                    pf("The queue is full\n");
                }
            }
            else if(in==pr)
            {
                cin >> j; //cout << " ** " << j << endl;
                if(dq.size()<n)
                {
                    dq.push_back(j);
                    pf("Pushed in right: %d\n", j);
                }
                else
                {
                    pf("The queue is full\n");
                }
            }
            else if(in==pol)
            {
                //cin >> j;
                if(dq.size())
                {
                    pf("Popped from left: %d\n", dq.front());
                    dq.pop_front();
                }
                else
                {
                    pf("The queue is empty\n");
                }
            }
            else if(in==por)
            {
                //cin >> j;
                if(dq.size())
                {
                    pf("Popped from right: %d\n", dq.back());
                    dq.pop_back();
                }
                else
                {
                    pf("The queue is empty\n");
                }
            }
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

