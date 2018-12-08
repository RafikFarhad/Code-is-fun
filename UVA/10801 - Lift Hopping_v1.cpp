/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define PI 2*acos(0)
#define SIZE 1000000
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
template <class T> void MyDebug(T x, T y)
{
    cout << "Debugging: " << x << ", " << y << endl;
}
template <class T> void MyDebug(T x, T y, T z)
{
    cout << "Debugging: " << x << ", " << y << ", " << z << endl;
}

class LIFT
{
public:
    int speed;
    bool floor[105];
} lift[6];

struct FLOOR
{
    int fn;
    int ln;
    int cost;
    FLOOR(int _fn, int _ln, int _cost)
    {
        fn = _fn;
        ln = _ln;
        cost = _cost;
    };
} q(0,0,0);

bool operator < (FLOOR a, FLOOR b)
{
    return a.cost>b.cost;
}

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("10801.inp","r",stdin);
#endif
    ///                                    MAIN
    int n, i, k, j, l, a, b;
    while(sf("%d %d", &n, &k)==2)
    {
        for(i=0; i<6; i++) memset(lift[i].floor, false, sizeof(lift[i].floor));
        for(i=0; i<n; i++)
            sf("%d ", &lift[i].speed);
        char line[1000], *pch;
        for(i=0; i<n; i++)
        {
            gets(line);
            //cout << line << endl;
            pch = strtok(line, " ");
            while(pch!=NULL)
            {
                lift[i].floor[atoi(pch)] = true;
                pch = strtok(NULL, " ");
            }
        }
        int tim[6][110];
        for(i=0; i<6; i++)
            for(j=0; j<110; j++)
                tim[i][j] = SIZE;

        for(i=0; i<n; i++)
            tim[i][0] = 0;

        priority_queue<FLOOR> qu;
        q.fn = 0;
        q.cost = 0;
        for(i=0; i<n; i++)
            if(lift[i].floor[0])
            {
                q.ln=i;
                qu.push(q);
            }
        bool t = false;
        while(!qu.empty())
        {
            FLOOR p(0,0,0);
            p = qu.top();
            qu.pop();
            if(p.cost>tim[p.ln][p.fn]) continue; //MyDebug(p.fn, p.ln, p.cost);
            for(i=0; i<100; i++)
            {
                int work = p.cost + lift[p.ln].speed * abs(p.fn - i);
                if(lift[p.ln].floor[i] && tim[p.ln][i] > work)
                {
                    q.fn = i;
                    q.ln = p.ln;
                    q.cost = tim[p.ln][i] = work; //PPP; MyDebug(i, p.fn, p.ln);
                    qu.push(q);
                    //MyDebug(i, p.ln, work);
                }
            }

            for(j=0; j<n; j++)
            {
                if(lift[j].floor[p.fn])
                {
                    int work = p.cost + 60;
                    if(tim[j][p.fn] > work)
                    {
                        q.fn = p.fn;
                        q.ln = j;
                        q.cost = tim[j][p.fn] = work;
                        qu.push(q);
                        //MyDebug(p.fn, j, work);
                        //PPP;
                    }
                }
            }
        }
        int mini = SIZE;
        for(i=0; i<6; i++)
            if(tim[i][k]<mini)
                mini = tim[i][k];
        if(mini==SIZE) pf("IMPOSSIBLE\n");
        else pf("%d\n", mini);
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
