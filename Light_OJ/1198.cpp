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
#define SIZE INT_MAX
bool COMPA(int a, int b)
{
    return a>b
;}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, t, keis = 0, ans, p, q, r, s, n, k;
    takei(t);
    vector <int> a, b;
    while(t--)
    {
        takei(n);
        a.clear();
        b.clear();
        for(i=0; i<n; i++)
        {
            takei(p);
            a.pb(p);
        }
        for(i=0; i<n; i++)
        {
            takei(p);
            b.pb(p);
        }
        sort(a.begin(), a.end(), COMPA);
        sort(b.begin(), b.end(), COMPA);
//        for(i=0; i<n; i++)        {
//            cout << a[i] << ", ";
//        }NL;        for(i=0; i<n; i++)
//        {            cout << b[i] << ", ";        }
//        NL;
        for(i=ans = j = 0; i<n and j<n; i++)
        {
            if(a[i]==-1) continue;
            if(b[j]==-1)
            {
                j++, i--;
                continue;
            }

            //deb(a[i], b[j]);
            if(a[i]>b[j])
            {
                k = i;
                a[k] = -1;
                b[j] = -1;
                j++;
                i--;
                ans+=2;
            }
            else if(a[i]<b[j])
            {
//                 ok
                for(k=j; k<n; k++)
                {
                        if(a[i]>b[k] and b[k]!=-1)
                        {
                            ans+=2;
                            a[i] = -1;
                            b[k] = -1;
                            break;
                        }
                }
                if(k==n)
                {
                    for(k=j; k<n; k++)
                    {
                            if(a[i]==b[k] and b[k]!=-1)
                            {
                                ans+=1;
                                a[i] = -1;
                                b[k] = -1;
                                break;
                            }
                    }
                }
                if(k==n)
                {
                    for(k=n-1; k>=0; k--)
                        if(a[k]!=-1)
                        {
                            //ans-=2;
                            a[k] = -1;
                            b[j] = -1;
                            j++;
                            i--;
                            break;
                        }
                }
            }
            else
            {
                p = 0;
                if(!p)//i+1<n and j+1 <n and a[i]!=-1 and a[i+1]==b[j+1])
                {
                    for(k=j+1; k<n; k++)
                    {
                        if(a[i]>b[k] and b[k]!=-1)
                        {
                            ans+=2;
                            b[k]= -1;
                            a[i] = -1;
                            i--;
                            p  = 1;
                            break;
                        }
                    }
                }
                else if(!p)
                {
                    a[i] = -1;
                    b[j] = -1;
                    ans++;
                    j++;
                }
            }
        }

        pf("Case %d: %d\n", ++keis, ans);
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


