# 11.1
当需要处理an unspecified number of integers. 我们需要用an array来存储这些整数，但是因为不知道尺寸，所以没法创建；或者说每次添加或者去除某些整数时，就需要重建array；这个问题可以通过指针轻松解决

# 11.2
- 指针变量存储地址
  - `&count` 获取变量count的地址；`&`称为地址操作符
    - 变量的地址是指 first byte allocated to that variable
  - `int* pCount` 指针需要在使用前先申明：`dataType* pVarName;`
    - `int* p1;` 声明一个指针
      ```bash
      int* p1,p2; //声明一个指针p1和一个整数型变量p2

      int* p1;
      int* p2; // 这才是声明了两个指针
      ```
  - `int* pCount = &count` 将变量count的地址赋给指针pCount
    - 指针可以在声明的时候初始化
- `*pCount` 访问变量count的数值
  - 这种访问数值的方法称为indirection，而`*`称为indirection operator/dereference operator
  - `count` 这样叫direction
- 指针类型要和其存储的地址的变量同类型
- 指针变量的命名和普通变量命名规则一样，但是有时候会被打破，比如说：array name本身也是一个指针
- 指针一定要记得初始化
  - 局部指针如果没有初始化，会自动初始化，等dereference的时候就会有大麻烦，因为自动初始化的地址，可能不是想要的变量
  - 可以用NULL来初始化指针，而不是0

# 11.3 
- `typedef int* intPointer` 将已有的数据类型（这里是整数型指针）取别名，这样在代码中看的更明白
  ```bash
  typedef int* intPointer;
  intPointer p;

  intPointer p1, p2; //和之前不同，这样就是创建了两个整数型的指针
  ```
# 11.4 常量指针
- `double* const p = &radius;` 常量指针需要在一句代码中声明和初始化；且之后不能再把别的变量的地址赋给该指针了
- `*p = 5;` 虽然指针的数值（即地址）不能改变，但是其对应的变量的数值可以改变
- `const double* const pValue = &radius;` 指针和对应的变量都是const
- `const double* p = &radius;` 指针不是const，但是对应的变量是const

# 11.5 arrays和指针
- Array name is a 常量指针 to the first element in the array
  ```bash
  int list[6] = {11, 12, 13, 14, 15, 16};
  int* p = list; // 可以直接把array名赋给指针，这样就让p指针指向list的第一个元素；而不是像普通变量那样用`&`将变量地址赋给指针
  // int* p = &list[0]； 和上面一句是等价的
  
  cout << list << endl; // 这里的list表示starting address of the array

  *list; // access the first element
  *(list+2); // access the third element；使用pointer syntax直接访问array元素
  // list[2]; 使用array syntax直接访问array元素
  // *(p+2); 使用pointer syntax从指针访问array元素
  // p[2]; 使用array syntax从指针访问array元素

  list + 1; // 指针可以加上或者减去一个整数；此时指针里的地址不仅仅是加一这么简单，而是会加上 1倍的 int类型的长度
  ```
- 指针可以用关系操作符比较斌且排序
- 当array创建好后，就不能更改地址了
  ```bash
  int list1[10], list2[10];
  list1 = list2; // 这是不合法的，因为array名相当于常量指针，是不能更改名字的
  ```
# 11.6 
    
