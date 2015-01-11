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
    head->next->next->next->next = head;
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
    bool hasCycle(ListNode *head) {
        if (!head) return false;

        ListNode* hare = head->next;
        ListNode* turtle = head;

        while (hare != turtle) {
            if (!hare) return false;
            hare = hare->next;
            if (hare == turtle) return true;
            turtle = turtle->next;
            if (!hare) return false;
            hare = hare->next;
        }
        return true;
    }
};

int main()
{
    Solution s;
    unique_ptr<ListNode> head(buildExampleList());

    cout << s.hasCycle(head.get());
}
