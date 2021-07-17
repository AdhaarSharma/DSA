//Answer was Wrong. Needs Correction


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        return treeHelper(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    TreeNode* treeHelper(vector<int>& preorder, vector<int>& inorder, int preS, int preE, int inS, int inE){
        if(inE<inS) return NULL;
        int rootData = preorder[preS];
        int rootIndex = -1;
        for(int i=inS; i<=inE; i++){
            if(inorder[i] == rootData){
                rootIndex = i;
                break;
            }
        }
        int lInS = inS;
        int lInE = rootIndex - 1;
        int lPreS = preS + 1;
        int lPreE = lInE - lInS + lPreS;
        int rInS = rootIndex + 1;
        int rInE = inE;
        int rPreS = lPreE;
        int rPreE = preE;
        TreeNode* root = new TreeNode();
        root->val = rootData;
        root->left = treeHelper(inorder, preorder, lInS, lInE, lPreS, lPreE);
        root->right = treeHelper(inorder, preorder, rInS, rInE, rPreS, rPreE);
        return root;
    }
};