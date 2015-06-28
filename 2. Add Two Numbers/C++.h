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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *curr = head;
        int number1, number2;
        int carry = 0;
        while(l1 || l2 || carry) {
			number1 = l1? l1->val : 0;
			number2 = l2? l2->val : 0;
			curr->next = new ListNode((number1 + number2 + carry) % 10);
			carry = (number1 + number2 + carry) / 10;
            
			if(l1) l1 = l1->next; 
            if(l2) l2 = l2->next; 
            curr = curr->next;
        }
        curr->next = NULL;
		ListNode *result = head->next;
		delete head;
        return result;
    }
};