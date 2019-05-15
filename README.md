Welcome! This repository contains the source code for:
* Blacktux namespace and libraries
* Depdenencies shared between files
* Custom Blacktux-designed data structures and methods

### Build Status
| Project Name  | Build Status |
| ------------- | ------------- |
| Blacktux | ![GitHub Logo](https://img.shields.io/badge/Blacktux%20Pipeline-never%20built-lightgrey.svg) |
| Microsoft SDK | ![GitHub Logo](https://img.shields.io/badge/Blacktux%20Pipeline-succeeded-brightgreen.svg) |

### To-Do List
- [ ] Rewrite in C++14 (or greater)
- [ ] Replace basic functions with inline lambda expressions
- [x] Build on Windows
- [x] Build on Kali Linux

# Blacktux Overview
Please take a few minutes to review the following documentation, before downloading and using:
 
## The Project
Blacktux is a C++-based collection of data structures, constants, macros, and methods. It includes many features that may already be expressed or defined in other preprocessor importations. 
 
The creator is not responsible for anything that may happen to your software or operating system, while developing with Blacktux. You acknowledge the risks and understand that otherwise extended C++ knowledge may be necessary, with certain parts of the source code.

## Naming Convention
Blacktux follows a developer-specific naming convention standard. Classes, structs, and functions (or methods) all follow the `UpperCamelCase` name-style. Non-member variables follow `lowerCamelCase` standards. Class member variables start with `m_` and continue with the non-member name-style. Abbreviations keep the capitalization in-tact (e.g. `ID` or `m_ID`).
 
| Data Structure  | Naming Convention | Special Case(s) |
| ------------- | ------------- | ------------- |
| Classes | `class Foo` | `class FooBar` |
| Structs | `struct Foo` | `struct FooBar`  |
| Methods | `void Foo();` | `void FooBar();` |
| Variables | `int foo` | `int m_foo(Bar)` |
 
 ## Unstable Data · ![GitHub Logo](https://img.shields.io/badge/stability-dangerous-red.svg)
This project contains potentially unstable and otherwise [volatile](https://www.embedded.com/electronics-blogs/beginner-s-corner/4023801/Introduction-to-the-Volatile-Keyword) functionality -- these types of data and algorithms are represented with the keyword `volatile` and a reference comment.
 
# Licensing
The Blacktux Project and its components are protected by the [MIT License](https://opensource.org/licenses/MIT). More information about the MIT License can be found, [here](https://en.wikipedia.org/wiki/MIT_License).
