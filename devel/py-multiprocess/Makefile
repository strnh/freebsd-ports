PORTNAME=	multiprocess
DISTVERSION=	0.70.17
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Better multiprocessing and multithreading in python
WWW=		https://multiprocess.readthedocs.io/en/latest/ \
		https://github.com/uqfoundation/multiprocess

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dill>=0.3.9:devel/py-dill@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist pytest

NO_ARCH=	yes

TEST_WRKSRC=	${WRKSRC}/py${PYTHON_VER}
TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.mk>
