#include <bits/stdc++.h>
#include <vector>
#include <set>
using namespace std;
int power(int x, unsigned int y, long long p=1000000007) 
{ 
	int res = 1;	 // Initialize result 

	x = x % p; // Update x if it is more than or 
				// equal to p 

	if (x == 0) return 0; // In case x is divisible by p; 

	while (y > 0) 
	{ 
		// If y is odd, multiply x with result 
		if (y & 1) 
			res = (res*x) % p; 

		// y must be even now 
		y = y>>1; // y = y/2 
		x = (x*x) % p; 
	} 
	return res; 
} 

vector<vector<int>> st;
class redirector{
streambuf* out;
fstream file;
public: 
void redirect(string a){
    file.open(a, ios::out); 
    string line;  
    out = cout.rdbuf(); 
    streambuf* stream_buffer_file = file.rdbuf(); 
    cout.rdbuf(stream_buffer_file);
}
void shell_direct(){
    cout.rdbuf(out); 
    cout << "redirected to shell\ndone" << endl; 
    file.close();
}
};
void print(vector<int> a)
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\n";
}
void Subsequences(vector<int> arr, int index, vector<int> subarr = {})
{
    if (index == arr.size())
    {
        int l = subarr.size();
        if (l != 0)
        {
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
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
    int max_count = 0, res = -1;
    for (auto i : map)
    {
        if ((max_count < i.second) || (max_count == i.second && res > i.first))
        {
            res = i.first;
            max_count = i.second;
        }
    }

    return res;
}
unordered_map<int, int> print_result(vector<vector<int>> a)
{
    unordered_map<int, int> result;
    for (int i = 0; i < a.size(); i++)
    {
        result[frequency(a[i], a[i].size())]++;
    }
    return result;
}
int main()
{
    unordered_map<int, int> fin;
    vector<int> input;
    int t, n, temp;
    long long result;
    bool loop = true;
    //cin >> t;
    t=1;
    redirector r;
    r.redirect("cout.txt");
    while (t-->0)
    {
        //cin >> n;
        n=rand()%20+1;
        //n=10;
        cin>>n;
        cout<<n<<"--------------------\n";
        input.clear();
        for (int i = 0; i < n; i++)
        {
            temp=i+1;
            input.push_back(temp);
        }
        st.clear();
        Subsequences(input, 0);
        fin = print_result(st);
        //for(int i=0;i<st.size();i++)
        //print(st[i]);
        for (int i = 0; i < input.size(); i++)
        {
            cout << fin[input[i]]%1000000007 << " ";
            //fin[input[i]]=0;
        }
        cout << "\n";
        cout<<"-----------------------------------\n";
        for (int i = 0; i < n; i++)
        { result=power(2, n - input[i]);
            cout << result << " ";
        }
        cout << "\n";

        for (int i = 0; i < n; i++)
        {
            if (fin[input[i]] != pow(2, n - input[i]))
            {
                loop = false;
                break;
            }
        }
    }
    r.shell_direct();
    return 0;
}
//------------------------------------------------------------
