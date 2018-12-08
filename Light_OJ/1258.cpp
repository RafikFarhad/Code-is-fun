/// In the name of Almighty Allah
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/** Algorithm  : KMP                        */
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
string suja, ulta;
int len, ar[1000006], ans;
void PREFIX()
{
    len = suja.size();
    int i, k=-1;
    ar[0] = -1;
    for(i=1; i<len; i++)
    {
        while(k>=0 and ulta[k+1]!=ulta[i])
            k = ar[k];
        if(ulta[k+1]==ulta[i])
            k++;
        ar[i] = k;
//        deb(i, ar[i]);
    }
    return;
}

void MATCH()
{
    int i;
    ans = -1;
    for(i=0; i<len; i++)
    {
        while(ans>=0 and suja[i]!=ulta[ans+1])
            ans = ar[ans];
        if(suja[i]==ulta[ans+1])
            ans++;
//        if(ans ==)
    }
}


int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ;
    //WRITE;
#endif
    ///                                    MAIN
    int t, keis=0, a, b, l;
    takei(t);
    getchar();
    while(t--)
    {
        cin >> suja;
        ulta = suja;
        reverse(ulta.begin(), ulta.end());
//        deb(suja, ulta);
        PREFIX();
        MATCH();
        pf("Case %d: %d\n", ++keis, len*2-ans-1);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


