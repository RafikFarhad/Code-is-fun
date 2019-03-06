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
template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long int POOW(int b, int p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

long long *tree, *prop;
int start, last, n, val;

void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = 0;
        return;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (i+j)>>1;

    INIT(i, mid, left);
    INIT(mid+1, j, right);

    tree[node] = 0;
    prop[node] = 0;
    return;
}

void UPDATE(int i, int j, int node)
{
    if(i>last || j<start) return;
    if(i>=start and j<=last)
    {
        tree[node] += ((j-i+1)*val);
        prop[node] += val;
        return;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (i+j)>>1;
    UPDATE(i, mid, left);
    UPDATE(mid+1, j, right);
    tree[node] = tree[left]  + tree[right] + prop[node] * (j-i+1);
    return;
}

long long QUERY(int i, int j, int node, long long carry)
{
    if(i>last or j<start) return 0;
    if(i>=start and j<=last)
    {
        return tree[node] + (j-i+1)*carry;
    }
    int left = node<<1;
    int right = left + 1;
    int mid = (i+j)>>1;
    long long p1 = QUERY(i, mid, left, carry+prop[node]);
    long long p2 = QUERY(mid+1, j, right, carry+prop[node]);
    return p1+p2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif // FARHAD
    tree = new long long[3*SIZE];
    prop = new long long[3*SIZE];
    //memset(prop, 0, sizeof prop);
    int a, b, t, keis = 0, p, q, i, j;
    takei(t);
    while(t--)
    {
        takei(n);
        takei(q);

        INIT(1,n,1);

        pf("Case %d:\n", ++keis);

        //deb(QUERY(1,n,1,0));
        while(q--)
        {
            takei(a);
            if(a)
            {
                takei(start);
                takei(last);
                start++;
                last++;
                pf("%lld\n", QUERY(1, n, 1, 0));
            }
            else
            {
                takei(start);
                takei(last);
                takei(val);
                start++;
                last++;
                UPDATE(1, n, 1);
            }
        }
    }
    delete(tree);
    delete(prop);
    return 0;
}


