/*
    Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.

    You may assume the integer do not contain any leading zero, except the number 0 itself.

    The digits are stored such that the most significant digit is at the head of the list.

    Example:
    Input:
    1->2->3

    Output:
    1->2->4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* plusOne(ListNode* head) {
        int overflow = doPlusOne(head);
        if(overflow)
        {
            ListNode *temp = new ListNode(overflow);
            temp->next = head;
            head = temp;
        }
        return head;
    }
    
private:
    int doPlusOne(ListNode *node)
    {
        int overflow = node->next == NULL ? 1 : doPlusOne(node->next);
        node->val += overflow;
        overflow = node->val / 10;
        node->val %= 10;
        return overflow;
    }
};
