all: main

%:
	latexmk -pdfxe $<

clean:
	latexmk -c

cleanall:
	latexmk -C
	rm -rf _minted-*
