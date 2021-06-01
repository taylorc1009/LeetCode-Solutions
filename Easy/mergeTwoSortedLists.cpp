#include <vector>
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* l3;
    ListNode* p = l1;
    ListNode* q = l2;
    ListNode** l3_it = &l3;

    while (p && q) {
        int val;

        if (p->val <= q->val) {
            val = p->val;
            p = p->next;
        }
        else if (q->val <= p->val) {
            val = q->val;
            q = q->next;
        }

        *l3_it = new ListNode(val);
        l3_it = &(*l3_it)->next;
    }
    
    *l3_it = p ? p : q;

    return l3;

    /* less lines but runs slower
    ListNode l3;
    ListNode *l3_it = &l3;
    
    while(l1 && l2) {
        ListNode *& node = l1->val < l2->val ? l1 : l2;
        l3_it = l3_it->next = node;
        node = node->next;
    }
    
    l3_it->next = l1 ? l1 : l2;
    return l3.next;*/
}

int main(int argc, char** argv) {
    ListNode* l1 = nullptr;
    ListNode* l2 = nullptr;
    std::vector<int> list1 = { 1, 2, 4, 5, 6 };
    std::vector<int> list2 = { 1, 3, 4 };

    ListNode** l1_it = &l1;
    for (std::vector<int>::const_iterator it = list1.begin(); it != list1.end(); it++) {
        *l1_it = new ListNode(*it);
        l1_it = &(*l1_it)->next;
    }

    ListNode** l2_it = &l2;
    for (std::vector<int>::const_iterator it = list2.begin(); it != list2.end(); it++) {
        *l2_it = new ListNode(*it);
        l2_it = &(*l2_it)->next;
    }

    ListNode* result = mergeTwoLists(l1, l2);
    
    while (result != nullptr) {
        std::cout << result->val;
        ListNode* tmp = result;
        result = result->next;
        delete tmp;
    }
}