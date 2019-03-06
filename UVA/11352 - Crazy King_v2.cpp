#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<sstream>
#include<set>
#include<utility>
#define ok cout << "ok" << endl;

using namespace std;

int dx[] = { 0, 1,  0, -1, -1, 1,  1, -1 };
int dy[] = { 1, 0, -1,  0,  1, 1, -1, -1 };


int xx[] = { -1, 1, 2, 2,  1, -1, -2, -2 };
int yy[] = {  2, 2, 1,-1, -2, -2, -1,  1 };


int r, c, dis[105][105];
bool visited[103][103];
char mat[105][105];
pair<int, int>st, dest;

bool Valid(int u, int v)
{
    if(u>=0 && u<r && v>=0 && v<c) return true;
    return false;
}

void BFS()
{
    int i, j, u, v;
    pair<int, int>p;
    queue<pair<int, int> > q;
    q.push(st);
    dis[st.first][st.second] = 0;
    visited[st.first][st.second] = true;
    while(!q.empty())
    { //cout << "ok" << endl;
        p = q.front();
        q.pop();
        for(i=0; i<8; i++)
        {
            u = p.first + dx[i];
            v = p.second + dy[i];
            //cout << u << " " << v << endl;
           // cout << (bool) Valid(u, v) << " " << (bool) visited[u][v] << endl;
            if(Valid(u, v) && !visited[u][v])
            {
                dis[u][v] = dis[p.first][p.second] + 1;
              //  cout << p.first << " " << p.second << endl;
                visited[u][v] = true;
                q.push(make_pair(u, v));
            }
        }

    }
    return;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("11352.inp","r",stdin);
    #endif

    int i, j, t, k;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d ", &r, &c);
        memset(visited, false, sizeof visited);
        memset(dis, -1, sizeof dis);
        for(i=0; i<r; i++) scanf("%s", mat[i]);

        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                if(mat[i][j] == 'A') st = make_pair(i, j);
                else if(mat[i][j] == 'B') dest = make_pair(i, j);
                else if(mat[i][j] == 'Z')
                {
                    visited[i][j] = true;
                    for(k=0; k<8; k++)
                    {
                        if(Valid(i+xx[k], j+yy[k]) && mat[i+xx[k]][j+yy[k]] != 'B')
                            {
                                visited[i+xx[k]][j+yy[k]] = true;

                            }
                    }
                }
            }
        }

       /*  for(i=0; i<r; i++, cout << endl)
        {
            for(j=0; j<c; j++)
            {
                cout << (bool) visited[i][j] << "  ";
            }}*/
        BFS();
        if(dis[dest.first][dest.second] == -1) printf("King Peter, you can't go now!\n");
        else printf("Minimal possible length of a trip is %d\n", dis[dest.first][dest.second]);

    }
    return 0;
}