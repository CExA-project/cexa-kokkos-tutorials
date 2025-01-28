handout:
	latexmk -pdfxe -shell-escape -jobname=handout $<

presentation:
	latexmk -pdfxe -shell-escape -usepretex="\def\createHandout{}" -jobname=presentation $<

all: handout presentation

clean:
	latexmk -c -jobname=handout
	latexmk -c -jobname=presentation

cleanall:
	latexmk -C -jobname=handout
	latexmk -C -jobname=presentation
	rm -rf _minted-*
