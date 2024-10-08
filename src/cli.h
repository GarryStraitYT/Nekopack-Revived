/* cli.h -- Code for providing a command-line interface.

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

#include <stdbool.h>
#include <stddef.h>

/* Identifiers for the mode of operation. */
enum {
    USAGE,
    HELP,
    VERSION,
    LIST,
    EXTRACT,
    CREATE,
};

/* Structure for storing options set from the command-line. */
struct params {
    bool    verbose;            /* Whether or not to output progress messages. */
    size_t  out_len;            /* Length of the output path string. */
    char   *out;                /* Path to extract files to. */
    int     mode;               /* Current mode of operation. */
    int     game;               /* Which encryption keys to use. */
    int     vararg_index;       /* Start index of paths in argv. */
};

struct params parse_args(int argc, char **argv);
void print_usage(char *progn);
void print_version(void);
void print_help(void);
