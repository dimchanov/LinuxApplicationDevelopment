#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([12_InstallPackaging], [1.0.0], [gse], [Guess_number])
AM_INIT_AUTOMAKE([foreign])
DX_INIT_DOXYGEN([guess_number])
AC_CONFIG_SRCDIR([src/guess_number.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h locale.h string.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale strcasecmp])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    Doxyfile
])
AC_OUTPUT
