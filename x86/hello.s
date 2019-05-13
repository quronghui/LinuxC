# PURPOSE: This program finds the maximum number of a
# set of data items.
#
# VARIABLES: The registers have the following uses:
#
# %edi - Holds the index of the data item being examined
# %ebx - Largest data item found
# %eax - Current data item
#
# The following memory locations are used:
#
# data_items - contains the item data. A 0 is used
# to terminate the data
#
.section .data
.section .text
.globl _start
_start:
movl $1, %eax # this is the linux kernel command
# number (system call) for exiting
# a program
movl $4, %ebx
 # this is the status number we will
# return to the operating system.
# Change this around and it will
# return different things to
# echo $?
int $0x80
# this wakes up the kernel to run
# the exit command
