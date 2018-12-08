/// In the name of Almighty Allah
/**************************************/
/** Author : Rafik Farhad                         */
/** mailto  : rafikfarhad@gmail.com     */
/**************************************/
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
#define MAX3(a, b, c)                       MAX(a , MAX(b,c))
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
#define READ                                   freopen("input.txt","r",stdin);
#define WRITE                                 freopen("output.txt", "w", stdout);
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
#define SIZE INT_MAX
char qu[1001][1001], line[1000006];

class NODE
{
public:
    NODE *next[53];
    bool flag;
    vector <NODE *> out;
    int counter;
    NODE()
    {
        for(int i=0; i<53; i++)
            next[i] = NULL;
        counter = flag = 0;
        out.clear();
    }
} *root;

void BUILD_TRIE(char a[])
{
    int i, j, len = strlen(a);
    NODE *temp = root;
    for(i=0; i<len; i++)
    {
        if(a[i]>='a' and a[i] <= 'z')
            j = a[i] - 'a' + 1;
        else
            j = a[i] - 'A' + 27;
        if(temp->next[j]==NULL)
            temp->next[j] = new NODE;
        temp = temp->next[j];
    }
    ;
    return;
}

void DELETE(NODE *temp)
{
    for(int i=1; i<53; i++)
        if(temp->next[i] and temp->next[i] != temp)
            DELETE(temp->next[i]);
    delete(temp);
    return;
}

void BFS_FOR_AHO_CORASICK()
{
    NODE *u, *v, *w, *temp = root;
    queue <NODE *> qu;
    int i, j;
    for(i=1; i<53; i++)
    {
        if(temp->next[i]!=NULL)
        {
            qu.push(temp->next[i]);
            (temp->next[i])->next[0] = root;
        }
        else
            temp->next[i] = root;
    }
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        for(i=1; i<53; i++)
        {
            if(u->next[i]!=NULL)
            {
                v = u->next[i];
                w = u->next[0];
                while(w->next[i]==NULL)
                    w = w->next[0];
                v->next[0] = w = w->next[i];
                w->out.pb(v);
                qu.push(v);
            }
        }
    }
    return;
}

void SCAN(char a[])
{
    int i, j, len = strlen(a);
    NODE *temp = root;
    for(i=0; i<len; i++)
    {
        if(a[i]>='a' and a[i] <= 'z')
            j = a[i] - 'a' + 1;
        else
            j = a[i] - 'A' + 27;
        while(temp->next[j]==NULL)
            temp = temp->next[0];
        temp = temp->next[j];
        temp->counter++;
    }
    return;
}

int DFS(NODE *temp)
{
    if(temp->flag) return temp->counter;
    temp->flag = 1;
    for(int i =0; i<temp->out.size(); i++)
        temp->counter += DFS(temp->out[i]);
    return temp->counter;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int t, query, i, j, ans, l, k;
    takei(t);
    getchar();
    while(t--)
    {
        root = new NODE;
        gets(line);
        takei(query);
        getchar();
        for(i=0; i<query; i++)
        {
            gets(qu[i]);
//            deb(qu[i]);
            BUILD_TRIE(qu[i]);
        }
        BFS_FOR_AHO_CORASICK();
        SCAN(line);
        for(i=0; i<query; i++)
        {
            NODE *temp = root;
            l = strlen(qu[i]);
            for(j=0; j<l; j++)
            {
                if(qu[i][j]>='a' and qu[i][j] <= 'z')
                    k = qu[i][j] - 'a' + 1;
                else
                    k = qu[i][j] - 'A' + 27;
                temp = temp->next[k];
            }
            ans = DFS(temp);
            if(ans) pf("y\n");
            else pf("n\n");
        }
        DELETE(root);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

