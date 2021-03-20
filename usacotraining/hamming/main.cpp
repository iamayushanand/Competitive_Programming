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
#include <fstream>

using namespace std;
const int INF= 2147483647;

#define MAX(a,b) ((a>b)?a:b)
#define MIN(a,b) ((a<b)?a:b)
#define MOD 1000000007

/*
ID: iamayus1
TASK: hamming
LANG: C++                 
*/
vector<int> ans;
int generate(int start,int N,int mx,int D){

	ans.push_back(0);
	int cnt=1;
	for(int i=1;i<=mx;i++){
		int sz=ans.size();
		if(cnt==N){break;}
		bool valid=1;
		for(int j=0;j<sz;j++){
			if(__builtin_popcount(ans[j]^i)<D){
				valid=0;
			}
		}
		if(valid){
			ans.push_back(i);
			cnt++;
		//	cout<<i<<'\n';
		}
	}
	return cnt;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("hamming.out");
    	ifstream fin ("hamming.in");
	int N,B,D;
	fin>>N>>B>>D;
	int mx=(1<<B)-1;
	for(int i=0;i<mx;i++){
		ans.clear();
		if(generate(i,N,mx,D)==N){
			break;
		}
	}
	//cout<<mx;
//	cout<<"cnt: "<<cnt;	
	int sz=ans.size();
	sort(ans.begin(),ans.end());
	for(int i=0;i<sz;i++){
		if(i%10!=9 && i!=(sz-1)){
			fout<<ans[i]<<' ';
		}else{
			fout<<ans[i]<<'\n';
		}
	}
	//cin.tie(0);
	return 0;
}
