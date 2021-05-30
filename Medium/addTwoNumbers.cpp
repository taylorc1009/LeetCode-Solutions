#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* l3 = new ListNode(0);
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode* cur = l3;
    int carry = 0;
    
    while (p != nullptr || q != nullptr) {
        int x = (p != nullptr) ? p->val : 0;
        int y = (q != nullptr) ? q->val : 0;
        
        int sum = carry + x + y;
        carry = sum / 10;
        
        cur->next = new ListNode(sum % 10);
        cur = cur->next;
        
        if (p != nullptr)
            p = p->next;
        
        if (q != nullptr)
            q = q->next;
    }
    
    if (carry > 0)
        cur->next = new ListNode(carry);
    
    return l3->next;
}

int main(int argc, char **argv) {
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    std::vector<int> num1 = { 2, 4, 3 };
    std::vector<int> num2 = { 5, 6, 4 };

    ListNode** l1_it = &l1;
    for (std::vector<int>::const_reverse_iterator it = num1.rbegin(); it != num1.rend(); it++) {
        *l1_it = new ListNode(*it);
        l1_it = &(*l1_it)->next;
    }

    ListNode** l2_it = &l2;
    for (std::vector<int>::const_reverse_iterator it = num2.rbegin(); it != num2.rend(); it++) {
        *l2_it = new ListNode(*it);
        l2_it = &(*l2_it)->next;
    }

    ListNode* result = addTwoNumbers(l1, l2);
    
    while (result != nullptr) {
        std::cout << result->val;
        result = result->next;
    }
}