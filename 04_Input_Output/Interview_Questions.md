# Interview Questions — Input Output

> **Author: Pavan Shetty H S**
>
> Questions I collected from placement drives and interviews. I answered each one in plain language — the way I would explain it in an interview.

---

## 🟢 Basic Questions

**Q1. What is the most important concept in Input Output?**

Understanding how Input Output connects to memory and runtime behaviour. The examiner wants to see that you understand the *why* behind the syntax, not just that you memorised it.

---

**Q2. What are the common mistakes beginners make in Input Output?**

See the Theory.md file for a dedicated "Common Mistakes" section. The most universal mistake across all topics: assuming things are initialised when they are not. In C, local variables start with garbage values. Always initialise explicitly.

---

**Q3. How does Input Output relate to memory in C?**

Every variable lives somewhere — stack, heap, data segment, or BSS. How Input Output interacts with these segments is what separates a surface-level understanding from a deep one. See Memory_Concepts.md for a detailed breakdown.

---

## 🟡 Intermediate Questions

**Q4. Explain Input Output with a code example and trace through the execution.**

Always come prepared to write code in an interview. Know the syntax cold. Trace through examples step by step — interviewers love to see you think out loud.

---

**Q5. What is the difference between the most commonly confused aspects of Input Output?**

In every topic there are a few pairs of things that look similar but behave differently. For Input Output, these distinctions are covered in Theory.md under the relevant sections. Make sure you understand each comparison clearly.

---

## 🔴 Advanced Questions

**Q6. How would you use Input Output in a real-world production scenario?**

Connect the concept to something real: embedded systems, file parsers, network code, game engines. Showing awareness of practical use cases makes you stand out.

---

**Q7. What does the C standard say about undefined behaviour in Input Output?**

Every major topic has edge cases that lead to undefined behaviour. Know what they are, be able to name them, and be able to say how to avoid them. See the Common Mistakes section in Theory.md.

---

## 🎯 Scenario-Based Questions

**Q8. Given this code, what is the output — and if it has a bug, what is it?**

These are the most common question format in technical rounds. The best practice is to go through the Programs/ folder and trace the output of every program by hand before running it. Then run it and compare.

---

*Study all three program files (Basic, Intermediate, Advanced) for this chapter before an interview.*

*— Pavan Shetty H S*
