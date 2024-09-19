class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<pair<string, int>>pq;
        pq.push({beginWord,1});
        while(!pq.empty())
        {
            pair<string,int>tmp = pq.front();
            string word= tmp.first;
            int ans = tmp.second;
            pq.pop();
            if(word== endWord)
            {
                return ans;
            }
            dict.erase(word);
            for(int i=0;i<word.size();i++)
            {
                char c= word[i];
                for(int k=0;k<26;k++)
                {
                    word[i]= 'a'+k;
                    if(dict.find(word)!= dict.end())
                    {
                        pq.push({word, ans+1});
                    }
                } 
                word[i]=c;
            }
        }
        return 0;
    }
};