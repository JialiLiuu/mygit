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
* java8的新特性| 特性                                                                              | 内容                                                                                                                                     |
  | :-------------------------------------------------------------------------------- | :--------------------------------------------------------------------------------------------------------------------------------------- |
  | [Lambda 表达式](https://www.runoob.com/java/java8-lambda-expressions.html)           | Lambda 允许把函数作为一个方法的参数（函数作为参数传递进方法中）。                                                                        |
  | [方法引用](https://www.runoob.com/java/java8-method-references.html)                 | 方法引用通过方法的名字来指向一个方法。方法引用使用一对冒号 :: 。                                                                         |
  | [函数式接口](https://www.runoob.com/java/java8-functional-interfaces.html)           | 函数式接口(Functional Interface)就是一个有且仅有一个抽象方法，但是可以有多个非抽象方法的接口。函数式接口可以被隐式转换为 lambda 表达式。 |
  | [默认方法](https://www.runoob.com/java/java8-default-methods.html)                   |                                                                                                                                          |
  | [Stream](https://www.runoob.com/java/java8-streams.html)                             |                                                                                                                                          |
  | [Optional 类](https://www.runoob.com/java/java8-optional-class.html)                 |                                                                                                                                          |
  | [Nashorn JavaScript 引擎](https://www.runoob.com/java/java8-nashorn-javascript.html) |                                                                                                                                          |
  | [新的日期时间 API](https://www.runoob.com/java/java8-datetime-api.html)              |                                                                                                                                          |
  | [Base64](https://www.runoob.com/java/java8-base64.html)                              |                                                                                                                                          |
* spring bean加载顺序

#### 0221

* InheritableThreadLocal
  InheritableThreadLocal主要用于子线程创建时，需要自动继承父线程的ThreadLocal变量，方便必要信息的进一步传递。
  [link](https://www.jianshu.com/p/94ba4a918ff5)
  ~~* ThreadLocal~~
  ~~[link](http://www.jasongj.com/java/threadlocal/)~~

#### 0222

* String.format()

```
str=String.format("Hi,%s:%s.%s", "王南","王力","王张");
// Hi,王南:王力.王张
```

[link](https://blog.csdn.net/lonely_fireworks/article/details/7962171)

#### 0224

* BigDecima
  Java在java.math包中提供的API类BigDecimal，用来对超过16位有效位的数进行精确的运算。双精度浮点型变量double可以处理16位有效数，但在实际应用中，可能需要对更大或者更小的数进行运算和处理。一般情况下，对于那些不需要准确计算精度的数字，我们可以直接使用Float和Double处理，但是Double.valueOf(String) 和Float.valueOf(String)会丢失精度。所以开发中，如果我们需要精确计算的结果，则必须使用BigDecimal类来操作。
  [link](https://www.cnblogs.com/zhangyinhua/p/11545305.html)
* Redis中String类型的Value最大可以容纳数据长度
  项目中使用redis存储，key-value方式，在Redis中字符串类型的Value最多可以容纳的数据长度是512M
  官方信息:
  A String value can be at max 512 Megabytes in length.
  [link](https://blog.csdn.net/lu_wei_wei/article/details/50906101)

#### 0225

* Mockito 框架
* implements Serializable
  一个对象序列化的接口，一个类只有实现了Serializable接口，它的对象才是可序列化的。因此如果要序列化某些类的对象，这些类就必须实现Serializable接口。而实际上，Serializable是一个空接口，没有什么具体内容，它的目的只是简单的标识一个类的对象可以被序列化.
  在进行Java的Socket编程的时候，你有时候可能要传输某一类的对象，那么也就要实现Serializable接口。最常见的你传输一个字符串，它是JDK里面的类，也实现了Serializable接口，这样做为的是将数据变为二进制来传输，所以可以在网络上传输。
  [link](https://blog.csdn.net/am540/article/details/82498298)
* redis过期键的删除策略
  redis使用的过期键值删除策略是：惰性删除加上定期删除，两者配合使用
  [link](https://www.jianshu.com/p/9352d20fb2e0)

#### 0228

* 序列化 反序列化
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

#### 0301

* instanceof
  [link](https://www.jianshu.com/p/5fc7d8cc0cf0)
* HTTP请求状态码| HTTP 返回码（Status Code）                                             | 说明（Description）                                                  |
  | :--------------------------------------------------------------------- | :------------------------------------------------------------------- |
  | 400                                                                    | 错误请求）服务器不理解请求的语法。                                   |
  | 404                                                                    | （未找到）服务器找不到请求的接口。                                   |
  | 500                                                                    | （服务器内部错误）服务器遇到错误，无法完成请求。                     |
  | 504                                                                    | （网关超时）服务器作为网关或代理，但是没有及时从上游服务器收到请求。 |
  | [link](https://docs-im.easemob.com/start/450errorcode/10restapierrorcode) |                                                                      |
* git提交规范

> feat - 新功能 feature
> fix - 修复 bug
> docs - 文档注释
> style - 代码格式(不影响代码运行的变动)
> refactor - 重构、优化(既不增加新功能，也不是修复bug)
> perf - 性能优化
> test - 增加测试
> chore - 构建过程或辅助工具的变动
> revert - 回退
> build - 打包
> [link](https://juejin.cn/post/6844903793033756680#heading-6)

#### 0302

* redis中hash类型操作
  [link](https://segmentfault.com/a/1190000037786578)
* java JSONObject
  构造JSONObject

```
JSONObject();
JSONObject(String str);
JSONObject(Object obj);
JSONObject(Map<String, Object> map);
```

无参构造JSONObject

```
People people = new People();
...省略
JSONObject jsonO = new JSONObject();
jsonO.put("a", "a");
jsonO.put("people", people);
System.out.println(jsonO);
```

[link](https://blog.csdn.net/Qimingweikun/article/details/79970180)

* spring context
* java.lang.reflect.Field
  [link](https://vimsky.com/examples/usage/field-set-method-in-java-with-examples.html)
  [link](https://www.cnblogs.com/Big-Boss/p/13402721.html)

#### 0303

* toString和toJSONString的区别

```
 Map<String, Integer> map = new HashMap<>();
map.put( "staff9", 1 );
map.put( "staff1", 3 );
System.out.println(map.toString());
System.out.println(JSONObject.toJSONString(map));

List<Map<String, Integer>> list = new ArrayList<>();
list.add(map);
System.out.println(list.toString());
System.out.println(JSONArray.toJSONString(list));
<!-- 结果
{staff9=1, staff1=3}
{"staff9":1,"staff1":3}
[{staff9=1, staff1=3}]
[{"staff9":1,"staff1":3}] -->
```

[link](https://blog.csdn.net/sinat_36454672/article/details/105969975)

#### 0304

* redis支持数据类型及用法
  字符串 done
  哈希 done
  列表 done
  集合 done
  有序集合
  HyperLogLog
  [link](https://www.redis.com.cn/redis-intro.html) **还要很多没有看**
* HTTP和RPC的区别

#### 0307

* BeanMap.create()
  进行对象与Map的相互转换
  [link](https://blog.csdn.net/q358543781/article/details/50176953)
* equals() equalsIgnoreCase()
  For e.g. The equals() method would return false if we compare the strings “TEXT” and “text” however equalsIgnoreCase() would return true.
  [link](https://beginnersbook.com/2013/12/java-string-equals-and-equalsignorecase-methods-example/)
* 拦截器
  Spring的拦截器

```
public abstract class HandlerInterceptorAdapter implements HandlerInterceptor{
    // 在业务处理器处理请求之前被调用
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception{
        return true;
    }
    // 在业务处理器处理请求完成之后，生成视图之前执行
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView)
      throws Exception{
    }
    // 在DispatcherServlet完全处理完请求之后被调用，可用于清理资源
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex)
      throws Exception{
    }
}
```

[link](https://segmentfault.com/a/1190000024464165)
Struts2的拦截器
[link](https://www.jianshu.com/p/30b62f11d6cb)

* 跨域| 参数                             | 值           | 描述                                                 |
  | :------------------------------- | :----------- | :--------------------------------------------------- |
  | Access-Control-Allow-Origin      | *            | 授权的源控制                                         |
  | Access-Control-Allow-Credentials | true / false | 是否允许用户发送和处理cookie                         |
  | Access-Control-Allow-Methods     | [,]*         | 允许请求的HTTP Method，多个用逗号分隔                |
  | Access-Control-Allow-Headers     | [,]*         | 控制哪些header能发送真正的请求，多个用逗号分隔       |
  | Access-Control-Max-Age           | 秒           | 授权的时间，单位为秒。有效期内，不会重复发送预检请求 |

当发生跨域请求时，浏览器会发起两次请求，第一次为预检请求，其请求方法为OPTIONS，第二次为真实请求。只有当第一次请求成功后才会发起第二次请求。
所以在拦截器或者过滤器对token进行验证的时候处理，OPTIONS的请求是不会带有认证信息，所以需要跳过OPTIONS请求。

```
String method = request.getMethod();
if(method.equals("OPTIONS")){
  // 放行
} else {
  // 验证token
}
```

![](image/README/1646649512725.png)
[link](https://segmentfault.com/a/1190000017823645)

#### 0309

* @PostConstruct注解
  该注解是Java jdk提供的注解，而不是Spring框架提供的， JavaEE5引入了@PostConstruct和@PreDestroy两个作用于Servlet生命周期的注解，实现Bean初始化之前和销毁之前的自定义操作。
  Constructor(构造方法) -> @Autowired(依赖注入) -> @PostConstruct(注释的初始化方法)

```
import javax.annotation.PostConstruct;
 
@Component
public class Utils {
 
    @Autowired
    private UserService userService;
 
    @PostConstruct
    void init() {
        userService.doSomething();  //userService注入后执行一些初始化操作
    }
 
}
```

[link](https://blog.csdn.net/skh2015java/article/details/117751380)

* ConcurrentHashMap
JDK1.8 ConcurrentHashMap取消了segment分段锁，而采用CAS和synchronized来保证并发安全。数据结构采用数组+链表/红黑二叉树。
ConcurrentHashMap是jdk的并发包中提供的并发map，可以有效防止多线程操作一个对象时出现对象副本不一致。
另外ConcurrentHashMap在多线程的情况下,也是一般用在**读多写少**的情况.不是所有的多线程都可以使用这个并发工具类的
[link](https://segmentfault.com/q/1010000009944819)
* ThreadLocal
ThreadLocal 适用于每个线程需要自己独立的实例且该实例需要在多个方法中被使用，也即变量在线程间隔离而在方法或类间共享的场景。
ThreadLocal 适用于如下两种场景
每个线程需要有自己单独的实例
实例需要在多个方法中共享，但不希望被多线程共享
[link](http://www.jasongj.com/java/threadlocal/)
