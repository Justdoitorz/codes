	.file	"other.cpp"
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNKSt5ctypeIcE8do_widenEc
	.def	__ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
__ZNKSt5ctypeIcE8do_widenEc:
	movzbl	4(%esp), %eax
	ret	$4
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.section .rdata,"dr"
LC0:
	.ascii "A()\0"
LC1:
	.ascii "A::A(int a)\0"
	.text
	.p2align 4,,15
	.globl	__Z4funcv
	.def	__Z4funcv;	.scl	2;	.type	32;	.endef
__Z4funcv:
	pushl	%ebx
	subl	$24, %esp
	movl	$3, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L7
	cmpb	$0, 28(%ebx)
	je	L5
	movsbl	39(%ebx), %eax
L6:
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	movl	$11, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L7
	cmpb	$0, 28(%ebx)
	je	L8
	movsbl	39(%ebx), %eax
L9:
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	addl	$24, %esp
	popl	%ebx
	jmp	__ZNSo5flushEv
	.p2align 4,,10
L5:
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L6
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L6
	.p2align 4,,10
L8:
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L9
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L9
L7:
	call	__ZSt16__throw_bad_castv
	.section	.text.startup,"x"
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z4funcv;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z4funcv:
	subl	$28, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z4funcv
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
