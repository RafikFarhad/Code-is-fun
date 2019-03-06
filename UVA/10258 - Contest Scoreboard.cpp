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
#define NL printf("\n")
#define PI 2*acos(0)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt", "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX
int have[105];

class DATA
{
public:
    int porichoy, score, tried[10], solved;
    bool ac[10];
    DATA(int a, int b, int c)
    {
        porichoy = a;
        score = b;
        solved = c;
        CLR(tried);
        CLR(ac);
    }
    bool operator < (const DATA a) const
    {
        if(a.solved==solved)
        {
            if(score==a.score)
                return porichoy<a.porichoy;
            return score < a.score;
        }
        return solved > a.solved;
    }
};
vector <DATA> v;

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    WRITE;
#endif
    ///                                    MAIN
    int t, keis=0, i, j, k, id, prob, tim, p, q, person;
    char c, line[100];
    takei(t);
    getchar();
    getchar();
    while(t--)
    {
        v.clear();
        CLR(have);
        person = 0;
        while(gets(line) && strlen(line))
        {
            //deb(line);
            ssf(line, "%d %d %d %c", &id, &prob, &tim, &c);
            if(!have[id])
            {
                have[id] = ++person;
                v.pb(DATA(id, 0, 0));
            }
            id = have[id] - 1;

            if(c=='C')
            {
                if(v[id].ac[prob]) continue;
                v[id].ac[prob] = 1;
                v[id].solved++;
                v[id].score+=(v[id].tried[prob]*20+tim);
            }
            else if(c=='I')
            {
                v[id].tried[prob]++;
            }
        }
        sort(v.begin(), v.end());
        for(i=0; i<person; i++)
            pf("%d %d %d\n", v[i].porichoy, v[i].solved, v[i].score);
        if(t) NL;
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
