# sort_int_tab
This exercise is about sorting an array of integers in **ascending order**.

> Here you can check the [subject]().

For this problem, I used several basic but inefficient algorithms:

## Stupid sort
My first was to pick a piece of paper and come up with the easiest way of sorting the array. I came up with a quite inefficient algorithm, which after a bit of google-fu, I could identify as  [stupid sort](https://sudonull.com/post/14880-Exchange-sorting).

![stupid sort](../img/stupid_sort.gif "stupid sort")

## Gnome sort
[Gnome sort](https://en.wikipedia.org/wiki/Gnome_sort) is slightly more efficient than **stupid sort**. Check the gif below:

![gnome sort](../img/gnome_sort.gif "gnome sort")

It's like **Stupid sort**, but instead of backing up the counter to the very beginning (`0` index), it backs up just **1 position**.

> Gnome and stupid sorting are quite inefficient, but imho excellent as an introduction to sorting algorithms. They are also really cute, and easy to grasp, since they only uses one loop.

## Bubble sort
[Bubble sort](https://en.wikipedia.org/wiki/Bubble_sort) is another basic one. Check the animation below:

![bubble sort](../img/bubble_sort.gif "bubble sort")

Basically we set up an **outer loop** which will increasingly decrease the size, and an inner loop that will compare pair of elements until we get to the end of the array.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./moment.md
[next]: ../index.md