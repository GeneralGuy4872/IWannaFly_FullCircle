the perferred method of C API function error checking is by `errno`, in
combination with an `IMPLICIT` return value of 0 for OK and -1 for an
error, or optionally use 1 for a less severe error and -1 for a more severe
error. this matches the convention of most C standard library and nCurses
library functions, but is the reverse of most C++ `std::` functions. C++
wrapers will use the idiom `-!(`...`)` to do conversion between the two.

critical errors will `exit(`...`)`, `abort()`, or `raise(`...`)` a signal.

bogon checking, to mitigate database corruption, will use assertions.
example: `assert(localfoo == *originalfoo)`

The plan for the navigational database is to write a simple shell program
in Objective-C++, using templates and it's introspection capabilities to
wrap void pointers that will build a stack that holds the path of the $PWD.
syntax will be based on the API; however, the ability to do anything other
than `PEEK` and `POKE`, and even that, is very much deferred.
