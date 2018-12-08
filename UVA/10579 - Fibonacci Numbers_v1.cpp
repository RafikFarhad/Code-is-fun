#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
void SUM(int n);
char a[4810][1001];

int main()
{
// PRE CALCULATION
    int i;
    a[0][0] = '0';
    a[1][0] = '1';
    for(i=2; i<4810; i++)
    {
        SUM(i);
    }
// CODE STARTS
    while(cin >> i)
    {
        cout <<  a[i] << endl;
    };
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
        else q = a[n-2][l_b] - '0'; // cout << "p = " << p << " q = " << q << endl;
        sum = p+q+carry;
        carry = 0;
        if(sum>9) carry = sum/10;
        sum %=10;
        a[n][i] = sum + '0';
    }
    if(carry)
    {
        for(i=l, a[n][l+1]='\0'; i>0; i--) a[n][i] = a[n][i-1];
        a[n][0] = carry+'0';
    }
}
