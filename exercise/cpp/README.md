### 初始化vector且值全为a(常数)
一维：
```
//初始化size,但每个元素值为默认值
vector<int> abc(10);    //初始化了10个默认值为0的元素
//初始化size,并且设置初始值
vector<int> cde(10，1);    //初始化了10个值为1的元素
```
二维：(x*y的vector，所有值为a)
```
vector<vector<int> > abc(x, vector<int>(y, a));
```

### 删除vector最后一个元素
```
vec.pop_back();         //删除最后一个元素

vec.erase( vec.begin() + 5 );                //删除第6个元素,{0 1 2 3 4 6 7 8 9}
vec.erase( vec.begin(), vec.begin() + 3 );   //删除第1个元素，到第4个元素 {3 4 6 7 8 9}
```

### vector元素排序
升序：sort(begin,end,less<data-type>());
降序：sort(begin,end,greater<data-type>());
```
//从大到小
sort(matchsticks.begin(), matchsticks.end(), greater<int>());
//从小到大
sort(matchsticks.begin(), matchsticks.end(), less<int>());
```