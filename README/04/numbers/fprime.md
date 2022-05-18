# fprime
This exercise is about writing a **program** that takes a **positive integer** and displays its [prime](https://en.wikipedia.org/wiki/Prime_number) factors (in ascending order), separated by an `*`, and followed by a newline.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/fprime/subject.en.txt).

In this exercise we're allowed to use `printf` and `atoi`!!!

## Main
We've been asked to write a **program**, so let's explain what we do in the `main` function:

* Use `atoi` to parse `argv[1]` into an **integer number**.
* Pass the **integer number** as an argument to `fprime`, which will take care of the rest.

The subject asks us to simply display a **newline** if the number of parameters is **not** `1`, and we also have to display a **newline** after printing the prime factors of the number. So we do the classic move:
```c
if (argc == 2) // meaning if we pass at least 1 command-line argument
    // do whatever
printf("\n"); // this time is an exception (usually: write(1, "\n", 1);)
```

The code above means that the same newline will be printed anyways:

1. Either to put an end of the factors.
2. Or it'll become the newline that is printed when the arguments are not exactly one.

## Is prime?
The first thing I did was to write a **helper function** named `isprime` which receives an integer number as argument and returns `1` if it's **prime**, `0` otherwise.

> Remember, a **prime number** is evenly divisible by `1` and itself.

In this function we set up a variable named `div` and initialize it to `2` (all numbers, primes and no primes, are divisible by `0` and `1`).

Then, in a loop, we keep increasing `div` and checking if `n` is evenly divisible by it. As soon as one value of `div` divides `n` evenly, we return `0` (meaning the number is **not prime**).

> We don't need to examine all the divisors up to our number, we just have to get to **half the number** (`div <= n / s`). Think about it: no number can be evenly divided by a number greater than his half (you can't evenly divide 4 by 3, can you?).

But if we exit the loop because the exit condition become false, meaning that `div` got up to half the number and couldn't evenly divide our number, that means that our number is **prime**, and we return `1`.

## Fprime
Then in `fprime`, first thing we do is to check if the argument we pass from `main` is a **prime**; if it is, we print it and job's done (we get out of the function with an empty `return` statement).

> The first check mentioned above is necessary because big numbers such as `804577` (which is prime) take a long time to check.

If the number is not prime, we set up a loop that will keep dividing our number by its factors in each iteration (We get out when the number becomes `1`). Inside this loop, we'll use a **nested loop**, where we use the same exit condition, plus we check that `div` is **prime** number and also a **factor** of the number (meaning it divides it evenly):

    * If the condition is fullfilled, we print the factor and an `*` as a separator.
    * If not, we exit the nested loop and increase the `div` variable (potential factors).

If you're wondering why we use a **nested loop**, that's because a number may have a prime factor repeated several times; for example, the prime factors of `27` are `3*3*3`. So in this inner loop we keep printing the same factor as many times as needed, without increasing `div`.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ../index.md
[next]: ./ft_itoa.md