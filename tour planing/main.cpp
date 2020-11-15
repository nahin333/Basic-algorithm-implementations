#include<bits/stdc++.h>

using namespace std;
class node
{
   public:
    int u;
    int t;
    int arive;
    int energy;
    node(int u_,int t_,int arive_,int energy_)
    {
        u=u_;
        t=t_;
        arive=arive_;
        energy=energy_;
    }
    bool operator<(const node &a)
    {
          return t>a.t;


    }
};
class station
{
  public:
    int v;
    int s_time;
    int e_time;
    int j_time;
    station(int v_,int s_,int e_,int j_)
    {
        v=v_;
        s_time=s_;
        e_time=e_;
        j_time=j_;

    }
};
vector<station> adj[505];

int main()
{
    int test_case;
    scanf("%d",&test_case);
    int cas=1;
    while(test_case--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        int tim[n+5];
        for(int i=1;i<=n;i++)
        {
            adj[i].clear();
            tim[i]=10e6;

        }
        for(int i=1;i<=m;i++)
        {
            int u,v,s,e,c;
            scanf("%d %d %d %d %d",&u,&v,&s,&e,&c);
            adj[u].push_back(station(v,s,e,c));
        }
        priority_queue<node> q;

       tim[1]=0;
       q.push(node(1,0,0,6));
       while(!q.empty())
       {
           int u=q.top().u;
           int t=q.top().t;
           int arive=q.top().arive;
           int energy_=q.top().energy;

           q.pop();
           for(int i=0;i<adj[u].size();i++)
           {
               station s=adj[u][i];
               int v=s.v;
               int st=s.s_time;
               int et=s.e_time;
               int jt=s.j_time;
               int extra;
               int extraen;
               int energy=energy_;
               if(jt>6)
               continue;

               if(arive>=st && arive<=et)
               {
                   if(energy-jt>=0)
                   {
                       extra=0;
                       extraen=0;
                   }
                   else
                   {
                       extra=extraen=jt-energy;
                       if((arive+extra)%24>et)
                       {
                           extra=extraen=24-arive+st;

                       }
                   }
               }
               else
               {
                   if(arive>et)
                   {
                        extra=extraen=24-arive+st;
                   }
                   else
                   {
                          extra=extraen=st-arive;
                         if(extra+energy-jt<0)
                         {
                             extra+=(jt-(energy+extra));
                             extraen=extra;
                         }


                   }
               }
               energy+=extraen;
               if(energy>6)
                energy=6;

               if(tim[v]>t+jt+extra)
               {
                   tim[v]=t+jt+extra;
                   q.push(node(v,tim[v],(arive+jt+extra)%24,energy-jt));
               }

           }
       }





    printf("Case %d: %d\n",cas++,tim[n] );
    }
}
