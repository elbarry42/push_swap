<*This project has been created as part of the 42 curriculum by elbarry and larchimb.*>

# push_swap – Sorting with Two Stacks 🔄🧠

<div align="center">

![42 Badge](https://github.com/elbarry42/elbarry42/blob/main/42_badges/push_swapn.png)

</div>

Welcome to **push_swap**! 🚀  
This project is an algorithmic challenge where the goal is to **sort a stack of integers using only two stacks and a restricted set of operations**, while generating the **smallest possible number of instructions**.

It is a core project of the **42 curriculum**, focused on **algorithmic optimization, complexity analysis, and clean architecture**.

---

## 📝 Description

The **push_swap** program takes a list of integers as arguments and outputs a sequence of operations that sorts them.

Constraints make the challenge interesting:

* Only **two stacks** are allowed (`a` and `b`)
* Only **specific operations** can be used
* The objective is not only correctness, but **performance**

This project emphasizes:

* Algorithmic **complexity**
* Strategy comparison
* Low-level data manipulation
* Measuring **input disorder**
* Writing clean and norm-compliant C code

---

## 📌 Rules Overview

* Stack **a** contains the input integers (no duplicates)
* Stack **b** starts empty
* Stack `a` must be sorted in **ascending order**
* Operations are printed to **stdout**
* No global variables allowed

---

## 🔧 Allowed Operations

| Operation | Description |
|---------|-------------|
| `sa` | Swap first two elements of stack a |
| `sb` | Swap first two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top of b to a |
| `pb` | Push top of a to b |
| `ra` | Rotate stack a |
| `rb` | Rotate stack b |
| `rr` | `ra` and `rb` |
| `rra` | Reverse rotate stack a |
| `rrb` | Reverse rotate stack b |
| `rrr` | `rra` and `rrb` |

---

## ⚙️ Compilation & Usage

Compile the project with the provided Makefile:

```bash
make
make clean
make fclean
make re
````

Run the program with an algorithm flag:

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <numbers>
```

### 📌 Examples

```bash
./push_swap 2 1 3 6 5
./push_swap --simple 5 4 3 2 1
./push_swap --bench --adaptive 4 67 3 87 23
```

If no arguments are provided, the program outputs nothing.

---

## 🧠 Sorting Strategies

This project implements **four different algorithms**, selectable at runtime.

### 1️⃣ Simple – **O(n²)**

Basic strategy, mainly for small inputs.

* Repeated minimum extraction
* Push to stack `b`, then back to `a`

✔ Easy to implement
✘ Inefficient for large inputs

---

### 2️⃣ Medium – **O(n√n)**

Chunk-based strategy:

* Divide input into chunks
* Push chunk by chunk into stack `b`
* Reinsert in sorted order

✔ Good balance between simplicity and efficiency
✔ Suitable for medium-sized inputs

---

### 3️⃣ Complex – **O(n log n)**

High-performance strategy for large inputs.

* Radix sort adaptation
* Binary index processing

✔ Very efficient
✔ Scales well on large datasets

---

### 4️⃣ Adaptive – **Dynamic Strategy** ⚡

Before sorting, the program computes a **disorder value** between `0` and `1`.

#### 📊 Disorder Definition

The disorder represents how far the input is from being sorted by counting inverted pairs.

| Disorder Range | Strategy Used    | Complexity     |
| -------------- | ---------------- | -------------- |
| `< 0.2`        | Optimized simple | **O(n)**       |
| `0.2 – 0.5`    | Medium chunks    | **O(n√n)**     |
| `≥ 0.5`        | Complex          | **O(n log n)** |

The program automatically selects the **most efficient strategy**.

---

## 📊 Benchmark Mode

Using the `--bench` flag, statistics are printed to **stderr**:

* 📉 Disorder value
* 🧠 Selected strategy & complexity class
* 🔢 Total number of operations
* 📋 Count of each operation type

Example:

```bash
./push_swap --bench --complex 4 67 3 87 23
```

---

## 🚫 Error Handling

The program prints `Error\n` to **stderr** if:

* Arguments are not integers
* Values exceed integer limits
* Duplicate numbers are detected
* Invalid input is provided

---

## 📚 Resources

* Big-O notation
* Stack data structures
* Radix sort
* Chunk-based sorting
* [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort)
* [https://www.geeksforgeeks.org/dsa/radix-sort/](https://www.geeksforgeeks.org/dsa/radix-sort/)

---

## 🤖 AI Usage

AI tools were used **only for documentation assistance and README structuring**.
All algorithms, logic, and implementation were **designed and coded manually**, in compliance with the **42 AI policy**.

---

✨ Thanks for checking out my **push_swap** project! 🚀
