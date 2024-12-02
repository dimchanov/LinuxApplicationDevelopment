AM_CFLAGS = -Wall

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
