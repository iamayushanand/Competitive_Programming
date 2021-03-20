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
TASK: crypt1
LANG: C++                 
*/
vector<char> digit;
bool check(string a, int len){
	int sz=a.size();
	if(sz!=len){return 0;}
	for(int i=0;i<sz;i++){
		if(find(digit.begin(),digit.end(),a[i])==digit.end()){
			return 0;
		}
	}
	return 1;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("crypt1.out");
    	ifstream fin ("crypt1.in");
	int N;
	fin>>N;
	for(int i=0;i<N;i++){
		char x;
		fin>>x;
		digit.push_back(x);
	}
	int count=0;
	for(int i=0;i<N;i++){
		char a1=digit[i];
		for(int j=0;j<N;j++){
			char a2=digit[j];
			for(int k=0;k<N;k++){
				char a3=digit[k];
				string a="";
				a+=a1;
				a+=a2;
				a+=a3;
				for(int l=0;l<N;l++){
					char b1=digit[l];
					for(int m=0;m<N;m++){
						char b2=digit[m];
						string b="";
						b+=b1;
						b+=b2;
						int prod=stoi(a)*stoi(b);
						if(!check(to_string(prod),4)){continue;}
						int p1=stoi(a)*(int)(b2-'0');
						if(!check(to_string(p1),3)){continue;}
						int p2=stoi(a)*(int)(b1-'0');
						if(!check(to_string(p2),3)){continue;}
						count++;	
					}
				}
			}
		}
	}
	fout<<count<<'\n';
	//cin.tie(0);	
	return 0;
}
