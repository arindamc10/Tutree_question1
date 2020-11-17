#include <bits/stdc++.h>
using namespace std;

bool contains(unordered_map<char,int>mp1, unordered_map<char,int>mp2)
{
	for(auto it: mp2)
	{
		char c=it.first;
		int cnt =it.second;
		if(mp1[c]<cnt)
		return false;
	}
	return true;
}
int main()
{
	string str1,str2;
	cin>>str1>>str2;
	
	int n=str1.length(), m=str2.length();
	unordered_map<char,int> char_count_str1, char_count_str2;
	for(char c: str2)
	{
		char_count_str2[c]++;
	}
	for(int i=0;i<m;i++)
	{
		char_count_str1[str1[i]]++;
	}
	int i=0;
	while(i<=n-m)
	{
		if(contains(char_count_str1,char_count_str2))
		{
			cout<<"substring "<< str1.substr(i,m)<<" present at index "<< i <<endl;
		}
			char_count_str1[str1[i]]--;
			i++;
			if(i<=n-m){
					char_count_str1[str1[i+m-1]]++;
			}
		
	}
	return 0;
}
