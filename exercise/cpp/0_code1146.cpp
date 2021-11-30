#include "../include/common.h"
//超时
class SnapshotArray
{
public:
    vector<int> item;
    map<int, vector<int>> _map;
    int count = 0;
    SnapshotArray(int length)
    {
        vector<int> temp(length, 0);
        item = temp;
    }

    void set(int index, int val)
    {
        item[index] = val;
    }

    int snap()
    {
        _map.insert({count, item});
        return count++;
    }

    int get(int index, int snap_id)
    {
        vector<int> temp = _map[snap_id];
        return temp[index];
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