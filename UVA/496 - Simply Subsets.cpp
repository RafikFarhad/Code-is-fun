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

vector <int> v[4];

void PROCESS(char a[], int p)
{
  //puts(a);
    int i, j, n, l = strlen(a), m;
    map <int , bool> mp;
    v[p].clear();
    for(i=n=0, m=0; i<l; i++)
    {
       // if(!n and a[i]=='-')
           // m = 1;
       // deb(n, a[i]);
       if(!isdigit(a[i]))
        {
            if(a[i]=='-') m = 1;
            if(!n) continue;
            if(m)
            n*=-1;
            m=0;
            if(a[i]=='-') m = 1;
            if(mp[n])
            {
                //m = 0;
                n = 0; continue;
            }
            mp[n] = 1;
            v[p].pb(n);
            n = 0;
        }
        else n = (n*10) + (a[i]-'0');
        //if(!isdigit(a[i])) m =0;
    }
    if(n)
    {
        if(m) n*=-1;
        if(!mp[n]) v[p].pb(n);
    }
    sort(v[p].begin(), v[p].end());
//    for(i=0; i<v[p].size(); i++)
//            cout << v[p][i] << " ";
//    NL;
    return ;
}

bool CHECK(int a, int b)
{
    //deb(a, b);
    int i, j, l = v[a].size(), m = v[b].size();
    for(i=0, j=0; i<l and j<m;)
    {
        //deb(v[a][i], v[b][j], i, j);
        //if(i and (v[a][i]==v[a][i-1])) i++;
        if(v[a][i]==v[b][j])
        {
            i++;
            //while(v[b][j]==v[b][j+1] and j<m) j++;
            j++;
        }
        else j++;
    }
    return i==l;
}

bool YES()
{
    int a = 1, b = 2;
    int i, j, l = v[a].size(), m = v[b].size();
    for(i=0; i<l ;i++)
    {
        if(i and (v[a][i]==v[a][i-1])) i++;
        for(j=0; j<m; j++)
            if(v[a][i]==v[b][j])
                return 1;
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, n, a, b, c, d;
    char line[10000];
    while(gets(line))
    {
        if(strlen(line)==0) continue;
        PROCESS(line, 1);
        gets(line);
        PROCESS(line, 2);//A and B are disjoint
        //deb(v[1].size(), v[2].size());
        a = CHECK(1, 2);
        b = CHECK(2 , 1);
        if(a and b)
            pf("A equals B");
        else if(b)
            pf("B is a proper subset of A");
        else if (a)
            pf("A is a proper subset of B");
        else if(YES())
            pf("I'm confused!");
        else
            pf("A and B are disjoint");

        NL;

//        for(i=0; i<v[1].size(); i++)
//            cout << v[1][i] << " ";
//        NL;
//        for(i=0; i<v[2].size(); i++)
//            cout << v[2][i] << " ";
//        NL;

    }



    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

//A equals B
//B is a proper subset of A
//A is a proper subset of B
//A and B are disjoint
//I'm confused!
