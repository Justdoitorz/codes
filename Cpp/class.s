	.file	"class.cpp"
	.text
	.section .rdata,"dr"
_ZStL19piecewise_construct:
	.space 1
.lcomm _ZStL8__ioinit,1,1
	.align 4
_ZN9__gnu_cxxL21__default_lock_policyE:
	.long	2
_ZStL13allocator_arg:
	.space 1
_ZStL6ignore:
	.space 1
	.globl	cnt
	.bss
	.align 4
cnt:
	.space 4
	.section .rdata,"dr"
.LC0:
	.ascii " , ~A(): \0"
	.section	.text$_ZN1AD1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN1AD1Ev
	.def	_ZN1AD1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AD1Ev
_ZN1AD1Ev:
.LFB2875:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movl	(%rax), %eax
	movl	%eax, %edx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZNSolsEi
	leaq	.LC0(%rip), %rdx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPKv
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2875:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2875-.LLSDACSB2875
.LLSDACSB2875:
.LLSDACSE2875:
	.section	.text$_ZN1AD1Ev,"x"
	.linkonce discard
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "A(), \0"
	.text
	.align 2
	.globl	_ZN1AC2Ei
	.def	_ZN1AC2Ei;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2Ei
_ZN1AC2Ei:
.LFB2877:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	%edx, 24(%rbp)
	movl	cnt(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, cnt(%rip)
	movq	16(%rbp), %rdx
	movl	%eax, (%rdx)
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPKv
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN1AC1Ei
	.def	_ZN1AC1Ei;	.scl	2;	.type	32;	.endef
	.set	_ZN1AC1Ei,_ZN1AC2Ei
	.section .rdata,"dr"
.LC2:
	.ascii "A(const A &a), \0"
.LC3:
	.ascii ", &a \0"
	.text
	.align 2
	.globl	_ZN1AC2ERKS_
	.def	_ZN1AC2ERKS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2ERKS_
_ZN1AC2ERKS_:
.LFB2880:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	cnt(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, cnt(%rip)
	movq	16(%rbp), %rdx
	movl	%eax, (%rdx)
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPKv
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPKv
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN1AC1ERKS_
	.def	_ZN1AC1ERKS_;	.scl	2;	.type	32;	.endef
	.set	_ZN1AC1ERKS_,_ZN1AC2ERKS_
	.section .rdata,"dr"
.LC4:
	.ascii "A(&&a), \0"
	.text
	.align 2
	.globl	_ZN1AC2EOS_
	.def	_ZN1AC2EOS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AC2EOS_
_ZN1AC2EOS_:
.LFB2883:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movl	cnt(%rip), %eax
	leal	1(%rax), %edx
	movl	%edx, cnt(%rip)
	movq	16(%rbp), %rdx
	movl	%eax, (%rdx)
	leaq	.LC4(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	16(%rbp), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPKv
	leaq	.LC3(%rip), %rdx
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rcx
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPKv
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZN1AC1EOS_
	.def	_ZN1AC1EOS_;	.scl	2;	.type	32;	.endef
	.set	_ZN1AC1EOS_,_ZN1AC2EOS_
	.section .rdata,"dr"
.LC5:
	.ascii "A &operator=(const A &a)\0"
	.text
	.align 2
	.globl	_ZN1AaSERKS_
	.def	_ZN1AaSERKS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AaSERKS_
_ZN1AaSERKS_:
.LFB2885:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	.LC5(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC6:
	.ascii "A &operator=(A &&a)\0"
	.text
	.align 2
	.globl	_ZN1AaSEOS_
	.def	_ZN1AaSEOS_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN1AaSEOS_
_ZN1AaSEOS_:
.LFB2886:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	leaq	.LC6(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rdx
	movq	%rax, %rcx
	call	_ZNSolsEPFRSoS_E
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3foo1A
	.def	_Z3foo1A;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3foo1A
_Z3foo1A:
.LFB2887:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3barv
	.def	_Z3barv;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3barv
_Z3barv:
.LFB2888:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movl	$0, %edx
	movq	16(%rbp), %rcx
	call	_ZN1AC1Ei
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	_Z3baz1A
	.def	_Z3baz1A;	.scl	2;	.type	32;	.endef
	.seh_proc	_Z3baz1A
_Z3baz1A:
.LFB2889:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	%rdx, 24(%rbp)
	movq	24(%rbp), %rax
	movq	%rax, %rdx
	movq	16(%rbp), %rcx
	call	_ZN1AC1EOS_
	movq	16(%rbp), %rax
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2889:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2889-.LLSDACSB2889
.LLSDACSB2889:
.LLSDACSE2889:
	.text
	.seh_endproc
	.globl	g
	.bss
	.align 4
g:
	.space 4
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2890:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	movl	$4168, %eax
	call	___chkstk_ms
	subq	%rax, %rsp
	.seh_stackalloc	4168
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	4020(%rbp), %rax
	leaq	g(%rip), %rdx
	movq	%rax, %rcx
.LEHB0:
	call	_ZN1AC1ERKS_
.LEHE0:
	leaq	-84(%rbp), %rax
	leaq	4020(%rbp), %rdx
	movq	%rax, %rcx
	call	_Z3baz1A
	leaq	4020(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	leaq	4028(%rbp), %rax
	leaq	g(%rip), %rdx
	movq	%rax, %rcx
.LEHB1:
	call	_ZN1AC1ERKS_
.LEHE1:
	leaq	4024(%rbp), %rax
	leaq	4028(%rbp), %rdx
	movq	%rax, %rcx
	call	_Z3baz1A
	leaq	4024(%rbp), %rdx
	leaq	-84(%rbp), %rax
	movq	%rax, %rcx
.LEHB2:
	call	_ZN1AaSEOS_
.LEHE2:
	leaq	4024(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	leaq	4028(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	movl	$1, 4012(%rbp)
	movl	$0, %ebx
	leaq	-84(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	movl	%ebx, %eax
	jmp	.L20
.L19:
	movq	%rax, %rbx
	leaq	4024(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	leaq	4028(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	jmp	.L17
.L18:
	movq	%rax, %rbx
.L17:
	leaq	-84(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN1AD1Ev
	movq	%rbx, %rax
	movq	%rax, %rcx
.LEHB3:
	call	_Unwind_Resume
.LEHE3:
.L20:
	addq	$4168, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
.LLSDA2890:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE2890-.LLSDACSB2890
.LLSDACSB2890:
	.uleb128 .LEHB0-.LFB2890
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2890
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L18-.LFB2890
	.uleb128 0
	.uleb128 .LEHB2-.LFB2890
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L19-.LFB2890
	.uleb128 0
	.uleb128 .LEHB3-.LFB2890
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE2890:
	.text
	.seh_endproc
	.def	_Z41__static_initialization_and_destruction_0ii;	.scl	3;	.type	32;	.endef
	.seh_proc	_Z41__static_initialization_and_destruction_0ii
_Z41__static_initialization_and_destruction_0ii:
.LFB3335:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	cmpl	$1, 16(%rbp)
	jne	.L23
	cmpl	$65535, 24(%rbp)
	jne	.L23
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	movq	.refptr.__dso_handle(%rip), %r8
	leaq	_ZStL8__ioinit(%rip), %rdx
	movq	.refptr._ZNSt8ios_base4InitD1Ev(%rip), %rcx
	call	__cxa_atexit
	movl	$0, %edx
	leaq	g(%rip), %rcx
	call	_ZN1AC1Ei
	movq	.refptr.__dso_handle(%rip), %r8
	leaq	g(%rip), %rdx
	leaq	_ZN1AD1Ev(%rip), %rax
	movq	%rax, %rcx
	call	__cxa_atexit
.L23:
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	_GLOBAL__sub_I_cnt;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_cnt
_GLOBAL__sub_I_cnt:
.LFB3336:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movl	$65535, %edx
	movl	$1, %ecx
	call	_Z41__static_initialization_and_destruction_0ii
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_cnt
	.ident	"GCC: (GNU) 7.3.0"
	.def	_ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPKv;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	__cxa_atexit;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZNSt8ios_base4InitD1Ev, "dr"
	.globl	.refptr._ZNSt8ios_base4InitD1Ev
	.linkonce	discard
.refptr._ZNSt8ios_base4InitD1Ev:
	.quad	_ZNSt8ios_base4InitD1Ev
	.section	.rdata$.refptr.__dso_handle, "dr"
	.globl	.refptr.__dso_handle
	.linkonce	discard
.refptr.__dso_handle:
	.quad	__dso_handle
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
