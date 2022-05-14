# ft_list_foreach
This exercise is about writing a function that receives a **function pointer** and applies it to each node of a linked list. It's a matter or traversing the list from beginning to end, calling the function argument on the `data` of each node.

Exercise				| ETA
---------------- -------|----------
[ft_list_foreach](https://github.com/lifeBalance/c_exam/blob/main/04/ft_list_foreach/ft_list_foreach.c)		| 5 minutes

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_list_foreach/subject.en.txt).


Even though the **subject** asks us to apply the function argument as:
```c
(*f)(list_ptr->data);
```

I find that syntax quite awkward, and prefer to do it as:
```c
f(list_ptr->data);
```

The reason why the line above works, it's that a **bare function name** is already **function pointer**, which is **dereferenced** when we write the parentheses right after it (similar to how square brackets work with array names).

> The exercise itself can be finished in a **couple of minutes** if you take your time to understand how linked-lists (and function pointers) work.

There's more work involved writing the functions to create nodes, append nodes, and print a list, than for the `ft_list_foreach` itself. Honestly, the formers should be second nature.

## The header
The `t_list` type definition must be put in a **header file** named `ft_list.h`. This header must be included both in the `ft_list_foreach.c` and in `main.c` (if we want to test the whole thing) 

> Don't forget to push the header too!

The **include guard** on the header itself is a nice addition ;-)

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./lists.md
[next]: ./ft_list_remove_if.md