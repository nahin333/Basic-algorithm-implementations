#include<bits/stdc++.h>
using namespace std ;
int INF = 10000000010 ;

int k ;
int m ;
int u ;
int v ;
int s ;
int f ;
int t ;

const int maxm = 1000 ;
int dist[maxm][10] ;
int visit[maxm][10];


class node1
{
public:
    int v, s, f, t ;
};


class node2
{
public:
    int r, e, t ;
};

bool operator<(const node2 &a,const node2 &b)
{
    return a.t>b.t;
}

vector< node1 >g[maxm] ;

int main()
{
    int n ;
    cin>>n;
    for(int c=1;c<=n;c++)
    {
        cin>>k>>m;

        for(int j=1;j<=k;j++)
            g[j].clear();


        for ( int i = 1 ; i <= k ; i++)
        {
            for ( int j = 0 ; j <= 6 ; j++)

            {
                visit[i][j] = 0 ;
                dist[i][j] = INF ;
            }
        }

        for ( int j = 1 ; j <= m ; j++)
        {
            cin >> u >> v >> s >> f >> t ;
            node1 a ;
            a.v = v ;
            a.s = s;
            a.f = f ;
            a.t = t ;
            g[u].push_back(a) ;
        }

        dist[1][6] = 0 ;

        priority_queue < node2 > q ;
        node2 start ;
        start.r = 1 ;
        start.e = 6 ;
        start.t = 0 ;

        q.push(start) ;

        while( !q.empty())
        {
            node2 x = q.top();
            q.pop() ;

            for( int j = 0 ; j < ( g[x.r]).size() ; j++)
            {
                int v1 = g[x.r][j].v ;

                for ( int i = 0 ; i <= 24 ; i++)
                {
                    int nt =  x.t + i  ;

                    int nh = ( ( x.t ) + i  ) % 24 ;

                    int ne = min ( x.e + i, 6 );

                    if ( ( g[x.r][j].s <= nh ) && (   g[x.r][j].f >= nh ) &&  ( g[x.r][j].t <=  ne  ) )
                    {
                        if ( ( nt + g[x.r][j].t ) < ( dist[v1][ ne - g[x.r][j].t ]) )
                        {
                            dist[v1][ne - g[x.r][j].t] =  g[x.r][j].t + nt  ;
                            node2 y;
                            y.r = v1 ;
                            y.e = ne - g[x.r][j].t ;
                            y.t = dist[v1][ne - g[x.r][j].t];

                            q.push(y) ;
                        }
                    }

                }

            }

            visit[x.r][x.e] = 1 ;

        }

        int ans = INF ;
        int fi, fj, fh ;

        for ( int i = 0 ; i < 7 ; i++)
        {

            if( ans > dist[k][i])
            {
                ans = dist[k][i];
                fi = k ;
                fj =  i ;

            }

        }

        cout <<"case"<< c <<":"<<ans<< endl ;

    }

    return 0 ;
}
