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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

class DATA
{
public:
    int ar[53], prefix;
    DATA()
    {
        ;
    }
    void CLEAR()
    {
        CLR1(ar);
        prefix = 0;
    }
};

DATA tree[SIZE];
char word[1000], sentence[100005], temp[10005];
int len, current, ans;
bool mark;

void ADD_TO_TRIE(int root=0, int pos=0)
{
    if(len==pos)
    {
        tree[root].prefix++;
        return;
    }
    int i, j, k;
    if(islower(word[pos]))
        k = word[pos] - 'a';
    else
        k = word[pos] - 'A' + 26;
    if(tree[root].ar[k]==-1)
    {
        tree[root].ar[k] = current;
        j = tree[root].ar[k];
        current++;
        tree[j].CLEAR();
    }
    else
        j = tree[root].ar[k];
    ADD_TO_TRIE(j, pos+1);
    return;
}

void COUNT(int root=0, int pos=0)
{
    if(len==pos)
    {
        //deb("#",tree[root].prefix);
        if(tree[root].prefix>0)
            ans*=tree[root].prefix;
        return;
    }
    int i, j, k;
    if(islower(word[pos]))
        k = word[pos] - 'a';
    else
        k = word[pos] - 'A' + 26;

    j = tree[root].ar[k];
    //deb(word[pos], k, tree[root].ar[k]);
    if(j>0)
    {
       //deb("*", j, word[pos]);

        COUNT(j, pos+1);
    }
    else
    {
        mark = 1;
    }
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
    int t, n;
    takei(t);
    while(t--)
    {
        tree[0].CLEAR();
        current = 1;
        takei(n);
        getchar();
        for(i=0; i<n; i++)
        {
            sf("%s", word);
            len = strlen(word);
            if(len>2)
                sort(word+1, word+(len-1));
            //deb(word);
            ADD_TO_TRIE();
        }
        pf("Case %d:\n", ++keis);

        //deb(current);
        takei(n);
        getchar();
        for(i=0; i<n; i++)
        {
            ans = 1;
            gets(sentence);
            l = strlen(sentence);
            //deb(sentence);
            mark = 0;
            for(j=0, k=0; j<=l and !mark; j++)
            {
                if(j==l or sentence[j]==' ')
                {
                    len = k;
                    word[k] = '\0';
                    //deb(word);
                    if(len>2)
                    {
                        sort(word+1, word+(len-1));
                        //deb(word);
                    }
                    COUNT();
                    if(mark) break;
                    //deb(ans);
                    k = 0;
                }
                else
                {
                    word[k++] = sentence[j];
                }
            }
            if(mark) ans=0;
            pf("%d\n", ans);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


