#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode* head) {
    ListNode* cur = head;
    std::string result = "", reversedResult;

    while (cur) {
        result += cur->val + '0';
        cur = cur->next;
    }

    reversedResult = result;
    std::reverse(reversedResult.begin(), reversedResult.end());
    return result == reversedResult; //(std::string){ result.rbegin(), result.rend() };
}

void freeNode(ListNode* node) {
    if (node) {
        freeNode(node->next);
        free(node);
    }
}

int main(int argc, char** argv) {
    ListNode* head = new ListNode(1,
        new ListNode(2,
            new ListNode(3,
                new ListNode(2,
                    new ListNode(1)
                )
            )
        )
    );

    std::cout << isPalindrome(head);

    freeNode(head);
}