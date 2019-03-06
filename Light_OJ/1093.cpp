/// In the name of Almighty Allah
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/** Algorithm  :                     */
/*****************************************/
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
///def
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0)

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
#define MX 1000000000
int *tree1, *tree2, n, d, ar[SIZE];

void INIT(int i, int j, int node)
{
//    deb(i, j, node);
    if(i==j)
    {
        tree1[node] = ar[i];
        tree2[node] = ar[i];
//        deb(node, ar[i]);
        return;
    }
    int left, right, mid;
    left = node * 2;
    right = node *2 + 1;
    mid = (i+j) >> 1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree1[node] = max(tree1[left], tree1[right]);
    tree2[node] = min(tree2[left], tree2[right]);
    return;
}

int QUERY_1(int start, int last, int i, int j, int node)
{
//    deb(i, j, node); ppp;
    if(start>j or last<i) return -MX;
//    deb(i, j, node, start);
    if(i>=start and j<=last)
    {
//        deb(node, tree1[node]);
        return tree1[node];
    }
    int left, right, mid;
    left = node*2;
    right = node*2+1;
    mid = (i+j) /2;
    int p1 = QUERY_1(start, last, i, mid, left);
    int p2 = QUERY_1(start, last, mid+1, j, right);
    //deb(p1, p2);
    return max(p1, p2);
}

int QUERY_2(int start, int last, int i, int j, int node)
{
    if(start>j or last<i) return MX;
    if(i>=start and j<=last)
    {
        return tree2[node];
    }
    int left, right, mid;
    left = node*2;
    right = node*2+1;
    mid = (i+j) /2;
    int p1 = QUERY_2(start, last, i, mid, left);
    int p2 = QUERY_2(start, last, mid+1, j, right);
    return min(p1, p2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("00.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, keis=0, l, a, b, c, ans;
    tree1 = new int[3*SIZE];
    tree2 = new int[3*SIZE];

    takei(t);
    while(t--)
    {
        takei(n);
        takei(d);
        for(i=1; i<=n; i++)
        {
            takei(ar[i]);
        }

        INIT(1, n, 1);
        ans = 0;
        for(i=1; i<=n-d+1; i++)
        {
            a = QUERY_1(i, i+d-1, 1, n, 1);
            b = QUERY_2(i, i+d-1, 1, n, 1);
            //deb(i, i+d-1, b);
//            deb(a, b);
            ans = max(ans, a-b);
        }
        pf("Case %d: %d\n", ++keis, ans);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


