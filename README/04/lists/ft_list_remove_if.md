# ft_list_remove_if
This exercise is about writing a function that removes a node if the return value of the **function pointer** passed as an argument is `0`. The function pointer receives two `void *` as arguments:

* The first **void pointer** points to the data, for example a string.
* The second `void *`, will point to the payload of each node (`void *data`) as we traverse the list.

This exercise is a **bit tricky**, since the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_list_remove_if/subject.en.txt) requires us to delete **any** node whose payload matches the `data_ref` argument. Which means that our function should be able to delete **not only** the **first match**, but **all of them** if that's the case.

The strategy I followed was:

1. Use a loop that will delete consecutive matches at the **head** of the list.
2. Use another loop to delete matches anywhere else in the list.

In both loop I use a fork of two **node pointers** named. On each iteration, this fork advances to the two next consecutive nodes.

> In the **first loop** I use `begin_list` and `curr` for the fork. In the **second loop** I use `prev` and `curr` for the fork.

To test the whole think, I just included `string.h`, and used `strcmp` as **function pointer**, which returns `0` when both strings match.

## The header
The `t_list` type definition must be put in a **header file** named `ft_list.h`. This header must be included both in the `ft_list_remove_if.c` and in `main.c` (if we want to test the whole thing).

> The header must **NOT** be pushed this time!

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./ft_list_foreach.md
[next]: ./sort_list.md