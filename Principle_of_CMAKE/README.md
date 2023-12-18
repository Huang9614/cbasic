# Manually build

/---------------------
The following part is based on the file `easiest_example.cpp`
---------------------/

- `g++ easiest_example.cpp` the easiest way
- Split the above command into 4 steps and find the problem
``` bash
g++ -E main.cpp > main.i  // Preprocess
g++ -S main.i  // Compilation
g++ -c main.s  // Assembly = generate an object/binary file
g++ main.o -o main  // Link
```
## Compilation Flag
- `-std=c++17`
- `-o` && `-c` && `-E` && `-S`
- `-Wall` && `-Wextra` && `-Werror`
- `-O0` && `-O3`

## Library 

- `lib*.a` static library
  - `ar rcs libname.a module1.o module2.o ...` Create a static library
  - Static libraries are archives like `zip` or `tar` and so on
- `lib*.so` dynamic library

/----------------
The following is based on the `main.cpp`, `tools.cpp` and `tools.hpp` files
-----------------/

We can separate the declaration and implementation of the functions; 
Move all declarations to header files `*.hpp` and the implementations goes to `*.cpp` files. 
In the main file, we need to include the header file of the functions and when we try to compile the main file, the Linker in the forth step as mentioned above will raise an error, which means `g++ -std=c++17 main.cpp -o main` doesn't work. 
The library is a binary object that contains the compiled implementation of functions and the forth step "linking" just maps the function delaration to its compiled implementation!
So if we want to use a library, we need the header files and the compiled library object!
Here is the problem: in the `main.cpp` file, we do include the `tools.hpp`, when we compile `main.cpp`, the compiler tries to link
the binary `main.o` and `tools.o`, but we DO NOT have the binray/compiled `tools.o`!

Therefore, we then want to first build the library and link the two binary files with each other to complete the compilation!

1. `c++ -std=c++17 -c tools.cpp -o tools.o`  compile modules
2. `ar rcs libtools.a tools.o <other_modules>`  organize modules into libraries
4. `c++ -std=c++17 main.cpp -L . -ltools -o main`  link libraries when building code
5. `./main`  run the code

# CMAKE

Compared to the building library steps, it's replaced easily by the following components:
1. `add_library(tools tools.cpp)` corresponds to the `c++ -std=c++17 -c tools.cpp -o tools.o` and `ar rcs libtools.a tools.o <other_modules>`
2. `add_executable(main main.cpp)` corresponds to `c++ -std=c++17 main.cpp`
3. `target_link_libraries(main tools)` corresponds to `-L . -ltools -o main`


## build process using CMAKE

The build process is completely defined in `CMakeLists.txt` and childrens `src/CMakeLists.txt`

```bash
cd <project_folder>
mkdir build
cd build
cmake .. // the .. means the CMakeLists.txt is in the level-up folder
make
```

## `CMakeLists.txt`
1. `add_executable(target_name source1.cpp source2.cpp ...)`：用于定义生成一个可执行文件的目标。`target_name` 是可执行文件的名称，后面跟着源文件的列表。
2. `add_library(lib_name source1.cpp source2.cpp ...)`：用于定义生成一个库文件的目标。`lib_name` 是库的名称，后面跟着源文件的列表。
3. `add_link_libraries(target_name library1 library2 ...)`：用于将库文件链接到可执行文件。`target_name` 是你通过 `add_executable` 定义的目标名称，后面跟着要链接的库的名称。
4. `add_dependencies(target_name dependency1 dependency2 ...)`：用于定义目标之间的依赖关系。`target_name` 是目标的名称，后面跟着它依赖的其他目标的名称
5. `target_link_libraries(target_name library1 library2 ...)`：用于将库文件链接到目标（可执行文件或库）。`target_name` 是目标的名称，后面跟着要链接的库的名称
   - `target_link_libraries(add_two_ints_client ${catkin_LIBRARIES})` 在CMake中，`${}` 是用于引用变量的语法。在这里，${catkin_LIBRARIES} 是一个变量，它包含了由Catkin构建系统生成的与当前工程及其依赖关系相关的库文件路径。


## Clean the build
```bash
cd project/build
make clean // remove the generated binaries
rm -rf * // ensure you are in the build folder
```

Or if you are in the `project/` folder, then just run `rm -rf build/`

## Using external libraries
- `find_library(...)`



ALL ABOVE NOTES COMES FROM [UNI BONN LECUTRE](https://www.youtube.com/watch?v=9mZw6Rwz1vg&list=PLgnQpQtFTOGRM59sr3nSL8BmeMZR9GCIA&index=5)

# CMAKE Tutorial
