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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* dummy=new ListNode(0),*curr;
        curr=dummy;
    
        vector<int>v;
        int c=0,i=0;
        head=head->next;
        while(head!=NULL)
        {
            if(head->val!=0)
            {
                c+=head->val;
            }
            else if(c>0)
            {
                v.push_back(c);
                c=0;
            }
            head=head->next;
        }
        
        while(i<v.size())
        {
            ListNode* temp=new ListNode(v[i]);
            dummy->next=temp;
            dummy=dummy->next;
            i++;
        }
        
        return curr->next;
        
    }
};