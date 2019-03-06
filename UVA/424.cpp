/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
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
#define MAX3(a, b, c) MAX(a , MAX(b,c))
#define sf scanf
#define ssf sscanf
#define pf printf
#define PI 2*acos(0)
using namespace std;

template <class T> T MAX(T a, T b)
{
    return a>b?a:b;
}
template <class T> T MIN(T a, T b)
{
    return a<b?a:b;
}
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}
char a[1001][1001], res[1005];
void SUM(int );

int main()
{
    //time_t t1=clock();
    freopen("424.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    ///                                    MAIN
    int i=0, j, k, l;
    while(1)
    {
        gets(a[i]);
        if(strlen(a[i])==1 && a[i][0]=='0') break;
        i++;
    }
    //sort(a, a+(i+1), COMPA);
    strcpy(res, a[0]);
   // cout << a[1] << endl;
    for(j = 1; j<i; j++)
    {
        SUM(j);
    }
    cout << res << endl;
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

void SUM(int n)
{
    //cout << "Start of SUM()  " << a[n] << " -> " << res << endl;
    char res2[105];
    int l = strlen(a[n]),   l_b=strlen(res), p, q, i, sum, carry=0;
    int k = l>l_b?l:l_b;
    //cout << "k = " << k << endl<< endl;
    res2[k] = '\0';
    for(i=k-1; i>-1; i--)
    {
        if(l-->0) p = a[n][l] - '0';
        else p = 0;
        if(l_b-->0) q = res[l_b] - '0';
        else q = 0;
           //cout << "p = " << p << "  q = " << q << endl;
        sum = p+q+carry;
        carry = 0;
        if(sum>9) carry = sum/10;
        sum %=10;
        res2[i] = sum + '0';
    }
    strcpy(res, res2);
    //cout << "res -> " << res << endl;
    if(carry)
    {
        for(i=k, res[k+1]='\0'; i>0; i--)
            res[i] = res[i-1];
    res[0] = carry+'0';
    }
    //cout << "final  " <<  res << endl;
}
