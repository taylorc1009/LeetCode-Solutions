#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void countNodes(TreeNode* p, TreeNode* q, const int curDepth, int& curMin) {
    if (curDepth >= curMin)
        return;

    if (p || q) {
        if (p)
            countNodes(p->left, p->right, curDepth + 1, curMin);
        if (q)
            countNodes(q->left, q->right, curDepth + 1, curMin);
    }
    else
        curMin = curDepth;
}

int minDepth(TreeNode* root) {
    if (!root)
        return 0;

    int count = INT_MAX;
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

int main(int argc, char** argv){
    TreeNode* root = new TreeNode(3,
        new TreeNode(9),
        new TreeNode(20,
            new TreeNode(15),
            new TreeNode(7)
        )
    );

    std::cout << minDepth(root);

    freeNode(root);
}