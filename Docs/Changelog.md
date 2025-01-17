# Change Log
All notable changes to this project will be documented in this file.

## [1.3.9] - 2022-06-17

- Fixed issue with duplicate non-local function registration
- Fix unit tests to allow easier max instruction tests
- Minor spelling corrections
- Corrected previously out-of-sync patch messages in changelog

## [1.3.8] - 2022-03-27

- Improved error messages
- Fixed URL to tutorial in JinxPad

## [1.3.7] - 2022-03-27

- Fixed memory allocation stats in amalgamated header

## [1.3.5] - 2022-03-27

- Added support for calling async functions from native code
- Update MSVC build scripts to support VS2022
- Update tools to .NET target to 4.7.2
- Update obsolete .NET function

## [1.3.4] - 2021-02-21

- Improved compiler error messages
- Minor code cleanup

## [1.3.3] - 2021-02-10

- Added support for string index pair operator for extraction and insertion of text
- Additional performance optimizations
- Improve test coverage
- Remove unused code

## [1.3.2] - 2021-02-04

- Various internal optimizations improves Jinx runtime performance by up to 25%
- Updated Performance doc
- Free and realloc memory callbacks now pass an additional size parameter
- Fix small internal memory leaks
- Fix multi-threaded safety issue
- Improved fuzz tester

## [1.3.1] - 2021-01-20

- Updated amalgamated header

## [1.3.0] - 2021-01-20

- Add support for first-class functions
- Add support for coroutines
- Improve error handling for library functions
- Update documentation

## [1.2.4] - 2021-01-07

- Fixed function lookup with matching optional/non-optional parts

## [1.2.3] - 2020-12-27

- Fixed issue with initialization lists parsing as function parameters

## [1.2.2] - 2020-12-14

- Fixed issue introduced in 1.2.1 causing functions to always wait on exit

## [1.2.1] - 2020-12-11

- Allow character-based access to strings using [] operators
- {} size function now returns number of Unicode characters for strings instead of byte count
- Added support for decorative possessive of variables using apostrophe-s
- Changed parsing precedence to fix some problematic compound function calls
- Fix bug when parsing and/or/not as part of function name
- Updated documentation

## [1.2.0] - 2020-09-11

- Removed pool allocator due to lack of measurable performance benefits
- Changed memory stats API appropriately for a more generic allocator
- Removed obsolete Jinx::Shutdown() function
- Updated documentation

## [1.1.9] - 2020-08-04

- Fix property name lookup when using multiple libraries

## [1.1.8] - 2020-07-24

- Fix local scope bug, manifesting in named-counter loop errors on subsequent loops
- Improved loopcount op variable names

## [1.1.7] - 2020-07-12

- Fix locale-based error on Linux
- Minor code cleanup

## [1.1.6] - 2019-09-18

- Slightly more efficient numeric conversions of continental-style tables
- Fix syntax coloring error in single-line commands in JinxPad

## [1.1.5] - 2019-09-05

- Explicitly allow return statements outside of functions
- Added documentation to clarify return statements
- Added unit tests for new return functionality
- Fixed issue with function calls calculation of stack return values
- Minor fixes to JinxPad project

## [1.1.4] - 2019-08-12

- Fixed an issue with C# editor not displaying text on initial load

## [1.1.3] - 2019-06-15

- Logging callback function now passes log level: Info, Warning, or Error

## [1.1.2] - 2019-04-07

- Improved CSV parsing to include quoted values and continental format
- Floating-point and integer parsing can optionally use faster std::from_chars() method
- Floating-point parsing is no longer affected by locale

## [1.1.1] - 2019-02-12

- Fix bug when max instruction count is reached
- Fix core write line to add newline after extra parameters

## [1.1.0] - 2019-02-08

- Fix index operator to allow arbitrary nesting depth
- Fix erase keyword to use arbitrary nesting depth
- Add CSV or tab-delimited table support via string to collection cast
- Fix path error in CMake file
- Updated tutorial

## [1.0.1] - 2019-01-20

- Fix unused variable warning in gcc
- Update tutorial

## [1.0.0] - 2019-01-01

- Jinx stable release

## [0.22.1] - 2018-12-30

- JinxPad projects are now generated by CMake
- Minor improvements to JinxPad

