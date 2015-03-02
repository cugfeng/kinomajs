/*
     Copyright (C) 2010-2015 Marvell International Ltd.
     Copyright (C) 2002-2010 Kinoma, Inc.

     Licensed under the Apache License, Version 2.0 (the "License");
     you may not use this file except in compliance with the License.
     You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

     Unless required by applicable law or agreed to in writing, software
     distributed under the License is distributed on an "AS IS" BASIS,
     WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
     See the License for the specific language governing permissions and
     limitations under the License.
*/
#if !FSK_NO_MD5
#include "cryptTypes.h"
#include "rfc1321.h"

static const UInt32 md5_k[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee, 0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be, 0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa, 0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed, 0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c, 0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05, 0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039, 0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1, 0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391
};

static UInt32 md5_iv[] = {
	0x67452301,
	0xefcdab89,
	0x98badcfe,
	0x10325476,
};

static inline UInt32 rotl(UInt32 n, int k)
{
	return (n << k) | (n >> (32-k));
}
#define F(x,y,z) (z ^ (x & (y ^ z)))
#define G(x,y,z) (y ^ (z & (y ^ x)))
#define H(x,y,z) (x ^ y ^ z)
#define I(x,y,z) (y ^ (x | ~z))
#define R1(a, b, c, d, i, s)	(a = b + rotl(a + F(b, c, d) + W[i] + md5_k[i], s))
#define R2(a, b, c, d, i, s)	(a = b + rotl(a + G(b, c, d) + W[(5*i + 1) % 16] + md5_k[i], s))
#define R3(a, b, c, d, i, s)	(a = b + rotl(a + H(b, c, d) + W[(3*i + 5) % 16] + md5_k[i], s))
#define R4(a, b, c, d, i, s)	(a = b + rotl(a + I(b, c, d) + W[7*i % 16] + md5_k[i], s))

void
md5_create(struct md5 *s)
{
	int i;

	s->len = 0;
	for (i = 0; i < MD5_NUMSTATE; i++)
		s->state[i] = md5_iv[i];
}

static void
md5_process(struct md5 *s, const UInt8 *blk)
{
	UInt32 W[16], a, b, c, d, w;
	int i;

	for (i = 0; i < 16; i++) {
		w = *blk++;
		w |= *blk++ << 8;
		w |= *blk++ << 16;
		w |= *blk++ << 24;
		W[i] = w;
	}
	a = s->state[0];
	b = s->state[1];
	c = s->state[2];
	d = s->state[3];

	i = 0;
	while (i < 16) {
		R1(a, b, c, d, i, 7); i++;
		R1(d, a, b, c, i, 12); i++;
		R1(c, d, a, b, i, 17); i++;
		R1(b, c, d, a, i, 22); i++;
	}
	while (i < 32) {
		R2(a, b, c, d, i, 5); i++;
		R2(d, a, b, c, i, 9); i++;
		R2(c, d, a, b, i, 14); i++;
		R2(b, c, d, a, i, 20); i++;
	}
	while (i < 48) {
		R3(a, b, c, d, i, 4); i++;
		R3(d, a, b, c, i, 11); i++;
		R3(c, d, a, b, i, 16); i++;
		R3(b, c, d, a, i, 23); i++;
	}
	while (i < 64) {
		R4(a, b, c, d, i, 6); i++;
		R4(d, a, b, c, i, 10); i++;
		R4(c, d, a, b, i, 15); i++;
		R4(b, c, d, a, i, 21); i++;
	}
	s->state[0] += a;
	s->state[1] += b;
	s->state[2] += c;
	s->state[3] += d;
}

void
md5_update(struct md5 *s, const void *data, UInt32 size)
{
	const UInt8 *p = data;
	UInt32 r = s->len % MD5_BLKSIZE;

	s->len += size;
	if (r > 0) {
		UInt32 n = MD5_BLKSIZE - r;
		if (size < n) {
			FskMemCopy(s->buf + r, p, size);
			return;
		}
		FskMemCopy(s->buf + r, p, n);
		size -= n;
		p += n;
		md5_process(s, s->buf);
	}
	for (; size >= MD5_BLKSIZE; size -= MD5_BLKSIZE, p += MD5_BLKSIZE)
		md5_process(s, p);
	FskMemCopy(s->buf, p, size);
}

void
md5_fin(struct md5 *s, UInt8 *dgst)
{
	UInt32 r = s->len % MD5_BLKSIZE;
	UInt64 l;
	UInt8 *p;
	int i;

	s->buf[r++] = 0x80;
	if (r > MD5_BLKSIZE - 8) {
		FskMemSet(s->buf + r, 0, MD5_BLKSIZE - r);
		md5_process(s, s->buf);
		r = 0;
	}
	FskMemSet(s->buf + r, 0, MD5_BLKSIZE - 8 - r);
	l = s->len * 8;
	p = &s->buf[MD5_BLKSIZE - 8];
	*p++ = l;
	*p++ = l >> 8;
	*p++ = l >> 16;
	*p++ = l >> 24;
	*p++ = l >> 32;
	*p++ = l >> 40;
	*p++ = l >> 48;
	*p++ = l >> 56;
	md5_process(s, s->buf);

	for (i = 0; i < MD5_NUMSTATE; i++) {
		UInt32 w = s->state[i];
		*dgst++ = w;
		*dgst++ = w >> 8;
		*dgst++ = w >> 16;
		*dgst++ = w >> 24;
	}
}
#endif /* !FSK_NO_MD5 */
