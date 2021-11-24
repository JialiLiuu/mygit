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

### map插入数据
[参考](https://blog.csdn.net/Leo_csdn_/article/details/86589904)
```
    map<string, int> m2;
    m2.insert({ "abc", 1 });                    //----1
    m2.insert(make_pair(string("def"), 2));     //----2
    m2.insert(pair<string, int>(string("ghi"), 3));     //----3
```

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

### map最大值最小值


### vector二维求一维长度，二维长度
```
//一维
vec[0].size()
//二维
vec.size()
```

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