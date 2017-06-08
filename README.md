<p align="center">zan thrift代码生成工具</p>

## 使用与安装
使用

   您可直接下载源码https://github.com/youzan/zan-thrift.git bin目录下已编译好的二进制文件。
   也可下载源码后自行按如下步骤编译安装。
   
编译安装

   注意linux环境cmake依赖gcc-c++/flex/bison，mac环境cmake需要3.8版本以上版本。
```
./configure
mkdir build
cd build
cmake ..
make
```

## 约束概述
1. 须在thrifts目录下面执行命令zan-thrift
2. IDL文件须放在thrifts目录下
3. IDL文件namespace以com开头, com.company.module_name.xxx
4. IDL文件路径须与namespace相对应(module_name后开始)
5. 定义接口的IDL的namespace有且仅有一个service
6. IDL文件后缀.thrift
7. 定义namespace的语言须为nova，namespace nova com.company.module_name.xxx

## 官方文档
在线查看文档 [http://zanphpdoc.zanphp.io/nova ✈](http://zanphpdoc.zanphp.io/nova)
- [thrift IDL语法](http://zanphpdoc.zanphp.io/nova/IDL_syntax.html)
- [zan-thrift IDL 设计规范](http://zanphpdoc.zanphp.io/nova/IDL_spec.html)
- [zan-thrift 代码生成工具](http://zanphpdoc.zanphp.io/nova/zan_thrift.html)


## 常用链接
- [异步网络模型](http://tech.youzan.com/yi-bu-wang-luo-mo-xing/)
- [PHP异步编程: 手把手教你实现co与Koa](https://github.com/youzan/php-co-koa) 


## 官方交流渠道
官网：[点我进入](http://zanphp.io)
QQ群：115728122

## 捐赠我们
[捐赠通道](http://zanphp.io/donate)

## License

[Zan-thrift](https://github.com/youzan/zan-thrift)基于 [Apache2.0 license](http://www.apache.org/licenses/LICENSE-2.0) 进行开源。