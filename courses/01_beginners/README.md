# Beginner course

This course is for beginners. It will teach you the basics of GPU programming and Kokkos. You will learn how to compile Kokkos, write your first Kokkos program using basic Kokkos data structures, parallel loops and reductions.

## How to compile

The slides use Beamer, a LaTeX package for creating presentations. To compile the slides, you need to have LaTeX installed on your system with the following packages: `latexmk`, `texlive-xetex` and `texlive-fonts-extra`.

Build simply with:

```sh
make
```

Or explicitly with:

```bash
xelatex -shell-escape main.tex
```
