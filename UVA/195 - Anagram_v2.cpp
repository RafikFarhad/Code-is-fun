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
#define PI 2*acos(0)
#define SIZE 10000000
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



int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("195.inp","r",stdin);
#endif
    ///                                    MAIN
    string a;
    map <int , string> mp;
    int t, len, i, j, k, ar[1000];
    sf("%d ", &t);
    while(t--)
    {
        cin >> a;
        mp.clear();
        len = a.size();
        for(j=0; j<len; j++)
        {
            k = a[j];
            if(k>='A' && k<='Z')
                k = k*2;
            else k = 131+((k-'a')*2);
            mp[k] = a[j];
            ar[j] = k;
        }
        for(j=0; j<len; j++)
            cout << mp[ar[j]];
        cout << endl;
        while(next_permutation(ar, ar+len))
        {
            for(j=0; j<len; j++)
                cout << mp[ar[j]];
            cout << endl;
        }
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
