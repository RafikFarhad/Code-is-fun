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
#include <iterator>
/***********************/
/** Rafik Farhad      **/
/***********************/

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
#define PI                                         2*acos(0.0)

using namespace std;
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
long long POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};
//const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
#define SIZE INT_MAX
int mat[25][25], level[25][25], m, n, xp, yp, pp, qq;
bool flag[25][25];

int BFS(int x, int y)
{
    if(mat[x][y]==1) return 0;
    int i, j, k, u1, u2, v1, v2;
    CLR1(level);
    queue<int> qu;
    qu.push(x);
    qu.push(y);
    level[x][y] = 0;
    while(qu.size())
    {
        u1 = qu.front(); qu.pop();
        u2 = qu.front(); qu.pop();
        for(i=0; i<4; i++)
        {
            v1 = u1+xx[i];
            v2 = u2+yy[i];
            if(v1<1 or v2<1 or v1>m or v2>n) continue;
            if(level[v1][v2]!=-1) continue;
            level[v1][v2] = level[u1][u2] + 1;
            if(mat[v1][v2]==1)
            {
                pp = v1;
                qq = v2;
                mat[v1][v2] = 0;
                return level[v1][v2];
            }
            qu.push(v1);
            qu.push(v2);
        }
    }
    return 000;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("00.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int i, j, k, l, t, x, y;
    takei(t);
    while(t--)
    {
        takei(m);
        takei(n);
        takei(xp);
        takei(yp);
       // deb(xp, yp);
       //mat[xp][yp] = 2;
        takei(k);
        CLR(mat);
        for(i=0; i<k; i++)
        {
            takei(x);
            takei(y);
            if(x!=xp or y!=yp) mat[x][y] = 1;
        }
        l = 0;
        pp = xp;
        qq = yp;
        for(i=0; i<k; i++)
        {
            l+=(BFS(pp, qq));
           // deb(xp, yp);
            //deb(pp, qq);
            //mat[xp][yp] = 1;
            //l+=BFS2(pp,qq);
           // mat[xp][yp] = 0;
            //deb(l);
        }
        mat[xp][yp] = 1;
        l+=BFS(pp,qq);
        pf("The shortest path has length %d\n", l);
    }
    return 0;
}




