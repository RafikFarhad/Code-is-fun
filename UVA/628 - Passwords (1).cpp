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
#define READ(a) freopen(a,"r",stdin);
#define WRITE(b) freopen(b, "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005
int full, k ,l ;
char input[107][260];
char output[260];
vector <int>res;
map < vector <int>, bool > mp;
//string res;

void PERM(int start)
{
    if(res.size()==l)
    {
        if(mp[res]) return;
        mp[res] = 1;
        int i, j=0;
        for(i=0; i<l; i++)
        {
            //cout << "  " << res[i] << "-> ";
            if(output[i]!='#')
                pf("%d", res[i]);
            else
                pf("%s", input[res[i]]);
        }
        NL;
        return;
    }
    if(start==l) return;
    int m=0;
    for(int i = 0; i<full; i++)
    {
        if(output[start]!='#')
        {
            for(int j=0; j<10; j++)
            {
                res.pb(j);
                PERM(start+1);
                res.pop_back();
            }
        }
        else
        {
            //if(m==full) continue;
            res.pb(m++);
            PERM(start+1);
            res.pop_back();
        }
    }
}


int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    WRITE("output.txt");
#endif
    ///                                    MAIN
    int n, m, i, j, a, b;
    while(sf("%d\n", &n)!=EOF)
    {
        full = n;
        puts("--");
        for(i=0; i<n; i++)
            cin >> input[i];
        sf("%d\n", &m);
        for(i=0; i<m; i++)
        {
            gets(output);
            mp.clear();
            l = strlen(output);
            k = 0;
            for(j=0; j<l; j++)
                if(output[j]=='#')
                    k++;
            //deb(full, l);
            PERM(0);
//            for(i=0; i<l; i++)
//                cout <<  all[i] << endl;;
        }
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
