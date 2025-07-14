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
    int calc(ListNode* head, int &p){
        
        if( head->next == nullptr ){
            p ++;
            return head->val;
        }

        int ret = calc(head->next, p) + head->val * (1 << p);
        p ++;
        return ret;
    }
public:
    int getDecimalValue(ListNode* head) {
        if( head == nullptr )
            return 0;
        int p = 0;
        return calc(head, p);
    }
};