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
TASK: dualpal
LANG: C++                 
*/

bool isPal(string a){
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]!=a[n-i-1]){
			return 0;
		}
	}
	return 1;
}
string base(int a,int B){
	string s="";
	do{
		int rem= a % B;
		if(rem<10){
			s=to_string(rem)+s;
		}
		else{
			char x=rem-10+'A';
			s=x+s;
		}
	}while(a/=B);
	return s;

}

int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("dualpal.out");
    	ifstream fin ("dualpal.in");
	int N,S;
	fin>>N>>S;
	int found=0;
	int cur=S+1;
//	fout<<cur;
	while(found!=N){
		int num=0;
		for(int i=2;i<11;i++){
			if(isPal(base(cur,i))){num++;}
		}
//		fout<<num;
		if(num>=2){
			fout<<cur<<'\n';
			found++;
		//	cur++;
		}
		cur++;
	}
	
	//cin.tie(0);	
	return 0;
}
