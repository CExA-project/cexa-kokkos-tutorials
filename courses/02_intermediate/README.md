# Intermediate course

This intermediate course digs deeper in the Kokkos API.

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
