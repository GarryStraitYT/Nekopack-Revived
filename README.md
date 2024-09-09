# Nekopack-Revived
A tool for reverse engineering Nekopara (or Nekopara Modifications) .xp3 archives.
Original Nekopack is Copyright (C) 2017 Jakob Kreuze, All Rights Reserved.
This fork/revival is to make it able to be compiled again, make it able to be run on Windows, and remove bugs/vulnerabilities. This is also being made as a learning/practicing experience for C coding.

# CONTENTS OF ORIGINAL README.MD::
Nekopack is a tool for extracting game data from Nekopara's XP3 archives. It was
the result of a month-long effort to reverse engineer the archive format used by
Nekopara.

Nekopack is free software, licensed under the [GNU General Public
License.](http://gnu.org/licenses/gpl.html)

## Compilation

Nekopack can be compiled on Linux by running `make` from the repository's root
directory.

*BSD users will have to install and run `gmake` to build Nekopack.

The test suite is run with `make test` or `gmake test`, depending on your
platform.

You can add specific flags to the Makefile with `USER_CFLAGS` and/or
`USER_LDFLAGS`.

## TODO

- Full unit testing, test static functions.
- Clean up `main.c`, move functions like `load_table` and `make_dirs` into more
  appropriate files.
- Clean up `create_archive`.
- Strict warnings.
- Game-compatible file encryption on created archives.

