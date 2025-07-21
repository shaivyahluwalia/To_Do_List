# 📝 To-Do List using C and Hash Table

This project is a **simple To-Do List application** implemented in **C** using a **hash table** for efficient task storage, lookup, and deletion. It allows users to add, search, display, and delete tasks by category or priority.

## 🚀 Features

* Add new tasks with title, category, or priority
* Search for tasks quickly using hashing
* Delete tasks efficiently
* Display all tasks neatly
* Uses hash table for fast access and management

## 🧠 Data Structure Used

* **Hash Table** with separate chaining or open addressing (based on implementation)
* Custom task struct containing task details

## 📂 File Structure

```
├── main.c          # Main driver code
├── todo.h          # Header file with structure & function declarations
├── todo.c          # Core hash table and task logic
└── README.md       # Project description
```

## 🛠️ How to Run

1. Clone or download the project
2. Compile using GCC:

   ```bash
   gcc main.c todo.c -o todo
   ```
3. Run:

   ```bash
   ./todo
   ```

## 📌 Sample Functions

* `addTask()` – Add new task to the hash table
* `deleteTask()` – Remove task based on key
* `displayTasks()` – Show all current tasks
* `searchTask()` – Find a specific task using hashing

## 📚 Concepts Applied

* Hashing & Hash Functions
* Collision handling (e.g., chaining or linear probing)
* Modular programming in C
* String handling and memory management

## 💡 Future Improvements

* Add file I/O for saving tasks persistently
* Add due date or reminder system
* Command-line flags or menu-based GUI

