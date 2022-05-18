# brackets
In this exercise we have to write a **program** that takes an **undefined number of strings** in arguments. For each argument, the program prints on the standard output `OK` followed by a **newline** if the expression is correctly bracketed, otherwise it prints `Error` followed by a **newline**.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/brackets/subject.en.txt) of the exercise for more information.

## My Approach
For this exercise I decided to use a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)) of a decent `SIZE`, where I would **push** all the **opening brackets** that showed up while parsing the string. Then, whenever a **closing bracket** showed up, I'd check the `top` of the stack to see if the brackets matched:

* If yes, I'd `pop` the stack, and continue the parsing.
* If not, that'd mean that the expression wasn't properly bracketed, and I'd exit the program.

## Helpers
For this program I wrote several helper functions:

* `is_opening`: receives a character as its only argument, and returns `1` if it's one of the opening brackets asked in the subject (either `(`, `[`, or `{`). Otherwise it returns `0`.

* `is_closing`: receives a character as its only argument, and returns `1` if it's one of the closing brackets asked in the subject (either `)`, `]`, or `}`). Otherwise it returns `0`.

* `match`: receives **two characters** as arguments, and returns `1` if they match. Otherwise it returns `0`.

* `brackets`: several things going on here:

    * Declare an instance of `t_stack` (on the **memory stack**, not the **heap**), and initialize it using a `struct` literal.
    * Set up a loop to traverse the string character by character, ignoring all characters except for:

        * **Opening brackets**, that are pushed onto the stack (if it's not full).
        * **Closing brackets**, that:
        
            * If they match what is at the `top` of the stack (and the stack is not empty), trigger a `pop` operation.
            * Else the program exits.

    * Outside the loop we return the expression `is_empty(&stack)`. Meaning that if the **stack** is empty, we matched all the brackets and the expression was `OK`.

## The stack
For the stack I create the following `typedef`:
```c
typedef struct	s_stack {
	char	data[SIZE];
	int		top;
}				t_stack;
```

When I declare the `stack` in `brackets`, I initialize it using a **struct literal** (`= {{0}, -1}`).

Regarding stack operations, we have:

* `is_full` that returns `1` if the `top` has reached the value of `SIZE`; otherwise `0`. 
* `is_empty` that returns `1` if the `top` is `-1`; otherwise `0`.
* `peek`: that returns the value of the element at the `top`.
* `pop`: that does the following:

    * Clears the value of the `stack` at the `top` (set to `0`).
    * Decreases the value of `top` by one.

* `push`: that increases the `top`, and stores the data argument at the new `top`.

> **IMPORTANT**: Do NOT forget to pass the **address** of the stack to our stack functions; otherwise we'd be performing stack operations on a **copy** of the `stack` structure.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ../index.md
[next]: ./options.md