#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head) {
    ListNode* tortoise = head;
    ListNode* hare = head;

    while (tortoise != NULL && hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        if (tortoise == hare)
            return true;
    }

    return false;
}

void freeNode(ListNode* node, const int depth, const int size) {
    if (node && depth < size) {
        freeNode(node->next, depth + 1, size);
        free(node);
    }
}

int main(int argc, char** argv) {
    ListNode* head = new ListNode(0);
    ListNode* tail = head;

    //"size" is required when freeing the list because "hasCycle" doesn't return the node which is looped back to, so we can't tell when we've freed the entire list
    //"hasCycle" returns a boolean here because the LeetCode problem specifies that it should, so it does the same here to remain true to LeetCode's problem
    int size = 10;

    for (int i = 1; i < size; i++)
        tail = tail->next = new ListNode(i);
    tail->next = head->next->next;

    std::cout << hasCycle(head);

    freeNode(head, 0, size);
}