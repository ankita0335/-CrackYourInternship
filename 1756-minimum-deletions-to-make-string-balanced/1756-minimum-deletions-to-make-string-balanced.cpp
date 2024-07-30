class Solution {
public:
    int minimumDeletions(string s) {
        int c = 0;
        int d= 0;
        for (int i = s.length()-1;i>=0;i--) {
            if (s[i] == 'a') 
            {
                c++;
            } 
            else 
            {
                d= min(d + 1, c);
            }
        }
        return d;
    }
};