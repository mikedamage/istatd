#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.61])
AC_INIT([istat], [0.5.3], [http://code.google.com/p/istat/issues/entry])
AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE

AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_INSTALL

AC_MSG_CHECKING([if the compiler supports -Wall])
oldcppflags="$CPPFLAGS"
CPPFLAGS="$CPPFLAGS -Wall"
AC_COMPILE_IFELSE([int main(void) { return 0; }],[
	AC_MSG_RESULT([yes])
],[
	AC_MSG_RESULT([no])
	CPPFLAGS="$oldcppflags"
])

AC_MSG_CHECKING([if the linker supports -rdynamic])
oldldflags="$LDFLAGS"
LDFLAGS="$LDFLAGS -rdynamic"
AC_LINK_IFELSE([int main(void) { return 0; }],[
	AC_MSG_RESULT([yes])
],[
	AC_MSG_RESULT([no])
	LDFLAGS="$oldldflags"
])

# Checks for libraries.
AC_CHECK_LIB([dl], [dlopen],,[
	AC_CHECK_FUNC([dlopen],,[
		AC_MSG_ERROR([cannot find a suitable dlopen() implementation])
	])
])
AC_CHECK_PROG([XML2_CONFIG],[xml2-config],[xml2-config])
if test x"$XML2_CONFIG" = x"" ; then
	AC_MSG_ERROR([cannot find xml2-config: depending on your operating system you may need to install a '-dev' package for libxml2])
fi
LIBS="$LIBS `$XML2_CONFIG --libs`"
CPPFLAGS="$CPPFLAGS `$XML2_CONFIG --cflags`"
AC_CHECK_HEADER([libxml/parser.h],,[
	AC_MSG_ERROR([xml2-config was located, but the header files could not be found])
])
AC_CHECK_FUNC([xmlFileOpen],[
	AC_DEFINE_UNQUOTED([HAVE_LIBXML2],[1],[Define to 1 if you have the `xml2' library (-lxml2).])
],[
	AC_MSG_ERROR([xml2-config was located, but a test program linking against -lxml2 could not be built])
])
AC_CHECK_LIB([kstat],[kstat_open])
# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h mntent.h netdb.h stdlib.h string.h paths.h sys/socket.h sys/statfs.h sys/statvfs.h sys/mnttab.h sys/loadavg.h kstat.h errno.h sys/sysinfo.h sys/processor.h sys/swap.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_GETMNTENT
AC_CHECK_FUNCS([gethostbyname getmntent inet_ntoa memset mkdir select socket strerror statvfs setmntent getloadavg swapctl])

# Try to figure out which type of mntent structure we're dealing with
AC_CHECK_MEMBER([struct mnttab.mnt_special],[AC_DEFINE_UNQUOTED([USE_STRUCT_MNTTAB],[1],[define to use 'struct mnttab'])],,[
#include <stdio.h>
#include <sys/mnttab.h>
])
AC_CHECK_MEMBER([struct mntent.mnt_fsname],[AC_DEFINE_UNQUOTED([USE_STRUCT_MNTENT],[1],[define to use 'strut mntent'])],,[
#include <stdio.h>
#include <mntent.h>
])
AC_CHECK_MEMBER([struct statvfs.f_frsize],[AC_DEFINE_UNQUOTED([HAVE_STATVFS_FRSIZE],[1],[define if statvfs has the f_frsize member])],,[
#include <sys/types.h>
#include <sys/statvfs.h>
])
AC_MSG_CHECKING([for default location of configuration file])
test x"$prefix" = x"NONE" && prefix="$ac_default_prefix"
configpath=`eval echo "$sysconfdir"/istat.conf`
AC_MSG_RESULT([$configpath])
AC_DEFINE_UNQUOTED([CONFIG_FILE_PATH],["${configpath}"],[default location of the configuration file])

AC_CONFIG_FILES([
Makefile
resource/Makefile
])
AC_OUTPUT