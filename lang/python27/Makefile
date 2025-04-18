PORTNAME=	python
DISTVERSION=	${PYTHON_DISTVERSION}
PORTREVISION=	4
CATEGORIES=	lang python
MASTER_SITES=	PYTHON/ftp/python/${DISTVERSION}
PKGNAMESUFFIX=	27
DISTNAME=	Python-${DISTVERSION}
DIST_SUBDIR=	python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Interpreted object-oriented programming language
WWW=		https://www.python.org/

LICENSE=	PSFL

DEPRECATED=	EOLed upstream
EXPIRATION_DATE=	2020-12-31

USES=		cpe ncurses pathfix pkgconfig readline shebangfix ssl tar:xz tk:86
PATHFIX_MAKEFILEIN=	Makefile.pre.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
python_CMD=	${PREFIX}/bin/python${PYTHON_DISTVERSION:R}
SHEBANG_FILES=	Lib/lib2to3/pgen2/*.py Lib/lib2to3/tests/*.py Lib/lib2to3/tests/data/*.py \
		Lib/idlelib/*.py Lib/encodings/*.py Lib/test/*.py Lib/UserString.py \
		Lib/base64.py Lib/cProfile.py Lib/keyword.py Lib/mimify.py Lib/pdb.py \
		Lib/platform.py Lib/profile.py Lib/pydoc.py Lib/quopri.py Lib/smtpd.py \
		Lib/smtplib.py Lib/symbol.py Lib/tabnanny.py Lib/timeit.py Lib/trace.py \
		Lib/uu.py Lib/webbrowser.py

CONFIGURE_ARGS+=	--enable-shared
CONFIGURE_ENV+=		ac_cv_opt_olimit_ok=no OPT=""				# Null out OPT to respect user CFLAGS and remove optimizations

INSTALL_TARGET=		altinstall						# Don't want cloberring of unprefixed files

TEST_TARGET=		buildbottest
TEST_ARGS=		TESTOPTS=-j${MAKE_JOBS_NUMBER}

MAKE_ARGS+=		INSTALL_SHARED="${INSTALL_LIB}"				# Strip shared library

PLIST_SUB=		ABI=${ABIFLAGS} \
			DISTVERSION=${DISTVERSION} \
			OSMAJOR=${OSVERSION:C/([0-9]*)[0-9]{5}/\1/}		# For plat-freebsd* in pkg-plist. https://bugs.python.org/issue19554

OPTIONS_DEFINE=		DEBUG IPV6 LIBFFI NLS PYMALLOC THREADS
OPTIONS_DEFAULT=	LIBFFI PYMALLOC THREADS UCS4
OPTIONS_SINGLE=		UNICODE
OPTIONS_SINGLE_UNICODE=	UCS2 UCS4
OPTIONS_SUB=		yes

LIBFFI_DESC=	Use libffi from ports instead of bundled version
NLS_DESC=	Enable gettext support for the locale module
UCS2_DESC=	Enable UCS2 Unicode Strings
UCS4_DESC=	Enable UCS4 Unicode Strings
PYMALLOC_DESC=	Enable specialized mallocs

DEBUG_CONFIGURE_WITH=	pydebug
IPV6_CONFIGURE_ENABLE=	ipv6
LIBFFI_CONFIGURE_ON=	--with-system-ffi
LIBFFI_LIB_DEPENDS=	libffi.so:devel/libffi

# Use CPPFLAGS over CFLAGS due to -I ordering, causing elementtree and pyexpat
# to break in Python 2.7, or preprocessor complaints in Python >= 3.3
# Upstream Issue: https://bugs.python.org/issue6299
NLS_USES=		gettext
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LIBS=		-L${LOCALBASE}/lib -lintl
NLS_CONFIGURE_ENV_OFF=	ac_cv_lib_intl_textdomain=no ac_cv_header_libintl_h=no

PYMALLOC_CONFIGURE_WITH=	pymalloc

THREADS_CONFIGURE_WITH=	threads
THREADS_LDFLAGS=	-lpthread

UCS2_CONFIGURE_ON=	--enable-unicode=ucs2
UCS4_CONFIGURE_ON=	--enable-unicode=ucs4

.include "${.CURDIR}/Makefile.version"
.include <bsd.port.options.mk>

# https://bugs.python.org/issue22521
# https://bugs.python.org/issue23042
.if !${PORT_OPTIONS:MLIBFFI} && ${ARCH} == i386
BROKEN=	You must use libffi from ports on i386. Enable the LIBFFI option
.endif

.if ${ARCH} == i386
PLIST_SUB+=	X86_ONLY=""
.else
PLIST_SUB+=	X86_ONLY="@comment "
.endif

.if ${ARCH:M*64*}
PLIST_SUB+=	32BIT_ONLY="@comment "
.else
PLIST_SUB+=	32BIT_ONLY=""
.endif

# See https://bugs.freebsd.org/115940 and https://bugs.freebsd.org/193650
.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
PLIST_SUB+=	NO_NIS="@comment "
.else
PLIST_SUB+=	NO_NIS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/bin/python|${python_CMD}|' \
		${WRKSRC}/Lib/cgi.py
	@${REINPLACE_CMD} -e \
		's,/usr/doc/python-docs-,${PREFIX}/share/doc/python,g' \
		${PATCH_WRKSRC}/Lib/pydoc.py

.if !exists(/usr/bin/ypcat) || defined(WITHOUT_NIS)
	@${REINPLACE_CMD} -e 's/disabled_module_list =[^]]*/&, "nis"/' \
		${WRKSRC}/setup.py
.endif

# This is just a dirty hack for building with OpenSSL 3.0.0 and later
# There is no plain string OPENSSL_VERSION_NUMBER available in
# openssl/opensslv.h so setup.py just detects the string as 00000000
# However care should be taken for the OSVERSION. If OpenSSL 3.0.9
# lands later the OSVERSION string should be fixed accordingly
.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400092 && (${SSL_DEFAULT} == base || \
	${SSL_DEFAULT} == openssl || ${SSL_DEFAULT:Mopenssl3*} )
	@${REINPLACE_CMD} -e 's|00907000|00000000|' \
		${WRKSRC}/setup.py
.endif

post-install:
	for i in ${STAGEDIR}${PREFIX}/lib/python2.7/lib-dynload/*.so; do \
		${STRIP_CMD} $$i; done						# Strip shared extensions
# This code block exists for the qemu-user enabled cross build environment.
# When using this environment in poudriere, CC is not set to the default
# of /usr/bin/cc and a cross-compile toolchain is used.  We need to hand
# edit this so that the run time configuration for python matches what the
# FreeBSD base system provides.  sbruno 02Aug2017
.if ${CC} == /nxb-bin/usr/bin/cc
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python2.7/_sysconfigdata.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -m compileall -d ${PREFIX}/lib/python2.7 \
		${STAGEDIR}${PREFIX}/lib/python2.7/_sysconfigdata.py
	@cd ${WRKSRC} && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		./python -E -O -m compileall -d ${PREFIX}/lib/python2.7 \
		${STAGEDIR}${PREFIX}/lib/python2.7/_sysconfigdata.py
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/lib/python2.7/config/Makefile
.endif
	${INSTALL_DATA} ${WRKSRC}/Tools/gdb/libpython.py \
		${STAGEDIR}${PREFIX}/lib/libpython2.7.so.1-gdb.py

.include <bsd.port.mk>
