PORTNAME=	kdnssd
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	dns kde kde-frameworks

COMMENT=	Network service discovery using Zeroconf
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/include/avahi-common/defs.h:net/avahi-app

USES=		cmake kde:6 qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base tools

.include <bsd.port.mk>
