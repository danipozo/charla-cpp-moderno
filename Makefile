all: presentacion.md
	pandoc -t beamer --slide-level=3 presentacion.md -o presentacion.pdf

