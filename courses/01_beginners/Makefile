handout:
	latexmk -pdfxe -shell-escape -jobname=handout -usepretex="\def\ishandout{handout}" $<

all: handout presentation

presentation:
	latexmk -pdfxe -shell-escape -jobname=presentation -usepretex="\def\ishandout{}" $<

clean:
	latexmk -c

cleanall:
	latexmk -C
	rm -rf _minted-*
