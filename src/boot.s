# Set up multiboot header constants
.set ALIGN,	1<<0
.set MEMINFO,	1<<1
.set FLAGS,	ALIGN | MEMINFO
.set MAGIC,	0x1BADB002
.set CHECKSUM,	-(MAGIC + FLAGS)

# Load constants in header
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

# 16 KiB stack pre-initialization
.section .bss
.align 16
stack_bottom:
.skip 16384
stack_top:

# Kernel entry point
.section .text
.global _start
.type _start, @function
_start:
	# Set up stack
	mov $stack_top, %esp

	# Call high-level kernel
	call kernel_main
	
	# When HL kernel execution is finished, nothing more to do:
	cli	# Disable interrupts
1:	hlt	# Wait for interrupt (so do nothing, or loop on NMI)
	jmp 1b

# Set size of _start symbol
.size _start, . - _start

