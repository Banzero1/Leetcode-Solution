class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
      //  tail->next=head;
        // tail = tail->next;
     //  // tail=tail->next;
       // dummy->next=head;
     // return tail;
        
        int flag = true; // should the current head be added ?
        while(head){
            while(head&&head->next&&head->val==head->next->val)
            {
                flag = false; // finds duplicate, set it to false
                head = head->next;
            }
            if(flag) // if should be added
            {
                tail->next = head;
                tail = tail->next;
            }
            head = head->next;
            flag = true; // time for a new head value, set flag back to true
        }
        tail->next = nullptr; // Don't forget this... I did..
        return dummy->next;
        //return tail;
    }
};