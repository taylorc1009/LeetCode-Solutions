#include <iostream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* deleteDuplicates(ListNode* head) {
    ListNode* node = head;
    ListNode* lastKept = head;

    while (node != nullptr) {
        if (node->val == lastKept->val) {
            lastKept->next = node = node->next;
            continue;
        }

        lastKept = lastKept->next = node;
        node = node->next;
    }

    return head;
}

int main(int argc, char** argv) {
    ListNode* head = nullptr;
    std::vector<int> list = { 1, 1, 1, 1, 2, 3, 3, 4, 4, 4, 5 };

    ListNode** it = &head;
    for (std::vector<int>::const_iterator i = list.begin(); i != list.end(); i++) {
        *it = new ListNode(*i);
        it = &(*it)->next;
    }

    deleteDuplicates(head);

    it = &head;
    while (*it != nullptr) {
        std::cout << std::to_string((*it)->val) + ((*it)->next == nullptr ? "" : " ");
        it = &(*it)->next;
    }
}