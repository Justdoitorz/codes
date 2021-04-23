	.file	"main.cpp"
	.section	.text$printf,"x"
	.linkonce discard
	.globl	_printf
	.def	_printf;	.scl	2;	.type	32;	.endef
_printf:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	subl	$36, %esp
	leal	12(%ebp), %eax
	movl	%eax, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	___mingw_vprintf
	movl	%eax, %ebx
	movl	%ebx, %eax
	addl	$36, %esp
	popl	%ebx
	popl	%ebp
	ret
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
.lcomm __ZStL8__ioinit,1,1
__ZStL13allocator_arg:
	.space 1
__ZStL6ignore:
	.space 1
LC0:
	.ascii "Test(), %p\12\0"
	.section	.text$_ZN4TestC1Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4TestC1Ei
	.def	__ZN4TestC1Ei;	.scl	2;	.type	32;	.endef
__ZN4TestC1Ei:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	nop
	leave
	ret	$4
	.section .rdata,"dr"
LC1:
	.ascii "~Test:%p .. _a : %d\12\0"
	.section	.text$_ZN4TestD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4TestD1Ev
	.def	__ZN4TestD1Ev;	.scl	2;	.type	32;	.endef
__ZN4TestD1Ev:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	(%eax), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	nop
	leave
	ret
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "foo end., &t = %p, &o = %p,  &a = %p\12\0"
	.text
	.globl	__Z3foov
	.def	__Z3foov;	.scl	2;	.type	32;	.endef
__Z3foov:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	leal	-12(%ebp), %eax
	movl	$4, (%esp)
	movl	%eax, %ecx
	call	__ZN4TestC1Ei
	subl	$4, %esp
	movl	$6, (%esp)
	movl	8(%ebp), %ecx
	call	__ZN4TestC1Ei
	subl	$4, %esp
	movl	$2, -16(%ebp)
	leal	-16(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 8(%esp)
	leal	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	nop
	leal	-12(%ebp), %eax
	movl	%eax, %ecx
	call	__ZN4TestD1Ev
	nop
	movl	8(%ebp), %eax
	leave
	ret
.lcomm __ZGVZ3barvE1t,8,8
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZZ3barvE1t, %ecx
	call	__ZN4TestD1Ev
	leave
	ret
	.section	.text$_ZSt4moveIR4TestEONSt16remove_referenceIT_E4typeEOS3_,"x"
	.linkonce discard
	.globl	__ZSt4moveIR4TestEONSt16remove_referenceIT_E4typeEOS3_
	.def	__ZSt4moveIR4TestEONSt16remove_referenceIT_E4typeEOS3_;	.scl	2;	.type	32;	.endef
__ZSt4moveIR4TestEONSt16remove_referenceIT_E4typeEOS3_:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %eax
	popl	%ebp
	ret
	.section .rdata,"dr"
LC3:
	.ascii "&t = %p\12\0"
	.text
	.globl	__Z3barv
	.def	__Z3barv;	.scl	2;	.type	32;	.endef
__Z3barv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	movl	$__ZGVZ3barvE1t, %eax
	movzbl	(%eax), %eax
	testb	%al, %al
	jne	L11
	movl	$__ZGVZ3barvE1t, (%esp)
	call	___cxa_guard_acquire
	testl	%eax, %eax
	setne	%al
	testb	%al, %al
	je	L11
	movl	$5, (%esp)
	movl	$__ZZ3barvE1t, %ecx
	call	__ZN4TestC1Ei
	subl	$4, %esp
	movl	$__ZGVZ3barvE1t, (%esp)
	call	___cxa_guard_release
	movl	$___tcf_0, (%esp)
	call	_atexit
L11:
	movl	$__ZZ3barvE1t, 4(%esp)
	movl	$LC3, (%esp)
	call	_printf
	movl	$__ZZ3barvE1t, (%esp)
	call	__ZSt4moveIR4TestEONSt16remove_referenceIT_E4typeEOS3_
	leave
	ret
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC4:
	.ascii "before foo()\12\0"
LC5:
	.ascii "after foo()\12\0"
LC6:
	.ascii "heiheihei\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	andl	$-16, %esp
	subl	$32, %esp
	call	___main
	movl	$LC4, (%esp)
	call	_printf
	leal	16(%esp), %eax
	movl	%eax, (%esp)
	call	__Z3foov
	movl	$LC5, (%esp)
	call	_printf
	movb	$-1, 31(%esp)
	movl	$255, 24(%esp)
	movl	24(%esp), %eax
	movb	%al, 23(%esp)
	movsbl	31(%esp), %eax
	movl	%eax, 24(%esp)
	movzbl	23(%esp), %eax
	cmpb	31(%esp), %al
	jne	L14
	movl	$LC6, (%esp)
	call	_printf
L14:
	movl	$0, %ebx
	leal	16(%esp), %eax
	movl	%eax, %ecx
	call	__ZN4TestD1Ev
	movl	%ebx, %eax
	movl	-4(%ebp), %ebx
	leave
	ret
	.def	___tcf_1;	.scl	3;	.type	32;	.endef
___tcf_1:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitD1Ev
	leave
	ret
	.def	__Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
__Z41__static_initialization_and_destruction_0ii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$24, %esp
	cmpl	$1, 8(%ebp)
	jne	L19
	cmpl	$65535, 12(%ebp)
	jne	L19
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_1, (%esp)
	call	_atexit
L19:
	nop
	leave
	ret
	.def	__GLOBAL__sub_I__Z3foov;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z3foov:
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
	.long	__GLOBAL__sub_I__Z3foov
.lcomm __ZZ3barvE1t,4,4
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	___cxa_guard_acquire;	.scl	2;	.type	32;	.endef
	.def	___cxa_guard_release;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
