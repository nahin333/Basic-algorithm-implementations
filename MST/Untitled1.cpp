
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct data
{
	int u,v,w,ans,num;
}e[200001];
struct data2
{
	int next,num,w;
}edge[200001];
int head[200001],dfn[200001],low[200001],fa[200001],deep,n,m,tot,vis[200001];
bool cmp(data p,data q)
{
	return p.w<q.w;
}
bool cmp2(data p,data q)
{
	return p.num<q.num;
}
void add(int u,int v,int w)
{
	edge[++tot].next=head[u];
	edge[tot].num=v;
	edge[tot].w=w;
	head[u]=tot;
}
int getf(int x)
{
	if (fa[x]==x) return x;
	fa[x]=getf(fa[x]);
	return fa[x];
}
void Tarjan(int x,int fa)
{
	deep++;
	dfn[x]=low[x]=deep;
	vis[x]=1;
	for (int i=head[x];i!=-1;i=edge[i].next)
	{
		if ((i^1)==fa) continue;
		int kx=edge[i].num;
		if (vis[kx])
		{
			low[x]=min(low[x],dfn[kx]);
			continue;
		}
		Tarjan(kx,i);
		low[x]=min(low[x],low[kx]);
		if (low[kx]==dfn[kx]) e[edge[i].w].ans=2;
	}
}
void doit(int l,int r)
{
	tot=-1;
	for (int i=l;i<=r;i++) head[getf(e[i].u)]=head[getf(e[i].v)]=-1;
	for (int i=l;i<=r;i++)
	{
		if (getf(e[i].u)==getf(e[i].v))
		{
			e[i].ans=0;
			continue;
		}
		e[i].ans=1;
		vis[getf(e[i].u)]=vis[getf(e[i].v)]=0;
		add(getf(e[i].u),getf(e[i].v),i);
		add(getf(e[i].v),getf(e[i].u),i);
	}
	deep=0;
	for (int i=l;i<=r;i++)
	  if (getf(e[i].u)!=getf(e[i].v)&&!vis[getf(e[i].u)]) Tarjan(getf(e[i].u),-1);
}
void kruskal()
{
	for (int i=1;i<=n;i++) fa[i]=i;
	for (int i=1;i<=m;)
	{
		int j=i;
		while (j<=m&&e[j].w==e[i].w) j++;
		doit(i,j-1);
		for (int k=i;k<=j-1;k++)
		{
			int fu=getf(e[k].u),fv=getf(e[k].v);
			if (fu==fv) continue;
			fa[fu]=fv;
		}
		i=j;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++) scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w),e[i].num=i;
	sort(e+1,e+m+1,cmp);
	kruskal();
	sort(e+1,e+m+1,cmp2);
	for (int i=1;i<=m;i++) if (e[i].ans==0) printf("none\n");
		  else if (e[i].ans==1) printf("at least one\n");else printf("any\n");
	return 0;
}
