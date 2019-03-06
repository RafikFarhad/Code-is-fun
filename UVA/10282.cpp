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
//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}

struct W
{
    char eng[26], xxx[50];
} input[1000002];

int COMPA(const void *a, const void *b)
{
    return strcmp(((W *)a)->xxx, ((W *) b)->xxx);
//   return strcmp(((word *)a)->xx,((word *)b)->xx);
}

int main()
{
    //time_t t1=clock();
    freopen("10282.txt", "r", stdin);

    ///                                    MAIN
    int i=0, j, k;
    char in[55], *temp;
    while(gets(in))
    {
        if(!strcmp(in, "")) break;
        temp = strtok(in, " ");
        strcpy(input[i].eng, temp);
        temp = strtok(NULL, " ");
        strcpy(input[i].xxx, temp);
        i++;
    }

    qsort(input, i, sizeof(W), COMPA);

    W *q, t;

    while(sf("%s", t.xxx)!=EOF)
    {
        q = bsearch(&t, input, i, sizeof(W), COMPA);
        //q = bsearch(&QUERY,dict,I,sizeof(word),cmp);
        if(q!=NULL) pf("%s\n", q->eng);
        else pf("eh\n");
    }
    //for(j=0; j<i; j++)
    //     cout << input[j].eng << " --- " << input[j].xxx <<endl;
    ///                                    ENDD
    //time_t t2=clock();
    //cout << " My time: " <<(t2-t1) << endl;;
    return 0;
}

