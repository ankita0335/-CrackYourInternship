class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int i=0;
        int idx=0;
        while(i<n)
        {
            char curr= chars[i];
            int c=0;
            while(i<n && chars[i]== curr)
            {
                i++;
                c++;
            }
            chars[idx]= curr;
            idx++;
            if(c>1)
            {
                string str = to_string(c);
                for(auto &ch : str)
                {
                    chars[idx]= ch;
                    idx++;
                }
            }
        }
        return idx;
    }
};