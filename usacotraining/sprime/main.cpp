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
TASK: sprime
LANG: C++                 
*/
vector<int> sol;
bool isprime(int a){
	if(a==2){return 1;}
	if(a%2==0){return 0;}
	for(int i=3;i*i<=a;i+=2){
		if(a%i==0){return 0;}
	}
	return 1;
}
int solve(int n){
	if(n==1){return 0;}
//	fout<<n<<' ';
	solve(n-1);
	int sz=sol.size();
	for(int i=0;i<sz;i++){
		for(int j=1;j<=9;j++){
			if(isprime(sol[i]*10+j)){
				sol.push_back(sol[i]*10+j);
			}
		}
	}
	vector<int>::iterator str=sol.begin();
	vector<int>::iterator end=str+sz;
	sol.erase(str,end);
	return 0;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("sprime.out");
    	ifstream fin ("sprime.in");
	int N;
	fin>>N;
	sol.push_back(2);
	sol.push_back(3);
	sol.push_back(5);
	sol.push_back(7);
	solve(N);
	int sz=sol.size();
	for(int i=0;i<sz;i++){
		fout<<sol[i]<<'\n';
	}
	//cin.tie(0);	
	return 0;
}
