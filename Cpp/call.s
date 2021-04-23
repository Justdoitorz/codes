	.file	"call.cpp"
	.text
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
	.text
	.globl	__Z3fooii
	.def	__Z3fooii;	.scl	2;	.type	32;	.endef
__Z3fooii:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	addl	%edx, %eax
	popl	%ebp
	ret
	.globl	__Z3barii@8
	.def	__Z3barii@8;	.scl	2;	.type	32;	.endef
__Z3barii@8:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	subl	12(%ebp), %eax
	popl	%ebp
	ret	$8
	.def	___main;	.scl	2;	.type	32;	.endef
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$36, %esp
	call	___main
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	__Z3fooii
	movl	%eax, -12(%ebp)
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	call	__Z3barii@8
	subl	$8, %esp
	movl	%eax, -16(%ebp)
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L9
	cmpl	$65535, 12(%ebp)
	jne	L9
	movl	$__ZStL8__ioinit, (%esp)
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___dso_handle, 8(%esp)
	movl	$__ZStL8__ioinit, 4(%esp)
	movl	$__ZNSt8ios_base4InitD1Ev, (%esp)
	call	___cxa_atexit
L9:
	nop
	leave
	ret
	.def	__GLOBAL__sub_I__Z3fooii;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z3fooii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$65535, 4(%esp)
	movl	$1, (%esp)
	call	__Z41__static_initialization_and_destruction_0ii
	leave
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z3fooii
	.ident	"GCC: (GNU) 7.3.0"
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	___cxa_atexit;	.scl	2;	.type	32;	.endef
