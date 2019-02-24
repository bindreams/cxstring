# cxstring
A string class for compile-time string manipulation.  
Inspired by this [blog post](https://akrzemi1.wordpress.com/2017/06/28/compile-time-string-concatenation/), this library expands on the idea by implementing all relevant string methods, modernizing the approach, and providing additional features such as compile-time number-to-string conversion.

## Installation
`cxstring` is a single-header library. There are no public releases available yet, but you can use the library in its "unwrapped" form by copying the cxstring folder into your project's directory, or manually build the single header from root-level cxstring.hpp.  
Using `cxstring` requires C++17 support.

## Usage
Including the library:
```c++
#include "cxstring.hpp"
```

Creating a `cxstring`:
```c++
zh::cxstring cxstr = "Hello there!"; // Deduced type: zh::cxstring<12> (12 symbols, \0 does not count)
```

Concatenating string literals:
```c++
auto cxstr = 
	zh::cxstring("General") + 
	zh::cxstring(" ") +
	zh::cxstring("Kenobi!");
// Deduced type: zh::cxstring<15>
```

Getting a string literal out, to not scare your users with your crazy libraries:
```c++
const auto& literal1 = cxstr.data(); // type: reference to const char array of the appropriate size
const auto& literal2 = cxstr.substr<7>(8).data();
//                              size^  ^start
```

## License
This project is licenced under the MIT licence. It is free for personal and commercial use.
