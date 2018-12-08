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
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
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
map <int, int> fibo;

void CALC()
{
    int i, j, k, l = 2147483640;
    fibo.clear();
    j = 2; i = 1;
    k = 2;
    fibo[1] = 1;
    fibo[2] = 2;
    while(j<l and j>0)
    {
        j = i+j;
        i = j-i;
        fibo[j] = ++k;
        //deb(k, j, i);
    }
    //deb(k);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, a, b, ar[120], n;
    char cc[120], line[120];
    string p;
    CALC();
    takei(t);
    while(t--)
    {
        takei(n);
        for(i=0; i<110; i++) ar[i] = 0;
        for(i=0; i<n; i++)
        {
            takei(a);
            ar[fibo[a]] = i+1;
           // deb(fibo[a]);
        }
        getchar();
        gets(line);
        b = strlen(line);
       // deb(b);
        for(i=0, j=0; i<b; i++)
        {
            if(isupper(line[i]))
                cc[j++] = line[i];
        }
        //deb(n, j, line);
        //deb(line, cc[0]);
        p = "";
        for(i=1; i<110; i++)
        {
            if(ar[i])
                p = p + cc[ar[i]-1];
            else
                p+=" ";
        }
        j = i = p.size() - 1;
        while(p[j] == ' ')
            j--;
        p = p.substr(0, j+1);
        //deb(i, j);
        pf("%s", p.c_str());
        NL;
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

