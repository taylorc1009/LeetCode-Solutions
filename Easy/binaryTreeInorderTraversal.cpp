#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL)
        return std::vector<int>();

    std::vector<int> left = inorderTraversal(root->left);

    left.push_back(root->val);

    std::vector<int> right = inorderTraversal(root->right);
    left.insert(left.end(), right.begin(), right.end());

    return left;
}

void freeNode(TreeNode* node) {
    if (node) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main(int argc, char** argv) {
    TreeNode* root = new TreeNode(1,
        nullptr,
        new TreeNode(2,
            new TreeNode(3),
            nullptr
        )
    );

    std::vector<int> inorder = inorderTraversal(root);
    for (int n : inorder)
        std::cout << n;

    freeNode(root);
}