# ft_split
The goal of this exercise is to write a function that splits a string, into an array of strings. The words in the **original string** are split by whitespace. This exercise considers as whitespace:

* The **space character** (`' '`).
* The **tab character** (`'\t'`).
* The **newline character** (`'\n'`).

A sequence of **non-whitespace characters** at the **beginning** or at the **end** of the original string are also considered as **words**.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_split/subject.en.txt) of the exercise for more information.

## My approach
To solve the problem I wrote the following **helper functions**:

* `ft_isspace`: This simple function will return `1` if its character argument is one of the whitespace characters asked in the subject.
* `count_words`: Since we have to **allocate** space in memory for each word, and we don't know how many words our function is gonna receive, the first thing is to write a function to traverse the string counting how many words it contains.
* `word_len`: It traverses its string argument counting the words, as defined in the subject.

In the main function (`ft_split`) we take the following steps:

* Count the words and **allocate** as many `char *` as words are counted, plus one, which will be a `NULL` pointer to terminate the array.
* Use a **loop** to traverse the **original string** character by character. A nested **if statement** will be triggered as soon as a **non-whitespace** character is found and the following will happen:

    * Count the word's length using the `word_len` helper.
    * Allocate space in memory for the word, plus one character to **null-terminate** the string.
    * Use a nested loop to iterate over the string, copying its non-whitespace characters to the newly allocated `char *`. As soon as we hit a **whitespace** we break out of the loop, and we null terminate that string, increase the `word` counter and add a **null character** (yeah, each word added to the array, even if it's not the last one, it's inmediately followed by a null. That way we don't have to keep track of which one is the last word, in order to put the null right after).
    * The other main piece in the outer loop is another inner loop to skip whitespace.

* At the end of the function, we return the array of words.

## Testing
Check out the loop that I use for iterating over the array of strings:
```c
while (arr[i])
{
    printf("%s\n", arr[i]);
    i++;
}
```

The loop stops when `arr[i]` hits the **null pointer** at the end (sentinel value).

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ../index.md
[next]: ./rev_wstr.md