#include <bits/stdc++.h>
#define int long long
using namespace std;

int up[200001][20];
vector<int> tree[200001];
int lvl[200001];

void dfs(int src,int par,int level=0)
{
    lvl[src]=level;
    for(auto child:tree[src])
    {
        if(child!=par)
            dfs(child,src,level+1);
    }
}

void binary_lift(int src,int par)
{
    up[src][0]=par;
    for(int i=1;i<20;i++)
    {
        if(up[src][i-1]!=-1)
            up[src][i]=up[up[src][i-1]][i-1];
        else
            up[src][i]= -1;
    }
    //till here you do everything on parent and then pass the answer for child nodes.
    for(auto child:tree[src])
    {
        if(child!=par)
            binary_lift(child,src);
    }
}

int query_up(int node,int jump_size)
{
    //query_up is simply lift_up by jump size given [2 ki power jumpsize]
    if(node==-1 || jump_size==0)
        return node;

    for(int i=19;i>=0;i--)
    {
        if(jump_size >= (1<<i))
            return query_up(up[node][i], jump_size - (1<<i));
    }
}

int lca(int a,int b)
{
    //lowest common anncestor in O(log N ) time
    if(lvl[a]<lvl[b])
    {
        swap(a,b);
       
    }
     a=query_up(a,lvl[a]-lvl[b]);
        if(a==b)
        {
            return a;

        }

    
    for(int i=19;i>=0;i--)
    {
        if(up[a][i]!=up[b][i])
        {
            a=up[a][i];
            b=up[b][i];

        }
    }
    return query_up(a,1);

}
// sample main function for distance between two node jump from a to lca and frmo lca to b.
int32_t main() 
{
    int n,q;
    cin>>n>>q;

    for(int i=0;i<n-1;i++)
    {
        int a,b;
        cin>>a>>b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    
    binary_lift(1,-1);
    dfs(1,-1);
    

    while(q--)
    {
        int a1,b1;
        cin>>a1>>b1;
        int r1=lca(a1,b1);
        cout<< ((lvl[a1]-lvl[r1]) + (lvl[b1]-lvl[r1]))<<endl;
        
    }

    return 0;
}
