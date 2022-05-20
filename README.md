# Gravity

This brilliantly named engine simulates Newtonian motion of planetary bodies using [Newton's law of
universal gravitation](https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation). The
main computations are done in C++ and the rendering is done in Python.

If you do a make run, you might not get a visually appealing animation, but I promise this uses the
formulae for Newtonian gravity and kinematics. You can double check for yourself in
[general.cpp](general.cpp). The scaling formula in [main.py](main.py) just finds the largest and
smallest locations in the entire simulation and sets that as the constant left, right, bottom and
top locations.

## Requirements

- `g++` Compiler
- `make`
- `pillow` Modern graphics library for python
- `python`

## TODO

In addition to using `grep -r TODO`, see [TODO.md](txt/TODO.md).

## Demos

See [Demos](txt/demos.md).
