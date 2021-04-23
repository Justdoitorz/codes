	.file	"virtual.cpp"
	.section .rdata,"dr"
__ZStL19piecewise_construct:
	.space 1
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
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
LC0:
	.ascii "Real()\0"
	.section	.text$_ZN4RealC2Ei,"x"
	.linkonce discard
	.align 2
	.globl	__ZN4RealC2Ei
	.def	__ZN4RealC2Ei;	.scl	2;	.type	32;	.endef
__ZN4RealC2Ei:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	8(%ebp), %edx
	movl	%edx, (%eax)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret	$4
	.section .rdata,"dr"
LC1:
	.ascii "Derived()\0"
	.section	.text$_ZN7DerivedC2Eii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7DerivedC2Eii
	.def	__ZN7DerivedC2Eii;	.scl	2;	.type	32;	.endef
__ZN7DerivedC2Eii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	leal	4(%eax), %edx
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	movl	%edx, %ecx
	call	__ZN4RealC2Ei
	subl	$4, %esp
	movl	$__ZTV7Derived+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 8(%eax)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret	$8
	.section .rdata,"dr"
LC2:
	.ascii "Derived.vfunc()\0"
	.section	.text$_ZN7Derived5vfuncEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7Derived5vfuncEv
	.def	__ZN7Derived5vfuncEv;	.scl	2;	.type	32;	.endef
__ZN7Derived5vfuncEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC2, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret
	.section .rdata,"dr"
LC3:
	.ascii "Derived.vfunc(int)\0"
	.section	.text$_ZN7Derived5vfuncEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN7Derived5vfuncEi
	.def	__ZN7Derived5vfuncEi;	.scl	2;	.type	32;	.endef
__ZN7Derived5vfuncEi:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC3, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret	$4
	.section .rdata,"dr"
LC4:
	.ascii "Third()\0"
	.section	.text$_ZN5ThirdC1Eiii,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5ThirdC1Eiii
	.def	__ZN5ThirdC1Eiii;	.scl	2;	.type	32;	.endef
__ZN5ThirdC1Eiii:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	-12(%ebp), %eax
	movl	12(%ebp), %edx
	movl	%edx, 4(%esp)
	movl	8(%ebp), %edx
	movl	%edx, (%esp)
	movl	%eax, %ecx
	call	__ZN7DerivedC2Eii
	subl	$8, %esp
	movl	$__ZTV5Third+8, %edx
	movl	-12(%ebp), %eax
	movl	%edx, (%eax)
	movl	-12(%ebp), %eax
	movl	16(%ebp), %edx
	movl	%edx, 12(%eax)
	movl	$LC4, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret	$12
	.section .rdata,"dr"
LC5:
	.ascii "Third.vfunc()\0"
	.section	.text$_ZN5Third5vfuncEv,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5Third5vfuncEv
	.def	__ZN5Third5vfuncEv;	.scl	2;	.type	32;	.endef
__ZN5Third5vfuncEv:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC5, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret
	.section .rdata,"dr"
LC6:
	.ascii "Third.vfunc(int)\0"
	.section	.text$_ZN5Third5vfuncEi,"x"
	.linkonce discard
	.align 2
	.globl	__ZN5Third5vfuncEi
	.def	__ZN5Third5vfuncEi;	.scl	2;	.type	32;	.endef
__ZN5Third5vfuncEi:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	movl	%ecx, -12(%ebp)
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, (%esp)
	movl	%eax, %ecx
	call	__ZNSolsEPFRSoS_E
	subl	$4, %esp
	nop
	leave
	ret	$4
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC7:
	.ascii "rd.r = %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$52, %esp
	call	___main
	leal	-32(%ebp), %eax
	movl	$3, 8(%esp)
	movl	$2, 4(%esp)
	movl	$1, (%esp)
	movl	%eax, %ecx
	call	__ZN5ThirdC1Eiii
	subl	$12, %esp
	leal	-32(%ebp), %eax
	addl	$4, %eax
	movl	%eax, -12(%ebp)
	leal	-32(%ebp), %eax
	movl	%eax, -16(%ebp)
	movl	-16(%ebp), %eax
	movl	4(%eax), %eax
	movl	%eax, 4(%esp)
	movl	$LC7, (%esp)
	call	_printf
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	movl	(%eax), %eax
	movl	-16(%ebp), %edx
	movl	%edx, %ecx
	call	*%eax
	movl	-16(%ebp), %eax
	movl	(%eax), %eax
	addl	$4, %eax
	movl	(%eax), %edx
	movl	-16(%ebp), %eax
	movl	$0, (%esp)
	movl	%eax, %ecx
	call	*%edx
	subl	$4, %esp
	movl	$0, %eax
	movl	-4(%ebp), %ecx
	leave
	leal	-4(%ecx), %esp
	ret
	.globl	__ZTV5Third
	.section	.rdata$_ZTV5Third,"dr"
	.linkonce same_size
	.align 4
__ZTV5Third:
	.long	0
	.long	__ZTI5Third
	.long	__ZN5Third5vfuncEv
	.long	__ZN5Third5vfuncEi
	.globl	__ZTV7Derived
	.section	.rdata$_ZTV7Derived,"dr"
	.linkonce same_size
	.align 4
__ZTV7Derived:
	.long	0
	.long	__ZTI7Derived
	.long	__ZN7Derived5vfuncEv
	.long	__ZN7Derived5vfuncEi
	.globl	__ZTI5Third
	.section	.rdata$_ZTI5Third,"dr"
	.linkonce same_size
	.align 4
__ZTI5Third:
	.long	__ZTVN10__cxxabiv120__si_class_type_infoE+8
	.long	__ZTS5Third
	.long	__ZTI7Derived
	.globl	__ZTS5Third
	.section	.rdata$_ZTS5Third,"dr"
	.linkonce same_size
	.align 4
__ZTS5Third:
	.ascii "5Third\0"
	.globl	__ZTI7Derived
	.section	.rdata$_ZTI7Derived,"dr"
	.linkonce same_size
	.align 4
__ZTI7Derived:
	.long	__ZTVN10__cxxabiv121__vmi_class_type_infoE+8
	.long	__ZTS7Derived
	.long	0
	.long	1
	.long	__ZTI4Real
	.long	1026
	.globl	__ZTS7Derived
	.section	.rdata$_ZTS7Derived,"dr"
	.linkonce same_size
	.align 4
__ZTS7Derived:
	.ascii "7Derived\0"
	.text
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
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
	jne	L15
	cmpl	$65535, 12(%ebp)
	jne	L15
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
L15:
	nop
	leave
	ret
	.globl	__ZTI4Real
	.section	.rdata$_ZTI4Real,"dr"
	.linkonce same_size
	.align 4
__ZTI4Real:
	.long	__ZTVN10__cxxabiv117__class_type_infoE+8
	.long	__ZTS4Real
	.globl	__ZTS4Real
	.section	.rdata$_ZTS4Real,"dr"
	.linkonce same_size
	.align 4
__ZTS4Real:
	.ascii "4Real\0"
	.text
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
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
	.long	__GLOBAL__sub_I_main
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	___mingw_vprintf;	.scl	2;	.type	32;	.endef
	.def	__ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
