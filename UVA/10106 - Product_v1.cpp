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
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
#define SIZE 10000000
using namespace std;

template <class T> T MAX(T a, T b){return a>b?a:b;}
template <class T> T MIN(T a, T b){return a<b?a:b;}
template <class T> void MyDebug(T x, T y){cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z){cout << "Debugging: " << x << ", " << y << ", " << z << endl;}
int xx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int yy[] = {1, -1, -2, -2, -1, 1, 2, 2};
int xx1[] = {-1, 0, 0, 1, 1, 1, -1, -1};
int yy1[] = {0, -1, 1, 0, -1, 1, 1, -1};
#define MaX 1000

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    //freopen("10106.inp","r",stdin);
#endif
    ///                                    MAIN
    char a[1000], b[1000];
    int pro[1000], i, j, k, l1, l2, mark;
    while(gets(a))
    {
        gets(b);
        l1 = strlen(a);
        l2 = strlen(b);
        memset(pro, 0, sizeof pro);
        for(i=l1-1; i>-1; i--)
        {
            k = l1-i-1;
            for(j=l2-1; j>-1; j--, k++)
            {
                pro[k] += (a[i]-'0')*(b[j]-'0');
                if(pro[k]>9)
                {
                    pro[k+1] += pro[k]/10;
                    pro[k]%=10;
                }
            }
        }
        k = 999;
        for(k=999; k>=0; k--) if(pro[k]) break;
        //cout << k << endl;
        if(k==-1) pf("0");
        for(; k>=0; k--)
            pf("%d", pro[k]);
        pf("\n");
    }

    ///                                    ENDD
   // time_t t2=clock();
   // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
