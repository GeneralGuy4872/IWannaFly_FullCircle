the perferred method of C API function error checking is by `errno`, in
combination with an `IMPLICIT` return value of 0 for OK and -1 for an
error, or optionally use 1 for a less severe error and -1 for a more severe
error. this matches the convention of most C standard library and nCurses
library functions, but is the reverse of most C++ `std::` functions. C++
wrapers will use the idiom `-!(`...`)` to do conversion between the two.

critical errors will `exit(`...`)`, `abort()`, or `raise(`...`)` a signal.

bogon checking, to mitigate database corruption, will use assertions.
example: `assert(localfoo == *originalfoo)`
