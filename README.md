# Gravity

This brilliantly named engine simulates Newtonian motion of planetary bodies using [Newton's law of
universal gravitation](https://en.wikipedia.org/wiki/Newton%27s_law_of_universal_gravitation). The
main computations are done in C++ and the rendering is done in Python.

```
This program generates random particles (planets) and then uses the Newtonian equation of gravity to
simulate it over time. The data is given as JSON, which can then be used as input to the renderer
which is written in Python. (The render is not to scale, because seeing the planets is pretty
important to the utility of the simulation.)
```

If you do a `make run`, you might not get a visually appealing animation, but I promise this uses the
formulae for Newtonian gravity and kinematics. You can double check for yourself in
[general.cpp](general.cpp). The scaling formula in [main.py](main.py) just finds the largest and
smallest locations in the entire simulation and sets that as the constant left, right, bottom and
top locations.

## Requirements

- `g++` Compiler
- `make` For - you won't believe this - making the build
- `pillow` Modern graphics library for python
- `python` Running the renderer

## TODO

In addition to using `grep -r TODO`, see [TODO.md](txt/TODO.md).

## Demos

See [Demos](txt/demos.md).
