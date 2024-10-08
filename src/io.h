/* io.h -- Code for file and memory I/O.

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

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>

/* Internal enumerable type for representing the location of a memory
   segment. Used for freeing and unmapping purposes, if necessary. */
enum _location {
    HEAP,
};

/* Structure to emulate a stream of data that maintains a current
   position. The structure additionally maintains a `length` variable
   containing the stream's length. */
struct stream {
    size_t         len;     /* Length of the stream. */
    char           *_start; /* Pointer to the stream's start. */
    char           *_cur;   /* Pointer to the current position. */
    enum _location _loc;    /* Location of the stream in memory. */
};

/* Allocates `len` bytes of non-zeroed memory and returns a new stream
   structure pointing to it, or NULL if any allocations fail. The stream
   returned is guaranteed to be positioned at the beginning. */
struct stream *stream_new(size_t len);

/* Copies `n` bytes from `s` into a new stream structure, returning NULL
   if any allocations fail. The stream returned is guaranteed to be
   positioned at the beginning. */
struct stream *stream_clone(struct stream *s, size_t n);

/* Maps the file at the given `path` into a stream structure, returning
   NULL if the path does not exist or if any allocations fail. The
   stream returned is guaranteed to be positioned at the beginning. */
struct stream *stream_from_file(char *path);

/* Called to free memory associated with the given stream, as well as
   the stream structure itself. */
void stream_free(struct stream *s);

/* Copies `n` bytes from the given stream into the memory area specified
   by `dest`. The stream's cursor is advanced appropriately. */
void stream_read(void *dest, struct stream *s, size_t n);

/* Copies `n` bytes into the given stream from the memory area specified
   by `src`. The stream's cursor is advanced appropriately. */
void stream_write(struct stream *s, void *src, size_t n);

/* Increases the length of `s` by `n` bytes. */
void stream_expand(struct stream *s, size_t n);

/* Concatenates the contents of `src` onto `dst`. */
void stream_concat(struct stream *dst, struct stream *src, size_t n);

/* Dumps the contents of `s` into the file specified by `fp`. */
void stream_dump(FILE *fp, struct stream *s, size_t n);

/* Applies an initial and primary key to the given stream, effectively
   encrypting or decrypting it. */
void stream_xor(struct stream *s, uint8_t initial, uint8_t primary);

/* Obtains the current value of the stream's position indicator. */
size_t stream_tell(struct stream *s);

/* Sets the stream's position indicator to the given `pos`. A `whence`
   value of SEEK_SET indicates seeking relative to the beginning of the
   file, SEEK_CUR indicates seeking relative to the current position,
   and SEEK_END indicates seeking from the end of the file. */
void stream_seek(struct stream *s, size_t pos, int whence);

/* Sets the stream's position indicator to the beginning. */
void stream_rewind(struct stream *s);
