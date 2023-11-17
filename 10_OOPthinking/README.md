这一节主要用来说明object-oriented的优点；
这里通过C++标准库中的string 类来说明

# 10.2 String 类
- `#include <string>`
- 该类中包含了许多不同的functions来处理string
  - 除了使用string类，还可以将string看作array of characters ending with `\0`
- `string s("HALLO!");` 使用string constructor创建一个string对象
  - `string s;` 使用no-arg string constructor创建一个string对象
  - `string s = "HELLO";` 等价，但是效率低；
- `s1.append(" to C++")`, `s1.append(" to C++", 0 ,5)`, `s1.append(4, "G")`
  - 这种同一个对象的同一个方法，却有不同的args，是因为constructor overloading
  - string类的`assign`方法也是同样的情况：`s1.assign("Dollas")` 和 `s1.assign("Dollas, Texas", 0 ,6)` 等
- 该类下的方法
  ```bash
  s1.at(3); // 返回string中index为3的character
  s1.clear(); // 清空s1
  s1.erase(2,5); // 清空s1从第二位开始后的5个bits
  s1.empty(); // 检查s1是否为空
  ...
  ```
  - 这些方法会返回一个新的string；可以同时赋值给一个新的string 量

## stringstream 类
- `#include <sstream>`
- string类允许用`.itoa()`将整数变成string；但是如果是浮点数，想要变成string，就得先用stringstream类的对象存储浮点数，再调用其中的`.str()`函数赋值给string类对象
  ```bash
  stringstream ss;
  ss << 3.1415935;
  string s = ss.str();
  ```
- 可以用来将一句话拆分成多个单独的单词

## 10.2.13 

