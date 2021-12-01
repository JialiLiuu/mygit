#include "../include/common.h"
//超时,参考https://leetcode-cn.com/problems/snapshot-array/solution/java-shi-yong-treemapzhi-xu-ji-xing-dai-ma-by-forz/ 改思路
class SnapshotArray
{
public:
    vector<map<int, int>> item;
    int count = 0;
    SnapshotArray(int length)
    {
        map<int, int> _map;
        _map[0]=0;
        for (int i = 0; i < length; i++)
            item.push_back(_map);
    }

    void set(int index, int val)
    {
        item[index][count]=val;
        // item[index].insert({count, val});
    }

    int snap()
    {
        return count++;
    }

    int get(int index, int snap_id)
    {
        auto it=item[index].upper_bound(snap_id);
        if(it==item[index].begin())
            return 0;
        else
            it--;
        return it->second;
    }
};

int main()
{
    SnapshotArray snapshotArr(3);
    snapshotArr.set(0, 5); // 令 array[0] = 5
    snapshotArr.snap();    // 获取快照，返回 snap_id = 0
    snapshotArr.set(0, 6);
    cout << snapshotArr.get(0, 0) << endl; // 获取 snap_id = 0 的快照中 array[0]
}