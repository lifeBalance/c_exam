# rpn_calc
In this exercise we have to write a **program** that evaluates an expression in [Reverse Polish notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation), and prints the result to `stdout`.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/rpn_calc/subject.en.txt) of the exercise for more information.

If you've ever used the [dc](https://en.wikipedia.org/wiki/Dc_(computer_program)) command (short for desktop calculator), you're probably familiar with this notation. Sadly, for some reason, some tests performed with `dc` don't throw the same results as our implementation.

> macOS systems usually have installed the [GNU dc](https://www.gnu.org/software/bc/manual/dc-1.05/html_mono/dc.html) implementation.

I also compiled some **moulinette tests** that I found online in a `test.csv` file. Once you've compiled your program as `rpn_calc`, you can run the `test.sh` script to see if everything matches.

## My approach
This problem presents the perfect scenario for using a [stack](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)), so that's what I did. This time I put all stack related functions in its own file, with its accompanying header.

In the main file (`rpn_calc.c`), I set up a loop to traverse the string argument. A nested **if-else statement** reacts to:

* **Digits**: `atoi` is called, and the string pointer is advanced pass the digits. There's a check for **negative numbers**, which are parsed when a `-` is inmediately followed by a digit (no space in between). All numbers are pushed onto the stack.

* **Operators**: where is checked that the operator is followed by a space, or shows up at the very end of the string. Then two numbers are **popped** from the stack, and sent to `do_op` to perform the operation. If `do_op` returns a **non-zero** value, that will trigger an **error** in the caller.

Ouside the loop, we just `pop` the stack for the last time, that should contain at this point a single value. If that's the case, we print it, and return **zero** (success); but if after the pop the stack is non empty, we don't print shit, and return a **non-zero** value (error).

## Helpers
I used some helpers to make the code clearer:

* `ft_isdigit`: returns `1` if it's character argument is a digit; `0` otherwise.

* `ft_isoperator`: returns `1` if it's character argument is one of the operators asked in the subject; `0` otherwise.

* `do_op`: which performs an operation with its two **integer arguments**, storing the value in the third argument, which is a pointer to integer. The operation is determined by the value of its **operator argument** (a character).

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./print_memory.md
[next]: ../index.md