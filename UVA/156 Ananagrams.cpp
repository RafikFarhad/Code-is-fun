
/*Ghost Return*/


#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
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
/******************************************/
/** Author      : Rafik Farhad            */
/** Mail to     : rafikfarhad@gmail.com   */
/** Created     : 2018-11-08             */
/** Status      : AC                    */
/******************************************/
#define CLR(o)                                  memset(o, 0x00, sizeof o)
#define CLR1(o)                                 memset(o, -1, sizeof o)
#define takei(a)                                scanf("%d", &a)
#define takell(a)                               scanf("%lld", &a)
#define takellu(a)                              scanf("%llu", &a)
#define sf                                      scanf
#define pb                                      push_back
#define mp                                      make_pair
#define ppp                                     system("pause")
#define ok                                      cout << "OKA" <<endl;
#define pf                                      printf
#define NL                                      printf("\n")
#define PI                                      2*acos(0)
#define all(o)                                  o.begin(), o.end()
#define csi                                     pf("Case %d: ", ++keis)
#define csii                                     pf("Case %d:\n", ++keis)
#define _(o)                                    pf("%d\n", o)
#define ll                                      long long
#define ull                                     unsigned long long
#define exx                                     2.7182818284590452353602875
#define xx                                      first
#define yy                                      second
#define debArr(o)                               copy(o.begin(), o.end(), ostream_iterator<short>(cout, "->")); cout << endl;
#define debStrArr(o)                               copy(o.begin(), o.end(), ostream_iterator<string>(cout, "->")); cout << endl;
///Helper
using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void __(T1 p) { cout << p << endl;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(long long b, long long p) { if(p==0) return 1; return b*POOW(b, p-1);}
//int SET(int mask, int pos){return mask  singlebar  (1<<pos);}
//bool CHK(int mask, int pos){return (1&(mask>>pos));}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define LT (1<<31)-1
#define MX
#define MOD
//#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}

void getValues(char pp[], vector <string> &answer)
{
    int l = strlen(pp);
    int g = 0;
    int a = 0;
    char p[100];
    int i, j, k;
    for(i = 0; i<l; i++)
    {
        if(pp[i] == '\n')
        {
            continue;
        }
        if(pp[i] != ' ')
        {
            p[a++] = pp[i];
        }
        else
        {
            p[a++] = '\0';
            answer.pb(string(p));
            a = 0;
            p[0] = '\0';
        }
    }
    {
            p[a++] = '\0';
            answer.pb(string(p));
            a = 0;
            p[0] = '\0';
    }
    return;
}

string toLower(string &p)
{
    string q = "";
    for(auto a: p)
    {
        q += tolower(a);
    }
    return q;
}

bool checkAnanagrams(string p, vector<string> words)
{
    p = toLower(p);
    sort(all(p));
    // deb(p);
    int c = 0;
    for(auto a : words)
    {
        // deb(a);
        if(p==a)
        {
            c++;
        }
    }
    return c<=1;
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    //freopen("/home/rafikfarhad/Desktop/000.txt","r",stdin);
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
    char pp[10000];
    vector <string> words, dictionary,dictionary2, res;
//    fgets(pp, 100, stdin);
    // while(sf("%[^\n]s", pp))
    while(fgets(pp, 10000, stdin))
    {
        if(pp[strlen(pp)-1] == '#') break;
        if(pp[strlen(pp)-2] == '#') break;
        getValues(pp, words);
    }
    for(int i=0; i<words.size(); i++)
    {
        string a = words[i];
        if(a=="") continue;
        dictionary2.push_back(a);
        a = toLower(a);
        sort(all(a));
        dictionary.push_back(a);
    }
    
    res.clear();
    for(i=0; i<dictionary.size(); i++)
    {
        if(checkAnanagrams(dictionary[i], dictionary))
        {
            res.pb(dictionary2[i]);
        }
    }
    sort(all(res));
    for(i = 0; i<res.size(); i++)
    {
       pf("%s\n", res[i].c_str());
    }

    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    // pf("-------ENDS OF OUTPUT------\n\n");
    pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}


