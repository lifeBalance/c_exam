# brainfuck
In this exercise we have to write a [Brainfuck](https://en.wikipedia.org/wiki/Brainfuck) interpreter **program**.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/brainfuck/subject.en.txt).

Since we've been asked for a **program**, most of the interpreter logic is place in `main`.

## The data
First thing we do is declare a `char` (which takes a byte) array of **2048** elements (with the help of a `SIZE` macro). We initialize all of its elements to `0` at the same time we declare it (`= {0}`).

## The program
The program is given as a **first argument** (`argv[1]`). We declared a `char` pointer named `program` to make it more explicit. Even though the subject mentions that it won't have more than **4096** operations, we're not checking for that (nor did any of the implementations I checked online).

## The mechanics
The deal is to read instructions from the `program`, character by character (each instruction is **one** character long). For that we created a **loop** to traverse `program` using the index `i` (could be done with a pointer too).

The following instructions will affect the data:

* `>` move the data pointer **forwards**.
* `<` move the data pointer **backwards**.
* `+` **increase** the pointed value (by one).
* `-` **decrease** the pointed value (by one).
* `.` write the pointed value to **stdout**.

> To move through the `data` array we're using the **index** `j` (again, we could use a pointer for that too).

The program instructions are caught by a series of **else if** statements. Outside of them, we increase the value of `i` (the index to traverse the program), which would skip **brainfuck comments**.

## The brackets
There are a couple of `program` instructions to jump around the brainfuck *code*:

* `[` go to the matching `]` if the pointed byte is `0`.
* `]` go to the matching `[` if the pointed byte is **not** `0`.

We outsourced the code to deal with these two instructions to a function named `match`. This function receives two arguments:

* A pointer to the beginning of `program`.
* An index pointing to the exact position where the bracket is.

If it's an **opening** bracket we'll be moving the pointing forwards, in order to match the **closing** one. We use a variable named `matches`, initialized to zero. Then a **loop** will keep increasing the **index** value searching for the **closing** bracket. Two interesting things happen here:

* If we find a closing bracket, we increase the value of `matches`. Then the loop condition checks if its value is `1` and exits; otherwise it continues.
* But if we find **another opening bracket**, the value of `matches` is **decreased** (now we have to match two opening brackets).

> The logic for matching an **opening** bracket is the same, only that we move the **index** backwards, decreasing its value.

This function returns the **index** of the bracket we jumped to, but back in the `main` function, at the bottom of the loop, the index used to traverse the program is increased right before the next iteration.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ../index.md
[next]: ./checkmate.md