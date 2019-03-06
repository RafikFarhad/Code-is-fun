/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moovs xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 8
vector <int> res;
bool flag[9][9];
int r, c, k=0;
void BT(int col);
void SeateD(int row, int col, int p)
{
    flag[row][col] = p;
    return;
}
bool ISOK(int row, int col)
{
    int i, j;
    for(i=1; i<=8; i++)
        if(flag[row][i] )
            return false;
    for(i=1; i<=8; i++)
        if(flag[i][col])
            return false;
    for(i=row, j=col; i<9 && j<9; i++, j++)
        if(flag[i][j])
            return false;
    for(i=row, j=col; i>0 && j>0; i--, j--)
        if(flag[i][j])
            return false;
    for(i=row, j=col; i>0 && j<9; i--, j++)
        if(flag[i][j])
            return false;
    for(i=row, j=col; i<9 && j>0; i++, j--)
        if(flag[i][j])
            return false;
    return true;
}
int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    int t, keis=0, i, j;
    takei(t);
    while(t--)
    {
        sf("%d %d", &r, &c);
        if(keis++) pf("\n");
        k = 0;
        res.clear();
        CLR(flag);
        SeateD(r, c, 1);
        pf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
        BT(1);
        /*for(i=1; i<=8; i++, cout << endl)
            for(j=1; j<=8; j++)
                cout << flag[i][j] << " ";
       /* */
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
void BT(int col)
{
    //if(col==c) BT(col+1);
    if(res.size()==8)
    {
        pf("%2d     ", ++k);
        for(int i=0; i<8; i++)
            pf(" %d", res[i]);
        pf("\n");
    }
    if(col==9) return;
    if(col==c)
    {
        res.pb(r);
        //SeateD(r, c, 1);
        BT(col+1);
        res.pop_back();
        //Re_SeateD(r, c);
        return;
    }
    for(int i=1; i<9; i++)
    {
        if(!ISOK(i, col)) continue;
        res.pb(i);
        SeateD(i, col, 1);
        BT(col+1);
        SeateD(i, col, 0);
        res.pop_back();
    }
    return;
}
