#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void rootToLeaf(TreeNode* node, int prevNum, int& result) {
    const int curNum = (prevNum * 10) + (node ? node->val : 0);

    if (node && (node->left || node->right)) {
        if (node->left)
            rootToLeaf(node->left, curNum, result);
        if (node->right)
            rootToLeaf(node->right, curNum, result);
    }
    else
        result += curNum;
}

int sumNumbers(TreeNode* root) {
    int result = 0;
    rootToLeaf(root, 0, result);
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
    TreeNode* root = new TreeNode(4,
        new TreeNode(9,
            new TreeNode(5),
            new TreeNode(1)
        ),
        new TreeNode(0)
    );

    std::cout << sumNumbers(root);

    freeNode(root);
}