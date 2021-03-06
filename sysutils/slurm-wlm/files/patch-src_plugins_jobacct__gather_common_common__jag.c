--- src/plugins/jobacct_gather/common/common_jag.c.orig	2019-09-13 13:35:31 UTC
+++ src/plugins/jobacct_gather/common/common_jag.c
@@ -250,6 +250,12 @@ static int _get_sys_interface_freq_line(uint32_t cpu, 
 	return 0;
 }
 
+
+/*
+ * Check for lightweight processes (POSIX threads)
+ * Should be rewritten for FreeBSD so it doesn't depend on /proc
+ */
+
 static int _is_a_lwp(uint32_t pid)
 {
 	char *filename = NULL;
@@ -258,6 +264,10 @@ static int _is_a_lwp(uint32_t pid)
 	ssize_t n;
 	char *tgids = NULL;
 	pid_t tgid = -1;
+
+	// Disable check for now, this will only skew process accounting
+	// slightly by including threads
+	return 0;
 
 	xstrfmtcat(filename, "/proc/%u/status", pid);
 
