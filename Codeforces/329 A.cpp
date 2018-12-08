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
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE INT_MAX

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int n, ar[150][29], i, j, k, l, t, keis=0;
    string a[150], b, c[150], p;
    while(cin >> n)
    {
        CLR(ar);
        for(i=0; i<n; i++)
        {
            cin >> a[i];
            p = a[i];
            for(j=0; j<p.size(); j++)
            {
                ar[i][p[j]-'a'] = 1;
            }
            for(j=0, k=0;j<26; j++)
            {
                if(ar[i][j]) k++;
            }
            ar[i][27] = k;
        }
        int maxi = 0;

        for(i=0;i<26; i++)
        {
            for(j=i+1; j<26; j++)
            for(j=i+1; j<26; j++)
            {
                k = 0;
                for(l=0; l<n; l++)
                {
                    if(ar[l][27]>2) continue;
                    else if(ar[l][27]==1 and (ar[l][i] or ar[l][j])) k+=a[l].size();
                    else if(ar[l][i] and ar[l][j]) k+=a[l].size();
                }
                maxi = max(k, maxi);
                //pf("%c %c %d\n", i+'a', j+'a', k);
            }
        }
        cout << maxi << endl;
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}


