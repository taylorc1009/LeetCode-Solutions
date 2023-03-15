#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p && q) {
        if (p->val == q->val)
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else if (!p && !q)
        return true;
    return false;
}

void freeNode(TreeNode* node) {
    if (node) {
        freeNode(node->left);
        freeNode(node->right);
        free(node);
    }
}

int main(int argc, char** argv) {
    TreeNode* p = new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );

    TreeNode* q = new TreeNode(1,
        new TreeNode(2),
        new TreeNode(3)
    );

    std::cout << isSameTree(p, q);

    freeNode(p);
    freeNode(q);
}