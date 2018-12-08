///Only Sakibul Mowla vai is real :P



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
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875

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
template <class T1> void __(T1 p)
{
    cout << p << endl;
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
long long int POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int n, m, len, current;
char pattern[100], word[100];
vector <int> v;
class DATA
{
public:
    int ar[30];
    vector <int> shesh;
    DATA(){};
    void CLEAR()
    {
        CLR1(ar);
        shesh.clear();
    }
};

vector <DATA> tree;

void BUILD_tree(int root, int pos, int number)
{
    int i, j, k;
    if(pos==len)
    {
        tree[root].shesh.pb(number);
        return;
    }
    if(pattern[pos]!='?' and pattern[pos]!='*') k = pattern[pos]-'a';
    else if(pattern[pos]=='*') k = 27;
    else k = 26;

    if(tree[root].ar[k]>0)
    {
        BUILD_tree(tree[root].ar[k], pos+1, number);
    }
    else
    {
        tree.pb(DATA());
        tree[root].ar[k] = current;
        tree[current].CLEAR();
        current++;
        BUILD_tree(tree[root].ar[k], pos+1, number);
    }
    return;
}

void SEARCH(int root=0, int pos=0, int bol=0)
{
    int i, j, k;
    if(pos==len)
    {
        if(tree[root].shesh.size()>0)
        {
            for(i=0; i<tree[root].shesh.size(); i++)
                v.pb(tree[root].shesh[i]-1);
        }
        if(tree[root].ar[27]>0) SEARCH(tree[root].ar[27], pos, 1);
        return;
    }
    if(bol) SEARCH(root, pos+1, 1);
    if(tree[root].ar[27]>0)
    {
        SEARCH(tree[root].ar[27], pos+1, 1);
        SEARCH(tree[root].ar[27], pos, 1);
    }
    if(tree[root].ar[26]>0)
    {
        SEARCH(tree[root].ar[26], pos+1, 0);
    }
    k = word[pos] - 'a';
    if(tree[root].ar[k]>0)
        SEARCH(tree[root].ar[k], pos+1, 0);


    return;
}

int main()
{
    //ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l,  keis=0, a, b, c, d;
    takei(n);
    takei(m);
    getchar();
    tree.pb(DATA());
    tree[0].CLEAR();
    current = 1;

    for(i=0; i<n; i++)
    {
        sf("%s", pattern);
        len = strlen(pattern);
        BUILD_tree(0,0, i+1);
    }


    for(i=0; i<m; i++)
    {
        v.clear();
        sf("%s", word);
        len = strlen(word);
        SEARCH();
        sort(all(v));
        if(v.size()==0)
        {
            pf("Not match\n");
            continue;
        }
        v.resize(unique(all(v))-v.begin());
        for(j=0; j<v.size(); j++)
        {
            if(j) pf(" ");
            pf("%d", v[j]);
        }
        NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

