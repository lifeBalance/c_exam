# moment
In this exercise we have to create a function that takes a duration in **seconds** as an argument and returns a string with the number of seconds, minutes, hours, days or months elapsed.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/moment/subject.en.txt).

For this problem, I used several helper functions:

* `ft_strcat`: which concatenates the first string argument to the second one.

* `mini_itoa`: which receives an integer number, and returns a dynamically allocated string. It only works with positive integers, hence `mini_itoa`.

* `ft_strlen`: no introductions needed.

* `get_digits_len`: which returns the amount of digits of a positive integer.

* `build_moments`: which receives a string with the `time_unit` (second, minute, hour, etc) and the duration in the aforementioned time unit. Then allocates space in memory for a string, taking into consideration the plural or singular form of the noun.
Then it calls `mini_itoa` which returns a string with the duration. Finally it concatenates the substrings and returns the string.

* `moment`: which is the main function is a switcher that calls `build_moments` passing two arguments:

    * An **integer** with the duration in either months, days, hours, minutes or seconds.
    * A **string**: `month`, `day`, `hour`, `minute`, or `second`.

 This function returns the string that `build_moments` creates.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./flood_fill.md
[next]: ./sort_int_tab.md.md