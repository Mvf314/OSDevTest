/* Set up init section */

.section .init
.global _init
.type _init, @function
_init:
	# Push stack base pointer
	push %ebp
	# Set stack pointer to base pointer
	movl %esp, %ebp
	/* gcc will put crtbegin.o .init contents here */

.section .fini
.global _fini
.type _fini, @function
_fini:
	# Same thing here
	push %ebp
	movl %esp, %ebp
	/* gcc will put crtbegin .fini contents here */
