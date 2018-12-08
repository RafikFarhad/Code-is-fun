/// In the name of Almighty Allah
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/** Algorithm  : Aho_Corasick             */
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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX

class DATA
{
public:
    int counter;
    bool flag;
    vector <DATA*> out;
    DATA *next[28];
    DATA()
    {
        for(int i=0; i<28; i++)
            next[i] = NULL;
        flag = counter = 0;
        out.clear();
    }
};
DATA *root;
void BUILD_TRIE(string a);
void BFS_CORASICK();
void SCAN(string my);
int DFS(DATA *p);
void DEL(DATA *t)
{
    for(int i=1; i<28; i++)
        if(t->next[i])
            if(t->next[i]!=t)
                DEL(t->next[i]);
    delete t;
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ;
    //WRITE;
#endif
    ///                                    MAIN
    string pat = "AC", pat2 = "FAR", my = "CFARHADSGDJFJFJJDACKJHGJHACFARFARFARFARFARFARFARFARFA";
    root = new DATA;
    BUILD_TRIE(pat);
    BUILD_TRIE(pat2);
    BFS_CORASICK();
    SCAN(my);
    DATA *temp = root;
    for(int i=0; i<pat2.size(); i++)
    {
        int j = pat2[i] + 1 - 'A';
        temp = temp->next[j];
    }
    cout << DFS(temp) << endl;
    DEL(root);
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

int DFS(DATA *p)
{
    if(p->flag) return p->counter;
    p->flag = 1;
    for(int i=0; i<p->out.size(); i++)
        p->counter+=DFS(p->out[i]);
    return p->counter;

}

void SCAN(string my)
{
    int i, j, k = my.size();
    DATA *temp = root;
    for(i=0; i<k; i++)
    {
        j = my[i] - 'A' +1;
        while(temp->next[j]==NULL)
            temp = temp->next[0];
        temp = temp->next[j];
        temp->counter++;
    }
    cout << "DONE SCANNING" << endl << endl;
}

void BFS_CORASICK()
{
    int i, j, k, l;
    DATA *u, *v, *temp = root, *w;
    queue <DATA*> qu;
    for(i=0; i<28; i++)
    {
        if(root->next[i]==NULL)
            root->next[i] = root;
        else
        {
            (root->next[i])->next[0] = root;
            qu.push(root->next[i]);
        }
    }
    while(qu.size())
    {
        u = qu.front();
        qu.pop();
        for(i=1; i<28; i++)
        {
            if(u->next[i]!=NULL)
            {
                v = u->next[i];
                w = u->next[0];
                while(w->next[i]==NULL)
                {
                    w = w->next[0];
                }
                v->next[0] = w = w->next[i];
                w->out.pb(v);
                qu.push(v);
            }
        }
    }
    cout << "DONE AHO" << endl << endl;
}

void BUILD_TRIE(string a)
{
    int i, j = a.size();
    DATA *temp = root;
    for(i=0; i<j; i++)
    {
        int k = a[i]-'A'+1;
        if(temp->next[k]==NULL)
            temp->next[k] = new DATA;
        temp = temp->next[k];
    }
    cout << "DONE Building" << endl << endl;
}
