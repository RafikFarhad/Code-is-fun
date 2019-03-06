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
string sp = "                                                                                            ",
hi = "-------------------------------------------------------------------------------";
bool COMPA(string a, string b)
{
    //if(a.size())
    return a < b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int line, i, j, n, max_per_line, total_line, max_word, a, b, p, q;
    string  temp, aa[105];
    vector <string> cc;
    while(sf("%d", &n)==1)
    {
        getchar();
        cc.clear();
        max_word = 0;
        for(i=0; i<n; i++)
        {
            cin >> temp;
            cc.pb(temp);
            max_word = max(max_word, (int)temp.size());
        }
        sort(cc.begin(), cc.end(), COMPA);

        max_per_line = (60-max_word)/(max_word+2) +1;
        if(max_word>58) max_per_line = 1;
        //deb(max_per_line);
        line = ceil(n/(double)max_per_line);
        //deb(line);
        for(i=0; i<line; i++) aa[i] = "";
        for(i=0; i<n; i++)
        {
            j = i%line;
            if(aa[j].size()) aa[j] += "  ";
            aa[j]+=cc[i];
            temp = sp.substr(0, max_word-cc[i].size());
            aa[j] += temp;
        //    if( i/line != max_per_line-1)
            {
            //     if(i+1!=n) aa[j]+="**";
            }
            //if(i/line!=max_per_line)
        }
        pf("%s\n", hi.substr(0, 60).c_str());
        for(i=0; i<line; i++)
            pf("%s\n", aa[i].c_str());
//        NL; NL;
    }


    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

