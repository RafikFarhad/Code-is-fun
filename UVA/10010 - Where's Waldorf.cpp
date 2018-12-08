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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int ans, n, m, s;
char mat[55][55], temp[100];

void DFS(int x, int y, int num, int k)
{
    if(tolower(mat[x][y])!=tolower(temp[num]))
        return;
    if(s-1==num)
    {
        ans = 1;
        return;
    }

    //for(int i=0; i<8 and !ans; i++)
    {
        int p = x+xx[k];
        int q = y+yy[k];
        if(p>=0 and p<m and q>=0 and q<n)
            DFS(p, q, num+1, k);
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, qu, a, b, k;
    takei(t);
    while(t--)
    {
        getchar();
        takei(m);
        takei(n);
        getchar();
        for(i=0; i<m; i++)
        {
            gets(mat[i]);
            //deb(i+1);
            //puts(mat[i]);
        }
        takei(qu);
        getchar();
//        deb(qu);
        while(qu--)
        {
            gets(temp);
            //deb(temp);
            s = strlen(temp);
            ans = 0;
            for(i=0; i<m and !ans; i++)
            {
                for(j=0; j<n and !ans; j++)
                {
                    if(tolower(mat[i][j])==tolower(temp[0]))
                    {
                        for(k=0; k<8; k++)
                            DFS(i, j, 0, k);
//                        deb(i+1, j+1);
                        if(ans)
                            pf("%d %d\n", i+1, j+1);
                    }
                }
            }
        }
        if(t) NL;
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

