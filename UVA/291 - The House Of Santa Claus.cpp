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
#define SIZE 100005
int mat[6][6];
map <pair<int, int>, bool> mp;
int n=9, k=0;
vector <int> res;

void DO(int start)
{
    if(res.size()==n)
    {
        for(int i=0; i<n; i++)
            cout << res[i];
        cout << endl;
        return;
    }
    int i = start;
    //for(int i=start; i<n; i++)
    {
        for(int j=1; j<=5; j++)
        {
            if(mat[i][j]==0 || mp[make_pair(i, j)] || mp[make_pair(j, i)]) continue;

            mp[make_pair(i, j)] = 1;
            mp[make_pair(j, i)] = 1;
            res.pb(j);
            DO(j);
            mp[make_pair(i, j)] = 0;
            mp[make_pair(j, i)] = 0;
            res.pop_back();
        }
    }
    return;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    CLR(mat);
    mat[1][5] = mat[1][2] = mat[2][5] = mat[3][5] = mat[4][5] = mat[3][4] = mat[2][3] = mat[1][3] = 1;
    mat[5][1] = mat[2][1] = mat[5][2] = mat[5][3] = mat[5][4] = mat[4][3] = mat[3][2] = mat[3][1] = 1;
    mp.clear();
    res.pb(1);

    DO(1);

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
