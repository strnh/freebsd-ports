$FreeBSD $

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SPAMCONTROL_VERSION}
PORTREVISION=	
CATEGORIES=	mail
MASTER_SITES+=	http://www.fehcom.de/qmail/spamcontrol/:spamcontrol \
		LOCAL/bdrewery/qmail/:spamcontrol
PKGNAMESUFFIX=	-spamcontrol
DISTFILES=	${QMAIL_DIST} ${SPAMCONTROL_DIST}:spamcontrol
EXTRACT_ONLY=	${QMAIL_DIST}

COMMENT=	Qmail MTA with SpamControl patches

CONFLICTS=	*qmail-[0-9]* qmail-ldap-[0-9]* *qmail-mysql-[0-9]* *qmail-tls-[0-9]*

EXTRA_PATCHES+=	${MASTERDIR}/files/patch-install.c \
		${MASTERDIR}/files/patch-Makefile \
		${MASTERDIR}/files/patch-auto_uids-c-dist \
	        ${MASTERDIR}/files/extra-patch-spamcontrol-tls_timeout.c

# Distfiles
QMAIL_DIST=		${PORTNAME}-${QMAIL_VERSION}${EXTRACT_SUFX}
SPAMCONTROL_DIST=	spamcontrol-${SPAMCONTROL_VERSION}.tgz
SPAMCONTROL_VERSION=	2733

SLAVE_SPAMCONTROL=	yes

# Local overrides
MASTERDIR=	${.CURDIR}/../qmail
PATCHDIR=	${.CURDIR}/files
DESCR=		${.CURDIR}/pkg-descr

.include "${MASTERDIR}/Makefile"
