#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool compareNodes(TreeNode* p, TreeNode* q) {
    if (p && q) {
        if (p->val == q->val)
            return compareNodes(p->left, q->right) && compareNodes(p->right, q->left);
    }
    else if (!p && !q)
        return true;
    return false;
}

bool isSymmetric(TreeNode* root) {
    return compareNodes(root->left, root->right);
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
            new TreeNode(3),
            new TreeNode(4)
        ),
        new TreeNode(2,
            new TreeNode(4),
            new TreeNode(3)
        )
    );

    std::cout << isSymmetric(root);

    freeNode(root);
}