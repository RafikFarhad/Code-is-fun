/**         HODOR          **/



#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
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
#define ll                                      long long

using namespace std;
#define SIZE 50005
int ar[50004], ans[50004], n;

int tree[SIZE<<2];
int start, last,val;
void INIT(int i, int j, int node)
{
    if(i==j)
    {
        tree[node] = ans[i];
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT(i, mid, left);
    INIT(mid+1, j, right);
    tree[node] = max(tree[left], tree[right]);
    return;
}

int QUERY(int i, int j, int node)
{
    if(i>last or j<start) return -100005;
    if(i>=start and j<=last)
    {
        //deb(tree[node]);
        return tree[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY(i, mid, left);
    int p2 = QUERY(mid+1, j, right);
    return max(p1,p2);
}
int tree2[SIZE<<2];
void INIT2(int i, int j, int node)
{
    if(i==j)
    {
        tree2[node] = ar[i];
        return;
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    INIT2(i, mid, left);
    INIT2(mid+1, j, right);
    tree2[node] = max(tree2[left], tree2[right]);
    return;
}

int QUERY2(int i, int j, int node)
{
    if(i>last or j<start) return -100005;
    if(i>=start and j<=last)
    {
        //deb(tree[node]);
        return tree2[node];
    }
    int left = node<<1;
    int right = left | 1;
    int mid = (i+j)>>1;
    int p1 = QUERY2(i, mid, left);
    int p2 = QUERY2(mid+1, j, right);
    return max(p1,p2);
}

int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b, val;
//    char pp[100];
//    fgets(pp, 100, stdin);
    ll pp = 200005;
    cout << (pp<<2);
    return 0;
    takei(n);
    for(i=1; i<=n; i++)
    {
        takei(ar[i]);
    }
    ans[0] = 0;
    for(i=1; i<=n; i++)
    {
        if(ar[i]<0)
            ans[i] = 0;
        else
            ans[i] = ans[i-1] + ar[i];
    }
    INIT(1, n, 1);
    INIT2(1, n, 1);
    takei(a);
    while(a--)
    {
        takell(start);
        takell(last);
        val = QUERY(1, n, 1);
        //cout << val << endl;
        if(val==0)
            val = QUERY2(1, n, 1);
        cout << val << endl;
    }
    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}

//
//10
//-1 2 3 0 4 -5 -6 1 1 10
//4
//4 4
//4 5
//2 5
//1 10
//1 2
//1 1
//6 7
