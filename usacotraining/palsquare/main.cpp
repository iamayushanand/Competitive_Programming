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
TASK: palsquare
LANG: C++                 
*/

int B;
bool isPal(string a){
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]!=a[n-i-1]){
			return 0;
		}
	}
	return 1;
}
string base(int a){
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
	ofstream fout ("palsquare.out");
    	ifstream fin ("palsquare.in");
//	int B;
	fin>>B;
	for(int i=1;i<=300;i++){
		if(isPal(base(i*i))){
			fout<<base(i)<<' '<<base(i*i)<<'\n';
		}
	}
	//cin.tie(0);	
	return 0;
}
