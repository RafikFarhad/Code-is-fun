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
#define SIZE 1000000
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
vector <int> lists;
bool *prime;
void SEIEVE()
{
    long long int i, j, r=sqrt(SIZE), k;
    for(i=4; i<=SIZE; i+=2)
        prime[i] = true;
    for(i=3; i*i<=SIZE ; i++)
    {
        if(prime[i]==false)
            for(j=i*i; j<SIZE ; j+= i*2)
            {
                prime[j] = true;
            }
    }
    lists.clear();
    lists.pb(2);
    for(i=3; i<SIZE ; i+=2)
        if(!prime[i]) lists.pb(i);
}
  bool IS_PRIME(int a)
  {
      if (a<SIZE) return (!prime[a]);
      int index =0;
      while(lists[index]*lists[index]<=a)
        {
            //cout << lists[index] << endl;
            if(a%lists[index]==0) return false;
            index++;
        }
       // cout << a << endl;
      return true;
  }

int main()
{
    // time_t t1=clock();
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#ifndef ONLINE_JUDGE
    //freopen("10200.inp","r",stdin);
#endif
    ///                                    MAIN
    prime = new bool[SIZE];
    SEIEVE();
    bool ar[10010];
    for(int i=0; i<10001; i++)
    {
        ar[i] = false;
        int sum = i*i + i + 41;
        if(IS_PRIME(sum))
            ar[i] = true;
    }

    int i, a, b, cow;
    while(sf("%d %d", &a, &b)!=EOF)
    {
        cow = 0;
        for(i=a; i<=b; i++)
            if(ar[i]) cow++;
        pf("%.2lf\n", (100.0*cow)/(double)(b-a+1) + 1e-9);
    }

    /*for(int i=2; i<100; i++)
        if(!prime[i])
            printf("%d, ", i);*/
    delete(prime);
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
