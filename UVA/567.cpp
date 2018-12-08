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
using namespace std;

//template <class T> void MyDebug(T x, T y) { cout << x << ", " << y << endl;}
//template <class T> void MyDebug(T x, T y, T z) { cout << x << ", " << y << ", " << z << endl;}
int BFS(int, int);
bool visited[21];
bool add[21][21];

int main()
{
    freopen("567.txt", "r", stdin);
    int i,j, n, k, l, keis=1;
    while(scanf("%d", &n)!=EOF)
    {
       //if(keis!=1) printf("\n");
        for(i=0; i<21; i++)
            for(j=0; j<21; j++)
                add[i][j] = false;

        for(i=1; i<20; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d", &k);
                add[k][i] = true;
                add[i][k] = true;
            }
            scanf("%d", &n);
        }
        /*
                 cout << "--- " << endl;

                    for(i=0; i<20; i++)
                        for(j=0; j<20; j++)
                            if(add[i][j])
                                cout << i << " is connected to " << j << endl;

                                */
        printf("Test Set #%d\n", keis++);
        for(i=0; i<n; i++)
        {
            int start, endd, dis;
            scanf("%d %d", &start, &endd);
                    if(add[start][endd])
                        dis = 1;
                    else
                        dis = BFS(start, endd);
            //      if(dis==0) dis = 19;
            printf("%2d to %2d: %d\n", start, endd, dis);
        }
         printf("\n");
    }
    return 0;
}

int BFS(int a, int b)
{
    memset(visited, false, sizeof(visited));
    queue<int> qu;
    int level[22];
    qu.push(a);
    memset(level, 0, sizeof(level));
    level[a] = 0;
    visited[a] = true;
    while(qu.size())
    {
        int working = qu.front();
        qu.pop();
        for(int j=1; j<21; j++)
        {
            if(visited[j]==false && add[j][working])
            {
                //cout << "trigered" <<endl;
                visited[j] = true;
                level[j] = level[working] + 1;
                if(j==b) return level[b];
                qu.push(j);
            }
        }
    }
    //return level[b];
}
