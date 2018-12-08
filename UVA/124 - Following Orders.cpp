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
bool flag[100];
void BT(int s);
vector <int> res;
class DATA
{
public:
    char c;
    int val;
    bool operator < (const DATA &a) const
    {
        if(val==a.val)
            return c < a.c;
        return val < a.val;
    }
}ar[25];

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ("input.txt");
    //WRITE("output.txt");
#endif
    ///                                    MAIN
    char line[100], sub[100];ok
    int i, j, k, a, b, c=0, l1, l2;
    while(gets(line))
    {
        if(c++) cout << endl;
        CLR(ar);
        CLR(flag);
        res.clear();
        gets(sub);
        l1 = strlen(line);
        l2 = strlen(sub);
        for(i=0, n=0; i<l1; i++)
            if(isalpha(line[i]))
            {
                ar[n].c = line[i];
                ar[n++].val = 0;
            }
        //deb(n);
        for(i=0; i<l2; i++)
        {
            if(sub[i]==' ') continue;
            for(a=0; a<n; a++)
                if(ar[a].c==sub[i])
                    break;
            for(b=0; b<n; b++)
                if(ar[b].c==sub[i+2])
                    break;
            i+=2;
            if(ar[b].val==0)
            {
                if(ar[a].val==0)
                {
                    ar[a].val = 100;
                    ar[b].val = ar[a].val + 1;
                }
                else
                    ar[b].val = ar[b].val + 1;
            }
            else
            {
                if(ar[a].val==0) ar[a].val = ar[b].val-1;
                else ar[a].val--;
            }
        }
        sort(ar, ar+n);
        BT(0);
        for(i=0; i<n; i++)
            deb(ar[i].c, ar[i].val);
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
        for(int i=0; i<n; i++)
            cout << ar[res[i]].c;
        cout << endl;
        return;
    }
    for(int i = 0; i<n; i++)
    {
        if(flag[i]) continue;
        if(ar[i].val < ar[s].val) continue;
        res.pb(i);
        flag[i] = 1;
        BT(i);
        flag[i] = 0;
        res.pop_back();
    }
    return;
}
