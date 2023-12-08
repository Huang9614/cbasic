# 《C++ Primer Plus 6th》

## `Queue::Node::Node( const Item& i) : item(i), next(0) {}` 
- 嵌套类需要连续多次使用作用域解析运算符 `::`
- 

# [菜鸟教程](https://www.runoob.com/cplusplus/cpp-tutorial.html)

## `void Box::set( double len, double bre, double hei){ length = len; breadth = bre; height = hei;}
- 在类外定义类的函数(https://www.runoob.com/cplusplus/cpp-classes-objects.html)

## `Line::Line(void)`
- 在类外定义类的构造函数
- `Line::Line( double len)` 在类外定义带参数的构造函数
  - [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)
  - `double len` 其实是Line类的私有成员变量 `double length`，这里是为了保证不重名
    - `this` 指针

## `Line::Line(double len): length(len){...}`
- 初始化列表初始化字段
- [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

## `Line::~Line(void)`
- 类的析构函数
- [查看](https://www.runoob.com/cplusplus/cpp-constructor-destructor.html)

## `Line( const Line &obj);`
- 在类中声明类的拷贝构造函数
- `Line::Line(const Line &obj){...}` 在类外定义类的拷贝构造函数
- [查看](https://www.runoob.com/cplusplus/cpp-copy-constructor.html)

## `friend void printWidth( Box box );`
- 在类中声明类的友元函数
- `void printWidth( Box box ){...}` 在类外定义类的友元函数
- `friend class ClassTwo;` 在类中声明类的友元类
- [查看](https://www.runoob.com/cplusplus/cpp-friend-functions.html)

## `Box1.height` 和 `Box3.get()`
- 创建类的对象，访问类的成员变量以及调用类的成员函数
- 类的私有成员不可以通过 `.` 来访问
  - 友元
  - 类的成员函数

## `class Dog : public Animal {};` 
- 子类Dog，以public的方式继承父类Animal
- `class Rectangle: public Shape, public PaintCost` 多继承
- [查看](https://www.runoob.com/cplusplus/cpp-inheritance.html)

## `virtual int area() = 0;`
- 类的公共成员，纯虚函数
- 如果没有 `= 0`，则为虚函数
- [查看](https://www.runoob.com/cplusplus/cpp-polymorphism.html)




