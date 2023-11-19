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
- pass arguments to a function 有三种方式：pass-by-value; pass-by-ref; pass-by-pointer
- A pointer argument can be passed by value or by reference
```bash
void f(int* p1, int* &p2)

typedef int* intPointer;
void f(intPointer p1, intPointer& p2); // 这个方法定义的函数和上面那个一样

f(q1, q2)； // q1和q2都是指针

f(&variable1, &variable2)；// 指针可以直接传递，普通变量只能传递地址，需要用地址操作符
```
- Pointer q1 is passed to p1 by value
  - q1 和 p1 指向同一个内容
  - 如果变p1，q1不变；但是如果变q1，p1也跟着变
- Pointer q2 is passed to p2 by reference
  - q2 和 p2 是 alias，完全一样
  - 无论是变q2还是p2，另一个都跟着变
  - 也就是允许函数修改调用者传递的指针，并且这种修改是可见的
- 函数中的array-arg可以用point-arg代替
  ```bash
  void m(int list[], int size)
  void m(int* list, int size) //两者等价
  ```

# 11.7 从函数返回一个指针
- * leetcode List 11.6 pass an array argument, reverses it and returns the changed array
- `int* reverse(int* list, int size)` 接受一个array argument，reverse it并且返回新的array

# 11.8 和array相关的函数
```bash
#include <algorithm>

int list[] = {4,2,3,5,6,1};

int* min = min_element(list, list + 6); // returns the pointer for the smallest element in the array from list[0] to list[5]
int* max = max_element(list, list + 6); //returns the pointer for the largest element

random_shuffle(list, list + 6)； // 将list[0] to list[5] 随机打乱

sort(list, list+6)；// 将list[0] 到list[5]的元素排序

int key = 5;
find(list, list+6, key); // 在list[0]到list[5]之间的元素中找‘5’，如果找到返回该元素对应的指针，否则返回范围内最后一个元素的指针，即list[5]
```

# 11.9 动态内存分配和持久性内存分配
- 在List11.6中，也可以不改变原来的array，而是返回一个新的array；问题在于，如何声明这个新的array：我们需要根据变量 `size` 调整array的尺寸，但是C++又不支持 `int new_arr[size]`这种形式，因为要求regular array的size要在编译的时候就知道，这和dynamic array不同！
  - 需要用的dynamic array这种持久性的内存分配 -> Listing 11.9
- `int* p = new int(4)`
  - `new int` allocates memory space for an int variable initialized to 4; the address is assigned to pointer p
  - 使用 `new` 创建的array称为dynamic array
  - `int* p = new int[size]` 当创建dynamic array时，size可以在runtime的时候决定，而不是编译的时候
  - dynamic array时持久性的，直到被删除
- `delete p` 删除由 `new` 操作符创建的指针 p，释放allocated memory for the pointer
- `delete [] list` 删除由 `new` 操作符 创建的数组 list，释放allocated memory for the array
- memory leak
  ```bash
  int* p = new int;
  *p = 45;

  p = new int; // 这一步就会产生memory leak；因为将新的地址赋给指针p后，原来地址里就得一直存储这45，再也没法使用或者释放了！
  ```
  所以为了避免这个问题，需要保证每个 `new` 操作都应该匹配一个 `delete` 操作

# 11.10 创建dynamic objects并且访问其成员
```bash
string* p = new string(); // 使用 no-arg constructor 创建 dynamic object
string* p = new string("asbd"); // 使用arg constructor创建dynamic object

(*p).length(); // 如果要访问对象成员函数或者属性，那么需要 dereference the pointer and use the dot operator

p->length(); // arrow operator作为member selection operator，和上面这个命令等效

delete p; 
```

# 11.11 This指针
- 这是一个特殊的built-in pointer，也是一个关键字；
- 指向当前对象的指针，允许在类的成员函数中访问该类的对象的成员变量
- 因为类和对象的成员变量名字都是一样的，所以在类中定义的方法的时候，尤其是需要输入argument的方法，可能会有歧义
```bash
Circle::Circle() // Circle类的constructor
{
  radius = 1;  // Circle类有一个成员变量，名字为radius
}

// 方法1
Circle::Circle(double newRadius) // constructor函数的重载
{
  radius = newRadius; // 这个newRadius是在创建对象是需要输入的argument，传递给了类的构造函数；然后将这个数值赋给对象中的成员变量radius；这里选择更换了类的构造函数的argument的名
}

// 方法2
Circle::Circle(double radius) // constructor函数的重载
{
  this->radius = radius; // 这里通过this指针，访问对象的这个属性，然后把传递给构造函数的参数radius的值赋给当前对象的成员变量radius
}
```

# 11.12 析构函数
- 每个类都一定有一个析构函数，当对象被删除的时候，自动调用
- 如果没有定义，则默认定义一个；有时候需要自行定义一个以便perform customized operations
- `~Circle();` 和构造函数非常像，就是开头多一个 `~`
  ```bash
  Circle::~Circle()
  {
    numberOfObjects--; // 该析构函数规定，如果删除对象后，将变量numberOfObjects减少1
  }
  ```






