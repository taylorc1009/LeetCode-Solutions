#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void right(TreeNode* node, int cur, int& max);

void left(TreeNode* node, int cur, int& max) {
    if (node->right)
        right(node->right, cur + 1, max);
    if (node->left)
        left(node->left, 1, max);
    if (cur > max)
        max = cur;
}

void right(TreeNode* node, int cur, int& max) {
    if (node->left)
        left(node->left, cur + 1, max);
    if (node->right)
        right(node->right, 1, max);
    if (cur > max)
        max = cur;
}

int longestZigZag(TreeNode* root) {
    if (!root)
        return 0;

    int max = 0;
    left(root, 0, max);
    right(root, 0, max);

    return max;
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
        new TreeNode(1,
            nullptr,
            new TreeNode(1,
                new TreeNode(1,
                    nullptr,
                    new TreeNode(1)
                ),
                new TreeNode(1)
            )
        ),
        new TreeNode(1)
    );

    std::cout << longestZigZag(root);

    freeNode(root);
}