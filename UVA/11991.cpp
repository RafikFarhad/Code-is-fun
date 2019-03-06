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
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

int main()
{
    //time_t t1=clock();
    //freopen("11991.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    long long n, m, k, v, i, j;
//    vector <int> big[10006];
  //  big = new int [1000006];
    while(sf("%lld %lld", &n, &m)!=EOF)
    {
        map <int, vector<int> > big;
       // big = new int [1000];
        for(i=0; i<n; i++)
        {
            sf("%lld", &j);
            big[j].push_back(i+1);
        }
        for(j=0; j<m; j++)
        {
            sf("%lld %lld", &k, &v);
            if(big.count(v) && big[v].size()> --k) pf("%d", big[v][k]);
            else putchar('0');
            pf("\n");
        }
//        delete(big);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}





