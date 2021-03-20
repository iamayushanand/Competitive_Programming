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
TASK: pprime
LANG: C++                 
*/
bool ispal(int a){
	string s=to_string(a);
	int sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]!=s[sz-i-1]){return 0;}
	}
	return 1;
}

bool isprime(int a){
	if(a%2==0){return 0;}
 	for(int i=3;i*i<=a;i+=2){
		if(a%i==0){return 0;}
	}
	return 1;
}
int main(){
	
	ios::sync_with_stdio(false);
	ofstream fout ("pprime.out");
    	ifstream fin ("pprime.in");
	fin.tie(0);
	int a,b;
	fin>>a>>b;
//	generate(b);
	for(int c=1;c<=9;c+=2){
			int i=c;
//			cout<<i<<' ';
			if(i>=a && i<=b && isprime(i)){
					fout<<i<<'\n';
			}
		
	}
	for(int c=1;c<=9;c+=2){
			int i=10*c+c;
//			cout<<i<<' ';
			if(i>=a && i<=b && isprime(i)){
					fout<<i<<'\n';
			}
		
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
				int i=100*c+10*d+c;
//				cout<<i<<' ';
				if(i>=a && i<=b && isprime(i)){
						fout<<i<<'\n';
				}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
				int i=1000*c+100*d+10*d+c;
//				cout<<i<<' ';
				if(i>=a && i<=b && isprime(i)){
						fout<<i<<'\n';
				}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
			for(int e=0;e<=9;e++){
					int i=10000*c+1000*d+100*e+10*d+c;
//					cout<<i<<' ';
					if(i>=a && i<=b && isprime(i)){
						fout<<i<<'\n';
					}
			}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
			for(int e=0;e<=9;e++){
					int i=100000*c+10000*d+1000*e+100*e+10*d+c;
//					cout<<i<<' ';
					if(i>=a && i<=b && isprime(i)){
						fout<<i<<'\n';
					}
			}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
			for(int e=0;e<=9;e++){
				for(int f=0;f<=9;f++){
						int i=1000000*c+100000*d+10000*e+1000*f+100*e+10*d+c;
//						cout<<i<<' ';
						if(i>=a && i<=b && isprime(i)){
							fout<<i<<'\n';
						}
				}
			}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
			for(int e=0;e<=9;e++){
				for(int f=0;f<=9;f++){
						int i=10000000*c+1000000*d+100000*e+10000*f+1000*f+100*e+10*d+c;
//						cout<<i<<' ';
						if(i>=a && i<=b && isprime(i)){
							fout<<i<<'\n';
						}
				}
			}
		}
	}
	for(int c=1;c<=9;c+=2){
		for(int d=0;d<=9;d++){
			for(int e=0;e<=9;e++){
				for(int f=0;f<=9;f++){
					for(int g=0;g<=9;g++){
						int i=100000000*c+10000000*d+1000000*e+100000*f+10000*g+1000*f+100*e+10*d+c;
			//			cout<<i<<' ';
						if(i>=a && i<=b && isprime(i)){
							fout<<i<<'\n';
						}
					}
				}
			}
		}
	}
	//cin.tie(0);	
	return 0;
}
