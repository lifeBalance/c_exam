# print_memory
In this exercise we have to write a **function** that takes a **void pointer**, and prints the memory area it's pointing to.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/print_memory/subject.en.txt) of the exercise for more information.

## Observations
For example, consider the following array:
```
int	tab[10] = { 0, 23, 150, 255,
                12, 16,  21, 42};
```

If we printed it out using our function, it should display:
```
0000 0000 1700 0000 9600 0000 ff00 0000 ................$
0c00 0000 1000 0000 1500 0000 2a00 0000 ............*...$
0000 0000 0000 0000                     ........$
```

To understand what's going on here, we have to consider some things:

* An `int`, in most C implementations, takes **4 bytes**. The size of the array is 10, which means that the memory area is **40 bytes**.

* We have **20 groups** of **4 digits** (hexadecimal), meaning that we're using **2 hexadecimal digits** to represent a **byte** (that amounts to 40 pairs of hexadecimal digits).

* You can verify what we mentioned above if you focus out attention in the first two groups of digits (`0000 0000`). That group represents **the first element**, whose value is `0`. It takes **four pairs of hexa digits** to represent each element.

> Check now the fourth element (index 3); its value is `255`, which in hexadecimal is `ff`.

## My Approach
The main take-away from this problem is the idea that even though the starting point is an array of ten `int` values, our `print_memory` function is receiving a **void pointer** to that area in memory. We can choose how to traverse this area.

First thing I did was to declared a pointer to `unsigned char`, to which I assigned the `void *addr` argument (using a cast). That allows us to traverse the area in **byte-sized** chunks.

> Note that the second argument (`size`) receives the amount in **bytes** of the memory area (the `sizeof` operator always returns size in **bytes**).

Then, we set up a loop to traverse the array of bytes using an index(`i`). On each iteration we'll call a helper function named `print_line`; this funtion returns an integer that is assigned to `i`.

> Actually, `print_line` always returns `16` on each call, meaning that the values of `i` will be: `0`, `16`, `32`, `48`. This last value makes the condition **false** and the loop exits.

## Helpers
I used three helpers:

* `print_byte_hex`: prints its `unsigned char` only argument using **two hexadecimal**. 

* `print_byte_char`: prints its `unsigned char` only argument as a character (it it's a **printable character**); prints an `*` otherwise.

* `print_line`: receives as arguments:

    * The `unsigned char` array.
    * The current index.
    * The size in bytes of the array (40 bytes in the example).

 In `print_line` we set up two loops to print a single line:

 * One for printing **16 bytes** in **hexadecimal** (grouped in **eight groups** of **two bytes/four digits**).
 * Another one for printing **16 bytes** as **characters**.

It's worth mentioning the *trick* we used in both loops to iterate through the bytes: we combined the values of `i` (which points to a byte in memory) and `j` (whose range goes from `0` to `16`).

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./options.md
[next]: ../index.md