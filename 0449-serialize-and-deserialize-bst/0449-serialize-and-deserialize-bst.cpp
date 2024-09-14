/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec 
{
public:
    int i=0;
    string serialize(TreeNode* root) 
    {
        if(!root)   return "X,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
    }
    TreeNode* deserialize(string data) 
    {
        if(i>= data.size() ) return nullptr;
        string tmp ="";
        while(data[i] != ',')
        {
            tmp += data[i];
            i++;
        }
        i++;
        if(tmp == "X")
        {
            return nullptr;
        }
        TreeNode* ans = new TreeNode(stoi(tmp));
        ans->left = deserialize(data);
        ans->right = deserialize(data);
        return ans;
    }
};





// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
