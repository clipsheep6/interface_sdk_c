# C API接口编码规范

## 1 简介
### 1.1 目的
OpenHarmony提供了一些C语言系统接口供三方应用开发者使用，为了规范SDK C API的接口，对外提供一个统一接口风格，防止出现不必要的符号冲突，特此制定了此规范。

此规范对接口的命名规则，接口头文件，stub库在SDK包中的目录结构进行约束。2章节介绍了OpenHarmony的接口命名规范。

### 1.2 术语定义
* __规则__：必须遵守的设计规则。
* __建议__：必须加以考虑的约定，规则。
* __说明__：对规则进行必须要的解释。
* __示例__：对规则的举例说明。
* __例外__：对规则的举例说明。

### 1.3 约定
* 此规范描述的路径都是指SDK包中相对于Native包中的目录，不是指代码仓中的原始路径。
* 全文xxx表示接口功能模块名，类比于C++中的类名；aaa，bbb表示普通的函数名，文件名。


## 2 C API接口命名规则
在C API中出现的接口，分为两类：
1. 业界标准接口或者是生态约定俗成的接口（如libc，opengles）
2. OpenHarmony自研接口

### 2.1 业界标准接口命名规则
#### 2.1.1 【规则】已有业界标准的C API接口命名规则按照业界标准来命名。

__举例__：
1. libc/libc++采用的是unix_like的命名规则；
2. opengl接口规范采用<库前缀><根命令><可选参数个数><可选参数类型>格式；

__说明__：针对第三方标准中，根据平台要求扩展的接口，也按照此三方库的推荐命名方式。

### 2.2 自研接口命名规则
#### 2.2.1 【规则】C API接口函数标识符命名规则，采用OH_<模块前缀>_<方法名>的方式，命名需要精准，模块前缀采用大驼峰，方法名采用大驼峰规则。

__说明__：采用C语言接口，符号是全局课件，容易与别的模块符号产生符号冲突，采用模块前缀进行作用域区分。

#### 2.2.2 【规则】模块前缀需要精准，描述接口具体功能，模块名字需要接口领域SIG组审议通过。
__说明__：模块前缀相当于C++中的类名，不要采用一些通用的名词，或者是范围过大的名字；
__举例__：OH_AI_xxx，AI这个一般指的是一个行业，一类技术的名词；这类名词座位模块名字不合适。

#### 2.2.3 【建议】接口文件中其他类型命名规范，基础类型建议都进行typedef进行定义。
|类别|命名风格|形式|
|----|----|----|
|【建议】结构体类型，枚举类型，联合体，typedef类型|带模块前缀的大驼峰|采用Xxx_AaaBbb|
|局部变量，函数参数，宏参数，结构体字段，联合体成员|小驼峰|aaaBbb|
|全局变量|带‘g_’前缀的小驼峰|g_Xxx_aaaBbb|
|宏（不包括函数式宏），枚举值，goto标签|全大写，下划线分割|XXX_BBB|
|函数宏|带模块前缀的大驼峰|OH_Xxx_AaaBbb|
|常量（在函数外部定义由const修饰的基本数据类型，枚举类型，字符串类型）|全大写下划线分割，或带'g_'前缀的小驼峰|XXX_BBB, g_Xxx_aaaBbb|

### 2.3 头文件命名规则

#### 2.3.1 【规则】头文件文件名采用unix_like的命名规则，名词与名词间用"_"隔离。
__举例__：采用xxx_aaa.h xxx_aaa_bbb.h，或者xxx/aaa.h xxx/aaa_bbb.h。
__说明__：如果此头文件在sysroot的include目录下的路径中已经包含xxx模块名，头文件的文件名就不需要带xxx前缀。


#### 2.3.2 【规则】自研接口头文件放置在sysroot/usr/include规则，在此目录下创建子系统目录（名字上APP SIG评审），放置到此子目录下。
__说明__：子系统下的目录组织形式可以采用模块名目录加头文件的形式，或者采用模块名_文件名.h方式；不建议新建太深的目录结构，开发者代码在引用头文件的时候，需要引用长串路径，不友好。
```
|--include
|   |--领域组名(需要上API SIG评审)
|   |   |--xxx
|   |   |   |-- aaa.h
|   |   |   |-- bbb.h
|   |   |
|   |   |--xxx_ccc.h 
|   |   |--xxx_common.h 

```

#### 2.3.3 【规则】三方库头文件按照生态的习惯放置，可以不遵守2.3.2规则。

### 2.4 库文件命名规则
#### 2.4.1 【建议】库文件放置在sysroot/usr/lib根目录，不用建子目录；文件名采用unix_like的命名规则，不用z.so结尾。
__说明__：是否需要给C API接口独立创建一个so库，这个没有强制要求；如果C API接口是重新封装，建议独立一个库，因为C API接口实现库在镜像中必须放置到/system/{lib|lib64}/ndk目录，方便接口管控。
__说明__：命名采用libxxx.so的命名方式，库名字最好与模块名字相同，如果包含多个模块，建议采用业界常用的名字；如果名字是常用单词，建议前面加oh前缀，如libohxxx.so，避免名字冲突。


#### 2.4.2 【规则】三方库的名字按照生态约定的名字命名。