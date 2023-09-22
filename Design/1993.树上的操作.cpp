/*
 * @lc app=leetcode.cn id=1993 lang=cpp
 *
 * [1993] 树上的操作
 */

// @lc code=start
class LockingTree {
private:
    // parent[i] = j 表示 i 的父节点是 j
    vector<int> parent;
    // locked[i] = j 表示 i 被 j 锁住, -1 表示未被锁
    vector<int> locked;
    // children[i] = [j, k, ...] 表示 i 的子节点是 j, k, ...
    vector<vector<int>> children;
public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;
        this->locked = vector<int>( n, -1 );
        this->children = vector<vector<int>>( n, vector<int>() );
        for ( int i = 1; i < n; i++ ) {
            int p = parent[i];
            if ( p != -1 )
                children[p].push_back(i);
        }
    }
    
    bool lock(int num, int user) {
        if ( locked[num] == -1 )  {
            locked[num] = user;
            return true;
        }
        return false;
    }
    
    bool unlock(int num, int user) {
        // 只有锁住的用户才能解锁
        if ( locked[num] == user ) {
            locked[num] = -1;
            return true;
        }
        return false;
    }
    
    bool upgrade(int num, int user) {
        // 1. 未被锁住
        // 2. 没有被锁住的祖先
        // 3. 子孙节点中有被锁住的
        // 注意短路原则，3会改变locked[num]的值，所以要放在最后
        bool res = locked[num] == -1 && !hasLockedFather(num) && check(num);
        if ( res ) {
            locked[num] = user;
        }
        return res;
    }
    bool hasLockedFather(int num) {
        num = parent[num];
        // 一直向上找父节点，直到根节点
        while (num != -1 ) {
            if (locked[num] != -1) return true;
            num = parent[num];
        }
        // 没有找到被锁的父节点
        return false;
    }
    // 检查子孙节点中是否有被锁的 并且解锁
    bool check(int num) {
        bool res = locked[num] != -1;
        locked[num] = -1;
        for (int child : children[num]) {
            // 只要有一个子孙节点被锁住就会返回true
            res |= check(child);
        }
        return res;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
// @lc code=end

