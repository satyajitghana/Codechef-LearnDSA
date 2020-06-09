# C++ STL - Standard Template Library and MORE !


## 1. Introduction to C++

- C++ is 💖

## 2. Data Types

- `int`
- `long`
- `long long`
- `float`
- `double`
- `char`
- `bool`
- `std::string`

Some Functions

- `std::minmax`
```cpp
std::pair<int, int> mnmx = std::minmax(3, 4);
std::pair<int, int> mnmx2 = std::minmax({1, 2, 3, 4, 5});
```
- `std::min`
- `std::max`

Logical Operations !

- `and`
- `or`
- `xor`

Bitwise Ops !

- `&`
- `|`
- `^`

HOMEWORK

- what happens when you overflow the limits ?
- how do you know the limits of each of these data types ?
- what is type casting ?
- what is the value of `~0` ? why do you thing its `-1` ? is c++ stupid ?

## BONUS: MACRO Substitution - Very Handy

2. Arrays and Vectors

- `std::array`
- raw arrays `<data_type> <arr_name>[<num_elems>]`
- `std::vector`
- `std::max_element`

```cpp
auto it = std::max_element(std::begin(V), std::end(V));
std::cout << *it << std::endl;
```

- `std::min_element`

HOMEWORK

- what is `emplace_back` ? why does it exist ? - very important question
- look for the different ways to initialize a `vector`
- find the sum of vector using `std::accumulate`

```cpp
int sum = std::accumulate(std::begin(V), std::end(V), 0);
```

## 3. I/O

- `std::cin`
- `std::cout`

Some conversion functions

- `std::stoi`
- `std::strtol`
- `std::stof`
- `std::stod`
- `std::stold`

HOMEWORK

- how do you read a line of input ?
- how do you read a file and point `stdin` or `stdout` to that file ?
- `std::endl` <- should you always use this ? why not just use `\n` for new line

## 4. Functions

- pass by value

```cpp
int foo(int x, int y);
```

- pass by reference

```cpp
int foo(int& x, int& y);
```

HOMEWORK

- look at `std::function` https://en.cppreference.com/w/cpp/utility/functional/function

## 5. Structs and Classes

- `struct`

```cpp
struct color {
    string name;
    int val;
};
```

- `class`

```cpp
class point {
private:
    int x, y;

public:
    point() : x(0), y(0) {
    }

    int get_x() { return this.x; }
    int get_y() { return this.y; }

    void set_x(int x) { this.x = x; }
    void set_y(int y) { this.y = y; }
};
```

HOMEWORK

- do we need to use a class for point ? can we get away with using `pair<int, int>` ?
- sort a `vector` of pair using std::sort and custom comparator function
- what do you think is the size of an empty class ?
- can all classes be converted to structs ? or can all structs be converted to classes ?
- what are destructors ?

## BONUS - the `auto` keyword

The auto keyword specifies that the type of the variable that is being declared will be automatically deducted from its initializer. In case of functions, if their return type is auto then that will be evaluated by return type expression at runtime.

- `decltype`

```cpp
auto x = 4;
auto y = 3.37;
std::cout << typeid(x).name() << std::endl;
```

## BONUS - `namespace` - why does this exist ?

HOMEWORK

- what are anonymous namespace ? why is it used ?
- what is name-mangling in c++ ?

## BONUS - `template`

HOMEWORK

- create a templated class for circle with radius of any data type
- create a member function to calculate area

## BONUS - `lambda` - what is this ?

A lambda is an unnamed function that is useful (in actual programming, not theory) for short snippets of code that are impossible to reuse and are not worth naming. `[]` is the capture list, `()` the argument list and `{}` the function body.

HOMEWORK

- can you implement boolean logic by using ONLY LAMBDAS ? only constraint is, everything HAS to be a function only

congratulations, you just discovered functional programming

HINTS: 
- https://github.com/satyajitghana/LambdaCalculus/blob/master/LambdasCPP/main.cpp
- https://github.com/satyajitghana/LambdaCalculus/blob/master/LambdaCalculus%20with%20Birds%20!.pdf

## BONUS - `for each` loop and how it makes everything faster and easier

HOMEWORK

- make a for each loop where you can modify elements of the container
- can you use `auto` in this ?

## 6. Sorting

- `std::sort`
- comparators like `std::greater<int>()`
- custom comparator

HOMEWORK

- create a custom comparator for our colors

```cpp
std::sort(std::begin(colors), std::end(colors), [](const color& a, const color&b){
    return a.val < b.val;
})
```

- sort the colors in reverse

## 7. Searching and Counting

- `std::binary_search` - O(logN) - container should be sorted

```cpp
std::sort(std::begin(A), std::end(A));
std::binary_search(std::begin(A), std::end(A), <value_to_search>);
```

- `std::find` - O(N)
- `std::lower_bound` - O(N) for random_access (like vectors), O(logN) for non_random_access (like sets)

```cpp
std::vector<int> a{1, 2, 2, 3, 4, 5};
auto it = std::lower_bound(std::begin(a), std::end(a), 2);
auto index = std::distance(std::begin(s), it);

std::cout << index << std::endl;
```

- `std::upper_bound` - O(N)
- `std::count` - O(N)
- `std::minmax`

```cpp
std::vector<int> V = {1, 2, 3, 4, 5};
auto mnmx = std::minmax_element(std::begin(V), std::end(V));
```

- `std::min_element`
- `std::max_element`

HOMEWORK

- C++ has a huge library of algorithms, look at them here http://www.cplusplus.com/reference/algorithm/

## 8. stack and queues

- `std::stack`

```cpp
std::stack<int> st;
st.push(1);
st.push(2);

st.size(); // size of the stack
st.top(); // get the top element
st.pop(); // remove the top element
```

- `std::queue`
- `std::priority_queue`
- `std::deque`

HOMEWORK

- whats the difference between `std::vector` and `std::stack`
- look at `std::set_union`, `std::set_intersection`, `set::difference`

## 9. maps

- `std::map`
- `std::unordered_map`

```cpp
std::map<std::string, int> colors;
colors.insert({"RED", 0});
colors.insert({"GREEN", 1});

colors.erase("RED");
```

## 10. sets

- `std::set`
```cpp
std::set<int> s;

s.insert(1); s.insert(2); s.insert(2); s.insert(3);

auto it = s.lower_bound(2);

std::cout << *it << std::endl;
```

- `std::unordered_set`

HOMEWORK

- what are multisets ?

## MORE STUFF

1. Memory Management - Very essential
- `std::unique_ptr`
- `std::shared_ptr`
- `std::move` <- this is actually just a cast
- `std::forward`

2. Operator Overload - Damn Cool 😎

- https://www.geeksforgeeks.org/operator-overloading-c/

HOMEWORK

- overload the addition operator to add two colors (class color was defined by us before)

3. Function Overloading

---

made with 💘 by shadowleaf
