# 和本地文件夹 D/c++ 链接
2023.12.08

# 域操作符（`::`）
在C++中，域操作符（::）被用于访问类、命名空间或枚举的成员；命名空间中又可以包括 函数，变量，类等等实体。有了命名空间，就可以统管多个文件中的函数，类等，只需要将这些实体所在文件的头文件 `#include` 到当前文件即可；然后用域操作符对该命名空间中的指定实体进行访问或调用或创建实例。

## 《C++ Primer Plus 6th》

### `Queue::Node::Node( const Item& i) : item(i), next(0) {}` 
- 嵌套类需要连续多次使用作用域解析运算符 `::`
- 

## [菜鸟教程](https://www.runoob.com/cplusplus/cpp-tutorial.html)

### `void Box::set( double len, double bre, double hei){ length = len; breadth = bre; height = hei;}
- 在类外定义类的函数(https://www.runoob.com/cplusplus/cpp-classes-objects.html)

### `Line::Line(void)`
- 在类外定义类的构造函数
- `Line::Line( double len)` 在类外定义带参数的构造函数
  - [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)
  - `double len` 其实是Line类的私有成员变量 `double length`，这里是为了保证不重名
    - `this` 指针

### `Line::Line(double len): length(len){...}`
- 初始化列表初始化字段
- [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

### `Line::~Line(void)`
- 类的析构函数
- [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

### `Line( const Line &obj);`
- 在类中声明类的拷贝构造函数
- `Line::Line(const Line &obj){...}` 在类外定义类的拷贝构造函数
- [查看](https://www.runoob.com/cplusplus/cpp-copy-constructor.html)

### `friend void printWidth( Box box );`
- 在类中声明类的友元函数
- `void printWidth( Box box ){...}` 在类外定义类的友元函数
- `friend class ClassTwo;` 在类中声明类的友元类
- [查看](https://www.runoob.com/cplusplus/cpp-friend-functions.html)

### `Box1.height` 和 `Box3.get()`
- 创建类的对象，访问类的成员变量以及调用类的成员函数
- 类的私有成员不可以通过 `.` 来访问
  - 友元
  - 类的成员函数

### `class Dog : public Animal {};` 
- 子类Dog，以public的方式继承父类Animal
- `class Rectangle: public Shape, public PaintCost` 多继承
- [查看](https://www.runoob.com/cplusplus/cpp-inheritance.html)

### `virtual int area() = 0;`
- 类的公共成员，纯虚函数
- 如果没有 `= 0`，则为虚函数
- [查看](https://www.runoob.com/cplusplus/cpp-polymorphism.html)


## ROS

### `ros::init(argc, argv, "talker");` 
这里的域操作符是用来命名空间 `ros` 

### `std_msgs::String msg;` 
在 `String,h` 文件中定义了命名空间 `std_msgs`，并且在该命名空间中，定义了一个模板结构体 `String`，它包含一个成员 data，是一个使用 `ContainerAllocator` 进行内存分配的 `std::basic_string` 对象
- `String_():data()  {}` 结构的默认构造函数
- `String_(const ContainerAllocator& _alloc) : data(_alloc) {}` 带有参数的构造函数，接受一个 `ContainerAllocator` 对象作为参数，然后用它来构造 `data` 成员


