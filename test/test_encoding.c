/* test_encoding.c -- MinUnit test cases for encoding.c

   Copyright (C) 2017 Jakob Kreuze, All Rights Reserved.

   This file is part of Nekopack.

   Nekopack is free software: you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation, either version 3 of the License, or (at
   your option) any later version.

   Nekopack is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
   General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Nekopack. If not, see <http://www.gnu.org/licenses/>. */

#include <stdlib.h>
#include <string.h>

#include "encoding.h"

#include "minunit.h"


const char *test_decode_utf16le(void) {
    char *in = "\x41\x00\x42\x00\x43\x00\x00\x00", *out = malloc(8);
    memset(out, '\xff', 8);
    utf16le_decode(in, out, 8);
    mu_assert("[encoding] test_decode_utf16le: UTF16-LE decoding failure",
              !strcmp(out, "ABC"));
    free(out);
    return NULL;
}


const char *test_encode_utf16le(void) {
    char *in = "ABC", *out = malloc(8);
    memset(out, '\xff', 8);
    utf16le_encode(in, out, 3);
    mu_assert("[encoding] test_encode_utf16le: UTF16-LE encoding failure",
              !memcmp(out, "\x41\x00\x42\x00\x43\x00\x00\x00", 8));
    free(out);
    return NULL;
}
