handout:
	latexmk -pdfxe -shell-escape -jobname=handout -usepretex="\def\ishandout{handout}" $<

presentation:
	latexmk -pdfxe -shell-escape -jobname=presentation -usepretex="\def\ishandout{}" $<

all: handout presentation

clean:
	latexmk -c -jobname=handout
	latexmk -c -jobname=presentation

cleanall:
	latexmk -C -jobname=handout
	latexmk -C -jobname=presentation
	rm -rf _minted-*
