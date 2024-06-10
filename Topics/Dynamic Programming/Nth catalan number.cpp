#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  // https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;


cpp_int dp[101];
class Solution{
  public:
    cpp_int findCatalan(int n) {

    if (dp[n] != 0)
        return dp[n];

    if (n==0)
        dp[n] = 1;
    else
    {
        dp[n]=0;
        for (int i=0 ; i<n ; i++)
            dp[n]+=findCatalan(i)*findCatalan(n-1-i);
    }
    return dp[n];
    }
};

// { Driver Code Starts.

int main()
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {

	    //taking nth number
	    int n;
	    cin>>n;
	    Solution obj;
	    //calling function findCatalan function
	    cout<< obj.findCatalan(n) <<"\n";
	}
	return 0;
}  // } Driver Code Ends
