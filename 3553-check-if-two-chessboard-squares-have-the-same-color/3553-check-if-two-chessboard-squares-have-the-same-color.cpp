class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) 
    {
        int x = coordinate1[0]-'a' ;
        int y = coordinate1[1] -'1';
        int a = coordinate2[0]-'a';
        int b= coordinate2[1]-'1';
        if((x+y)%2 == (a+b)%2)  return true;
        return false;   
    }
};