# The Bisection Method

In this exercise we will implement the bisection method. The bisection method requires a function
`f` with the following signature:

```c
double f(double);
```

that we assume to be continuous. I am sure there are more Mathematical conditions to keep in mind, but
for the current exercise, let´s just assume that `f(x)` is continuous for all `x` real.

The bisection method searches the root of `f(x) = 0` given an interval `[a, b]` such that `f(a)f(b) < 0`.
Check for more details [here](https://en.wikipedia.org/wiki/Bisection_method).
