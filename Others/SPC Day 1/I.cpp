
/*Winter is coming*/


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
/*****************************************************/
/** Author      : Rafik Farhad                       */
/** Mail        : github.com/RafikFarhad/Code_is_fun */
/** Created on  : 2017-03-23-22.32 _ Thursday       */
/****************************************************/
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
#define MY INT_MIN
//ll FAST_EXP(ll base, ll power) /*base^power%MOD*/   {ll res=1ll;while(power){if(power&1)res=(res*base)%MOD;base=(base*base)%MOD;power>>=1;}return res%MOD;}


class SuffixArray
{
public:
    const int L;
    string s;
    vector<vector<int> > P;
    vector<pair<pair<int,int>,int> > M;

    SuffixArray(const string &s) : L(s.length()), s(s), P(1, vector<int>(L, 0)), M(L)
    {
        for (int i = 0; i < L; i++) P[0][i] = int(s[i]);
        for (int skip = 1, level = 1; skip < L; skip *= 2, level++)
        {
            P.push_back(vector<int>(L, 0));
            for (int i = 0; i < L; i++)
                M[i] = make_pair(make_pair(P[level-1][i], i + skip < L ? P[level-1][i + skip] : -1000), i);
            sort(M.begin(), M.end());
            for (int i = 0; i < L; i++)
                P[level][M[i].second] = (i > 0 && M[i].first == M[i-1].first) ? P[level][M[i-1].second] : i;
        }
    }
    vector<int> GetSuffixArray()
    {
        //return P.back();
        return Reverse_Suffix_Array(); /// This is the original Suffix Array
    }

    vector<int> LCP_Array()
    {
        vector<int> lcp(s.length()), SA = P.back(), RSA = Reverse_Suffix_Array();

        /*for(int i=0; i<s.length(); i++)
        deb(i, s.substr(RSA[i]));*/
        for(int i=1; i<s.length(); i++)
            lcp[i] = LongestCommonPrefix(RSA[i-1], RSA[i]);
        /* for(int i=0; i<s.size(); i++)
        deb(i, lcp[i]);*/
        return lcp;
    }
    vector<int> Reverse_Suffix_Array()
    {
        vector<int> lcp(s.length()), SA = P.back(), RSA(s.length());
        for(int i=0; i<s.length(); i++)
            RSA[SA[i]] = i;
        return RSA;
    }

// returns the length of the longest common prefix of s[i...L-1] and s[j...L-1]
    int LongestCommonPrefix(int i, int j)
    {
        int len = 0;
        if (i == j) return L - i;
        for (int k = P.size() - 1; k >= 0 && i < L && j < L; k--)
        {
            if (P[k][i] == P[k][j])
            {
                i += 1 << k;
                j += 1 << k;
                len += 1 << k;
            }
        }
        return len;
    }
};
int n, l, endadd[100005];
string all, tt;


int main()
{
    //ios_base::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
    freopen("/home/looser/Desktop/000.txt","r",stdin);
    //freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    //clock_t ooo = clock();
#endif
    ///                                    MAIN
    int i, t, j, k, l,  keis(0), c, d, x, y, a, b;
//    char pp[100];
//    fgets(pp, 100, stdin);
    cin >> all;
    l = all.size();
    SuffixArray p = SuffixArray(all);
    int q;
    vector <int> SA = p.GetSuffixArray();

    takei(q);
    for(i=0; i<l; i++)
    {
        deb(i, SA[i]);
    }

    int tot = 0, ans1=-1, ans2;
    tot = 0;
    for(i=0; i<l; i++)
    {
        {
            tot = tot + l - SA[i];
        }
        if(tot>=q)
        {
            ans1 = SA[i];
            ans2 = tot-q;
            break;
            ok
        }
    }
    deb(tot);
    if(ans1==-1)
    {
        pf("No such line.\n");
    }
    else
    {
        cout << all.substr(ans1, ans2);
    }


    /* Coding is FUN  */
    ///                                    ENDD
#ifndef ONLINE_JUDGE
    //pf("-------ENDS OF OUTPUT------\n\n");
    //pf("Time Elapsed: %lu\n", (clock()-ooo));
#endif
    return 0;
}



