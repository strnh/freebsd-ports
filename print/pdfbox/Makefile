PORTNAME=	pdfbox
PORTVERSION=	3.0.4
CATEGORIES=	print textproc java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTVERSION}/
DISTFILES=	${JAR_NAMES:S/$/-${PORTVERSION}.jar/}
EXTRACT_ONLY=	# none

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Java tool for working with PDF documents
WWW=		https://pdfbox.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	${JAVALIBDIR}/bcmail.jar:java/bouncycastle \
		${JAVALIBDIR}/commons-logging.jar:java/apache-commons-logging \
		${JAVALIBDIR}/commons-io.jar:devel/apache-commons-io

JAR_NAMES=	pdfbox fontbox preflight xmpbox pdfbox-tools pdfbox-debugger \
		pdfbox-app

USES=		cpe java
CPE_VENDOR=	apache

NO_BUILD=	yes
NO_ARCH=		yes

PLIST_FILES=	${JAR_NAMES:S/^/%%JAVAJARDIR%%\//:S/$/.jar/}

do-install:
	@${ECHO_MSG} -n ">> Installing JAR files in ${JAVAJARDIR}..."
	@${MKDIR} ${STAGEDIR}${JAVAJARDIR}
.for f in ${JAR_NAMES}
	${INSTALL_DATA} ${DISTDIR}/${f}-${PORTVERSION}.jar \
		${STAGEDIR}${JAVAJARDIR}/${f}.jar
.endfor
	@${ECHO_MSG} " [ DONE ]"

.include <bsd.port.mk>
