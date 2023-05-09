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

void preorderHelper(TreeNode* node, std::vector<int>& result) {
    if (!node)
        return;

    result.push_back(node->val);
    preorderHelper(node->left, result);
    preorderHelper(node->right, result);
}

std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    preorderHelper(root, result);
    return result;
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

    std::vector<int> result = preorderTraversal(root);
    for (int n : result)
        std::cout << n;

    freeNode(root);
}