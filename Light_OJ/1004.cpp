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
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
template <class T1, class T2, class T3, class T4, class T5> void deb(T1 p, T2 q, T3 r, T4 s, T5 z) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << "\t" <<z<< endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int mem[205][105], mat[205][105], sum, n;

int CALC(int line, int pos, int sum)
{
    if(line==2*n ) return 0;
    if(mem[line][pos]!=-1) return mem[line][pos];
//    pf("Calling: %d\t%d\n", line, pos);
    int bam = mat[line][pos] , dan = mat[line][pos] ;
    if(line<n)
    {
        bam += CALC(line+1, pos, bam);
        dan += CALC(line+1, pos+1, dan);
    }
    else
    {
        bam += pos+1<2*n-line? CALC(line+1, pos, bam) :0;
        dan += pos-1<0 ? 0 : CALC(line+1, pos-1, dan);
    }
    mem[line][pos] = max(bam, dan);
//    deb(line, pos, bam, dan, mat[line][pos]);
    return mem[line][pos];
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    int i, j, keis=0, k, t;
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=1; i<=n; i++)
        {
            for(j=0; j<i; j++)
                takei(mat[i][j]);
        }
        for(i=1; i<n; i++)
        {
            for(j=0; j<n-i; j++)
                takei(mat[i+n][j]);
        }
        CLR1(mem);
//        CALC(1, 0, 0);
        pf("Case %d: %d\n", ++keis, CALC(1,0,0));
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


