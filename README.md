# C Preprocessor

This project is a simple implementation of how a **C preprocessor works internally**.
It takes a `.c` file as input and generates a processed `.i` file after handling things like macros, comments, and header files.

The idea behind this project was to understand what actually happens *before* a C program is compiled.



## 💡 What This Program Does

When you give a C file as input, the program:

* Removes all comments (`//` and `/* */`)
* Processes `#define` macros and stores them using a linked list
* Replaces macros wherever they appear in the code
* Handles `#include` files (both user-defined and system headers)
* Generates a clean `.i` file as output



## ⚙️ How It Works 

The program reads the input file step by step and checks what each part of the code is:

* If it finds a comment → it removes it
* If it finds `#define` → it stores the macro (name + value)
* If it finds `#include` → it opens and processes that file
* Otherwise → it checks if any macro needs to be replaced

All the logic is split into multiple files to keep things organized.



## 📂 Project Structure

* `main.c`
  Handles file input/output and starts the processing

* `process.c`
  Core logic that scans the file and decides what action to take

* `header.c`
  Handles `#include` and `#define` (adds macros to linked list)

* `comment.c`
  Removes comments from the code

* `comment.h`
  Contains structure definitions and function declarations

* `Makefile`
  Used to compile and run the project easily



## ▶️ How to Run

### Using Makefile (Recommended)

```bash
make
./pree input.c
```

To clean compiled files:

```bash
make clean
```

---

### Manual Compilation

```bash
gcc main.c process.c header.c comment.c -o pree
./pree input.c
```



## 📌 Example

### Input (`input.c`)

```c
#include<stdio.h>
#define PI 3.14

int main() {
    int i = 10; // comment
    i = PI * 2;

    /* multi-line
       comment */
}
```

### Output (`input.i`)

```c
int main() {
    int i = 10;
    i = 3.14 * 2;
}
```

---

## 🧠 What I Learned

While building this project, I got hands-on experience with:

* File handling in C
* String processing and parsing logic
* Linked list implementation
* How macros actually work
* How preprocessing happens before compilation



## ⚠️ Limitations

This is a simplified version of a real C preprocessor, so:

* It may not handle all edge cases
* Complex macros are not fully supported
* System header path is fixed (MinGW)



## 🚀 Future Improvements

* Better macro handling (nested macros, function-like macros)
* More accurate parsing (character-by-character instead of token-based)
* Cross-platform header file support
* Error handling improvements



## 👨‍💻 Author

atharvbarge1421

---

## 📌 
This project is mainly for learning purposes and to understand the internal working of the C compilation process.

