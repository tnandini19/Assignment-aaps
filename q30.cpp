// What is a Linked List?
// A linked list is a linear data structure where elements (called nodes) are stored in non-contiguous memory locations and are connected using pointers.

// Each node typically contains:

// Data: The actual value.

// Pointer (next): Address of the next node in the list.

// Types of Linked Lists

// Singly Linked List
// Each node has one pointer to the next node.
// A → B → C → NULL

// Doubly Linked List
// Each node has two pointers: one to the next and one to the previous node.
// NULL ← A ⇄ B ⇄ C → NULL

// Circular Linked List
// The last node points back to the first node.
// A → B → C → A (Singly Circular)
// A ⇄ B ⇄ C ⇄ A (Doubly Circular)

// Why Use Linked Lists?
// Dynamic Size: Unlike arrays, they can grow or shrink at runtime.

// Efficient Insertions/Deletions: No need to shift elements like in arrays.

// Memory Usage: Better memory utilization as elements are not required to be contiguous.

// Applications in Algorithm Design

// Stacks and Queues Implementation
// Linked lists provide efficient push/pop for stacks and enqueue/dequeue for queues.

// Graph Adjacency Lists
// Used to represent graphs efficiently, especially sparse graphs.

// Memory Management
// Free memory blocks managed using linked lists (e.g., heap memory allocators).

// Polynomial Arithmetic
// Polynomials can be stored as linked lists to support addition/multiplication.

// Hash Tables (Chaining)
// Used in collision handling via chaining in hash tables.

// LRU Cache
// Doubly linked lists are used with hash maps to design efficient LRU cache algorithms.

// Operating System Scheduling
// Process scheduling often uses circular linked lists or queues.