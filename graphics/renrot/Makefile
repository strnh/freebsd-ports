PORTNAME=	renrot
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	ftp://download.gnu.org.ua/pub/release/${PORTNAME}/

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	Program to rename and rotate image files according to EXIF tags
WWW=		https://puszcza.gnu.org.ua/projects/renrot/

LICENSE=	ART20

BUILD_DEPENDS=	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 jpeg:run
USE_PERL5=	configure

PORTDOCS=	AUTHORS README README.russian ChangeLog NEWS TODO

OPTIONS_DEFINE=	IMAGEMAGICK DOCS
IMAGEMAGICK_DESC=	Image::Magick Perl module support

IMAGEMAGICK_USES=	magick:6,run

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
.for conf in colors.conf copyright.tag renrot.conf tags.conf
	${INSTALL_DATA} ${WRKSRC}/etc/${conf} \
		${STAGEDIR}${ETCDIR}/${conf}.sample
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
