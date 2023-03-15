#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void countNodes(TreeNode* p, TreeNode* q, const int curDepth, int& curMax) {
    if (p || q) {
        if (p)
            countNodes(p->left, p->right, curDepth + 1, curMax);
        if (q)
            countNodes(q->left, q->right, curDepth + 1, curMax);
    }
    else if (curDepth > curMax)
        curMax = curDepth;
}

int maxDepth(TreeNode* root) {
    if (!root)
        return 0;

    int count = 1;
    countNodes(root->left, root->right, 1, count);
    return count;
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
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(5)
        ),
        new TreeNode(3)
    );

    std::cout << maxDepth(root);

    freeNode(root);
}