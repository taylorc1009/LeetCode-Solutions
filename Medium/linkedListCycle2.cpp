#include <iostream>
#include <string>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* detectCycle(ListNode* head) {
    ListNode* tortoise = head;
    ListNode* hare = head;

    while (tortoise != NULL && hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare) {
            tortoise = head;

            while (tortoise != hare) {
                tortoise = tortoise->next;
                hare = hare->next;
            }

            return tortoise;
        }
    }

    return NULL;
}

int main(int argc, char **argv) {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;
    for (int i = 1; i < 9; i++)
        tail = tail->next = new ListNode(i);
    tail->next = head->next->next;

    ListNode* result = detectCycle(head);
    if (result)
        std::cout << "Cycle detected, beginning at index " + std::to_string(result->val);
    else
        std::cout << "No cycle detected";
}