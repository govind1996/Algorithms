#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<long int> vi;
typedef long long int lli;
const lli mod=1000000007;
lli powmod(lli a,lli b) {lli res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
lli gcd(lli a,lli b) { return b?gcd(b,a%b):a;}

struct node
{
    lli data;
};
node *createNode(lli val)
{
    node *newNode=new node;
    newNode->data=val;

    return newNode;
}

void addEdge(vector<node*>g[],lli s,lli d)
{
    node *temp=createNode(d);
    g[s].pb(temp);
    //undirected
    temp=createNode(s);
    g[d].pb(temp);
}

void DFSutil(vector<node*>g[],lli r,vector<bool>&visited,lli TIME,vi &st,vi &ft)
{
    //cout<<r<<" ";
    visited[r]=1;
    st[r]=TIME++;
    cout<<r<<" ";
    rep(i,0,g[r].size())
    {
        if(!visited[g[r][i]->data])
            DFSutil(g,g[r][i]->data,visited,TIME,st,ft);
    }
    ft[r]=TIME;

}
void DFS(vector<node*>g[],lli v,lli r)
{
    vector<bool>visited(v,0);
    lli TIME=0;
    //start time
    vi st(v);
    //finish time
    vi ft(v);
    DFSutil(g,r,visited,TIME,st,ft);
    rep(i,0,v)
    {
        if(!visited[i])
            DFSutil(g,i,visited,TIME,st,ft);
    }
    cout<<"\n";
    rep(i,0,v)
    cout<<st[i]<<" ";
    cout<<"\n";
    rep(i,0,v)
    cout<<ft[i]<<" ";
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli v,e,r;
    cin>>v>>e>>r;
    //graph *g=createGraph(v);
    vector<node*>g[v];
    rep(i,0,e)
    {
        lli s,d;
        cin>>s>>d;
        addEdge(g,s,d);
    }
    DFS(g,v,r);

}




