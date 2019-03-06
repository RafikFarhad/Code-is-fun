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
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

long long GCD(long long a, long long b)
{
    return a%b==0?b:GCD(b, a%b);
}

long long LCM (long long a, long long b)
{
    return b = (a*b)/GCD(a,b);
}

int main()
{
    //time_t t1=clock();
    //freopen("414.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    ///                                    MAIN
    long long data;
    long long i, j, k;
    vector <long long> factor;
    while(sf("%lld", &data)==1 && data)
    {
        if(data==1)
        {
            pf("1 1\n");
            continue;
        }
        factor.clear();
        long long k = sqrt(data);
        for(i=1; i<=k; i++)
        {
            if(i*i==data)
                factor.push_back(i);
            else if(data%i==0)
            {
                factor.push_back(i);
                factor.push_back(data/i);
            }
        }
        long long cow = 0;
        //for(i=0; i< factor.size(); i++) cout << factor[i] << endl;
        for(i=0; i< factor.size(); i++)
            for(j=i; j < factor.size(); j++)
                if(LCM(factor[i], factor[j])==data)
                    cow++;
        pf("%lld %lld\n", data, cow);
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

