# moment
In this exercise we have to create a **function** that takes a duration in **seconds** as an argument and returns a string with the number of seconds, minutes, hours, days or months elapsed.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/moment/subject.en.txt).

For this problem, I used several helper functions:

* `ft_strcat`: which concatenates the first string argument to the second one.

* `mini_itoa`: which receives an integer number, and returns a dynamically allocated string. It only works with positive integers, hence the prefix `mini_`.

* `ft_strlen`: no introductions needed.

* `get_digits_len`: which returns the amount of digits of a positive integer (or **zero**).

These helper functions are used in the next two functions:

* `moment`: which is the function that we've been asked to write and the one we call from `main`. What we do here is to call the `build_moments` function once we have divided the `duration` argument (received in **seconds**) by one of several macros. Which macro will depend on the amount of seconds we receive and it's selected in a series of **else if** statements. Once we've done that, we call `build_moments` passing two arguments:

    * An **integer** with the duration in either months, days, hours, minutes or seconds (resulting of the integer division, which truncates the decimal part).
    * A **string**: `month`, `day`, `hour`, `minute`, or `second` (depending on which **else if** is triggered).

 This will call `build_moments` to create the final string.

* `build_moments` receives a small hardcoded **string** (`second`, `minute`, `hour`, etc) in its `time_unit` argument and the **integer** `time`, with duration in the aforementioned time unit. Then it allocates space in memory taking into consideration:

    * The length of the digits in `time`.
    * The length of the plural or singular form of the word `time_unit`.
    * Also the spaces and the part of the string ` ago.`, which is constant.

Once the space in memory is allocated, it calls `mini_itoa` which returns a numeric string with the duration. Finally it concatenates the substrings, free the memory for the numeric string (it's already copied) and returns the resulting string.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./flood_fill.md
[next]: ./sort_int_tab.md.md