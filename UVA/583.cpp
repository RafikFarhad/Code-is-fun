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
bool *prime;

void SEIEVE()
{
    long long int i, j, r=sqrt(SIZE);
    for(i=2; i<r ; i++)
    {
        if(prime[i]==false)
            for(j=2; i*j<SIZE ; j++)
                prime[i*j] = true;
    }
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
    prime = new bool[SIZE];
    SEIEVE();
    vector <long long> pr;
    for(long long i=2; i<SIZE; i++)
        if(!prime[i])
            pr.push_back(i);

    long long data;
    while(sf("%lld", &data)==1 && data!=0)
    {
        if(data==1)
            {
                pf("%lld\n", data);
                continue;
            }
        if(data < 0)
        {
            pf("%lld = -1 x ", data);
            data*=(-1);
        }
        else
            pf("%lld = ", data);
            long long k=sqrt(data), a, b=0, i;
            //cout << k << endl;
            for(i=0; pr[i] < k+10 && data>1; i++)
            {
                //cout << "data " << data << endl;
                if(data%pr[i]==0)
                {
                    while(data%pr[i]==0)
                    {
                        data/=pr[i];
                        pf("%lld", pr[i]);
                        if(data!=1) pf(" x ");
                    }
                }
            }
            if(data!=1) pf("%lld", data);
            puts("");
    }
    delete(prime);
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
