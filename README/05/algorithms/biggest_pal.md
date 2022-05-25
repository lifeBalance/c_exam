# biggest_pal
In this exercise we have to write a **program** that takes a string as argument and prints the biggest palindrome included inside this string, followed by a **newline**.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/biggest_pal/subject.en.txt) of the exercise for more information.

## My Approaches
This exercise is the classic find the [longest palindromic substring](https://en.wikipedia.org/wiki/Longest_palindromic_substring), which shows up more often than not in technical interviews. I tried to solve it using different methods:

* [Brute force](https://en.wikipedia.org/wiki/Brute-force_search), which times out with one of the tests.
* [Dynamic programming](https://en.wikipedia.org/wiki/Dynamic_programming) (which for some reason wasn't working for me).
* The **expand around center** approach, which consists on traversing the string picking up two indices for the **center** of the palindrome:

    * The same value (`i` and `i`), for the start and end character of **odd palindromes** such as `aba`. The center of such palindrome would be the `b`, where we'd start and keep expanding outwards.
    * Two consecutive indices (`i` and `i + 1`, for **even palindromes** such as `abba`, where we'd need the index of the first `a` (`i`) and the one of the second `a` (`i + 1`).

In the main loop we pass the two indices to a function that I named as `expand`, which keeps expanding the indices outwards, checking if each substring it's a palindrome.

## Helpers used in Expand Around Center
For this program I made use of several helper functions:

* `ft_strlen`: the equivalent of `strlen`, just coded by myself.

* `expand`: which receives two indices and keeps expanding them and checking for palindrome. It stores the indices which mark the palindrome with the maximum length in a **two-element** array.

* `biggest_pal`: which traverses the string starting from the beginning, sending two indices to `expand`.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ../index.md
[next]: ./options.md