## [0.22.0] - 2018-11-18

- Add CMake support
- Reorganize folders to separate source from projects

## [0.21.1] - 2018-11-02

- Added missing 'set' keyword to C# editor library

## [0.21.0] - 2018-10-21

- Removed local script function override

## [0.20.0] - 2018-10-14

- Changed API functions registering function callbacks to use string instead of initializer lists
- IString::FindFunction() no longer requires a Visibility type parameter
- Function names passed via API are now processed using the same lexer and parser as scripts, ensuring more robust error checking
- Fixed minor error in tutorial
- Add std::any aliases due to macOS platform limitations

## [0.19.0] - 2018-10-09

- Added API to find and call Jinx functions from C++

## [0.18.3] - 2018-10-07

- Added additional tests

## [0.18.2] - 2018-10-04

- Replaced void* with std::any
- Minor fixes to tutorial

## [0.18.1] - 2018-09-29

- Minor improvement to parser error handling message
- Added new parser error tests

## [0.18.0] - 2018-09-27

- Added unary negation operator (-)
- Added new tests and updated documentation
- Silenced MSVC warnings if C++ exceptions are disabled

## [0.17.0] - 2018-09-22

- Jinx is now available as an optional single-header library
- Updated tests and documentation

## [0.16.1] - 2018-08-11

- Keywords are now case-insensitive
- Added more detailed examples in tutorial for function parameters
- Changed Jinx object allocator to use perfect forwarding

## [0.16.0] - 2018-08-04

- Added script-specific native function overrides

## [0.15.6] - 2018-07-17

- Unicode conversion no longer uses deprecated standard libraries
- Updated projects to compile in C++ 17 mode
- Updated Doxygen binaries

## [0.15.5] - 2018-04-29

- Added debug info to identify source line number for runtime errors
- Version string is acquired via a function instead of being a constant
- Fixed overly-cluttered changelist with a simpler format

## [0.15.4] - 2018-04-18

- Added 'get call stack' core library function

## [0.15.3] - 2018-04-17

- Improved runtime performance of local variable lookups

## [0.15.2] - 2018-02-22

- Fixed a bug related to function chains

## [0.15.1] - 2018-02-03

- Fixed a bug when assigning collection elements within a collection

## [0.15.0] - 2017-12-26

- Function precedence now works left to right
- Compound expressions are no longer a problem for the parser

## [0.14.0] - 2017-12-06

- Opcode debug output now shows symbol and function names
- Logical 'not' operation now has same precedence as 'or/and'
- Mod operators now works like Python instead of C++
- Parser now rejects function parameter names that collide with properties

## [0.13.0] - 2017-12-01

- Logical operators now perform short-circuit evaluation
- Updated Catch unit test library

## [0.12.0] - 2017-11-19

- Most operators no longer perform automatic type coersion, and errors are more explicitly handled.
- Documented type coersion behavior in tutorial.
- Fixed comparison between integer and numeric types

## [0.11.0] - 2017-11-07

- Added per-script user context pointer for native library functions.
- Made changes to reduced probability of name collisions.

## [0.10.3] - 2017-10-25

- Fix potential error in allocator with static initialization ordering

## [0.10.2] - 2017-10-13

- Minor change for Xcode 9 compatibility

## [0.10.1] - 2017-08-26

- Improved local script variable lookup speed
- Fixed potential crash on shutdown in allocator

## [0.10.0] - 2017-08-24

- New ellipse operator allows explicit continuation of statements on a new line
- Initialization lists can handle new lines between items in the list
- Check for name collision of variables assigned in loop statements

## [0.9.0] - 2017-08-17

- Added test case for case-folding variable rules
- Added total performance time interval to performance data
- Optimized allocator for better multi-threaded performance
- Optimized script runtime to avoid unneeded case folding on internal function calls
- PerfTest and FuzzTest now use standard C++ threads for test code

## [0.8.0] - 2017-07-09

- Index operators can now be used directly following function calls for returned collections
- Added new performance metric for completed scripts
- Added new performance test
- Added new initialization parameter for caching memory blocks
- Math operations now use C-style precedence rules
- Function return values are now always optional

## [0.7.0] - 2017-07-07

- Added better support for alternative string character encodings / types
- Changed function registration with more explicit parameters
- Changed required ordering of readonly parameter for properties

