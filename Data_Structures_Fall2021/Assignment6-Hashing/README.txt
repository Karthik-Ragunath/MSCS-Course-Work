Compilation Details

g++ --version
Configured with: --prefix=/Library/Developer/CommandLineTools/usr --with-gxx-include-dir=/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/c++/4.2.1
Apple clang version 12.0.5 (clang-1205.0.22.11)
Target: arm64-apple-darwin20.6.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin

Should run with default c++ compilers in Ubuntu 16+

====================================================================================

Hashing

The program needs four inputs:
1. input count
2. input type (1 for reading from file and 0 for inputting manually)
3. enter inputs manually (if 0 is specified as input type)
4. table size

Once the input is given, program executes and inputs the strings into hash table and in the meantime, we also keep a count of collisions.

We print collisions before we resize the hash table each time and also total collisions at the end.
====================================================================================
