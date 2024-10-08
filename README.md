# ft_malloc - Memory leak detection tool for 42 students

## ⚠️ Important warning for students at école 42

**This module does not comply with standard 42 because it uses a global variable.**  
It is intended solely as a development tool and should not be included in your final renderings.

## 📚 Description

ft_malloc is a module designed to help École 42 students detect and understand memory leaks in their C projects. It offers a simple, educational alternative to more complex tools like Valgrind, while remaining accessible to beginners.

## 🎯 Project goal

The main objective of ft_leaks is to :

1. Trace all memory allocations in your program.
2. Provide information on each allocation (size, name, ft_malloc line number).
3. Allow controlled release of memory.
4. Help identify potential memory leaks.

## 🛠 How it works

### Main functions :

1. `ft_malloc()`: Replaces `malloc()` to allocate memory while tracking it.
2. `ft_free()`: Replaces `free()` to free memory while updating tracking.
3. `ft_putalloc()` Displays all unreleased memory allocations otherwise displays `➜ No malloc`.

### Process :

1. Each call to `ft_malloc()` allocates memory and stores the details in a linked list.
2. Information stored includes: pointer, size, name (given by user), and line of code.
3. `ft_free()` frees memory and removes the corresponding entry from the tracking list.
4. At the end of the program, any allocation not freed is considered a potential leak.

## 📋 Use

1. Include “ft_leaks.h” in your source files.
2. Replace all calls to `malloc()` with `ft_malloc(size, “name”, __LINE__)`.
3. Replace all calls to `free()` with `ft_free()`.
4. Compile your program with ft_leaks.c.
Exemple :

```c
#include "ft_leaks.h"

int main()
{
    char *str;

    str = ft_malloc(10, "ma_chaine", __LINE__);
    //init de str
    ft_free(str);

    //Display allocations not released
    ft_putalloc();
    return 0;
}
```

## 🚫 Limits

1. **Not compliant with standard 42**: Use of a global variable.
2. Slight performance overload due to allocation tracking.
3. Requires source code modification to use.
4. Impossible to release all pointers at once, as the project is not up to standard and therefore not usable.

## 💡 Tips

- Use descriptive names for your allocations to facilitate debugging.
- Regularly check the list of unreleased allocations during development.
- Don't forget to replace ft_malloc and ft_free with malloc and free in your final code before submitting it.

## 🤝 Contribution

This project is open to improvement. Feel free to suggest modifications to make it more useful or effective, while keeping in mind that it must remain simple and educational.

---


> Remember: ft_malloc is a learning tool. For real projects or production environments, use more robust and proven memory leak detection tools.
