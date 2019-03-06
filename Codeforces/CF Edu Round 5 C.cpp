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
#define _(o)                                    pf("%d", o)

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
#define SIZE 1005
int flag[SIZE][SIZE];
char res[SIZE][SIZE], mat[SIZE][SIZE];
int n, m, ar[SIZE][SIZE];

int DFS(int x, int y)
{
    if(x<0 or y< 0 or x==n or y==m or mat[x][y]=='*' or flag[x][y]) return 0;
    flag[x][y] = 1;
    int i, p=0;
    for(i=0; i<4; i++)
        p += DFS(x+xx[i], y+yy[i]);
    return p+1;
}

void UPD(int x, int y, int a, int id)
{
    if(x<0 or y< 0 or x==n or y==m or mat[x][y]=='*' or flag[x][y]==id) return ;
    flag[x][y] = id;
    ar[x][y] = a;
    int i;
    for(i=0; i<4; i++)
        UPD(x+xx[i], y+yy[i], a, id);
    return ;
}

int COUNT(int x, int y)
{

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    //char a[1000006], b[1000006], aa[1000006], bb[1000006];
    int i, j, k, a, b, c, id, id1, id2, id3, id4;
    while(cin >> n >> m)
    {
        //getchar();
        for(i=0; i<n; i++)
        {
            sf("%s", mat[i]);
            //strcpy(res[i], mat[i]);
            //deb(mat[i], res[i]);
        }
        CLR(flag);
        CLR(ar);
        id = 3;
        for(i=0; i<n; i++)
            for(j=0; j<m; j++)
                if(mat[i][j]=='.' and flag[i][j]==0)
                {
                    a = DFS(i, j);
                   // deb(i, j, a);
                    UPD(i, j, a, ++id);
                    //deb(ar[i][j]);
                }
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(mat[i][j]=='*')
                {
                    map<int, bool> mp;
                    a = 0;
                    if(j>0 and !mp[flag[i][j-1]])
                    {
                        a+=ar[i][j-1];
                        mp[flag[i][j-1]] = 1;
                    }
                    if(i>0 and !mp[flag[i-1][j]])
                    {
                        a+=ar[i-1][j];
                        mp[flag[i-1][j]] = 1;
                    }
                    if(j+1<m and !mp[flag[i][j+1]])
                    {
                        a+=ar[i][j+1];
                        mp[flag[i][j+1]] = 1;
                    }
                    if(i+1<n and !mp[flag[i+1][j]])
                    {
                        a+=(ar[i+1][j]);
                        mp[flag[i+1][j]] = 1;
                    }
                    a = ++a%10;
                    mat[i][j] = (a+'0');
                }
            }
            puts(mat[i]);
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}




