PORTNAME=	ufal.udpipe
PORTVERSION=	1.2.0.3
PORTREVISION=	1
CATEGORIES=	textproc python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python bindings to UDPipe library for parsing universal treebanks
WWW=		https://ufal.mff.cuni.cz/udpipe

LICENSE=	MPL20
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=		mips mips64 powerpc powerpc64 powerpcspe
NOT_FOR_ARCHS_REASON=	Only little endian systems are supported!

USES=		compiler:c++11-lang python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
