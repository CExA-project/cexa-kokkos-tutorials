all: handout presentation

handout:
	latexmk -pdfxe -shell-escape -jobname=$@

presentation:
	latexmk -pdfxe -shell-escape -usepretex="\def\createHandout{}" -jobname=$@

clean:
	latexmk -c -jobname=handout
	latexmk -c -jobname=presentation
	latexmk -c

cleanall:
	latexmk -C -jobname=handout
	latexmk -C -jobname=presentation
	latexmk -C
	rm -rf _minted-*
