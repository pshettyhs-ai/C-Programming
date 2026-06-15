# Interview Questions — Command Line Arguments

## 🟢 Basic
**Q1. What are argc and argv?**
> `argc` (argument count) is the total number of command-line arguments including the program name. `argv` (argument vector) is an array of C strings: `argv[0]` is the program name, `argv[1]` through `argv[argc-1]` are the actual arguments, and `argv[argc]` is `NULL`. All arguments arrive as strings — convert with `atoi`, `atof`, `strtol` as needed.

**Q2. What is argv[0]?**
> The name of the program as invoked (implementation-defined, but usually the path used to invoke it). Used to print usage messages: `fprintf(stderr, "Usage: %s [options] file\n", argv[0])`.

**Q3. What are the two valid signatures for main in C?**
```c
int main(void);
int main(int argc, char *argv[]);
/* or equivalently: */
int main(int argc, char **argv);
```

## 🟡 Intermediate
**Q4. Why should you use strtol instead of atoi?**
> `atoi` has no error detection — on invalid input it silently returns 0, and on overflow behavior is undefined. `strtol(str, &endptr, base)` sets `endptr` to the first unconverted character (you check `*endptr == '\0'` for full conversion), sets `errno` on overflow, and handles different bases.

**Q5. What is getopt and why use it?**
> `getopt` (POSIX) parses short options (`-v`, `-o file`). The option string specifies valid options; a colon after a letter means it requires an argument. `optarg` holds the argument, `optind` is the index of the first non-option argument. Handles `-v -o output.txt` and combined `-vo output.txt` forms. Use for any program with more than 2-3 options.

## 🔴 Advanced
**Q6. What is the difference between `char *argv[]` and `char **argv`?**
> They are identical as function parameters. `char *argv[]` is an array of pointers to char, which decays to `char **` (pointer to pointer to char) in a function parameter context. Both can be used with `argv[i]` or `*(argv + i)` notation.

**Q7. How would you handle subcommands like `git commit` or `docker run`?**
> Check `argv[1]` for the subcommand name, then dispatch to a subcommand handler function with the remaining arguments:
```c
if (argc < 2) { show_help(); return 1; }
if (strcmp(argv[1], "commit") == 0)
    return cmd_commit(argc-1, argv+1);  /* shift argv */
else if (strcmp(argv[1], "push") == 0)
    return cmd_push(argc-1, argv+1);
```
> Each subcommand handler sees its own argv starting at `argv[0]`.

---

*— Pavan Shetty H S*
