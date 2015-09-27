/*	$NetBSD: hd64461uartvar.h,v 1.6 2008/04/28 20:23:22 martin Exp $	*/

/*-
 * Copyright (c) 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by UCHIYAMA Yasushi.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _HPCSH_DEV_HD64461UARTVAR_H_
#define _HPCSH_DEV_HD64461UARTVAR_H_

extern int hd64461uart_kgdb_init(void);

#define HD64461COM_TX_BUSY()						\
	while ((*(volatile uint8_t *)HD64461_ULSR_REG8 & LSR_TXRDY) == 0)

#define HD64461COM_PUTC(c)						\
do {									\
	HD64461COM_TX_BUSY();						\
	*(volatile uint8_t *)HD64461_UTBR_REG8 = c;			\
	HD64461COM_TX_BUSY();						\
} while (/*CONSTCOND*/0)

#define HD64461COM_PRINT(s)						\
do {									\
	char *__s = (char *)(s);					\
	int __i;							\
	for (__i = 0; __s[__i] != '\0'; __i++) {			\
		char __c = __s[__i];					\
		if (__c == '\n')					\
			HD64461COM_PUTC('\r');				\
		HD64461COM_PUTC(__c);					\
	}								\
} while (/*CONSTCOND*/0)

#endif /* !_HPCSH_DEV_HD64461UARTVAR_H_ */
