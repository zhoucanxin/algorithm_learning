/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start
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

/* //迭代方法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* tmp_head = new ListNode(0);
        tmp_head->next = head;
        ListNode* tmp_node = tmp_head;
        while (tmp_node->next != NULL && tmp_node->next->next != NULL)
        {
            ListNode* node1 = tmp_node->next;
            ListNode* node2 = tmp_node->next->next;
            tmp_node->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            tmp_node = node1;
        }
        return tmp_head->next;
    }
}; */

//递归法
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* new_head = head->next;
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        return new_head;
    }
};
// @lc code=end

