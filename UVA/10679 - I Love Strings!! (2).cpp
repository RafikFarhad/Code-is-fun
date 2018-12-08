/// In the name of Almighty Allah
/**************************************/
/** Author : Rafik Farhad              */
/** mailto  : rafikfarhad@gmail.com   */
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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
char pat[1050], st[100005];
bool flag;
int ar[1050], l1, l2;

void FAILURE()
{
    int i, j, k=-1;
    l1 = strlen(pat);
    ar[0]=-1;
    for(i=1; i<l1; i++)
    {
        while(k>=0 && pat[k+1]!=pat[i])
            k = ar[k];
        if(pat[k+1]==pat[i])
            k++;
        ar[i] = k;
//        deb(i, ar[i]);
    }

}

void MATCH()
{
    l2 = strlen(st);
    int i, j, matched = -1;
    for(i=0; i<l2; i++)
    {
        while(matched>=0 and st[i]!=pat[matched+1])
            matched = ar[matched];
        if(st[i]==pat[matched+1])
            matched++;
        if(matched==l1-1)
        {
            flag = true;
            return;
        }
    }
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int test, qu, i, j, k, m;
    takei(test);
    getchar();
    while(test--)
    {
        gets(st);
        takei(qu);
        getchar();
        while(qu--)
        {
            gets(pat);
            FAILURE();
            flag = 0;
            MATCH();
            if(flag) pf("y\n");
            else pf("n\n");
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

