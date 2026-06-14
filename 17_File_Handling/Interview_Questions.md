# Interview Questions — File Handling

## 🟢 Basic
**Q1. What is the difference between text mode and binary mode in file handling?**
> **Text mode** (`"r"`, `"w"`): newline translation occurs — `\n` may be converted to `\r\n` on Windows. Suitable for human-readable files. **Binary mode** (`"rb"`, `"wb"`): no translation — bytes read/written exactly as stored. Required for non-text data (structs, images, audio). On Linux, text and binary are identical; on Windows they differ.

**Q2. What does fopen return if the file cannot be opened?**
> `NULL`. Always check the return value: `if (fp == NULL) { perror("fopen"); exit(1); }`. `perror()` prints the system error message (e.g., "No such file or directory") alongside your custom message.

**Q3. What is the difference between `fgets` and `fscanf` for reading text?**
> `fgets(buf, n, fp)` reads a whole line (up to `n-1` chars) including whitespace, preserving the `\n`. Predictable and safe. `fscanf(fp, fmt, ...)` reads formatted data matching a format string, stops at whitespace by default with `%s`. Use `fgets` for line-by-line reading, `fscanf` for structured data.

## 🟡 Intermediate
**Q4. Explain fseek and its three reference positions.**
> `fseek(fp, offset, whence)` moves the file position:
> - `SEEK_SET`: offset from beginning of file
> - `SEEK_CUR`: offset from current position (can be negative)
> - `SEEK_END`: offset from end of file (usually negative for backward)
> Used for random access in binary files — jump directly to record `n`: `fseek(fp, n * sizeof(Record), SEEK_SET)`.

**Q5. What is the difference between fread and fscanf?**
> `fread(ptr, size, count, fp)` reads `count` binary blocks of `size` bytes each — no format interpretation, no conversions. `fscanf` reads formatted text and converts to types. Use `fwrite`/`fread` for binary (struct) files — much faster and exact. Use `fprintf`/`fscanf` for human-readable text files.

## 🔴 Advanced
**Q6. What is buffered file I/O and when would you call fflush?**
> By default, file writes go to a buffer in memory, not directly to disk. The buffer is flushed when: it fills up, `fclose` is called, or `fflush(fp)` is called explicitly. `fflush` forces data to be written to the OS immediately. Needed when: another process reads the file, the program might crash before normal close, or real-time logging is required.

**Q7. How do you implement a simple database using binary file access?**
> Store fixed-size records (structs) sequentially. To access record `n`: `fseek(fp, n * sizeof(Record), SEEK_SET); fread(&rec, sizeof(Record), 1, fp);`. To update: seek to position, `fwrite` the modified record. To delete: mark a field (e.g., `is_deleted=1`) or shift remaining records. This is how simple flat-file databases work.

---

*— Pavan Shetty H S*
