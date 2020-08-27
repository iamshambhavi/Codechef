#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;

int p,q,r,a,b,c;
void solve(){
	cin>>p>>q>>r>>a>>b>>c;
	// 0
	if(p==a&&q==b&&r==c){
		cout<<"0\n";
		return;
	}
	// 1 - Add krke aa jaye
	unordered_set<int> s;
	if(a!=p)
		s.insert(a-p);
	if(b!=q)
		s.insert(b-q);
	if(c!=r)
		s.insert(c-r);
	if(s.size()==1){
		cout<<"1\n";
		return;
	}
	// 1- Multiply krke aa jaye
	if((p!=0 || p==a) &&(q!=0 || q==b) &&(r!=0 || r==c) && (p==0 || a%p==0) && (q==0 || b%q==0) && (r==0 || c%r==0)){
		unordered_set<int> s;
		if(p!=a)
			s.insert(a/p);
		if(q!=b)
			s.insert(b/q);
		if(r!=c)
			s.insert(c/r);
		if(s.size()==1){
			cout<<"1\n";
			return;
		}
		// 2 - 2 times multiply krke aa jaye
		if(s.size()==2 ){
			cout<<"2\n";
			return;
		}else{
			vector<int> v;
			for (auto itr=s.begin();itr!=s.end();++itr){ 
        		v.push_back(*itr); 
			}
			if(v[0]*v[1]==v[2] || v[1]*v[2]==v[0] || v[0]*v[2]==v[1]){
				cout<<"2\n";
				return;
			}
		}
	}

	// 2 - 2 number bache hai bas
	if(p==a || q==b ||r==c){
		cout<<"2\n";
		return;
	}
	// 2 - 2 times add krna
	if(s.size()==2){
		cout<<"2\n";
		return;
	}else{
		vector<int> v;
		for (auto itr=s.begin();itr!=s.end();++itr){ 
        	v.push_back(*itr); 
    	}
		if(v[0]+v[1]==v[2] || v[1]+v[2]==v[0] || v[0]+v[2]==v[1]){
			cout<<"2\n";
			return;
		}
	}
	// 2 - 1 mien add, 3 mien multiply
	if(p!=0 && q!=0 && a%p==0 && b%q==0){
		if((a/p)==(b/q)){
			cout<<"2\n";
			return;
		}
	}
	if(p!=0 && r!=0 && a%p==0 && c%r==0){
		if((a/p)==(c/r)){
			cout<<"2\n";
			return;
		}
	}
	if(r!=0 && q!=0 && c%r==0 && b%q==0){
		if((c/r)==(b/q)){
			cout<<"2\n";
			return;
		}
	}
	// 2- 2 mien add, 2 mien multiply
	if(p!=0 && a%p==0){
		int x=a/p;
		int diff1=b-q;
		int diff2=c-r;
		if((q*x+diff2) == b ||(r*x+diff1) == c ||(q+diff2)*x == b||(r+diff1)*x == c){
			cout<<"2\n";
			return;
		}
	}
	if(q!=0 && b%q==0){
		int x=b/q;
		int diff1=a-p;
		int diff2=c-r;
		if((p*x+diff2) == a ||(r*x+diff1) == c ||(p+diff2)*x == a||(r+diff1)*x == c){
			cout<<"2\n";
			return;
		}
	}
	if(r!=0 && c%r==0){
		int x=c/r;
		int diff1=b-q;
		int diff2=a-p;
		if((q*x+diff2) == b ||(p*x+diff1) == a ||(q+diff2)*x == b||(p+diff1)*x == a){
			cout<<"2\n";
			return;
		}
	}
	// 2 - Teeno mien multiply, phir add
	// 2 - Do mien multiply, phir add
	// 2 - Ek mien multiply, phir add
	// x=(a-b)/(p-q)   y=(pb-aq)/(p-q)
	if((p-q)!=0  && (a-b)%(p-q)==0 && ((p*b)-(a*q))%(p-q)==0 ){
		
		int x=(a-b)/(p-q) ,y=((p*b)-(a*q))/(p-q);
		if(x*r+y == c || r+y==c || r*x == c){
			cout<<"2\n";
			return;
		}
		
	}
	if((p-r)!=0  && (a-c)%(p-r)==0 && ((p*c)-(a*r))%(p-r)==0 ){
		int x=(a-c)/(p-r) ,y=((p*c)-(a*r))/(p-r);
		if(x*q+y == b || q+y==b || q*x == b){
			cout<<"2\n";
			return;
		}
		
	}
	if((r-q)!=0  && (c-b)%(r-q)==0 && ((r*b)-(c*q))%(r-q)==0 ){
		int x=(c-b)/(r-q) ,y=((r*b)-(c*q))/(r-q);
		if(x*p+y == a || p+y==a || p*x == a){
			cout<<"2\n";
			return;
		}	
	}
	// 2 - Teeno mien add, phir multiply
	// 2 - Do mien add, phir multiply
	// 2 - Ek mien add, phir multiply
	// x=(bp-aq)/(a-b)    y=(a-b)/(p-q)
	 if((a-b)!=0 && (p-q)!=0 && ((b*p)-(a*q))%(a-b)==0 && (a-b)%(p-q)==0){
		int x=((b*p)-(a*q))/(a-b), y=(a-b)/(p-q);
		if((r+x)*y==c || r+x==c || r*y==c){
			cout<<"2\n";
			return;
		}
	 }
	 if((a-c)!=0 && (p-r)!=0 && ((c*p)-(a*r))%(a-c)==0 && (a-c)%(p-r)==0){
		int x=((c*p)-(a*r))/(a-c), y=(a-c)/(p-r);
		if((q+x)*y==b || q+x==b || q*y==b){
			cout<<"2\n";
			return;
		}
	 }
	 if((c-b)!=0 && (r-q)!=0 && ((b*r)-(c*q))%(c-b)==0 && (c-b)%(r-q)==0){
		int x=((b*r)-(c*q))/(c-b), y=(c-b)/(r-q);
		if((p+x)*y==a || p+x==a || p*y==a){
			cout<<"2\n";
			return;
		}
	 }
	// 3 - Always
	cout<<"3\n";
}
int32_t main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
