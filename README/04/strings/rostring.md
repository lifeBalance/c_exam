# rostring
The goal of this exercise is to write a **program** that displays a string, with its last word at the very beginning. The remaining words will be shown in the original order but, separated by a **single space**.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/rostring/subject.en.txt) of the exercise for more information.

## My approach
To solve the problem I wrote the following **helper functions**:

* `ft_isspace`: This simple function will return `1` if its character argument is one of the whitespace characters asked in the subject.

* `word_len`: It traverses its string argument counting the length of words, number of **non-whitespace** characters, as defined in the subject.

In the main function (`rostring`) we take the following steps:

* Traverse the string, skipping any initial whitespace.

* Using an **if statement** we check the string is not emtpy, then we measure the length of the **first word**, allocate space in memory for it, and fill it with the contents of the original string, placing a null at the end.

* **Skip whitespace** in the original string after the **first word**.

* Use another loop to iterate over the string, printing the words (with a space at the end) and skipping any whitespace in between. If you're wondering, since we have to still place the first word at the end, we don't have to worry about always printing a space after each word.

* At the end of the function, we free the space assigned to the allocated word.

> As you may have notice, we've allocated space for the first word. There's no need to do that for the remaining ones.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./rev_wstr.md
[next]: ../index.md