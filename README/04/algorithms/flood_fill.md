# flood_fill
This exercise is about filling an area in a two-dimensional array of characters with another character. For example, if the **original array** looks like this:
```
  | 0 1 2 3 4 5 6 7
-------------------
0 | 1 1 1 1 1 1 1 1
1 | 1 0 0 0 1 0 0 1
2 | 1 0 0 1 0 0 0 1
3 | 1 0 1 1 0 0 0 1
4 | 1 1 1 0 0 0 0 1
```

And we're told to fill the area which begins at **row** `2`, **column** `2`, the resulting array should look like this
```
  | 0 1 2 3 4 5 6 7
-------------------
0 | 1 1 1 1 1 1 1 1
1 | 1 F F F 1 0 0 1
2 | 1 F F 1 0 0 0 1
3 | 1 F 1 1 0 0 0 1
4 | 1 1 1 0 0 0 0 1
```

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/flood_fill/subject.en.txt).

If you read the subject carefully, it seems to imply that if the `begin` point was `{5, 2}`, the area above should NOT be filled, since the bottom row is not surrounded by `1` characters. BUT, I've checked other people's exercises online (ones that claimed to have passed moulinette), and they all fill the area.

## To push or not to push
In this exercise, the subject gives us the code of `main.c`, and we're supplied with a header file named `t_point.h`, which contains the `t_point` type defininition. In the source code of `main` we can also see that a couple of headers named `test_functions.h` and another one named `flood_fill.h` are also used.

> As with some other projects in 42, is anally important to be careful about what we push to the remote repository.

* Files that we must **submit**:

    * `test_functions.h`
    * `test_functions.c`
    * `flood_fill.h`
    * `flood_fill.c`

* Files that **SHOULD NOT** be **submitted**:

    * `t_point.h`
    * `main.c`

## Test Functions
If we check the supplied `main.c`, we can see there are two function calls:

* `make_area`: which returns a two-dimensional array or characters (`char **`), and takes in another two-dimensional array or characters (`zone`).

* `print_tab`: it's a simple function that takes a two-dimensional array or characters, and prints it to **stdout**. This function doesn't need a size for any of the array dimensions, because `make_area` is supposed to **null-terminate** the array itself, as well as each of the string arrays it contains.

* `putc`: which is a really simple function that prints a character using `write`. Note that this function is included in `stdio.h` header, which is **not** at the top of `main.c`, which means that we have to supply our own definition.

> Even though the `make_area` function doesn't take a size argument, we need to pass one, otherwise there's no way to know how many strings the two-dimensional array contains. I chose to pass `size` (a `t_point`).

The three functions above go in the `test_functions.c` file. Their prototypes go in the `test_functions.h` file.

> Don't forget to `push` the `flood_fill.h` header, which must contain the prototype of our main `flood_fill` function and also the `t_point.h` header (since the 2nd and 3rd arguments of `flood_fill` are `t_point`).

## Flood fill: Iterative
The **iterative version** of `flood_fill` will contain two helper functions:

* `fill_row`: which takes the array of strings and the point where we must begin to fill the area. This function uses two loops (one after another) to fill the **columns** at the `begin.y` row, to the left and to the right.

* `fill_col`: which takes the array of strings and the point where we must begin to fill the area. This function uses two loops (one after another) to fill the **rows** at the `begin.x` column, upwards and downwards.

The main function, `flood_fill` starts by calling the two aforementioned helpers in order to fill the **row** and the **column** of the `begin` point (like a cross of `F`). Then, using the classical nested loop, iterates over the all the characters in the two-dimensional array of characters. Each time an `F` character is found, two calls to `fill_col` and `fill_row` are made.

> Don't forget to include the `flood_fill.h` header at the top of `flood_fill.c`. The helpers can (and probably should) be declared as `static`, since they're only used by `flood_fill`.

## Flood fill: Recursive
Once you've coded the iterative version of `flood_fill`, the recursive version is easy to understand; it's also way shorter to type, which in the exam front-line is something to consider.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./checkmate.md
[next]: ./moment.md