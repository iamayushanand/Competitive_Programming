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
 

ll C[1000001];
ll fact[1000001];
bool check(ll n,ll a, ll b){
	while(n!=0){
		if(n%10!=a && n%10!=b){
			return false;
		}
		n=n/10;
		
	}
	return true;
}

ll fast_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}
int main(){
	ios::sync_with_stdio(false);

	//int n;
	//int m;
	//
	//scanf("%d %d",&n,&m);
	//
	//int T;
	//scanf("%d %d",&T);	
	fact[1]=1;
	ll a,b;
	ll n;
	cin>>a>>b>>n;
	
	for(int i=2;i<=n;i++){
		fact[i]=(fact[i-1]*i)%MOD;
		fact[i]%=MOD;
	}

	for(int i=0;i<=n;i++){
		if(i==n || i==0){
			C[i]=1;
			continue;
		}
		C[i]=fact[n]*fast_pow(((fact[n-i]%MOD)*(fact[i]%MOD))%MOD,MOD-2,MOD);
	}	

//	cout<<<<endl;
	int ans=0;
	for(int x=0;x<=n;x++){
		if(check((x*a)+((n-x)*b),a,b)){
			ans+=C[x]%MOD;
//			cout<<C[x]<<" ";
			ans%=MOD;
		}
	}
	cout<<ans%MOD;
	return 0;
}
