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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%I64d", &a)
#define takellu(a) scanf("%I64uu", &a)
#define sf scanf
#define pb push_back
#define mp make_pair
#define ppp system("pause")
#define ok cout << "OK" << endl;
#define pf printf
#define NL printf("\n")
#define PI 2 * acos(0)

///Helper
using namespace std;
template <class T>
T MAX(T a, T b) { return a > b ? a : b; }
template <class T>
T MIN(T a, T b) { return a < b ? a : b; }
template <class T1>
void deb(T1 p) { cout << "Debugging: " << p << endl; }
template <class T1, class T2>
void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q << endl; }
template <class T1, class T2, class T3>
void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl; }
template <class T1, class T2, class T3, class T4>
void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl; }
long long int POOW(int b, int p)
{
    if (p == 0)
        return 1;
    return b * POOW(b, p - 1);
}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1}; // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 10000007
int arr[SIZE], sod[SIZE], more_fun[SIZE], val[SIZE];
int SOD(int n)
{
    int s = 0;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }
    return s;
}

int fun(int a)
{
    int i;
    for (i = max(1, a - 100); i <= a; i++)
    {
        if (i + sod[i] == a)
        {
            return i;
        }
    }
    return -1;
}
int fun(int a, int b)
{
    if (a > b)
        return 0;
    int p = val[a - 1];
    int q = val[b];
    return q - p;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, t, a, b, c;
    char input[1000], pp;
    val[0] = 0;
    for (i = 0; i < SIZE; i++)
    {
        sod[i] = SOD(i);
        more_fun[i] = fun(i);
        if(i)
        {
            val[i] = val[i - 1];
        }
        if (more_fun[i] == -1 and i)
        {
            val[i] = val[i - 1] + 1;
        }
        // deb(i, more_fun[i], val[i]);
    }
    takei(t);
    sf("%c", &pp);
    k = 0;
    while (t-- && fgets(input, 100, stdin))
    {
        c = sscanf(input, "%d %d\n", &a, &b);
        pf("Case %d: ", ++k);
        if (c == 1)
        {
            pf("%d\n", more_fun[a]);
        }
        else
        {
            pf("%d\n", fun(a, b));
        }
    }

    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
