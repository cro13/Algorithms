#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
 
#define MAXN 50100
#define pb push_back
 
int N, M, deg[MAXN], Q[MAXN]; vector<int> G[MAXN];
 
// deg[x] = gradul exterior al nodului x
// folosesc o coada Q in care introduc pe rand nodurile care
// au gradul exterior zero
// complexitate O(N+M)
 
void solve()
{
    int i, x; vector<int>::iterator it;
     
    for(x = 1; x <= N; x++)
     if(deg[x] == 0) Q[++Q[0]] = x;
 
    for(i = 1; i <= N; i++)
    {
        x = Q[i];
        for(it = G[x].begin(); it != G[x].end(); ++it)
        {
            deg[*it]--;
            if(deg[*it] == 0) Q[++Q[0]] = *it;
        }
    }
}
 
void citire()
{
    int i, a, b;
 
    scanf("%d %d\n", &N, &M);
    for(i = 1; i <= M; i++)
        scanf("%d %d\n", &a, &b), G[a].pb(b), deg[b]++;
}
 
void afis()
{
    int i;
 
    for(i = 1; i <= N; i++)
        printf("%d ", Q[i]);
}
 
int main()
{
    freopen("sortaret.in", "rt", stdin);
    freopen("sortaret.out", "wt", stdout);
 
    citire();
    solve();
    afis();
 
    return 0;
}
