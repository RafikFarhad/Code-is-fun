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

void OT(int n)
{
    int t, i, j;
    stack <int> st;
    while(1)
    {
        while(st.size()) st.pop();
        j = 0;
        for(i=0; i<n; i++)
        {
            sf("%d", &t);
            if(!t) return;
            //j = 0;
            while(j<n && j!=t)
            {
                if(st.size() && st.top()==t) break;
                j++;
                st.push(j);
            }
            if(st.top()==t) st.pop();
        }
        if(st.size()>0) pf("No\n");
        else pf("Yes\n");
    }
    cout << st.size() << endl;
}

int main()
{
    //time_t t1=clock();
    //freopen("10420.txt", "r", stdin);

    ///                                    MAIN
    int n;
    while(sf("%d", &n)==1 && n)
    {
        OT(n);
        pf("\n");
    }
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}




