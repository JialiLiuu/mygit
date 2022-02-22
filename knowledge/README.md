# Day by day

#### 0210

* 架构设计/OOD
  [link](https://segmentfault.com/a/1190000023122582)

#### 0216

* 幂等服务
  以SQL为例，有下面三种场景，只有第三种场景需要开发人员使用其他策略保证幂等性：
  1、 SELECT col1 FROM tab1 WHER col2=2，无论执行多少次都不会改变状态，是天然的幂等。
  2、 UPDATE tab1 SET col1=1WHERE col2=2，无论执行成功多少次状态都是一致的，因此也是幂等操作。
  3、 UPDATE tab1 SET col1=col1+1WHERE col2=2，每次执行的结果都会发生变化，这种不是幂等的。
  [link](https://cloud.tencent.com/developer/article/1522973)

#### 0217

* java双亲委派
所谓的双亲委派机制，指的就是：当一个类加载器收到了类加载的请求的时候，他不会直接去加载指定的类，而是把这个请求委托给自己的父加载器去加载。只有父加载器无法加载这个类的时候，才会由当前这个加载器来负责类的加载。
* java8的新特性
|特性|内容|
|:-|:-|
|[Lambda 表达式](https://www.runoob.com/java/java8-lambda-expressions.html)|Lambda 允许把函数作为一个方法的参数（函数作为参数传递进方法中）。|
|[方法引用](https://www.runoob.com/java/java8-method-references.html)|方法引用通过方法的名字来指向一个方法。方法引用使用一对冒号 :: 。|
|[函数式接口](https://www.runoob.com/java/java8-functional-interfaces.html)|函数式接口(Functional Interface)就是一个有且仅有一个抽象方法，但是可以有多个非抽象方法的接口。函数式接口可以被隐式转换为 lambda 表达式。|
|[默认方法](https://www.runoob.com/java/java8-default-methods.html)||
|[Stream](https://www.runoob.com/java/java8-streams.html)||
|[Optional 类](https://www.runoob.com/java/java8-optional-class.html)||
|[Nashorn JavaScript 引擎](https://www.runoob.com/java/java8-nashorn-javascript.html)||
|[新的日期时间 API](https://www.runoob.com/java/java8-datetime-api.html)||
|[Base64](https://www.runoob.com/java/java8-base64.html)||
* spring bean加载顺序

#### 0221

* InheritableThreadLocal
InheritableThreadLocal主要用于子线程创建时，需要自动继承父线程的ThreadLocal变量，方便必要信息的进一步传递。
[link](https://www.jianshu.com/p/94ba4a918ff5)
* ThreadLocal
[link](http://www.jasongj.com/java/threadlocal/)


#### 0222

* String.format()
```
str=String.format("Hi,%s:%s.%s", "王南","王力","王张");
// Hi,王南:王力.王张
```
[link](https://blog.csdn.net/lonely_fireworks/article/details/7962171)

* @Resource
@Resource用法与@Autowired 用法 用法相似，也是做依赖注入的，从容器中自动获取bean。
在启动spring的时候，首先要启动容器；
启动spring容器时，会默认寻找容器扫描范围内的可加载bean，然后查找哪些bean上的属性和方法上有@Resource注解；
找到@Resource注解后，判断@Resource注解括号中的name属性是否为空，如果为空：看spring容器中的bean的id与@Resource要注解的那个变量属性名是否相同，如相同，匹配成功；如果不相同，看spring容器中bean的id对应的类型是否与@Resource要注解的那个变量属性对应的类型是否相等，若相等，匹配成功，若不相等，匹配失败。
如果@Resource注解括号中的name属性不为空，看name的属性值和容器中的bean的id名是否相等，如相等，则匹配成功；如不相等，则匹配失败。
[link](https://blog.csdn.net/u010502101/article/details/78950045)

* WebSocket
WebSocket协议是基于TCP的一种新的网络协议。它实现了浏览器与服务器全双工(full-duplex)通信——允许服务器主动发送信息给客户端。
[link](https://www.helloworld.net/p/4778073982)

* java内存分析
java内存分析工具 jmap，jhat及dump分析
[link](https://www.jianshu.com/p/1b1c998c4448)

* try catch finally
不管try有没有出错finally方法块都会被执行。
就算try和catch方法都有return，finally都会执行；
只要try或者catch return返回，try catch 之外的return都无效；
那在finally写个return是什么结果哪？写了会不能离开finally子句主体；
[link](https://www.cnblogs.com/yanbigfeg/p/9295541.html)

# Project highlights

#### 单点登录

[理解](https://www.cnblogs.com/ywlaker/p/6113927.html)

#### 数据库读写分离

[实践](https://segmentfault.com/a/1190000023775512)

#### 自定义分库分表

[实践](https://blog.csdn.net/weixin_42437633/article/details/89765740)

#### mysql分页查询

[`<![CDATA[LIMIT #{startIndex},#{pageSize}]]>`](https://www.shangmayuan.com/a/75ecb6de1a594d32af3e572e.html)

#### UMP监控

#### 动态配置

#### 动态调度

#### ES业务日志

[入门教程1](https://www.ruanyifeng.com/blog/2017/08/elasticsearch.html)
[入门教程2](https://www.cainiaojc.com/elasticsearch/)
[java api](https://www.elastic.co/guide/en/elasticsearch/client/java-rest/7.15/index.html)

#### 限流、熔断、降级

[实现](https://www.jianshu.com/p/2ecc233712ce)

#### jemeter压测

[教程](https://www.cnblogs.com/stulzq/p/8971531.html)

#### LDAP

#### 多线程编程技术

[创建线程](https://www.cnblogs.com/pcheng/p/6905340.html)
[线程池](https://www.cnblogs.com/pcheng/p/13540619.html)

#### mybatis

[foreach](https://www.cnblogs.com/fnlingnzb-learner/p/10566452.html)
[动态sql](https://mybatis.org/mybatis-3/zh/dynamic-sql.html)

#### [redis](https://www.runoob.com/redis/redis-tutorial.html)

#### Cache<K, V>

#### @Scheduled(cron = "$")

[解释](https://www.jianshu.com/p/1defb0f22ed1)

#### @Value

[解释](https://blog.csdn.net/woheniccc/article/details/79804600)

#### 缓存操作类

[实现](https://cloud.tencent.com/developer/article/1465411)

#### 消息队列

#### 一致性保证/容灾

[理解](https://www.cnblogs.com/dh-dh/p/12851655.html)

#### [docker](https://blog.51cto.com/lwc0329/3010862)

[安装1](https://blog.51cto.com/lwc0329/3010862)
[安装2](https://www.jianshu.com/p/028b40ca4f2a)

#### 关闭服务

[理论](https://segmentfault.com/a/1190000039405032)

#### 微服务架构

[理论](https://www.cnblogs.com/Leo_wl/p/11736579.html)

#### 拦截器和过滤器

#### ES的索引模板

#### ClickHouse

#### 红黑树

# Big data

### 大数据通用处理平台

1. ~~Spark~~
   [安装](https://www.cnblogs.com/zhangyongli2011/p/10572152.html)
2. Flink
   [安装](https://www.cnblogs.com/linjiqin/p/12425584.html)
   [实践](http://wuchong.me/blog/2018/11/07/use-flink-calculate-hot-items/)
3. Hadoop
   [Map/Reduce](https://hadoop.apache.org/docs/r1.0.4/cn/mapred_tutorial.html)
   [实践1](https://codeantenna.com/a/jr0FIy5JmT)
   [实例](https://www.zhihu.com/question/19936492/answer/142657799)
4. presto

### 分布式存储

1. HDFS

### 资源调度

1. Yarn
2. ~~Mesos~~

### 机器学习工具

1. ~~Mahout~~
2. [Spark Mlib](https://zhuanlan.zhihu.com/p/24320870)
3. ~~TensorFlow (Google 系)~~
4. ~~Amazon Machine Learning~~
5. ~~DMTK (微软分布式机器学习工具)~~

### 数据分析/数据仓库(SQL类)

1. ~~Pig~~
2. Hive
   [安装1](https://www.jianshu.com/p/3fef90437a9c)
   [安装2](https://www.cnblogs.com/qingyunzong/p/8708057.html)
3. kylin
4. [Spark SQL](https://spark.apache.org/docs/latest/api/python/reference/api/pyspark.sql.DataFrame.html#pyspark.sql.DataFrame)
5. [Spark DataFrame](https://blog.csdn.net/dabokele/article/details/52802150)
6. ~~Impala~~
7. ~~Phoenix~~
8. ~~ELK~~
9. ElasticSearch
10. ~~Logstash~~
11. ~~Kibana~~

### 消息队列

1. Kafka([Zookeeper](https://www.runoob.com/w3cnote/zookeeper-tutorial.html))
2. ~~RocketMQ~~
3. ~~ZeroMQ~~
4. ~~ActiveMQ~~
5. ~~RabbitMQ~~

### 流式计算

1. ~~Storm/JStorm~~
2. ~~Spark Streaming~~
3. Flink

### 日志收集

1. Scribe
2. Flume

### 编程语言

1. Java
2. Python
3. ~~R~~
4. ~~Ruby~~
5. Scala

### 数据分析挖掘

1. MATLAB
2. SPSS
3. ~~SAS~~

### 数据可视化

1. ~~R~~
2. ~~D3.js~~
3. ~~ECharts~~
4. Excle
5. Python

### 机器学习基础

1. 聚类
2. 时间序列
3. 推荐系统
4. 回归分析
5. 文本挖掘
6. 决策树
7. 支持向量机
8. 贝叶斯分类
9. 神经网络

### 算法一致性

1. paxos
2. raft
3. gossip

### 数据结构

1. 栈，队列，链表
2. 散列表
3. 二叉树，红黑树，B树
4. 图

### 常用算法

1. 插入排序桶排序堆排序
2. 快速排序
3. 最大子数组
4. 最长公共子序列
5. 最小生成树最短路径
6. 矩阵的存储和运算

### 云计算云服务

1. SaaS
2. PaaS
3. IaaS
4. Openstack
5. Docker

# Read books

#### 2.8

Java核心90页
