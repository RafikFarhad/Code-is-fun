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
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen("b", "w", stdout);
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << ", " << q << ", " << r << ", " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
char st[SIZE];
class DATA
{
public:
    int prop, val;
}*tree;

void INIT(int start, int last, int node)
{
    if(start==last)
    {
        tree[node].val = st[start-1] - '0';
        return;
    }
    int left = node<<1, right = (node<<1)+1, mid = (start+last)>>1;
    INIT(start, mid, left);
    INIT(mid+1, last, right);
    return;
}

void UPDATE(int i, int j, int start, int last, int node)
{
    //deb(i, j, start, last);
    if(j < start || i > last) return;
    if(i<=start && last<=j )
    {
        tree[node].prop++;
        return;
    }
    int left = node<<1, right = (node<<1)+1, mid = (start+last)>>1;
    UPDATE(i, j, start, mid, left);
    UPDATE(i, j, mid+1, last, right);
    return;
}
int QUERY(int a, int start, int last, int node, int carry)
{
    if(a<start || a>last) return 0;
    if(start==last)
    {
        return carry+tree[node].prop;
    }
    int left = node<<1, right = (node<<1)+1, mid = (start+last)>>1, p1, p2;
    p1 = QUERY(a, start, mid, left, carry+tree[node].prop);
    p2 = QUERY(a, mid+1, last, right, carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE(output.txt);
#endif
    ///                                    MAIN
    int t, keis=0, i, j, l, a, b, q;
    char ch;
    tree = new DATA[3*SIZE];
    sf("%d", &t);
    while(t--)
    {
        getchar();
        pf("Case %d:\n", ++keis);
        gets(st);
        l = strlen(st);
        //puts(st);
        memset(tree, 0x00, sizeof(tree)*3*SIZE);
        INIT( 1, l, 1);
        sf("%d", &q);
        while(q--)
        {
            //puts(st); putchar(ch);
            sf("\n%c", &ch);
            if(ch=='I')
            {
                sf("%d %d", &i, &j);
                UPDATE(i, j, 1, l, 1);
            }
            else
            {
                sf("%d", &i);
                j = QUERY(i, 1, l, 1, 0);
                //deb(j, 0,0,0);
                if(j&1) pf("%d\n", st[i-1]=='1'?0:1);
                else pf("%d\n", st[i-1]=='1'?1:0);
            }
        }
        //for(i=1; i<11; i++) pf("%d %d\n", i, tree[i].prop);
    }

    delete(tree);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

