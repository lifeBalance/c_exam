# rev_wstr
The goal of this exercise is to write a **program** that takes a string as a parameter, and prints its words in reverse order.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/rev_wstr/subject.en.txt) of the exercise for more information.

## My approach
To solve the problem I wrote the following **helper functions**:

* `ft_isspace`: This simple function will return `1` if its character argument is one of the whitespace characters asked in the subject.

* `ft_strlen`: It traverses its string argument counting the amount of characters. A 42 classic.

* `print_word`: It prints all the non-whitespace character of its string argument.

* `last_word`: It receives a string, and an index. Then traverses the string back using the index. If when the loop exits the value of `i` is negative, it means the string from the index backwards contained **whitespace** characters.

* Finally, in the main function (`rev_wstr`) I proceeded as follows:

    * Use the `ft_strlen` to measure the string length, and assigned it to the `i`, to place the index at the last characters.
    * Use a loop to traverse back the string skipping all trailing whitespace characters (if any).
    * Lastly, another loop that traverses the string backwards contains an **if statement** which is triggered when:

        * We are on a non-whitespace character.
        * The character to the left is either a **whitespace** character (marking the beginning of a word).
        * Or the index is negative, meaning the word starts at index `0`.
     In the body of the if statement, we call `print_word` and print a **single space** character, only if it's not the last word.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./rev_wstr.md
[next]: ../index.md