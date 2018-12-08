/// In the name of Almighty Allah
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/** Algorithm  : TRIE                    */
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
#define SIZE 100005
int n, len[SIZE];
char line[SIZE][85];
class DATA
{
public:
    DATA *next[30];
    int child, word;
    DATA()
    {
        for(int i=0; i<30; i++)
            next[i] = NULL;
        child = word = 0;
    }
};
DATA *root;

void BUILD(char a[], int k)
{
    DATA *temp = root;
    int i, j, l = len[k];
    for(i=0; i<l; i++)
    {
        j = a[i] - 'a';
        if(temp->next[j]!=NULL)
        {
            temp->word++;
            temp = temp->next[j];
        }
        else
        {
            temp->word++;
            temp->child++;
            temp->next[j] = new DATA;
            temp = temp->next[j];
        }
    }
    j = 'z' - 'a' + 1;
    if(temp->next[j]!=NULL)
    {
        temp->word++;
        temp = temp->next[j];
    }
    else
    {
        temp->word++;
        temp->child++;
        temp->next[j] = new DATA;
        temp = temp->next[j];
    }
//    deb(a);
    return;
}

void DELETE(DATA *temp)
{
    for(int i=0; i<30; i++)
        if(temp->next[i])
            DELETE(temp->next[i]);
    delete temp;
    return;
}

int CALC()
{
    int a, l, i, j, k, sum = 0;
    for(i=0; i<n; i++)
    {
        l = len[i];
        DATA *temp = root;
        a = line[i][0] - 'a';
        temp = temp->next[a];
//        pf("%c", a+'a');
//        deb(sum, temp->word);
        sum++;
        for(j=1; j<l; j++)
        {
            a = line[i][j] - 'a';
//            deb(sum, temp->word);
            if(temp->word==1)
            {
                j = l+1;
            }
            else if(temp->child==1)
            {
                temp = temp->next[a];
                continue;
            }
            else
            {
                sum++;
                temp = temp->next[a];
            }
        }
//        deb(sum);
    }
    return sum;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int i, j, a, b, l;
    while(sf("%d", &n)!=EOF)
    {
        getchar();
        root = new DATA;
        for(i=0; i<n; i++)
        {
            sf("%s", line[i]);
            len[i] = strlen(line[i]);
            BUILD(line[i], i);
        }
        l = CALC();
//        deb(l);
        pf("%.2f\n", l/(double)n);
        DELETE(root);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

