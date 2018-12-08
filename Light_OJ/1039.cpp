/// #define_SUST
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
#define CLR(o) memset(o, 0, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takel(a) scanf("%ld", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 x){ cout << "Debugging: " << x << endl;}
template <class T1, class T2> void deb(T1 x, T2 y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T1, class T2, class T3> void deb(T1 x, T2 y, T3 z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
const int xx[] = {0, 0, 1, -1, 0, 0};
const int yy[] = {1, -1, 0, 0, 0, 0 };      // diagonal -> 8 horizontal/vertical->4
const int zz[] = {0, 0, 0, 0, 1, -1};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs
#define SIZE 46400
bool visited[27][27][27];
int level[27][27][27];

int BFS(char s[], char e1[])
{
    int a = s[0]-'a', b = s[1]-'a', c = s[2]-'a', d = e1[0]-'a', e = e1[1]-'a', f = e1[2]-'a', i, j, k, u, v, w, x, y, z;
    if(visited[a][b][c] || visited[d][e][f]) return -1;
    if(a==d && b==e && c==f) return 0;
    //puts(s); puts(e1);
    //deb(a,b,c); deb(d,e,f);
    queue <int> qu;
    qu.push(a);
    qu.push(b);
    qu.push(c);
    level[a][b][c] = 0;
    visited[a][b][c] = 1;
    while(qu.size())
    {
        u = qu.front() ; qu.pop();
        v = qu.front() ; qu.pop();
        w = qu.front();  qu.pop();
        for(i=0; i<6; i++)
        {
            x = (u+xx[i]) %26; x = x<0?x+26:x;
            y = (v+yy[i]) %26; y = y<0?y+26:y;
            z = (w+zz[i]) %26; z = z<0?z+26:z;
            //deb(x, y, z);
            if(!visited[x][y][z])
            {
                qu.push(x);
                qu.push(y);
                qu.push(z);
                level[x][y][z] = level[u][v][w] + 1;
                visited[x][y][z] = 1;
                if(x==d && y==e && z==f) return level[x][y][z];
            }
        }
    }
    return -1;
}

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int t, keis=0, m, i, j, k, u, w, v;
    char s[4], e[4], p1[27], p2[27], p3[27];
    sf("%d", &t);
    while(t--)
    {
        sf("\n");
        //memset(level, -1, sizeof level);
        CLR(visited);
        gets(s);
        gets(e);
        sf("%d", &m);
        while(m--)
        {
            sf("%s %s %s", p1, p2, p3);
            u = strlen(p1);
            v = strlen(p2);
            w = strlen(p3);
            for(i=0; i<u; i++)
                for(j=0; j<v; j++)
                    for(k=0; k<w; k++)
                        visited[p1[i]-'a'][p2[j]-'a'][p3[k]-'a'] = 1;
        }
        u = BFS(s, e);
        pf("Case %d: %d\n", ++keis, u);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

