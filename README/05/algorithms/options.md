# options
In this exercise we have to write a **program** that takes an **undefined number** arguments which could be considered as options and writes on standard output a representation of those options as groups of **bytes** followed by a newline.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/option/subject.en.txt) of the exercise for more information.

Note that:

1. A set of options (lowercase letters starting with a `-`) may be followed by a **string** which could represent the name of a file for example. Check this out:
```
$>./options -z hive
00000010 00000000 00000000 00000000
```

 The `hive` string is simply not parsed!

2. That string, could appear by itself:
```
$>./options Bonjour
00000000 00000000 00000000 00000000
```

 As you can see, in this case we still must print the bytes, even though all the bits are `0`.

## My Approach
For this exercise I used the following helper functions:

* `validate_options`: we call this function from `main`, passing all the arguments (`argv`), as well as `argc`. Then we iterate over each string using a nested loop. In the inner one, we check that the **first character** is a `-`, otherwise we return `0`. If we hit anything other than a **lowercase** letter also return `0`. If we finish the string without incidences, return `1`.

* `islowercaseletter`: receives a character and returns `1` if it's a lowercase letter, `0` otherwise.

* `ft_strlen`: no introductions needed. We use it as a convenience for measuring the `USAGE` and `ERROR` messages.

* `test_bit`: receives an `unsigned int` **value** and another one with the **position**. Returns `1` if the bit at that position is **on**; `0` otherwise.
* `set_bit`: receives an `unsigned int` **value** and another one with the **position**. Returns another `unsigned int` with the bit at that position turned **on**.

* `print_bits`: receives an `unsigned int` and traverses its bits (starting from the most significant one) printing them on `stdout`. It also adds a **space** to separate bytes.

* `represent`: sets up a nested loop to iterate over the characters of the command-line arguments. In the inner loop, as soon as we hit an `h`, we print the `USAGE` message; otherwise we set up **bits** in the `options` variable. Outside the loops, we print the **four bytes** in the `unsigned int`.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./brackets.md
[next]: ./print_memory.md