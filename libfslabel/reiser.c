/* Copyright (c) 2009 William Tisäter.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The names of the author(s) of this software may not be used to endorse
 *    or promote products derived from this software without specific prior
 *    written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY 
 * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL
 * AUTHORS OF THIS SOFTWARE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS 
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "p_fslabel.h"

/* Murder-family filesystem labels */

#define REISER_OFFSET                  0x10000
#define REISER35_MAGIC                 "ReIsErFs"
#define REISER36_MAGIC                 "ReIsEr2Fs"
#define REISERJR_MAGIC                 "ReIsEr3Fs"
#define REISER40_MAGIC                 "ReIsEr4"

struct reiser_header
{
	/* Note that by 'unused' we mean 'unused by us' */
	uint32_t unused1;
	uint32_t unused2;
	uint32_t unused3;
	uint32_t unused4;
	uint32_t unused5;
	uint32_t unused6;
	uint32_t unused7[5];
	uint16_t unused8;
	uint16_t unused9[3];
	uint8_t magic[12];
	uint32_t unused10[5];
	uint8_t uuid[16];
	uint8_t label[16];
} __attribute__((__packed__));

struct reiser4_header
{
	/* Note that by 'unused' we mean 'unused by us' */
	uint8_t magic[16];
	uint16_t unused1[2];
	uint8_t uuid[16];
	uint8_t label[16];
	uint64_t unused2;
} __attribute__((__packed__));

int
fslabel__reiser_probe(fslabel_src_t *src, fslabel_t *dest)
{
	char lbuf[17];
	struct reiser_header header;
	struct reiser4_header header4;
	
	/*
	if(0 != fslabel__src_seek(src, EXT_OFFSET) ||
		0 != fslabel__src_readbuf(src, &header, sizeof(struct ext_header)))
		{
			return -1;
		}
	if(htons(header.magic) != EXT_MAGIC)
		{
			fprintf(stderr, "ext: expected 0x%04x, found 0x%04x\n", htons(header.magic), EXT_MAGIC);
			return 0;
		}
	memcpy(lbuf, header.label, 16);
	lbuf[16] = 0;
	fslabel__strlcpy(dest->fstype, "ext", sizeof(dest->fstype));
	fslabel__strlcpy(dest->label, lbuf, sizeof(dest->label));
	snprintf(dest->uuid, sizeof(dest->uuid), "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
		header.uuid[0], header.uuid[1], header.uuid[2], header.uuid[3],
		header.uuid[4], header.uuid[5],
		header.uuid[6], header.uuid[7],
		header.uuid[8], header.uuid[9],
		header.uuid[10], header.uuid[11], header.uuid[12], header.uuid[13], header.uuid[14], header.uuid[15]);
	*/
	return 1;
}
