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

void postorderHelper(TreeNode* node, std::vector<int>& result) {
    if (!node)
        return;

    postorderHelper(node->left, result);
    postorderHelper(node->right, result);
    result.push_back(node->val);
}

std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    postorderHelper(root, result);
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

    std::vector<int> result = postorderTraversal(root);
    for (int n : result)
        std::cout << n;

    freeNode(root);
}