#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std; 
vector<vector<int>> st; 
void print(vector<int> a){
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}
void Subsequences(vector<int> arr, int index, vector<int> subarr={}) 
{ 
	if (index == arr.size()) 
	{ 
		int l = subarr.size(); 
		if (l != 0){
            st.push_back(subarr); 
        } 
	} 
	else
	{ 
		Subsequences(arr, index + 1, subarr); 
        subarr.push_back(arr[index]); 
		Subsequences(arr, index + 1, subarr); 
	} 
	return; 
} 
int frequency(vector<int> arr, int n) 
{    unordered_map<int, int> map; 
    for (int i = 0; i < n; i++) 
        map[arr[i]]++;  
    int max_count = 0, res = -1; 
    for (auto i : map) { 
        if ((max_count < i.second)|| (max_count==i.second && res>i.first)) { 
            res = i.first; 
            max_count = i.second; 
        } 
    } 
  
    return res; 
}
unordered_map<int,int> print_result(vector<vector<int>> a){
    unordered_map<int,int> result;
    for(int i=0;i<a.size();i++){
        result[frequency(a[i],a[i].size())]++;
    }
    return result;
}
int main() 
{   unordered_map<int,int> fin;
	vector<int> input;
    int t,n,temp;
    cin>>t;
    while(t-->0){ 
	cin>>n;
    input.clear();
    for(int i=0;i<n;i++){
        //cin>>temp;
        input.push_back(i+1);
    } 
    st.clear();
	Subsequences(input, 0);
    fin=print_result(st); 
    //for(int i=0;i<st.size();i++)
      //print(st[i]);
    for(int i=0;i<input.size();i++){
        cout<<fin[input[i]]<<" ";
        fin[input[i]]=0;
    }cout<<"\n";
    }
	return 0; 
} 

