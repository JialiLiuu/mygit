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

# Project highlights
#### 单点登录
[理解](https://www.cnblogs.com/ywlaker/p/6113927.html)
#### 数据库读写分离
[实践](https://segmentfault.com/a/1190000023775512)
#### 自定义分库分表
[实践](https://blog.csdn.net/weixin_42437633/article/details/89765740)
#### mysql分页查询
[<![CDATA[LIMIT #{startIndex},#{pageSize}]]>](https://www.shangmayuan.com/a/75ecb6de1a594d32af3e572e.html)
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
#### @Scheduled(cron = "${attr.realtime.update.worker.cron:39 15 7 * * ?}")
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
9.  ElasticSearch
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