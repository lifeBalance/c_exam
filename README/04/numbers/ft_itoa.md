# ft_itoa
This exercise is about writing a **function** that takes an integer and converts it to a **null-terminated** string.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_itoa/subject.en.txt).

For this task I only wrote a **helper function** named `count_digits` that takes a **positive integer** (or zero) as argument, and returns the amount of digits in that number.

In `ft_itoa` we take the following steps:

1. Store the amount of digits in the `len` variable.

2. Increase the `len` variable by one if the number is negative (we need to allocate space for the `-` sign in our string).

3. Allocate `len` plus one for the **null-character**.

4. Place the **null-character** at the position of `len` (remember we allocated `len + 1`, which means that the index `len` is within boundaries).

5. Decrease the value of `len` by one, so that it points at the position of the last digit (right before the null).

6. If the number is **negative**, place the `-` sign at `s[0]`, and assign to `cpy` the absolute value of `nbr`. If it's **positive**, assign `nbr` to `cpy`.
7. Now we use a loop to iterate over the positions in `s`, starting from the end. Remember that we left `len` pointing to the least significant digit. On each iteration we store the character version of the digit in the right place, and divide `cpy` by 10.

8. Finally, we return the string.

> The only tricky part is the conditional expression we used in the **loop**: `len >= (nbr < 0)`. That means that `len` will decrease up to either `1` if the number is **negative** or to `0` if it's positive. Let's not forget that, if the number is negative, we placed a `-` sign at index `s[0]` that we don't want to smeeesh ;-)

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./fprime.md
[next]: ./ft_itoa_base.md