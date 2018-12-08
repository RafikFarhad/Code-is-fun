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
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1}; const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal->8 horizontal/vertical->4
#define SIZE 100005
int n;
vector <int> par[100];
bool flag[100];
map <char, int> mp;
map <int, char> mp2;
void BT(int s);
vector <int> res;
vector <string> finall;
bool IS_OK(int s);

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    WRITE("output.txt");
#endif
    ///                                    MAIN
    char line[100], sub[100];
    int i, j, k=0, a, b, c=0, l1, l2;
    while(gets(line))
    {
        if(c++) cout << endl;
        k = 0;
        CLR(flag);
        //CLR1(par);
        res.clear();
        gets(sub);
        l1 = strlen(line);
        l2 = strlen(sub);
        //sort(line, line+l1);
        for(i=0, n=0; i<l1; i++)
            if(isalpha(line[i]))
            {
                mp[line[i]] = k;
                mp2[k] = line[i];
                k++;
            }
        n = k;
        for(i=0; i<n; i++)
            par[i].clear();
        //deb(n);
        for(i=0; i<l2; i++)
        {
            if(sub[i]==' ') continue;
            a = mp[sub[i]];
            b = mp[sub[i+2]];
            par[a].pb(b);
            i+=2;
            //deb(par[a]);
        }
        finall.clear();
        BT(0);
        k = finall.size();
        sort(finall.begin(), finall.end());
        for(i=0; i<k; i++)
            cout << finall[i] << endl;

         //   deb(mp2[i], par[i]);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

void BT(int s)
{
    if(res.size()==n)
    {
        string res2 = "";
        for(int i=0; i<n; i++)
            res2+= mp2[res[i]];
        finall.pb(res2);
        return;
    }
    for(int i = 0; i<n; i++)
    {
        if(flag[i]) continue;
        if(IS_OK(i)) return;
        res.pb(i);
        flag[i] = 1;
        BT(i);
        flag[i] = 0;
        res.pop_back();
    }
    return;
}
bool IS_OK(int s)
{
    if(par[s].size()==0) return false;
    int i, j = par[s].size();
    for(i=0; i<j; i++)
        if(flag[par[s][i]]) return true;
    return false;
    //return IS_OK(par[s]);
}
