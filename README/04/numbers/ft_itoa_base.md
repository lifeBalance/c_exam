# ft_itoa_base
This exercise is about writing a **function** that takes an integer and converts it to a **null-terminated** string using the specified **base**.

> Here you can check the [subject](https://github.com/lifeBalance/c_exam/blob/main/04/ft_itoa_base/subject.en.txt).

If **base** is `10` and value is **negative**, the resulting string is preceded with a **minus sign** (`-`). With any other base, value is always considered **unsigned**.

For this task all that I wrote for [ft_itoa](./ft_itoa.md) applies. The only difference is that we have to use the value of `base`, instead of hardcoding a `10`.

Even the **tricky part** changes minimally. We just include in the test condition a check for the `base` (it must be `10` in order to leave space for the `-` sign.

---
[:arrow_backward:][back] ║ [:house:][home] ║ [:arrow_forward:][next]

<!-- navigation -->
[home]: ../../../README.md
[back]: ./ft_itoa.md
[next]: ../index.md