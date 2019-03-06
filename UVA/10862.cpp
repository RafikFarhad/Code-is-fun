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

void SUM(int n);
char a[4010][1220];
int main()
{
    //                                        PRE CALCULATION
    int i;
    a[0][0] = '1';
    a[1][0] = '2';
    for(i=2; i<4003; i++)
    {
        SUM(i);
    }
    //                                 CODE STARTS
    while(sf("%d", &i)==1 && i)
    {
        pf("%s\n", a[(i-1)*2]);
    }
    return 0;
}
void SUM(int n)
{
    int l=strlen(a[n-1]), l_b=strlen(a[n-2]), p, q, i, sum, carry=0;
    a[n][l] = '\0';
    for(i=l-1; i>-1; i--)
    {
        p = a[n-1][i] - '0';
        if(--l_b<0) q = 0;
        else q = a[n-2][l_b] - '0';
        //   cout << "p = " << p << "  q = " << q << endl;
        sum = p+q+carry;
        carry = 0;
        if(sum>9) carry = sum/10;
        sum %=10;
        a[n][i] = sum + '0';
    }
    if(carry)
    {
        for(i=l, a[n][l+1]='\0'; i>0; i--)
            a[n][i] = a[n][i-1];
        a[n][0] = carry+'0';
    }
}

