# fprime
This exercise is about writing a **program** that takes a **positive integer** and displays its [prime](https://en.wikipedia.org/wiki/Prime_number) factors (in ascending order), separated by an `*`, and followed by a newline.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/fprime/subject.en.txt).

In this exercise we're allowed to use `printf` and `atoi`!!!

## Main
We've been asked to write a **program**, so let's explain what we do in the `main` function:

* Use `atoi` to parse `argv[1]` into an **integer number**.
* Pass the **integer number** as an argument to `fprime`, which will take care of the rest.

The subject asks us to simply display a **newline** if the number of parameters is not `1` (or in other words, if `argc != 2`).

## Is prime?
The first thing I did was to write a **helper function** named `isprime` which receives an integer number as argument and returns `1` if it's **prime**, `0` otherwise.

In this function we set up a variable named `div` and initialize it to `2`; that's because **primes** are divisible by themselves and `1`.

Then, in a loop, we iterate over the potential divisors of the number; as soon as one divides the number evenly, we return `0` (meaning the number is **not prime**).

> We don't need to examine all the divisors up to our number, we just have to get to half the number. No number can be evenly divide by a number greater than his half (10 / 2 = 5).

But if we reach the end of the loop, it means that `div` got up to half the number, and no number in between could evenly divide our number; which means that our number is **prime**, and we return `1`.

## Fprime
Then in `fprime`, first thing we do is to check if the argument we pass from `main` is a prime; if it is, we print it and get out of the function with an empty `return` statement.

If the number is not prime, we set up a loop that will iterate for as long as the number is greater than `1`. Inside this loop, we'll use a **nested loop**, where we use the same exit condition, plus we check that `div` is prime number and also a factor of the number:

    * If the condition is fullfilled, we print the factor and an `*` as a separator.
    * If not, we exit the nested loop and increase the `div` variable (potential factors).

If you're wondering why we use a **nested loop**, that's because a number may have a prime factor repeated several times; for example, the prime factors of `24` are `3*3*3`. So in this inner loop we keep printing the same factor as many times as needed, without increasing `div`.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ../index.md
[next]: ./ft_itoa.md