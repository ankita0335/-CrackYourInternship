//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here // code here
        vector<string> vr;
        int start = 0;
        int count = 0;
        for(int i = 0; i<str.size(); i++){
            count+=1;
            if(str[i] == '.'){
                string temp = str.substr(start,count-1);
                vr.push_back(temp);
                start = i+1;
                count = 0;
            }
        }
        vr.push_back(str.substr(start));
        string ans;
        int n = vr.size();
        for(int i = n-1; i>0; i--){
            ans = ans + vr[i] + '.';
        }
        ans += vr[0];
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends