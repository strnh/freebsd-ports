PORTNAME=	libdatachannel
DISTVERSIONPREFIX=	v
DISTVERSION=	0.22.6
CATEGORIES=	www

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	WebRTC Data Channels, WebRTC Media Transport, and WebSockets library
WWW=		https://github.com/paullouisageneau/libdatachannel

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libsrtp2.so:net/libsrtp2

USES=		cmake compiler:c++17-lang ssl

USE_GITHUB=	yes
GH_ACCOUNT=	paullouisageneau
GH_TUPLE=	SergiusTheBest:plog:e21baecd4753f14da64ede979c5a19302618b752:SergiusTheBest_plog/deps/plog \
		sctplab:usrsctp:ebb18adac6501bad4501b1f6dccb67a1c85cc299:sctplab_usrsctp/deps/usrsctp \
		paullouisageneau:libjuice:70ba50c:paullouisageneau_libjuice/deps/libjuice \
		nlohmann:json:9cca280a4d0ccf0c08f47a99aa71d1b0e52f8d03:nlohmann_json/deps/json \
		cisco:libsrtp:a566a9cfcd619e8327784aa7cff4a1276dc1e895:cisco_libsrtp/deps/libsrtp
CMAKE_ON=	USE_SYSTEM_SRTP NO_EXAMPLES NO_TESTS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=       -Wno-error=unused-but-set-variable \
			   -Wno-error=strict-prototypes
.endif

do-test: # tests require dual stack to be enabled with 'sysctl net.inet6.ip6.v6only=0', at least one test is known to fail
	# tests fail (intermittently?): https://github.com/paullouisageneau/libdatachannel/issues/682
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DNO_TESTS:BOOL=OFF ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		./tests-${DISTVERSION:C/-.*//}

# installs lib/libjuice.a and lib/libusrsctp.a that would conflict with separately installed packages juice and usrsctp, see https://github.com/paullouisageneau/libdatachannel/issues/1277

.include <bsd.port.post.mk>
