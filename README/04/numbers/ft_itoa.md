# ft_itoa
This exercise is about writing a **function** that takes an integer and converts it to a **null-terminated** string.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_itoa/subject.en.txt).

For this task I only wrote a **helper function** named `count_digits` that takes a **positive integer** (or zero) as argument, and returns the amount of digits in that number.

## Helper function: Counting digits
For this problem I used a helper which I named `count_digits`, which receives an `unsigned int`, and keeps dividing it by 10 till it equals `0`. At that point we should have the amount of digits stored in a `len` counter.

> The range of an `int` goes from `-2,147,483,648` to `2,147,483,647`.

I had to declare its only argument as `unsigned int`, in case we have to deal with the lowest possible integer: `-2147483648`. That number is representable by an `int` without issue, but when we use its absolute value in our helper, it suddenly becomes `2147483648` and we get **integer overflow**.

> The range of an `unsigned int` goes from to `0` to `4,294,967,295`.

In `ft_itoa`, when we invoke the helper, we use the following ternary expression:
```c
cpy = (nbr < 0) ? (unsigned int) -nbr : (unsigned int) nbr;
```

The line above checks the **sign** of `nbr`:

* If it's **negative**, we have to **change its sign** before casting it and store it in `cpy`.
* If it's **positive** we just have to cast it.

> Changing the sign of the value of `nbr` before we assign it to `cpy` it's necessary, otherwise we don't get the right values.

Having said that, the logic behind `ft_itoa` is quite simple:

1. Create a copy of `nbr` and store it as `unsigned int`.

2. Send that value to our counting digits helper, and store the amount of digits in the `len` variable.

3. Increase the `len` variable by one if the number is **negative** (we need to allocate space for the `-` sign in our string).

4. **Allocate** `len` bytes, plus one for the **null-character**.

5. Place the **null-character** at the position of `len` (remember we allocated `len + 1`, which means that the index `len` is within boundaries). In the same expression we can use a **post-decrement** operator to decrease the value of `len` by one, so that it points at the position of the last digit (right before the null).

6. Now we use a loop to iterate over the positions in `s`, starting from the **least significant digit**. Remember that we left `len` pointing to the least significant digit. On each iteration we store the character version of the digit in the right place, and divide `cpy` by 10.

7. If the number is **negative**, place the `-` sign at `s[0]`.

8. Finally, we return the string.

> The only tricky part is the conditional expression we used in the **loop**: `len >= (nbr < 0)`. That means that `len` will decrease up to either `1` if the number is **negative** or to `0` if it's positive. Let's not forget that, if the number is negative, we placed a `-` sign at index `s[0]` that we don't want to smeeesh ;-)

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./fprime.md
[next]: ./ft_itoa_base.md