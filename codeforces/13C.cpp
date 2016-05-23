#include <math.h>
#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
 
using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define REP(i,a) for(int i=0;i<(a);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define pb(x) push_back(x)
#define SORT(a,n) sort(begin(a),begin(a)+n)
#define REV(a,n) reverse(begin(a),begin(a)+n)
#define ll long long
#define pii pair<int,int>
#define MOD 1000000007
#define DEBUG(x) cout<<">>>> "<<x<<endl
 

ll dp[5000];
ll b[5000];
ll a[5000];
int main(){
	ios::sync_with_stdio(false);

	//int n;
	//int m;
	//
	//scanf("%d %d",&n,&m);
	//
	//int T;
	//scanf("%d %d",&T);
//	memset(dp, 0, sizeof dp);
//	memset(b, 0, sizeof b);
//	memset(a, 0, sizeof a);
	int n;
	cin>>n;
	REP(i,n){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b,b+n);
	dp[0]=abs(a[0]-b[0]);
	for(int i=1;i<n;i++){
		dp[i]=MIN(abs(a[0]-b[i]),dp[i-1]);
	}

	for(int i=1;i<n;i++){
		for(int j=0;j<n;j++){
			if(j==0){
				dp[j]=((ll)abs(a[i]-b[1]))+(ll)(dp[1]);
			}else{
				dp[j]=((ll)MIN(dp[j-1],(ll)(dp[j])+(ll)(abs(a[i]-b[j]))));
			}
		}
	}
	cout<<dp[n-1];
	return 0;
}
