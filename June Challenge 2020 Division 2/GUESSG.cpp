#include<bits/stdc++.h>
#define MOD 1000000007
#define int long long
using namespace std;
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

int n;
char query(int check){
char reply;
cout<<check<<endl;
cin>>reply;
return reply;
}
void solve(){
cin>>n;
// Answer exists in odd query
int min=1;
int max=n;
while(min<=max){
int mid=(min+max)/2;
char ans=query(mid);
char waste=query(mid);
if(ans=='E'){
return;
}
else if(ans=='G'){
min=mid+1;
}else{
max=mid-1;
}
}
//Answer exists in even query
min=1;
max=1000000000;
while(min<=max){
int mid=(min+max)/2;
char waste=query(mid);
char ans=query(mid);
if(ans=='E'){
return;
}
else if(ans=='G'){
min=mid+1;
}else{
max=mid-1;
}
}
}
int32_t main(){
ios::sync_with_stdio(0);
cin.tie(0);
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
int t=1;
while(t--){
solve();
}
return 0;
}
