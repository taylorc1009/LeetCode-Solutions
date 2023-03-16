#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool rootToLeaf(TreeNode* p, TreeNode* q, int curPathSum, const int& targetSum) {
    if (p || q)
        return (p && rootToLeaf(p->left, p->right, curPathSum + p->val, targetSum)) ||
                (q && rootToLeaf(q->left, q->right, curPathSum + q->val, targetSum));
    return curPathSum == targetSum;
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root)
        return false;
    return rootToLeaf(root->left, root->right, root->val, targetSum);
}

void freeNode(TreeNode* node) {
    if (node) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(5,
        new TreeNode(4,
            new TreeNode(11,
                new TreeNode(7),
                new TreeNode(2)
            ),
            nullptr
        ),
        new TreeNode(8,
            new TreeNode(13),
            new TreeNode(4,
                nullptr,
                new TreeNode(1)
            )
        )
    );

    std::cout << hasPathSum(root, 22);

    freeNode(root);
}