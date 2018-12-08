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

template <class T> T MAX(T a, T b) { return a>b?a:b;}
template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T> void MyDebug(T x, T y){ cout << "Debugging: " << x << ", " << y << endl;}
template <class T> void MyDebug(T x, T y, T z) { cout << "Debugging: " << x << ", " << y << ", " << z << endl;}

bool COMPA(char a, char b)
{
    int d = tolower(a) - tolower(b);
    return d?d<0:a<b;
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
    string a, b;
    int t, len, i, j, k;
    sf("%d ", &t);
    while(t--)
    {
        cin >> a;
        b = a;
        //len = a.size();
        /*for(i=0; i<26; i++)
            for(j=0; j<len; j++)
                {
                    if(a[j] == 'A'+i) b+=('A'+i);
                    if(a[j] =='a'+i) b+=('a'+i);
                }*/
        //cout << b << endl;;
        //map <string, bool> mp;
        sort(b.begin(), b.end(), COMPA);
        do
        {
            cout << b << endl;
        }
        while(next_permutation(b.begin(), b.end(), COMPA));
    }

    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
