#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
using ll = long long int ;
using ld = long double ;
using P = pair<ll,ll>;
using PD = pair<ld,ld>;
using Graph= vector<vector<ll>>;
struct edge{ll to ; ll cost ;} ;
using graph =vector<vector<edge>> ;
#define rep(i,n) for (ll i=0; i < (n); ++i)
#define rep2(i,n,m) for(ll i=n;i<=m;i++)
#define rep3(i,n,m) for(ll i=n;i>=m;i--)
#define pb push_back 
#define eb emplace_back 
#define ppb pop_back 
#define mpa make_pair 
#define fi first  
#define se second  
#define set20 cout<<fixed<<setprecision(20)  ;
const ll INF=1e18 ;   
inline void chmax(ll& a,ll b){a=max(a,b);}  
inline void chmin(ll& a,ll b){a=min(a,b);} 
long double pi=acos(-1) ;  
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}  
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;} 
ll dx[4] {1,0,-1,0} ;
ll dy[4] {0,1,0,-1} ;
#define debug cout<<888<<endl ;

struct UnionFind {
	vector<int> d;
	UnionFind(int n=0): d(n,-1) {}
	int find(int x) {
		if (d[x] < 0) return x;
		return d[x] = find(d[x]);
	}
	bool unite(int x, int y) {
		x = find(x); y = find(y);
		if (x == y) return false;
		if (d[x] > d[y]) swap(x,y);
		d[x] += d[y];
		d[y] = x;
		return true;
	}
	bool same(int x, int y) { return find(x) == find(y);}
	int size(int x) { return -d[find(x)];}
};


// sum(x) x以下の和
// sum(a,b) a以上b以下の和
template<typename T>
struct BIT {
	int n;
	vector<T> d;
	BIT(int n=0):n(n),d(n+1) {}
	void add(int i, T x=1) {  //x=1ならsumは個数のカウント
		for (i++; i <= n; i += i&-i) {
			d[i] += x;
		}
	}
	T sum(int i) {
		T x = 0;
		for (i++; i; i -= i&-i) {
			x += d[i];
		}
		return x;
	}
	T sum(int i,int j) {
		if(i>0) return sum(j)-sum(i-1);
		else return sum(j) ; } 
};



int main(){
	ios::sync_with_stdio(false) ;
	cin.tie(nullptr) ; 
	
	ll h,w,n; cin>>h>>w>>n;
	ll sx,sy; cin>>sx>>sy;
	sx--; sy--;
	ll gx,gy; cin>>gx>>gy;
	gx--; gy--;

	map<ll,ll> f,g;
	f[sx]++; g[sy]++;
	f[gx]++; g[gy]++;
	vector<P> memo(n);
	rep(i,n){
		ll x,y; cin>>x>>y;
		x--; y--;
		f[x]++; g[y]++;
		f[x-1]++; g[y-1]++;
		f[x+1]++; g[y+1]++;
		memo[i]={x,y};
		//A[x].pb(y); B[y].pb(x);
	}
	
	map<ll,ll> c,d;
	vector<ll> cc,dd;
	for(auto u:f){cc.pb(u.fi);}
	for(auto u:g){dd.pb(u.fi);}
	sort(cc.begin(),cc.end());
	sort(dd.begin(),dd.end());
	h=cc.size(); w=dd.size();
	rep(i,h) c[cc[i]]=i;
	rep(i,w) d[dd[i]]=i;
	//rep(i,h) cout<<c[i]<<endl;
	sx=c[sx];
	sy=d[sy];
	gx=c[gx];
	gy=d[gy];
	
	vector<vector<ll>> A(h),B(w);
	rep(i,n){
		ll x=memo[i].fi; ll y=memo[i].se;
		ll xx=c[x]; ll yy=d[y];
		A[xx].pb(yy);
		B[yy].pb(xx);
		//cout<<xx<<" "<<yy<<endl;
	}
	/////////////////////
	rep(i,h){
		sort(A[i].begin(),A[i].end());
	}
	rep(i,w){
		sort(B[i].begin(),B[i].end());
	}
	
	queue<P> q;
	map<P,ll> mp; 
	q.push({sx,sy});
	mp[{sx,sy}]=1;
	ll ans=-1;

	
	while(!q.empty()){
		P now=q.front();
		ll a=now.fi; ll b=now.se;
		ll d=mp[now];
		q.pop();
		//cout<<a<<" "<<b<<" "<<d<<endl;

		if(now==P({gx,gy})){
			ans=d-1;
		}
		ll sia=A[a].size();
		ll sib=B[b].size();
		//cout<<sia<<" "<<sib<<endl;
		ll u=-1;
		if(sia>0){
		u=lower_bound(A[a].begin(),A[a].end(),b)-A[a].begin();
		if(0<=u&&u<=sia-1){ 
			if(!mp[{a,A[a][u]-1}]){
				q.push({a,A[a][u]-1}); mp[{a,A[a][u]-1}]=d+1;
		}
		}
		
		u--;
		if(0<=u&&u<=sia-1){
			if(!mp[{a,A[a][u]+1}]){
				q.push({a,A[a][u]+1}); mp[{a,A[a][u]+1}]=d+1;
		}
		}
		}

		u=-1;
		if(sib>0){
		u=lower_bound(B[b].begin(),B[b].end(),a)-B[b].begin();
		
		if(0<=u&&u<=sib-1){
			if(!mp[{B[b][u]-1,b}]){
				q.push({B[b][u]-1,b}); mp[{B[b][u]-1,b}]=d+1;
			}
		}
		u--;
		if(0<=u&&u<=sib-1){
			if(!mp[{B[b][u]+1,b}]){
				q.push({B[b][u]+1,b}); mp[{B[b][u]+1,b}]=d+1;
			}
		}
		}
		
	} 
	
	cout<<ans<<endl;

	return 0 ;
	}

