# cycle_detector
In this exercise we have to write a **function** that that takes a [linked list](https://en.wikipedia.org/wiki/Linked_list) as argument, and check if it contains any cycles. Returns `1` if yes, `0` otherwise.

> Check here the [subject](https://github.com/lifeBalance/c_exam/blob/main/05/cycle_detector/subject.en.txt) of the exercise for more information.

This is a classic algorithmic problem of [cycle detection](https://en.wikipedia.org/wiki/Cycle_detection) but applied to **linked lists**. There are several algorithms to solve it, but I stuck to a solution that I think it's using the [tortoise and hare](https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare) approach.

It consists on setting two pointers that at the beginning point to the head of the list. Then, in a loop we make advance each pointer at different speeds:

* The **turtle** jumps nodes one by one.
* The **hare** jumps nodes by two.

If at some point the address of both is the same, it means we have a **loop**, and our function returns `1`. If we exit the loop without finding a cycle, we return `0`.

> The interesting part is the exit condition `hare && hare->next`, which requires pen a paper and a bit of time to understand.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../README.md
[back]: ./print_memory.md
[next]: ../index.md