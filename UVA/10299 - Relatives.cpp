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

///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100000009
bool *p;
vector<int> v;
int ss;

//void SEIEVE()
//{
//    long long i, j, l = sqrt(SIZE)+1, ll = sqrt(l)+10;
//    p = new bool[l+5];
//    v.clear();
////    for(i=4; i<l; i+=2)
////        p[i] = 1;
//   // deb(l, ll);
//    p[1] = 1;
//    for(i=2; i<l; i++)
//    {
//        if(p[i]==0)
//        {
//            for(j=i*i; j<l; j+=i)
//                p[j] = 1;
//        }
//    }
//    for(i=2; i<l; i++)
//        if(!p[i])
//            v.pb(i);
//            //deb(i);
//    ss = v.size();
//    //deb(p[0]);
//     //       deb(ss);
//    return ;
//}

long long PHI(long long t)
{
    long long i, ans =t;
    if(t==1) return 1;

    if(t%2==0)
    {
        ans-=(ans/2);
        while(t%2==0) t>>=1;
    }
    for(i=3; i*i<=t; i++)
        if(t%i==0)
        {
            ans-=(ans/i);
            while(t%i==0) t/=i;
        }
    if(t>1) ans-=(ans/t);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    long long i, j, k, l, t, p, keis=0;
    //SEIEVE();
    while(sf("%lld", &t)==1 and t)
    {
//        k = 1;
//        p=t;
//        for(i=0; i<ss and t>1; i++)
//        {
//            if(t%v[i]==0)
//            {
//                l=0;
//                while(t%v[i]==0)
//                {
//                    l++;
//                    t/=v[i];
//                }
//                deb(v[i], l);
//                k = k*(l+1);
//            }
//        }
//        if(t>1) k<<=1;
        pf("%lld\n", PHI(t));
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

