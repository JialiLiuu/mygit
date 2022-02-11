# plan

* ~~150~~
* 1996
* 1827
* M_17_18
* JZ_60
* 775
* JZ_87

### Lambda的语法

```
auto it=find_if(rooms.begin(), rooms.end(), [&](const vector<int> &a) {return a[1] >= queries[i][1]; });
```

[参考](https://blog.csdn.net/huangshanchun/article/details/47155859)

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

升序：sort(begin,end,less`<data-type>`());
降序：sort(begin,end,greater`<data-type>`());

```
//从大到小
sort(matchsticks.begin(), matchsticks.end(), greater<int>());
//从小到大
sort(matchsticks.begin(), matchsticks.end(), less<int>());
```

[参考](https://blog.csdn.net/wlzx1993/article/details/82425813)

### map插入数据

[参考](https://blog.csdn.net/Leo_csdn_/article/details/86589904)

```
    map<string, int> m2;
    m2.insert({ "abc", 1 });                    //----1
    m2.insert(make_pair(string("def"), 2));     //----2
    m2.insert(pair<string, int>(string("ghi"), 3));     //----3
```

### map取最后一个元素

map的自动排序的特性！默认的是从小到大递增排序！！！
[参考](https://blog.csdn.net/Fly_as_tadpole/article/details/82748798)

```
map<int,int>res;
auto map_at = res.end(); 
map_at--;    //指向最后一个元素！
auto map_at = res.begin();   //指向第一个元素！
```

### map lower_bound和upper_bound

map::lower_bound(key):返回map中第一个大于或等于key的迭代器指针
map::upper_bound(key):返回map中第一个大于key的迭代器指针

```
map <int, int> :: const_iterator it = _map.upper_bound(2);
it -> second;
```

[来源](https://www.cnblogs.com/billin/archive/2011/09/01/2162102.html)

### map delete

```
//删除键为k1指向的元素
cmap.erase("k1");
//删除迭代器 key所指向的元素
map<string,int>::iterator key = cmap.find("mykey");
  if(key!=cmap.end())
 {
	cmap.erase(key);
 }
//删除所有元素
cmap.erase(cmap.begin(),cmap.end());
```

[参考](https://blog.csdn.net/zvall/article/details/52267007)

### map find

```
map<int, string>::iterator iter = mapStudent.find(1);
if(iter != mapStudent.end())
    Cout<<”Find, the value is ”<<iter->second<<endl;
else
    Cout<<”Do not Find”<<endl;
```

### map的元素个数

```
_map.size()
```

### map排序(由大到小)

自定义的比较函数是静态的！！
将map转化成vector<pair<xxx,xxx> >

```
class Solution
{
    static bool cmp(const pair<int, int> &p1, const pair<int, int> &p2) //要用常数，不然编译错误 加static！！！
    {
        return p1.second > p2.second;
    }

public:
    int AA(vector<vector<int>> &times, int n, int k)
    {
        vector<pair<int, int>> _map;
        sort(_map.begin(), _map.end(), cmp);
    }
```

[参考](https://blog.csdn.net/qq_31217423/article/details/76375336)

### vector二维求一维长度，二维长度

```
//一维
vec[0].size()
//二维
vec.size()
```

### vector求和

```
    vector<int> v = { 1, 2, 3, 4, 5 };
    cout << "sum2: " << accumulate(v.begin(), v.end(), 0) << endl; //15
    cout << "sum3: " << accumulate(v.begin(), v.end(), 5) << endl;  //20
```

[参考](https://blog.csdn.net/qq_22186119/article/details/104995831)

### vector find

* 一维数组寻找

```
vector<int>::iterator it = find(vec.begin(), vec.end(), 6);
if (it != vec.end())
    cout<<*it<<endl;
else
    cout<<"can not find"<<endl;
```

* 二维数组寻找

```
auto it=find_if(rooms.begin(), rooms.end(), [](const vector<int> &a) {return a[1] >= 4; });
```

[参考](https://www.cnblogs.com/heyonggang/p/3241789.html)

### int转string

[参考](https://blog.csdn.net/chavo0/article/details/51038397)

```
to_string()
```

### 数组最大值/最小值

1. 求数组的最大值或最小值

* vector容器
  最大值：int maxValue = *max_element(v.begin(),v.end());
  最小值：int minValue = *min_element(v.begin(),v.end());
* 普通数组
  最大值：int maxValue = *max_element(a,a+6);
  最小值：int minValue = *min_element(a,a+6);

2. 求数组最大值最小值对应的下标

* vector容器
  最大值下标：int maxPosition = max_element(v.begin(),v.end()) - v.begin();
  最小值下标：int minPosition = min_element(v.begin(),v.end()) - v.begin();
* 普通数组
  最大值下标：int maxPosition = max_element(a,a+6) - a;
  最小值下标：int minPosition = min_element(a,a+6) - a;
  [参考](https://www.cnblogs.com/Tang-tangt/p/9352093.html)

### vector 差分

```
std::vector<int> v{2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
std::adjacent_difference(v.begin(), v.end(), v.begin());
for (auto n : v)
    std::cout << n << ' ';  //2  2  2  2  ....
```

[参考](https://blog.csdn.net/zhangxiao93/article/details/75822424)

### string 初始化全为a的字符串

string(size_type n,char c) ：创建一个包含 n 个元素的 string 对象，其中每个元素都被初始化为字符 c

```
string str(10,'a');
string.find_first_of();
string.find_last_of();
```

[来源](https://www.cnblogs.com/tongye/p/10760154.html)
