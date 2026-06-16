# C Programming Cheatsheet

> **Author: Pavan Shetty H S**
>
> Everything I need on one page — the stuff I look up most often.

---

## Data Types and Sizes (64-bit Linux)

```
char          1 byte    -128 to 127 (signed) / 0 to 255 (unsigned)
short         2 bytes   -32,768 to 32,767
int           4 bytes   -2,147,483,648 to 2,147,483,647
long          8 bytes   -9.2×10¹⁸ to 9.2×10¹⁸
long long     8 bytes   same as long on 64-bit Linux
float         4 bytes   ~7 significant decimal digits
double        8 bytes   ~15 significant decimal digits
void *        8 bytes   any pointer type
```

---

## Format Specifiers

```
%d or %i    int                   %u    unsigned int
%ld         long int              %llu  unsigned long long
%lld        long long int         %f    float or double (printf)
%lf         double (scanf only)   %e    scientific notation
%c          char                  %s    char * (string)
%p          pointer address       %x    hex lowercase
%X          hex uppercase         %o    octal
%zu         size_t                %%    literal % sign
```

---

## Operator Precedence (High → Low)

```
1.  ()  []  ->  .  (postfix) ++  --
2.  (prefix) ++  --  +  -  !  ~  *  &  sizeof  (type)
3.  *  /  %
4.  +  -
5.  <<  >>
6.  <  <=  >  >=
7.  ==  !=
8.  &
9.  ^
10. |
11. &&
12. ||
13. ?:
14. =  +=  -=  *=  /=  %=  &=  |=  ^=  <<=  >>=
15. ,
```

---

## Pointer Quick Reference

```c
int  x = 42;
int *p = &x;      /* p holds address of x */
*p = 99;          /* dereference: change x through p */
p++;              /* moves by sizeof(int) = 4 bytes */

int **pp = &p;    /* double pointer */
**pp = 5;         /* two levels of indirection */

void *vp = p;     /* generic pointer — must cast before deref */
*(int *)vp = 7;

const int *cp = &x;    /* value locked, pointer can move */
int * const pc = &x;   /* pointer locked, value can change */
```

---

## String Functions (string.h)

```c
strlen(s)              /* character count, NOT counting \0 */
strcpy(dst, src)       /* copy — UNSAFE, no bounds check */
strncpy(dst, src, n)   /* safe copy, may not null-terminate */
snprintf(dst,n,"%s",s) /* safest copy */
strcat(dst, src)       /* concatenate — UNSAFE */
strncat(dst, src, n)   /* safe concatenate */
strcmp(s1, s2)         /* 0=equal, <0 s1<s2, >0 s1>s2 */
strncmp(s1, s2, n)     /* compare first n characters */
strchr(s, c)           /* pointer to first c in s, or NULL */
strstr(s, sub)         /* pointer to first substring, or NULL */
strtok(s, delim)       /* tokenise — MODIFIES original string */
```

---

## Memory Functions

```c
malloc(size)             /* allocate bytes, uninitialised */
calloc(count, size)      /* allocate count×size bytes, zeroed */
realloc(ptr, new_size)   /* resize — never assign to original directly */
free(ptr); ptr = NULL;   /* free and nullify */
memcpy(dst, src, n)      /* copy n bytes, no overlap allowed */
memmove(dst, src, n)     /* copy n bytes, handles overlap */
memset(ptr, val, n)      /* fill n bytes with val */
```

---

## File I/O Quick Reference

```c
FILE *fp = fopen("file.txt", "r");   /* "r","w","a","r+","rb","wb" */
if (!fp) { perror("fopen"); exit(1); }

fprintf(fp, "%d\n", n);      /* formatted write */
fscanf(fp, "%d", &n);        /* formatted read */
fgets(buf, n, fp);            /* safe line read */
fputs(str, fp);               /* write string */
fgetc(fp) / fputc(c, fp);    /* character I/O */
fread(ptr, size, count, fp);  /* binary read */
fwrite(ptr, size, count, fp); /* binary write */

fseek(fp, offset, SEEK_SET / SEEK_CUR / SEEK_END);
ftell(fp);                    /* current byte position */
rewind(fp);                   /* go to beginning */
feof(fp) / ferror(fp);        /* check status */
fclose(fp);                   /* always close */
```

---

## Bitwise Tricks

```c
x |=  (1u << n)     /* set bit n */
x &= ~(1u << n)     /* clear bit n */
x ^=  (1u << n)     /* toggle bit n */
(x >> n) & 1        /* check bit n (0 or 1) */
x & (x - 1)         /* clear lowest set bit */
!(x & (x-1))        /* true if x is power of 2 */
x & (-x)            /* isolate lowest set bit */
```

---

## GCC Flags I Use

```bash
gcc -Wall -Wextra          # show all warnings — always use this
gcc -std=c11               # compile as C11
gcc -g                     # debug symbols for gdb
gcc -O2                    # optimise for speed
gcc -fsanitize=address     # detect memory errors at runtime
gcc -fsanitize=undefined   # detect undefined behaviour
gcc -lm                    # link math library (for sqrt, pow, etc.)
gcc -o output input.c      # specify output name
```

---

## Sorting Complexity

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Counting | O(n+k) | O(n+k) | O(n+k) | O(k) | Yes |

---

*— Pavan Shetty H S*
