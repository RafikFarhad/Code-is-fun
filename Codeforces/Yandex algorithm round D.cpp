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
#define takell(a)                                scanf("%I64lld", &a)
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
long long int POOW(int b, int p) { if(p==0) return 1; return b*POOW(b, p-1);}
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1}; const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2}; const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // KX-> Knight moves xx-> diagonal -> 8 horizontal/vertical->4
#define SIZE 200010
int part = 555;//= ceil(sqrt(SIZE)) ;
class DATA
{
public:
    int l, r, id, block;
    DATA(int a=0, int b=0, int c=0)
    {
        l = a;
        r = b;
        id = c;
        block = a/part;
    };

};
bool COMP(const DATA a, const DATA b)
{
    if(a.block==b.block)
        return a.r<b.r;
    return a.block<b.block;
}
DATA in[SIZE];
long long ans[SIZE], res;
int ar[SIZE], cnt[1000006];
int n, q;

void ADD(int pos)
{

    res = res + (long long)(2ll*(long long)cnt[ar[pos]]*ar[pos]+(long long)ar[pos]);

    cnt[ar[pos]]++;

    //deb(res);
}

void REMOVE(int pos)
{

    res = res - (long long)(2ll*(long long)cnt[ar[pos]]*ar[pos]-(long long)ar[pos]);

    cnt[ar[pos]]--;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("000.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ///                                    MAIN
    int i, j, k, l, t, keis=0, left, right;
    takei(n);
    takei(q);
    part = sqrt(n)+1;
    //deb(part);
    for(i=0; i<n; i++)
        sf("%d", &ar[i]);
    for(i=0; i<q; i++)
    {
        takei(j);
        takei(k);
        DATA temp = DATA(j-1, k-1, i);
        in[i]= temp;
    }
    sort(in, in+q, COMP);
    int mo_l = 0, mo_r = 0;
    res = 0ll;
   //     for(i=0; i<q; i++)
            //deb(in[i].l, in[i].r, in[i].id);
    for(i=0; i<q; i++)
    {
        left = in[i].l;
        right = in[i].r;
       // if(right==19) deb(mo_l, mo_r,res);
      //  deb(mo_l, mo_r, left, right);NL; NL;
        while(mo_r<=right)
        {
            ADD(mo_r);
           // deb(mo_r, res);
            mo_r++;
        }
        //ok
        //deb(left, right, res);NL; NL;
        while(mo_r>right+1)
        {
            REMOVE(mo_r-1);
            mo_r--;
        }

        while(mo_l<left)
        {
            //deb(mo_l, mo_l+1);
            REMOVE(mo_l);
            mo_l++;
        }
        //deb(mo_l, mo_r, res);
        while(mo_l>left)
        {//deb("P");
            ADD(mo_l-1);
            mo_l--;
        }
        //deb(res);

        //deb(mo_l, mo_r, res);
        ans[in[i].id] = res;
    }
    for(i=0; i<q; i++)
        pf("%lld\n", ans[i] );
    /* Coding is FUN  */
    ///                                    ENDD
    return 0;
}
/*
20 8

1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2 1 2

4 15

1 2

2 20

7 7

13 18

7 7

3 19

3 8
*/
