/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* listNode) {
        if (!listNode)  return nullptr;

        ListNode* prev = nullptr;
        ListNode* curr = listNode;

        while (curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;

        ListNode* head1 = l1;
        ListNode* head2 = l2;
        ListNode* ansHead = nullptr;
        ListNode* tempHead = ansHead;
        int rem = 0; 

        while (head1 && head2) {
            ListNode* temp = new ListNode((head1->val + head2->val + rem)%10);
            rem = (head1->val + head2->val + rem)/10;

            if (!tempHead) {
                ansHead = temp;
                tempHead = ansHead;
            }
            else {
                tempHead->next = temp;
                tempHead = tempHead->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        while (head1) {
            ListNode* temp = new ListNode((head1->val + rem)%10);
            rem = (head1->val + rem)/10;
            tempHead->next = temp;
            tempHead = tempHead->next;
            head1 = head1->next;
        }

        while (head2) {
            ListNode* temp = new ListNode((head2->val + rem)%10);
            rem = (head2->val + rem)/10;
            tempHead->next = temp;
            tempHead = tempHead->next;
            head2 = head2->next;
        }

        if (rem) {
            ListNode* temp = new ListNode(rem);
            tempHead->next = temp;
        }

        return ansHead;
    }
};
