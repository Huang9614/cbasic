# 9.2-9.4 类的定义和相关基础
- 类使用变量来定义 `data fields` 和 `functions`， 分别对应object的属性和方法
  - `Circle circle()` 或者`Circle circle(5)` 创建对象
- `constructors` 构造函数 是一个特殊的方法
  - 用于初始化data field
    - 也可以使用一个initializer list在constructor中初始化data field
  - 可以是有参数的，也可以是无参数的
    - 支持overload（重载）：同一个类中定义多个构造函数，这些构造函数具有不同的参数列表。通过构造函数的重载，可以根据不同的需求使用不同的参数来创建对象
  - 名字必须和类名保持一致
  - 这种方法无返回值，甚至是没有void
  - 只要创建对象，则自动运行这个方法
  - default constructor：定义class的时候如果没有直接的constructor，就自动定义一个no-arg constructor with empty body
 
- `data field`作为类成员，不允许在声明的时候初始化
  - C++中，全局变量和局部变量可以在声明的时候初始化

# 9.5 访问对象的属性和方法
- `ClassName objectname;` `ClassName objectname(args);` 使用一个no-arg constructor和一个arg constructor来创建一个对象
- 自定义的类，名字首字母大写
- 可以将类看作是一个数据类型，因为声明变量和声明对象形式一样
- 可以用 `=` 将一个对象复制到另一个对象中，同时保持两个对象互相独立
- `sizeof` 用来查看对象的大小；data field里的数据存储在对象中，但是方法并没有；所以`sizeof`输出的只是data的大小，如double类型的数据，输出为8
- anonymous object：只需要访问一次，所以没有必要name it
  - `Circle().getArea()` 或者 `Circle(5).getArea()`
  - `circle1 = Circle()` 或者 `circle1 = Circle(5)`
  - 需要注意的是，如果是使用no-arg constructor创建anonymous object时，得要在constructor名后面加上括号
  
# 9.6 允许类的definition和implementation分在不同文件中
- Basic
  - `.h`头文件：放类的definition；`.cpp`：放类的implementation
  - 在`.cpp`文件中，罗列所有的 data fields, constructor prototypes, 和 function prototypes.
  - The class implementation implements the constructors and functions.
  - the definition and implementation may be in two separate files which must have the same name, but `.h` for definition and `.cpp` for implementation

- `::`： binary scope resolution operator specifies the scope of a class member in a class; `Class::` tells the compiler that these constructors and functions are defined in the `Circle` class.

- Beneficial of separation：可以只将`.h` 文件以及可执行文件发给甲方，从而保护知识产权

- `g++ Circle.h Circle.cpp TestCircle.cpp -o main` 或者用CMake

# 9.7 防止多次Inclusions

- 比如: 在 `A.cpp` 中需要
  ```bash
  #include "B.h"
  #include "C.h"
  ```
  但是 `B.h` 里已经 `#include "C.h"` 。此时如果编译`A.cpp`，会产生编译错误说 `Multiple definitions for Circle`

- `#pragma once` 比书上提供的更优雅

# 9.9 private的data field
- `private:`开启私有的data field
- private data field只能由该类中的其他成员访问，而不能由程序中的其他部分用点操作进行访问和修改
  - `returnType getPropertyName()` 特殊的constructor进行访问
    - `bool isPropertyName()` 如果是bool类型的属性
  - `void setPropertyName()` 特殊的constructor进行修改

# 9.10 变量的Scope
- 在第六章中，我们学过全局变量，局部变量，静态局部变量
- 类中的data fields定义为变量；类中的所有constructor和functions都可以直接使用这些变量
- data field和 functions的顺序无所谓；但是一般把public的放在前面
- 在data field中，只能定义一个变量一次；但是在不同方法中，可以定义重名的变量，该变量的scope只在自己的function中有效，但是最后输出的时候，以最后执行的一条相关命令为准

# 9.11 类的抽象和封装
- 类的抽象是指将类的implementation独立出来；Implementation的细节被封装起来，对user不可观
- C++提供了不同层次的抽象：第六章中学习了函数的抽象并且在stepwise program中使用了
- 数据抽象是一种仅向外部暴露接口而隐藏具体实现细节的机制。也就是只要知道这个类创建的对象有什么方法，以及怎么用就行 [更多资料](https://www.runoob.com/cplusplus/cpp-data-abstraction.html)
- 数据封装通过将数据成员（data fields）声明为私有（private）或受保护（protected），然后提供公共的方法（成员函数）来访问或修改这些数据。这样做的目的是隐藏数据的具体实现细节，使得外部无法直接访问类的内部数据，而必须通过类提供的接口进行访问。[更多资料](https://www.runoob.com/cplusplus/cpp-data-encapsulation.html)
  - 这个也是data field分成public和private的目的


