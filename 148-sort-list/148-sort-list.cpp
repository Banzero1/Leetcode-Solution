class Solution
{
public:
    ListNode *merge(ListNode *a, ListNode *b) // fn to merge the sorted lists
    {
        // base case
        if (a == NULL)
        {
            return b;
        }
        if (b == NULL)
        {
            return a;
        }
		
        // take a new head pointer
		 ListNode *temp; 
		
        if (a->val < b->val)
        {
            temp = a;
            temp->next = merge(a->next, b);
        }
        else
        {
            temp = b;
            temp->next = merge(a, b->next);
        }
        return temp;
    }

    ListNode *midpoint(ListNode *head) // midpoint runner technique to find midpoint
    {
        if (head == NULL or head->next == NULL) // fast=head->next so it cant be NULL
        {
            return head;
        }

        // 2 pointers one slow and one fast 
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL and fast->next != NULL) // because fast->next->next will lead to segmentation fault if not checked for null
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow; // this will return midpoint
    }

    ListNode *sortList(ListNode *head)
    {
		//base case
        if (head == NULL or head->next == NULL)
        {
            return head;
        }

        // recursive case		
        // 1. break the linked list
        ListNode *mid = midpoint(head);
        ListNode *a = head;
        ListNode *b = mid->next;

        mid->next = NULL;

        // 2. recursively sort the 2 parts
        a = sortList(a);
        b = sortList(b);

        // 3. merge them
        ListNode *c = merge(a, b);
        return c;
    }
};