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
    ListNode* head = new ListNode(0);
    head->next = new ListNode(0);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(0);
    head->next->next->next->next = new ListNode(1);
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode* next = head;
        ListNode* prev = head;

        if (head == nullptr)
            return head;

        while (next->next != nullptr) {
            next = next->next;

            if (prev->val == next->val) {
                prev->next = next->next;
                delete next;
                next = prev;
            }
            else {
                prev = next;
            }
        }

        return head;
    }
};

int main()
{
    Solution s;
    unique_ptr<ListNode> head(buildExampleList());

    printList(s.deleteDuplicates(head.get()));
    printList(s.deleteDuplicates(NULL));
    printList(s.deleteDuplicates(new ListNode(55)));
}
