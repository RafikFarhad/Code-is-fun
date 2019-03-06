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
#include <bitset>
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
string zero = "000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";

string SUM(string a, string b)
{
    int i, j, s1 = a.size(), s2 = b.size(), k, carry = 0, rem;
    char c;
    string r = "";
    if(s2>s1)
    {
        a = zero.substr(0, s2-s1) + a;
    }
    for(i=s2-1; i>=0; i--)
    {
        k = a[i] + b[i] - '0' - '0' + carry;
        carry = k/10;
        k%=10;
        c = k+'0';
        r = c+r;
    }
    if(carry)
    {
        c = carry+'0';
        r = c+r;
    }
    return r;
}

bool COMPA(string a, string b)
{
    if(a.size()==b.size())
        return a<b;
    return a.size()<b.size();
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0;
    vector <string> v;
    string a, b, c;
    a = "1";
    b = "2";
    v.pb(a);
    v.pb(b);
    while(b.size()<=100)
    {
        c = SUM(a, b);
        a = b;
        b = c; //keis++;
        v.pb(c);
        //deb(c);
    }
    while(cin >> a >> b)
    {
        if(a=="0" and b == "0") break;
        t = 0;
        for(auto it:v)
        {
           // deb(it);
            if( min(it, a, COMPA)==a and max(it, b, COMPA)==b) t++;
        }
        pf("%d\n", t);
    }
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

