# sort_list
This exercise is about writing a function that receives a sorts the nodes in a list in the order determined by a **function pointer**. Meaning that if we want to sort the list in **ascending order**, we'd pass as an argument a **function pointer** that returns `1` when two elements are in ascending order, `0` otherwise.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/sort_list/subject.en.txt).

Read [here](./lists.md) to learn how to create functions to **create nodes**, **append nodes**, and **print a list**.

## My approach
At first, I spent some time trying to write my function reordering the nodes, but then I realized that the `list.h` header given for the assignment, defines a `t_list` with the `data` member being an **integer** (not a `void *`). All we have to do when two nodes are not in the order we want, it's to swap their **payloads**.

So it's a matter or traversing the list from beginning to end, calling the function argument on the `data` of two consecutive nodes, and swapping their payloads if needed. In more detail:

* The loop traverses up till the last node (`while (tmp->next)`)
* Uses the same pointer to compare to adjacent nodes: `cmp(tmp->data, tmp->next->data)`.
* If they are **swapped**, I reassign `tmp` the value of the original `lst`, to start again from the beginning of the list (**stupid sort**).

> Don't forget **NOT** to push the supplied header!

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./ft_list_remove_if.md
[next]: ../index.md