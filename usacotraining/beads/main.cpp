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
TASK: beads
LANG: C++                 
*/
int len;
string s;
int mod(int a, int b) { return (a % b + b) % b; }
int cost(int strind,char crf,char crb){
	//char crf=s[strind];
	//char crb=s[mod(strind-1,len)];
		
	//cout<<s[-2 % len]<<' ';
	int i=strind;
	int fwd=0;
	int bwd=0;
	int j=mod(strind-1,len);
	do{fwd++;i++;}while((s[mod(i,len)]==crf || s[mod(i,len)]=='w') && (mod(i,len)!=strind));
	do{bwd++;j--;}while((s[mod(j,len)]==crb || s[mod(j,len)]=='w') && (mod(j,len)!=mod(strind-1,len)));
	if(fwd+bwd>=len){return len;}
	//cout<<fwd<<' '<<bwd;
	return fwd+bwd;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("beads.out");
    	ifstream fin ("beads.in");
	//int len;
	fin>>len;
	//string s;
	fin>>s;
	//int strind=0;
	//cout<<len;
	int mx=-1;
	for(int i=0;i<len;i++){
		//char crf,crb;
		
		char crf=s[i];
		char crb=s[mod(i-1,len)];
		int c=0;
		if(crf=='w'){
			c=MAX(cost(i,'r',crb),cost(i,'b',crb));
		}
		if(crb=='w'){
			c=MAX(cost(i,crf,'r'),cost(i,crf,'b'));

		}
		if(crb!='w' && crf!='w'){c=cost(i,crf,crb);}
		//cout<<c;
		//cout<<c<<' ';
		if(c>mx){mx=c;}
	}
	fout<<mx<<'\n';
	//cin.tie(0);	
	return 0;
}
