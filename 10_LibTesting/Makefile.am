SUBDIRS = src tests

gcov: check
	$(MAKE) $(MAKEFLAGS) -C src gcov

checklog: check
	cat tests/*.log

gitclean:
	git clean -df

