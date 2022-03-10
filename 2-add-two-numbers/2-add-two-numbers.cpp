class Solution {
public:
    ListNode* addTwoNumbers(ListNode* h1, ListNode* h2) {
        queue<int> s1, s2;
        while (h1) {
            s1.push(h1->val);
            h1 = h1->next;
        }
        while (h2) {
            s2.push(h2->val);
            h2 = h2->next;
        }
        int carry_on = 0;
        ListNode *curr = new ListNode, *prev = curr;
        while (s1.size() || s2.size() || carry_on) {
            int sum = carry_on;
            if (s1.size()) {
                sum += s1.front();
                s1.pop();
            }
            if (s2.size()) {
                sum += s2.front();
                s2.pop();
            }
            carry_on = sum / 10;
             ListNode *prev1 = new ListNode(sum % 10);
            prev->next=prev1;
            prev=prev->next;
          //  curr = prev;
        }
        return curr->next;
    }
};