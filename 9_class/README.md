# 9.6 Seperating Class definition from Implementation
- Basic
  - Class definition simply lists all the data fields, constructor prototypes, and function prototypes.
  - The class implementation implements the constructors and functions.
  - the definition and implementation may be in two separate files which must have the same name, but .h for definition and .cpp for implementation

- `::` symbol, known as binary scope resolution operator, specifies the scope of a class member in a calss; `Class::` tells the compiler that these constructors and functions are defined in the `Circle` class.

- Beneficial of separation
