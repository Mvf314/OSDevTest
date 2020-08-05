.section .init
	/* gcc will put crtend.o .init here */
	# Retrieve stack base
	popl %ebp
	ret

.section .fini
	/* gcc will put crtend.o .fini here */
	# Same thing here
	popl %ebp
	ret
