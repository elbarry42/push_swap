````md
<*This project has been created as part of the 42 curriculum by elbarry and larchimb.*>

# 🧠 push_swap – Sorting Data with Two Stacks

Welcome to **push_swap**!  
This project is an algorithmic challenge where the goal is to **sort a stack of integers using only two stacks and a restricted set of operations**, while producing the **smallest possible number of instructions**.

It is a core project of the **42 curriculum**, focused on **algorithmic complexity, optimization, and low-level reasoning**.

---

## 📝 Description

The **push_swap** program takes a list of integers as input and outputs a sequence of operations to sort them.

Constraints make the problem challenging:

- 🔹 Only **two stacks** are allowed (`a` and `b`)
- 🔹 Only a **limited set of operations**
- 🔹 The goal is not only correctness, but **efficiency**

This project introduces concepts such as:

- 📈 Algorithmic **time complexity**
- 🧩 Optimization strategies
- 🔄 Adapting classic algorithms to constrained rules
- 📊 Measuring and exploiting **input disorder**
- 🤝 Team work and clean architecture

---

## 🎯 Objectives

- Understand how algorithm choices impact performance
- Compare different complexity classes in practice
- Optimize strategies based on input characteristics
- Write clean, norm-compliant, memory-safe C code

---

## 📌 Rules Summary

- Stack **a** contains the input integers (no duplicates)
- Stack **b** starts empty
- Stack `a` must be sorted in **ascending order**
- Operations are printed to **stdout**, one per line
- ❌ No global variables

---

## 🔧 Allowed Operations

| Operation | Description |
|---------|-------------|
| `sa` | Swap first two elements of stack a |
| `sb` | Swap first two elements of stack b |
| `ss` | `sa` and `sb` at the same time |
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

Compile the project using the provided Makefile:

```bash
make
make clean
make fclean
make re
````

Run the program with the desired strategy:

```bash
./push_swap [--simple | --medium | --complex | --adaptive] <numbers>
```

### 📌 Examples

```bash
./push_swap 2 1 3 6 5 8
./push_swap --simple 5 4 3 2 1
./push_swap --bench --complex 4 67 3 87 23
```

If no arguments are given, the program outputs nothing.

---

## 🧠 Algorithmic Strategies

This project implements **four sorting strategies**, selectable at runtime.

### 1️⃣ Simple – **O(n²)**

A basic algorithm mainly used for small inputs.

* Repeated minimum extraction
* Push to stack `b`, then back to `a`

✔ Easy to understand
✘ Inefficient for large inputs

---

### 2️⃣ Medium – **O(n√n)**

Chunk-based strategy:

* Split input into chunks
* Push chunk by chunk into stack `b`
* Reinsert in sorted order

✔ Good balance between simplicity and performance
✔ Suitable for medium-sized inputs

---

### 3️⃣ Complex – **O(n log n)**

High-performance strategy for large inputs.

* Radix sort adaptation
* Binary index processing

✔ Very efficient
✔ Excellent scalability

---

### 4️⃣ Adaptive – **Dynamic Strategy**

Before sorting, the program computes a **disorder value** between `0` and `1`.

#### 📊 Disorder definition

The disorder measures how far the input is from being sorted by counting inverted pairs.

| Disorder Range | Strategy Used           | Complexity     |
| -------------- | ----------------------- | -------------- |
| `< 0.2`        | Optimized simple method | **O(n)**       |
| `0.2 – 0.5`    | Medium chunk-based      | **O(n√n)**     |
| `≥ 0.5`        | Complex algorithm       | **O(n log n)** |

👉 The program automatically selects the most efficient strategy.

---

## 📊 Benchmark Mode

Using the `--bench` flag, performance data is printed to **stderr**:

* 📉 Computed disorder
* 🧠 Selected strategy & complexity class
* 🔢 Total number of operations
* 📋 Count of each operation

Example:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

---

## 🚫 Error Handling

The program prints `Error\n` to **stderr** if:

* ❌ Arguments are not integers
* ❌ Values exceed integer limits
* ❌ Duplicate numbers are detected
* ❌ Invalid input is provided

---

## 📚 Resources

* 📖 Algorithm complexity (Big-O notation)
* 📦 Stack data structures
* 🔢 Radix sort
* 🧩 Chunk-based sorting
* [https://en.wikipedia.org/wiki/Radix_sort](https://en.wikipedia.org/wiki/Radix_sort)
* [https://www.geeksforgeeks.org/dsa/radix-sort/](https://www.geeksforgeeks.org/dsa/radix-sort/)

---

## 🤖 AI Usage

AI tools were used **only for documentation, explanations, and README structuring**.
All algorithms and implementation choices were **designed and coded manually**, in full compliance with the **42 AI policy**.

