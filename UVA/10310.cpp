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
#define MIN3(a, b, c) MIN(a , MIN(b,c))
#define sf scanf
#define ssf sscanf
#define pb push_back
#define PPP system("pause");
#define ppp system("pause");
#define ok cout << "OK" <<endl;
#define pf printf
#define CLR(a) memset(a, 0, sizeof(a))
#define PI 2*acos(0)
using namespace std;
const int xx[] = {0, 0, 1, -1, -1, 1, -1, 1};
const int yy[] = {1, -1, 0, 0, 1, 1, -1, -1};      // diagonal -> 8 horizontal/vertical->4
const int kx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int ky[] = {1, 2, 2, 1, -1, -2, -2, -1};   // Knight moovs


double DISTANCE(double a, double b, double c, double d)
{
    return (a-c)*(a-c)+(b-d)*(b-d);
}

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("j.txt","r",stdin);
   // freopen("k_o.txt","w",stdout);

#endif
    ///                                    MAIN
    double dx, dy, gx, gy, dd[1005], dg[1005], disx[1005], disy[1005];
    int i, j, n, k, l=0;
    //cout << DISTANCE(1.0, 1.0, 3.0, 2.0) << endl;
    while(sf("%d %lf %lf %lf %lf", &n, &gx, &gy, &dx, &dy)!=EOF)
    {
        //if(l) sf("\n");
       // if(l++) pf("\n");
        for(i=0; i<n; i++)
            sf("%lf %lf", &disx[i], &disy[i]);
        for(i=0; i<n; i++)
        {
            dg[i] = 4*DISTANCE(gx, gy, disx[i], disy[i]);
            dd[i] = DISTANCE(dx, dy, disx[i], disy[i]);
           // cout << dg[i] << endl << dd[i] << endl;
        }
        bool mark = false;
        for(i=0; i<n; i++)
        {
            if(dg[i]<=dd[i])
            {
                mark = true;
                break;
            }
        }
        if(mark) pf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", disx[i], disy[i]);
        else pf("The gopher cannot escape.\n");
    }
    ///                                    ENDD
    // time_t t2=clock();
    // cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}


