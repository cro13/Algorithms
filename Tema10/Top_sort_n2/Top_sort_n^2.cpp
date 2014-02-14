#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
#define MAXN 50100
#define pb push_back
 
int N, M, viz[MAXN], deg[MAXN]; vector<int> G[MAXN];
 
void solve_and_write()
{
    int i, j, k;
 
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
         if(!viz[j] && deg[j] == 0)
         {
            viz[j] = 1, printf("%d ", j);
            for(k = 0; k < G[j].size(); k++)
                deg[ G[j][k] ]--;
            break ;
         }
    }
}
 
void read_data()
{
    int i, a, b;
 
    scanf("%d %d\n", &N, &M);
    for(i = 1; i <= M; i++)
        scanf("%d %d", &a, &b), G[a].pb(b), deg[b]++;
}
 
int main()
{
    freopen("sortaret.in", "rt", stdin);
    freopen("sortaret.out", "wt", stdout);
 
    read_data();
    solve_and_write();
 
    return 0;
}
 