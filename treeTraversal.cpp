#include <deque>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x), left(NULL), right(NULL) {}
};

class traversal {
    // 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
    vector<int> levelOrder1(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            auto temp = q.front();
            res.emplace_back(temp->val);
            q.pop();
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        return res;
    }

    // 从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<int> tier;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int s = q.size();
            res.emplace_back(vector<int>());
            for (int i = 1; i <= s; i++) {
                auto temp = q.front();
                q.pop();
                res.back().emplace_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
        }
        return res;
    }

    // 按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印
    vector<vector<int>> levelOrder3(TreeNode* root) {
        vector<vector<int>> res;
        if (!root)
            return res;
        deque<TreeNode*> q;
        bool odd = true;  // 是否奇数层
        q.push_back(root);
        while (!q.empty()) {
            int s = q.size();
            res.emplace_back(vector<int>());
            for (int i = 1; i <= s; i++) {
                if (odd) {  // 奇数层，前取后放，从左向右打印
                    auto temp = q.front();
                    q.pop_front();
                    res.back().emplace_back(temp->val);
                    if (temp->left)
                        q.push_back(temp->left);
                    if (temp->right)
                        q.push_back(temp->right);
                } else {  // 偶数层，后取前放，从右向左打印
                    auto temp = q.back();
                    q.pop_back();
                    res.back().emplace_back(temp->val);
                    // 先放右子树，保证下一层顺序
                    if (temp->right)
                        q.push_front(temp->right);
                    if (temp->left)
                        q.push_front(temp->left);
                }
            }
            odd = !odd;
        }
        return res;
    }
};