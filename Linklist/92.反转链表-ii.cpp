/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // 使用三个指针完成一趟
        // cur 指向待反转区域的第一个节点
        // next 指向cur的下一个节点
        // pre 指向待反转区域的第一个节点前的一个节点，在循环中需要保持不变
        ListNode* dummy = new ListNode(-1, head);
        ListNode* pre = dummy;
        for (int i = 0; i < left - 1; i++) {
            // 定位pre
            pre = pre->next;
        }
        ListNode* cur = pre->next;
        ListNode* next;
        for (int i = 0; i < right - left; i++) {
            next = cur->next;
            cur->next = next->next;
            next->next = pre->next;
            pre->next = next;
        }
        return dummy->next;
    }
};
// @lc code=end

