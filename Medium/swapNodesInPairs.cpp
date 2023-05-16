#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next)
        return head;

    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* newHead = nullptr;

    while (cur != nullptr && cur->next != nullptr) {
        ListNode* temp = cur->next;
        cur->next = cur->next->next;
        temp->next = cur;

        if (prev)
            prev->next = temp;
        prev = cur;

        if (!newHead)
            newHead = temp;
        cur = cur->next;
    }

    return newHead;
}

void freeNode(ListNode* node) {
    if (node) {
        freeNode(node->next);
        free(node);
    }
}

int main(int argc, char **argv) {
    ListNode* head = new ListNode(1,
        new ListNode(2,
            new ListNode(3,
                new ListNode(4,
                    new ListNode(5)
                )
            )
        )
    );

    ListNode* cur = swapPairs(head);
    while (cur) {
        std::cout << cur->val;
        cur = cur->next;
    }

    freeNode(head);
}