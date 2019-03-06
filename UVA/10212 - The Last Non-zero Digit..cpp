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
/******************************************/
/** Author     : Rafik Farhad              */
/** Mail to     : rafikfarhad@gmail.com   */
/*****************************************/
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
#define PI                                         2*acos(0)
#define all(o)                                      o.begin(), o.end()

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 20000007
                      //20000000

//int BIGMOD(int b, int p, int mod)
//{
//    if(p==0) return 1;
//    int r = BIGMOD(b, p/2, mod);
//    r = (r*r)%mod;
//    if(p&1) r = (r*(b%mod))%mod;
//    return r;
//}
//bool *p;
//vector <int> prime;
//int ss;
//
//void SEIEVE()
//{
//    int i, j, l = sqrt(SIZE+55), ll = sqrt(l+55);
// //   deb(l, ll);
//    p = new bool[l+55];
//    for(i=2; i<ll; i++)
//    {
//        if(!p[i])
//        {
//            prime.pb(i);
//            for(j=i*i; j<l; j+=i)
//                p[j] = 1;
//        }
//    }
//    for(i=ll; i<l; i++)
//        if(!p[i])
//        prime.pb(i);
//    ss = prime.size();
//    for(i=2; i<100; i++)
//        if(!p[i])
//      //  deb(i);
//    return;
//}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, keis=0, n, r, res;
    //map <int, int> mp;
   // SEIEVE();
    //deb(ss);
    //deb(BIGMOD(11, 2, 100));

    while(sf("%lld %lld", &n, &r)!=EOF)
    {
        //mp.clear();
        if(r==0)
        {
            pf("%lld\n", 1);
            continue;
        }
        //n++;
        res = 1;
       // deb(n-r);
        for(i=n; i>=n-r+1; i--)
        {
            res = res*i;
            while(res%10==0) res/=10;
            res%=1000000000;
//            t = i;
//            for(j=0; j<ss and t>1; j++)
//            {
//                if(t%prime[j]==0)
//                {
//                    l = 0;
//                    while(t%prime[j]==0)
//                    {
//                        l++;
//                        t/=prime[j];
//                    }
//                    mp[prime[j]]+=l;
//                }
//            }
//            if(t>1) mp[t]++;
        }
//        res = 1;
//        if(mp[2]>mp[5])
//        {
//            mp[2]-=mp[5];
//            mp[5] = 0;
//        }
//        else
//        {
//            mp[5]-=mp[2];
//            mp[2] = 0;
//        }
//        for(auto i:mp)
//        {
//        //    deb(i.first, i.second);
//            res = (res*BIGMOD(i.first, i.second, 10))%10;
//        }

        pf("%lld\n", res%10);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

