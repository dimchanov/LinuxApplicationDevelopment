AM_CFLAGS = -Wall


all-local: doxygen-clean doxygen-doc

doxygen-clean:
	rm -rf doxygen-doc

doxygen-doc: doxygen-clean
	doxygen Doxyfile

install-data-local:
	mkdir -p $(DESTDIR)/$(docdir)
	cp -a doxygen-doc/html $(DESTDIR)/$(docdir)

http: doxygen-doc
	python3 -m http.server --directory $</html 5000


bin_PROGRAMS=guess_number

pkgdata_DATA = ./ru/LC_MESSAGES/guess_number.mo


ru/LC_MESSAGES/guess_number.mo: ru.po
	mkdir -p `dirname $@`
	msgfmt $< -o $@

ru.po: translate.pot
	msgmerge -U $@ $<

translate.pot: guess_number.pot guess_number.c
	xgettext guess_number.c -o translate.new.pot
	cp guess_number.pot $@
	msgmerge -U $@ translate.new.pot

gitclean:
	git clean -df
	rm -f *.o *~ o.*
