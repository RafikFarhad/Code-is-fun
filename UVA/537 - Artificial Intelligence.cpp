/// Heil Hydra
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
#define CLR(o) memset(o, 0x00, sizeof o)
#define CLR1(o) memset(o, -1, sizeof o)
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define takei(a) scanf("%d", &a)
#define takell(a) scanf("%lld", &a)
#define takellu(a) scanf("%llu", &a)
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause")
#define ok cout << "OK" <<endl;
#define pf printf
#define NL printf("\n")
#define PI 2*acos(0)
#define READ freopen("input.txt","r",stdin);
#define WRITE freopen("output.txt", "w", stdout);

using namespace std;
template <class T> T MAX(T a, T b) { return a>b?a:b;}template <class T> T MIN(T a, T b) { return a<b?a:b;}
template <class T1> void deb(T1 p) { cout << "Debugging: " << p << endl;}
template <class T1, class T2> void deb(T1 p, T2 q) { cout << "Debugging: " << p << "\t" << q  << endl;}
template <class T1, class T2, class T3> void deb(T1 p, T2 q, T3 r) { cout << "Debugging: " << p << "\t " << q << "\t " << r << endl;}
template <class T1, class T2, class T3, class T4> void deb(T1 p, T2 q, T3 r, T4 s) { cout << "Debugging: " << p << "\t " << q << "\t " << r << "\t " << s << endl;}
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 100005

int main()
{
    // time_t t1=clock();
#ifndef ONLINE_JUDGE
    READ;
    //WRITE;
#endif
    ///                                    MAIN
    string line;
    int t, keis=0,  i, j, a;
    double u, I, p, f;
    bool minu = false;
    char ch;
    takei(t);
    getchar();
    while(t--)
    {
        getline(cin, line);
        a = line.find("U=", 0);
        if(a==-1)
            u = -1;
        else
        {
            u = 0.0;
            if(line[a+2]=='-')
            {
                minu = 1;
                a++;
            }
            for(i=a+2; line[i]>='0' && line[i] <='9' ; i++)
            {
                u = 10*u + line[i] - '0';
                //deb(u, line[i]);
            }
            if(line[i]=='.')
            {
                i++;
                for(f=10.0; line[i]>='0' && line[i] <='9' ; i++, f*=10)
                {
                    u = u + (line[i] - '0')/f;
//                    deb(u, line[i]);
                }
            }
            if(minu)
            {
                u *= -1.0;
                minu = 0;
            }
            if(line[i]=='m')  u/=1000;
            else if(line[i]=='k')  u*=1000;
            else if(line[i]=='M')  u*=1000000;
        }
        a = line.find("I=", 0);
        if(a==-1)
            I = -1;
        else
        {
            I = 0;
            if(line[a+2]=='-')
            {
                minu = 1;
                a++;
            }
            for(i=a+2; line[i]>='0' && line[i] <='9' ; i++)
            {
                I = 10*I + line[i] - '0';
                //deb(u, line[i]);
            }
            if(line[i]=='.')
            {
                i++;
                for(f=10.0; line[i]>='0' && line[i] <='9' ; i++, f*=10)
                {
                    I = I + (line[i] - '0')/f;
//                    deb(u, line[i]);
                }
            }
            if(minu)
            {
                I *= -1.0;
                minu = 0;
            }
            if(line[i]=='m')  I/=1000;
            else if(line[i]=='k')  I*=1000;
            else if(line[i]=='M')  I*=1000000;
        }
        a = line.find("P=", 0);
        if(a==-1)
            p = -1;
        else
        {
            p = 0;
            if(line[a+2]=='-')
            {
                minu = 1;
                a++;
            }
            for(i=a+2; line[i]>='0' && line[i] <='9' ; i++)
            {
                p = 10*p + line[i] - '0';
                //deb(u, line[i]);
            }
            if(line[i]=='.')
            {
                i++;
                for(f=10.0; line[i]>='0' && line[i] <='9' ; i++, f*=10)
                {
                    p = p + (line[i] - '0')/f;
//                    deb(u, line[i]);
                }
            }
            if(minu)
            {
                p *= -1.0;
                minu = 0;
            }
            if(line[i]=='m')  p/=1000;
            else if(line[i]=='k') p*=1000;
            else if(line[i]=='M')  p*=1000000;
        }
        if(p<0)
        {
            pf("Problem #%d\nP=%.2lfW\n\n", ++keis, u*I);
        }
        else if(u<0)
        {
            if(I<.00001) NL;
            else pf("Problem #%d\nU=%.2lfV\n\n", ++keis, p/I);
        }
        else
        {
            if(u<.00001) NL;
            else pf("Problem #%d\nI=%.2lfA\n\n", ++keis, p/u);
        }




//        deb(u, I, p);
    }

    /* Coding is FUN  */
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}
