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


struct tuple{
	int x;
	int y;
};




bool compare( tuple &a,tuple &b){
	return a.y<b.y;
}

tuple matrix[400002];
int n;
int m;
int main(){
	ios::sync_with_stdio(false);	
	cin>>n;
	REP(i,n){cin>>matrix[i].y;matrix[i].x=1;}
	cin>>m;
	REP(i,m){cin>>matrix[n+i].y;matrix[n+i].x=2;}
	
	ll first=n*3;
	ll second=m*3;
	ll ma = first-second;
	sort(matrix,matrix+n+m,compare);
//	REP(i,n+m){
//		cout<<"x: "<<matrix[i].x<<" y: "<< matrix[i].y<<endl;
//	}
	int l1=0;
	int l2=0;
	for(int i=0;i<n+m;){
		int d=0;
		d=matrix[i].y;
		while(i<n+m && matrix[i].y<=d){
			if(matrix[i].x==1){
				l2++;
			}else{
				l1++;
			}
			i++;
		}
		
		ll diff = ((l2*2)+((n-l2)*3))-((l1*2)+((m-l1)*3));
		if(diff>ma || (diff==ma && (l2*2)+((n-l2)*3)>first)){
			ma=diff;
			first= (l2*2)+((n-l2)*3);
			second=  (l1*2)+((m-l1)*3);
		}
	}
//	cout<<ma<<endl;
	cout<<first<<":"<<second;
	
	return 0;
}
