#include<stdio.h>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>

using namespace std;

#define dim 8000
#define pb push_back

vector < int > v [ dim*3 ] ;
int plm[dim];
queue < int > q;
int n,m,n1,n2;
int  dst [ dim ] ,f[dim],t[dim];
bitset <dim> nr;
void read()
{
    int x,y;
    scanf("%d %d %d %d\n",&n,&m,&n1,&n2);
    for(int i=1 ;i<=m;i++)
    {
        scanf("%d %d\n",&x,&y);
        v[x].pb(y);
       v[y].pb(x);
    }
}
void solve()
{
    int x;
    dst[ n1 ] =1;
    for(q.push(n1) ; !q.empty() ; q.pop())
    {
        x = q.front ();
        for(int i=0 ; i<v[x].size() ; i++)
        {
            if (dst [ v[ x ] [ i ]] == 0 )
            {
                dst [ v[x][i] ] = dst[ x ] +1;
                f[ v[x][i]] = f[ x ] ;
                q.push ( v[x][i] ) ;
                t[ v[x][i] ] = x;
            }
            else
            if( dst[v[ x ] [ i ]] == dst[ x ]+1  )
            f[ v[x][i] ] ++;
        }
      
    }
    int x2=n2,l=0;
   while ( x2 )
    {
       if ( f[x2] == f[t[x2] ] && t[x2] !=0 )
            dst[ ++l ] =t[x2];
        x2= t [ x2 ] ;
    }
    dst[ ++l ] = n2 ;
    sort ( dst + 1 , dst + l + 1 );
    printf("%d\n",l);
    for(int i=1 ;i<=l;i++)
    printf("%d " ,dst [ i ]);
}


int main ()
{
    freopen("graf.in","r",stdin);
    freopen("graf.out","w",stdout);
    read();
    solve();
    return 0;
    
}