PORTNAME=	Graph
PORTVERSION=	0.9735
PORTEPOCH=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Graph, the Perl module for graph operations
WWW=		https://metacpan.org/release/Graph

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Heap>=0:devel/p5-Heap \
		p5-Set-Object>=1.40:devel/p5-Set-Object

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	skipv:0.20105

.include <bsd.port.mk>
