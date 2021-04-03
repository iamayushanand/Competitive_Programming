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
#define MOD 1000000007

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);	
	int n,m;
	cin>>n>>m;
	string s;
	string t;
	cin>>s>>t;
	int left[m+1];
	int right[m+1];

	for(int i=0;i<m;i++){
		static int curr=-1;
		curr++;
		while(s[curr]!=t[i])curr++;
		left[i]=curr;
	}
	for(int i=m-1;i>=0;i--){
		static int curr=n;
		curr--;
		while(s[curr]!=t[i])curr--;
		right[i]=curr;
	}
	int ans=0;
	for(int i=0;i<m-1;i++){
		ans=MAX(ans,right[i+1]-left[i]);
	}
	cout<<ans<<'\n';
	return 0;
}
