
/// RAFIK FARHAD
/// fb.com/rafikfarhad
/// SUST_CSE_13
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <new>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define PI 2*acos(0)
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

bool EVEN(int k)
{
    if(k%2) return false;
    return true;
}

int main()
{
    //freopen("541.txt", "r", stdin);
    int dim;
    while(scanf("%d", &dim)==1 && dim)
    {
        int ar[dim][dim], i, j, sum, row, col, a=0, b=0;
        for(i=0; i<dim; i++)
            for(j=0; j<dim; j++)
                scanf("%d", &ar[i][j]);

        for(i=0; i<dim; i++)
            {
                for(j=sum=0; j<dim; j++)
                sum += ar[i][j];
                if(!EVEN(sum))
                {
                    row = i+1;
                    a++;
                }
            }

            sum  = 0;
            for(i=0; i<dim; i++)
            {
                for(j=sum=0; j<dim; j++)
                sum += ar[j][i];
                if(!EVEN(sum))
                {
                    col = i+1;
                    b++;
                }
            }
          //  cout << a << " " << b << endl;
            if(a==0 && b==0) printf("OK\n");
            else if(a==1 && b==1) printf("Change bit (%d,%d)\n", row, col);
            else printf("Corrupt\n");
    }
}


