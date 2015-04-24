#include <iostream>
#include <memory>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };


ListNode* buildExampleList()
{
    ListNode* head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);
    head->next->next->next = new ListNode(9);
    head->next->next->next->next = new ListNode(9);
    return head;
}

void printList(ListNode* head)
{
    while (head != nullptr)
    {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << "\n";
}

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int add = 0;
        int res = 0;
        ListNode* head = nullptr;
        ListNode* cur = nullptr;

        while (l1 || l2 || (add != 0)) {
            res = 0;
            if (l1) {
                res += l1->val;
                l1 = l1->next;
            }
            if (l2) {
                res += l2->val;
                l2 = l2->next;
            }

            if (!cur) {
                cur = new ListNode((res + add) % 10);
                head = cur;
            }
            else {
                cur->next = new ListNode((res + add) % 10);
                cur = cur->next;
            }

            add = (res + add) / 10;
        }

        return head;
    }
};

int main()
{
    Solution s;

    ListNode* l1 = buildExampleList();
    ListNode* l2 = buildExampleList();

    printList(l1);
    printList(l2);
    printList(s.addTwoNumbers(l1, l2));
    printList(s.addTwoNumbers(nullptr, nullptr));
}
