#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define inc(i,a,b) for(int i(a);i<=b;i++)
#define dec(i,a,b) for(int i(a);i>=b;i--)
const int MAXN(205);
int h[MAXN*MAXN];
int n,m;
int fa[MAXN*MAXN];
int g[MAXN][MAXN];
int tx[4]={1,-1,0,0};
int ty[4]={0,0,1,-1};
int fd(int a){return fa[a]==a?a:fa[a]=fd(fa[a]);}
bool isIn(int x,int y)
{
    return x>=1&&x<=n&&y>=1&&y<=m;
}
int ans(0);
vector<int> ed[MAXN*MAXN],root;
void solve()
{
    cin>>n>>m;
    inc(i,1,n)
    inc(j,1,m)cin>>g[i][j];
    inc(i,1,n*m)fa[i]=i;
    inc(i,1,n)
    inc(j,1,m)
    {
        inc(k,0,3)
        {
            int a(i+tx[k]),b(j+ty[k]);
            if(isIn(a,b)&&g[a][b]<g[i][j])
            {
                ed[m*(i-1)+j].push_back(m*(a-1)+b);
                fa[m*(a-1)+b]=fd(m*(i-1)+j);
            }
        }
    }
    while(true)
    {
        ans++;
        inc(i,1,n*m)
        {
            if(fa[i]==i)
            {
                fa[i]=0;
                for(int t:ed[i])
                {
                    root.push_back(t);
                }
            }
        }
        if(root.empty())break;
        for(int p:root)
        {
            fa[p]=p;
        }
        root.clear();
    }
    cout<<ans<<endl;
}
signed main()
{
    // ios::sync_with_stdio(false);
    int _;
    // cin>>_;
    _=1;
    while(_--)solve();
    system("pause");
}
/*
5 5
1 2 3 4 5
16 17 18 19 6
15 24 25 20 7
14 23 22 21 8
13 12 11 10 9

5 4
12 345 2 12
2 34 3 1 
1 1 3 1
3 7 7 9 
3 3 3 7
*/