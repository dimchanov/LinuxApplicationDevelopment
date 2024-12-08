AM_CFLAGS = -Wall

bin_PROGRAMS=main tests

pkgdata_DATA = ./ru/LC_MESSAGES/guess_number.mo

main_SOURCES = main.c guess_number.c

tests_SOURCES = tests.c guess_number.c

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
	git clean -xdf
	rm -f *.o *~ o.*
