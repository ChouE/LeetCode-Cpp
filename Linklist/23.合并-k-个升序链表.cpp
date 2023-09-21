/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // erase 参数为迭代器，remove_if 返回的是迭代器
        // remove_if 会将不满足条件的元素移动到容器末尾，返回指向第一个被移动的元素的迭代器
        // erase + remove_if 将所有空list删除
        lists.erase(remove_if(lists.begin(), lists.end(), [](auto p) {
            return !p;
        }), lists.end());
        // 优先队列的比较函数，lambda 表达式
        priority_queue q {[](auto &a, auto &b){
            return a->val > b->val;
        }, lists};
        
        ListNode dummy;
        for (auto p = &dummy; !q.empty(); q.pop()) {
            p = p->next = q.top();
            if (p->next) q.push(p->next);
        }
        return dummy.next;
    }
};
// @lc code=end

