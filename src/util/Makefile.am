AM_CPPFLAGS = \
	-D__BUILDING_CVC4LIB \
	-I@builddir@/.. -I@srcdir@/../include -I@srcdir@/..
AM_CXXFLAGS = -Wall -Wno-unknown-pragmas $(FLAG_VISIBILITY_HIDDEN)

noinst_LTLIBRARIES = libutil.la


# Do not list built sources (like integer.h, rational.h) here!
# Rather, list them under BUILT_SOURCES, and their .in versions under
# EXTRA_DIST.  Otherwise, they're packaged up in the tarball, which is
# no good---they belong in the configured builds/ directory.  If they
# end up in the source directory, they build the cvc4 that was
# configured at the time of the "make dist", which (1) may not be the
# configuration that the user wants, and (2) might cause link errors.
libutil_la_SOURCES = \
	Makefile.am \
	Makefile.in \
	abstract_value.cpp \
	abstract_value.h \
	bin_heap.h \
	bitvector.cpp \
	bitvector.h \
	bool.h \
	cardinality.cpp \
	cardinality.h \
	channel.h \
	debug.h \
	dense_map.h \
	divisible.cpp \
	divisible.h \
	floatingpoint.cpp \
	gmp_util.h \
	hash.h \
	index.cpp \
	index.h \
	maybe.h \
	ostream_util.cpp \
	ostream_util.h \
	proof.h \
	random.cpp \
	random.h \
	regexp.cpp \
	regexp.h \
	resource_manager.cpp \
	resource_manager.h \
	result.cpp \
	result.h \
	safe_print.cpp \
	safe_print.h \
	sampler.cpp \
	sampler.h \
	sexpr.cpp \
	sexpr.h \
	smt2_quote_string.cpp \
	smt2_quote_string.h \
	statistics.cpp \
	statistics.h \
	statistics_registry.cpp \
	statistics_registry.h \
	tuple.h \
	unsafe_interrupt_exception.h \
	utility.h

BUILT_SOURCES = \
	floatingpoint.h \
	integer.h \
	rational.h

if CVC4_CLN_IMP
libutil_la_SOURCES += \
	rational_cln_imp.cpp \
	integer_cln_imp.cpp
endif
if CVC4_GMP_IMP
libutil_la_SOURCES += \
	rational_gmp_imp.cpp \
	integer_gmp_imp.cpp
endif


EXTRA_DIST = \
	bitvector.i \
	bool.i \
	cardinality.i \
	divisible.i \
	floatingpoint.h.in \
	floatingpoint.i \
	hash.i \
	integer.h.in \
	integer.i \
	integer_cln_imp.cpp \
	integer_cln_imp.h \
	integer_gmp_imp.cpp \
	integer_gmp_imp.h \
	proof.i \
	rational.h.in \
	rational.i \
	rational_cln_imp.cpp \
	rational_cln_imp.h \
	rational_gmp_imp.cpp \
	rational_gmp_imp.h \
	regexp.i \
	resource_manager.i \
	result.i \
	sexpr.i \
	statistics.i \
	tuple.i \
	unsafe_interrupt_exception.i


DISTCLEANFILES = \
	floatingpoint.h.tmp \
	integer.h.tmp \
	rational.h.tmp \
	floatingpoint.h \
	integer.h \
	rational.h
