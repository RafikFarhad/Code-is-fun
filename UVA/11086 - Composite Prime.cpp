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
#include <iterator>
/***********************/
/** Rafik Farhad      **/
/***********************/

#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                 scanf("%d", &a)
#define takell(a)                                scanf("%I64d", &a)
#define takellu(a)                               scanf("%I64uu", &a)
#define sf                                          scanf
#define pb                                         push_back
#define mp                                         make_pair
#define ppp                                       system("pause")
#define ok                                         cout << "OK" <<endl;
#define pf                                         printf
#define NL                                        printf("\n")
#define PI                                         2*acos(0.0)

using namespace std;
template <class T1> void deb(T1 p)
{
    cout << "Debugging: " << p << endl;
}
template <class T1, class T2> void deb(T1 p, T2 q)
{
    cout << "Debugging: " << p << "\t" << q  << endl;
}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;
}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s)
{
    cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;
}
long long POOW(long long b, long long p)
{
    if(p==0) return 1;
    return b*POOW(b, p-1);
}
const int xx[] = {1, -1, 0, 0};
const int yy[] = {0, 0, 1, -1};
//const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
//const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};
#define SIZE 1000006
bool prime[SIZE];
vector <int> p;
int ss;

void SEIEVE()
{
    int i, j, lim = sqrt(SIZE) + 1;
    for(i=2; i<=lim; i++)
    {
        if(prime[i]==0)
        {
            for(j=i*i; j<SIZE; j+=i)
                prime[j] = 1;
        }
    }
    prime[1] = 1;
    for(i=1; i<SIZE; i++)
        if(!prime[i])
            p.pb(i);
    ss = p.size();
    //deb(ss);
    //deb(p[ss-1]);
    return;
    //deb(p[0],p[1]);
}


int main()
{
#ifndef ONLINE_JUDGE
  freopen("00.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    int i, j, k, l, m, n, t;
    SEIEVE();
    while(sf("%d", &n)!=EOF)
    {
        l = 0;
        //deb("n", n);
        for(i=0; i<n; i++)
        {
            takei(t);
            //deb("--", t);
            if(!prime[t]) ;
            else
            {
                for(j=0; j<ss; j++)
                {
                    if(t%p[j]==0)
                    {
                        if(!prime[t/p[j]])
                        {
                            l++;
                            break;
                        }
                        else
                            break;
                    }
                }
            }
            //else l++;
        }
        pf("%d\n", l);
    }
    return 0;
}


