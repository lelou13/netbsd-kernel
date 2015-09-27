/*	$NetBSD: conf.c,v 1.5 2009/01/12 07:01:00 tsutsui Exp $	*/

#include <stand.h>
#include <ufs.h>
#include <dev_disk.h>

#include "libsa.h"

struct fs_ops file_system[] = {
	FS_OPS(ufs),
};
int nfsys = 1;

struct devsw devsw[] = {
	{ "disk", disk_strategy, disk_open, disk_close, disk_ioctl },
};
int ndevs = 1;

int
main(void)
{

	xxboot_main("ufsboot");

	return 0;
}
