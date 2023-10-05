/*
 * 此方法是參考前一題所想的，比較重大的收穫於，在遍歷的方式中，都會遇到所有的點，那我
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int minDepth(struct TreeNode* root){
  if(root == NULL) return 0;
  int l_depth = minDepth(root->left);
  int r_depth = minDepth(root->right);
  //用來排除NULL點的方式，用來解決題目提供的範例2會出現的問題。
  if(root->left==NULL) return r_depth+1; //新增判斷是否為單一子葉，如果左邊的子葉是空的，那勢必得以另一側的子葉為準。
  if(root->right==NULL) return l_depth+1;
  
  int min = l_depth;
  if(r_depth < min) min = r_depth;
  return min+1;
}