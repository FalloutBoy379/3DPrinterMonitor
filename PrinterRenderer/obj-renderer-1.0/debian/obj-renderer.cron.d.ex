#
# Regular cron jobs for the obj-renderer package
#
0 4	* * *	root	[ -x /usr/bin/obj-renderer_maintenance ] && /usr/bin/obj-renderer_maintenance
