#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (long int i=a;i<n;i++)
#define per(i,a,n) for (long int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
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

void addEdge(vector< pair<node*,lli> >g[],lli s,lli d,lli wt)
{
    node *temp=createNode(d);
    g[s].pb(mp(temp,wt));
    //undirected
    temp=createNode(s);
    g[d].pb(mp(temp,wt));
}
void printGraph(vector< pair<node*,lli> >g[],lli v)
{
    rep(i,0,v)
    {
        cout<<i;

        rep(j,0,g[i].size())
        {
            cout<<"->("<<g[i][j].first->data<<", "<<g[i][j].second<<")";
        }
        cout<<endl;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    lli v,e;
    cin>>v>>e;
    //graph *g=createGraph(v);
    vector< pair<node*,lli> >g[v];
    rep(i,0,e)
    {
        lli s,d,wt;
        cin>>s>>d>>wt;
        addEdge(g,s,d,wt);
    }
    printGraph(g,v);

}



