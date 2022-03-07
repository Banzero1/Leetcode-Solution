class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL){
			return l2;
		}
		if(l2 == NULL){
			return l1;
		}
		ListNode* newHead = NULL;
		ListNode* newTail = NULL;
		if(l1->val < l2->val){
			newHead = l1;
			newTail = l1;
			l1 = l1->next;
		}
		else{
			newHead = l2;
			newTail = l2;
			l2 = l2->next;
		}
        
		while(l1 != NULL and l2 != NULL){
			if(l1->val < l2->val){
				newTail->next = l1;
				newTail = newTail->next;
				l1 = l1->next;
			}
			else{
				newTail->next = l2;
				newTail = newTail->next;
				l2 = l2->next;
			}
		}
		while(l1 != NULL){
			newTail->next = l1;
			newTail = newTail->next;
			l1 = l1->next;
		}
		while(l2 != NULL){
			newTail->next = l2;
			newTail = newTail->next;
			l2 = l2->next;       
		}
        
		return newHead;
	}
};