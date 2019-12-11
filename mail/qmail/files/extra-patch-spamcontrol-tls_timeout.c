--- tls_timeoutio.c.orig        2019-12-10 05:53:47.495339000 +0900
+++ tls_timeoutio.c     2019-12-10 05:56:57.740423000 +0900
@@ -75,10 +75,10 @@

   SSL_renegotiate(ssl);
   r = tls_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
-  if (r <= 0 || ssl->type == SSL_ST_CONNECT) return r;
+  if (r <= 0 || SSL_get_state(ssl) == SSL_ST_CONNECT ) return r;

   /* this is for the server only */
-  ssl->state = SSL_ST_ACCEPT;
+  SSL_set_accept_state(ssl);
   return tls_timeoutio(SSL_do_handshake, t, rfd, wfd, ssl, NULL, 0);
 }
