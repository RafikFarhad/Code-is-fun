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
bool num[11][8];
string pp[25];
int s;

void FUNC(int n)
{
    int i, j;
    for(i=0; i<s+2; i++)
    {
        if(i==0 or i==s+1)
            pp[0] = pp[0] + " ";
        else if(num[n][1])
            pp[0] = pp[0] + "-";
        else
            pp[0] = pp[0] + " ";
    }
    for(i=1; i<s+1; i++)
    {
        if(num[n][6]) pp[i] = pp[i]+"|";
        else pp[i] = pp[i]+" ";
        for(j=0; j< s; j++)
            pp[i] = pp[i]+" ";
        if(num[n][2]) pp[i] = pp[i]+"|";
        else pp[i] = pp[i]+" ";
    }
    for(i=0; i<s+2; i++)
    {
        if(i==0 or i==s+1)
            pp[s+1] = pp[s+1] + " ";
        else if(num[n][7])
            pp[s+1] = pp[s+1] + "-";
        else
            pp[s+1] = pp[s+1] + " ";
    }
    for(i=s+2; i<s+s+2; i++)
    {
        if(num[n][5]) pp[i] = pp[i]+"|";
        else pp[i] = pp[i]+" ";
        for(j=0; j< s; j++)
            pp[i] = pp[i]+" ";
        if(num[n][3]) pp[i] = pp[i]+"|";
        else pp[i] = pp[i]+" ";
    }
    for(i=0; i<s+2; i++)
    {
        if(i==0 or i==s+1)
            pp[s+s+2] = pp[s+s+2] + " ";
        else if(num[n][4])
            pp[s+s+2] = pp[s+s+2] + "-";
        else
            pp[s+s+2] = pp[s+s+2] + " ";
    }
    for(i=0; i<s+s+3; i++)
        pp[i]+=" ";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int a, b, c = 0, i, j, n;;
    char line[100];
    num[0][1] = num[0][2] = num[0][3] = num[0][4] = num[0][5] = num[0][6] = 1;
    num[1][2] = num[1][3] = 1;
    num[2][1] = num[2][2] = num[2][7] = num[2][5] = num[2][4] = 1;
    num[3][1] = num[3][2] = num[3][3] = num[3][4] = num[3][7] = 1;
    num[4][6] = num[4][7] = num[4][2] = num[4][3] = 1;
    num[5][1] = num[5][6] = num[5][7] = num[5][3] = num[5][4] = 1;
    num[6][1] = num[6][6] = num[6][5] = num[6][7] = num[6][3] = num[6][4] = 1;
    num[7][1] = num[7][2] = num[7][3] = 1;
    num[8][1] = num[8][2] = num[8][3] = num[8][4] = num[8][5] = num[8][6] = num[8][7] = 1;
    num[9][1] = num[9][2] = num[9][3] = num[9][4] = num[9][6] = num[9][7] = 1;
//    for(i=0; i<11; i++)
//    {
//        while(1)
//        {
//            takei(j);
//            if(!j) break;
//            pf("num[%d][%d] = ", i, j);
//        }
//        NL;
//    }
    while(sf("%d %s",&s, line)==2 and s)
    {
        a = strlen(line);
     //   if(c++) NL;
        for(i=0; i<2*s+5; i++)
        {
            pp[i] = "";
        }
        for(i=0; i<a; i++)
        {
            FUNC(line[i]-'0');
        }
        for(i=0; i<2*s+3; i++)
        {
            pp[i].pop_back();
        }
        for(i=0; i<2*s+3; i++)
        {
            pf("%s\n", pp[i].c_str());
        }
        NL;
    }




    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}

