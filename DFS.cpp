#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
typedef vector<long int> VI;
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
void DFSutil(vector<node*>g[],lli r,vector<bool>&visited)
{
    stack<lli> s;
    //cout<<r<<" ";
    s.push(r);
    visited[r]=1;
    while(!s.empty())
    {
        lli cur=s.top();
        s.pop();

        cout<<cur<<" ";
        rep(i,0,g[cur].size())
        {
            if(!visited[g[cur][i]->data])
            {
                visited[g[cur][i]->data]=1;
                s.push(g[cur][i]->data);
            }
        }
    }
}
void DFS(vector<node*>g[],lli v,lli r)
{
    vector<bool>visited(v,0);
    DFSutil(g,r,visited);
    rep(i,0,v)
    {
        if(!visited[i])
            DFSutil(g,i,visited);
    }
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



