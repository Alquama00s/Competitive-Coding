#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int power(int x, unsigned int y, long long p=1000000007) 
{ 
	long long res = 1;	 // Initialize result 

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

int main(){
    int t,n,temp;
    long long result;
    vector<int> input;
    cin>>t;
    while(t-->0){
        cin>>n;
        input.clear();
        for(int i=0;i<n;i++){
            cin>>temp;
            input.push_back(temp);
        }
        for(int i = 0; i < n; i++)
        { result=power(2,n-input[i]);
            cout<<result<<" ";
        }cout<<"\n";
        
    }
    return 0;
}