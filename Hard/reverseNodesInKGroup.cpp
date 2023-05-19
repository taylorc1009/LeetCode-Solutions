#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseKGroup(ListNode* head, int k) {
    if (k < 2)
        return head;

    ListNode* cur = head;
    ListNode* prev = nullptr;
    ListNode* newHead = nullptr;
    std::vector<ListNode*> kGroup(k, nullptr);
    int count = 0;

    while (cur || count == k) {
        if (count == k) {
            if (!newHead)
                newHead = kGroup.back();

            if (prev)
                prev->next = kGroup.back();
            prev = kGroup[0];
            kGroup[0]->next = cur;

            for (int i = 1; i < k; i++)
                kGroup[i]->next = kGroup[i - 1];

            if (!cur)
                return newHead;

            fill(kGroup.begin(), kGroup.end(), nullptr);
            kGroup[0] = cur;
            count = 1;
        }
        else
            kGroup[count++] = cur;
        cur = cur->next;
    }

    return newHead ? newHead : head;
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
                new ListNode(4,
                    new ListNode(5)
                )
            )
        )
    );

    ListNode* reversed = reverseKGroup(head, 3);

    ListNode* cur = reversed;
    while (cur) {
        std::cout << cur->val;
        cur = cur->next;
    }

    freeNode(reversed);
}