## [0.6.0] - 2017-06-02

- Implemented Unicode-aware case folding algorithm to make Jinx case insensitive
- Runtime type conversion errors properly checked, and unit tests added

## [0.5.0] - 2017-03-08

- Added erase keyword for removing collection elements
- Variable and property assignment now uses set {var} to {expression} pattern
- Collection iterators now store an iterator/collection pair
- Multi-part variable names can include keywords as second or later parts
- Removed obsolete library functions to erase collection element

## [0.4.5] - 2017-03-04

- Jinxpad keyword list corrected
- Collection elements are removed by setting value to null
- Removed some potentially problematic library functions

## [0.4.4] - 2017-02-27

- Error when parsing multi-part variables
- Potential infinite loop in core library
- Potential for incorrect memory values in multi-threaded programs 
- Improved fuzz testing program for better performance and easier debugging

## [0.4.3] - 2017-02-08

- Function name parts can now be optional
- Function name registration was incorrectly converting to lower case
- Function as last parameter of another function call was not being handled correctly

## [0.4.2] - 2017-01-31

- New 'external' keyword for variables set via API
- Obsolete library functions dealing with externally set variables have been removed
- Tutorial updated with 'external' keyword use and examples

## [0.4.1] - 2016-12-08

- Instruction count performance metric
- Cleaned up expression parsing code
- Add Variant class documentation
- Fixed bug in block parsing
- Improved documentation to better describe complex function parameters

## [0.4.0] - 2016-12-01

- Add new keyword 'until' used similarly to 'while' in loops and conditional wait statements, but with inverted conditional logic
- Add new test cases for 'until' keyword
- Add new 'until' keyword added to Jinx editor
- 'yield' keyword is now 'wait', a more user-friendly term
- Deleted unused keywords in source

## [0.3.0] - 2016-11-04

- Support for multi-word variable and property support without requiring enclosing quotes

## [0.2.2] - 2016-11-01

- Improved variant conversion function
- New variant conversion tests and methods
- Variant conversion unit test

## [0.2.1] - 2016-09-21

- Improved thread-safety of collection operators
- Fixed mutex issues on macOS and Linux
- Add new test case for collections
- Changed OSX to macOS

## [0.2.0] - 2016-09-14

- Added yield while {conditional} support
- Added documentation for yield while conditional
- Added test cases for yield
- Fixed minor documentation errors

## [0.1.3] - 2016-09-04

- Default library import API
- Prevent memory leaks due to circular references by collections
- Validate collection key types at runtime
- Allow initialization lists inside initialization lists

## [0.1.2] - 2016-08-14

- Added PDF version of tutorial and LibCore library doc
- Overview doc removed, as it's now a bit redundant
- Jinx now uses % operator instead of mod keyword
- Floating-point mod operations now supported
- Minor fixes to Variant class
- Updated documentation

## [0.1.1] - 2016-08-14

- LogAllocations() function generates a detailed report of all allocated memory

## [0.1.0] - 2016-08-12

- Added fuzzing test to ensure runtime robustness
- Added new unit tests for incrementing/decrementing properties
- Added bytecode execution count limiter and behavior flag
- Modified changelog date format to year-month-date as intended
- Increment and decrement keywords now work correctly with properties
- Memory shutdown function fixed
- Fixed several runtime crashes or asserts from initial fuzz tests

## [0.0.4] - 2016-07-29

- Added WPF/.NET Editor control for Jinx
- Added JinxPad sample project demonstrating use of editor control
- Reorganized library projects

## [0.0.3] - 2016-07-17

- Added makefiles and NetBeans projects for Linux platform
- Projects compile cleanly under Linux/g++

## [0.0.2] - 2016-07-09

- Added support for UTF-16 conversions in Variant class
- Added unit tests for Unicode conversion and variable names
- Fixed potential memory corruption bug when using Jinx::Shutdown() and not all memory has been freed
- Identifiers now have fewer naming restrictions
- Updated tutorial with new Unicode and naming rules
- Regenerated API documentation
- Renamed "callback" unit test to "native"
- Deleted unused opcode
- Removed case insensitivity

## [0.0.1] - 2016-07-08

- Initial release
- Added initial library version numbers and string
- Added changelog
- Fixed minor documentation issues


