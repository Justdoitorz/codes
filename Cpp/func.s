	.file	"func.cpp"
	.text
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNKSt5ctypeIcE8do_widenEc
	.def	_ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNKSt5ctypeIcE8do_widenEc
_ZNKSt5ctypeIcE8do_widenEc:
.LFB1252:
	.seh_endprologue
	movl	%edx, %eax
	ret
	.seh_endproc
	.text
	.align 2
	.p2align 4,,15
	.def	_ZNSs4_Rep10_M_disposeERKSaIcE.part.1;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSs4_Rep10_M_disposeERKSaIcE.part.1
_ZNSs4_Rep10_M_disposeERKSaIcE.part.1:
.LFB3149:
	.seh_endprologue
	movl	$-1, %eax
	lock xaddl	%eax, 16(%rcx)
	testl	%eax, %eax
	jle	.L5
	ret
.L5:
	jmp	_ZNSs4_Rep10_M_destroyERKSaIcE
	.seh_endproc
	.align 2
	.p2align 4,,15
	.def	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83;	.scl	3;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83:
.LFB3231:
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%r8, %rbx
	movq	%rcx, %r12
	movl	$64, %ecx
	movq	%rdx, %r14
	leaq	8(%r12), %r13
	call	_Znwm
	movq	%rax, %rdi
	movq	(%rbx), %rax
	cmpq	%r14, %r13
	movq	%r14, %rbx
	movl	(%rax), %ebp
	movq	$0, 40(%rdi)
	movq	$0, 48(%rdi)
	movq	$0, 56(%rdi)
	movl	%ebp, 32(%rdi)
	je	.L64
	cmpl	32(%r14), %ebp
	jge	.L19
	movq	24(%r12), %rsi
	cmpq	%r14, %rsi
	je	.L22
	movq	%r14, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %ebp
	movq	%rax, %r8
	jle	.L21
	cmpq	$0, 24(%rax)
	je	.L60
.L22:
	movq	%rbx, %r8
.L42:
	testq	%rbx, %rbx
	jne	.L53
	cmpq	%r8, %r13
	jne	.L30
.L53:
	movl	$1, %ecx
.L40:
	movq	%r13, %r9
	movq	%rdi, %rdx
	call	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_
	addq	$1, 40(%r12)
	movq	%rdi, %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
.L19:
	jle	.L39
	cmpq	%r14, 32(%r12)
	je	.L49
	movq	%r14, %rcx
	call	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base
	cmpl	32(%rax), %ebp
	movq	%rax, %r8
	jge	.L31
	cmpq	$0, 24(%r14)
	je	.L49
	movq	%rax, %rbx
	jmp	.L42
	.p2align 4,,10
.L34:
	testb	%cl, %cl
	movq	%rbx, %r8
	jne	.L32
.L37:
	cmpl	%edx, %ebp
	jle	.L39
.L17:
	xorl	%ebx, %ebx
	testq	%r8, %r8
	jne	.L42
.L39:
	movq	%rdi, %rcx
	call	_ZdlPv
	movq	%rbx, %rax
	addq	$32, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	ret
	.p2align 4,,10
.L64:
	cmpq	$0, 40(%r12)
	je	.L8
	movq	32(%r12), %r8
	cmpl	32(%r8), %ebp
	jg	.L60
.L8:
	movq	16(%r12), %rbx
	testq	%rbx, %rbx
	jne	.L11
	jmp	.L65
	.p2align 4,,10
.L66:
	movq	16(%rbx), %rax
	movl	$1, %ecx
.L14:
	testq	%rax, %rax
	je	.L34
	movq	%rax, %rbx
.L11:
	movl	32(%rbx), %edx
	cmpl	%edx, %ebp
	jl	.L66
	movq	24(%rbx), %rax
	xorl	%ecx, %ecx
	jmp	.L14
	.p2align 4,,10
.L60:
	xorl	%ebx, %ebx
	jmp	.L42
	.p2align 4,,10
.L21:
	movq	16(%r12), %rbx
	testq	%rbx, %rbx
	jne	.L24
	jmp	.L67
	.p2align 4,,10
.L68:
	movq	16(%rbx), %rax
	movl	$1, %ecx
.L27:
	testq	%rax, %rax
	je	.L25
	movq	%rax, %rbx
.L24:
	movl	32(%rbx), %edx
	cmpl	%edx, %ebp
	jl	.L68
	movq	24(%rbx), %rax
	xorl	%ecx, %ecx
	jmp	.L27
	.p2align 4,,10
.L49:
	movq	%r14, %r8
.L30:
	xorl	%ecx, %ecx
	cmpl	32(%r8), %ebp
	setl	%cl
	jmp	.L40
.L69:
	movq	%r13, %rbx
	.p2align 4,,10
.L32:
	movq	24(%r12), %r8
	cmpq	%rbx, %r8
	je	.L17
.L61:
	movq	%rbx, %rcx
	call	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base
	movq	%rbx, %r8
	movl	32(%rax), %edx
	movq	%rax, %rbx
	jmp	.L37
	.p2align 4,,10
.L25:
	testb	%cl, %cl
	movq	%rbx, %r8
	je	.L37
.L23:
	cmpq	%rbx, %rsi
	movq	%rsi, %r8
	jne	.L61
	jmp	.L17
	.p2align 4,,10
.L31:
	movq	16(%r12), %rbx
	testq	%rbx, %rbx
	jne	.L33
	jmp	.L69
	.p2align 4,,10
.L70:
	movq	16(%rbx), %rax
	movl	$1, %ecx
.L36:
	testq	%rax, %rax
	je	.L34
	movq	%rax, %rbx
.L33:
	movl	32(%rbx), %edx
	cmpl	%edx, %ebp
	jl	.L70
	movq	24(%rbx), %rax
	xorl	%ecx, %ecx
	jmp	.L36
	.p2align 4,,10
.L65:
	movq	%r14, %rbx
	jmp	.L32
	.p2align 4,,10
.L67:
	movq	%r13, %rbx
	jmp	.L23
	.seh_endproc
	.section	.text$_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E
	.def	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E
_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E:
.LFB2795:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$120, %rsp
	.seh_stackalloc	120
	.seh_endprologue
	testq	%rdx, %rdx
	movq	%rdx, 200(%rsp)
	je	.L71
	leaq	111(%rsp), %rax
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %r14
	movq	%rcx, %r13
	movq	%rax, 48(%rsp)
	movq	%rdx, %rax
.L73:
	movq	24(%rax), %rax
	testq	%rax, %rax
	movq	%rax, 72(%rsp)
	je	.L74
.L75:
	movq	24(%rax), %rax
	testq	%rax, %rax
	movq	%rax, 80(%rsp)
	je	.L76
.L77:
	movq	24(%rax), %rax
	testq	%rax, %rax
	movq	%rax, 88(%rsp)
	je	.L78
.L79:
	movq	24(%rax), %rax
	testq	%rax, %rax
	movq	%rax, 64(%rsp)
	je	.L80
.L81:
	movq	24(%rax), %rbp
	testq	%rbp, %rbp
	je	.L82
	movq	%rbp, 40(%rsp)
	movq	%rbp, %rax
.L83:
	movq	24(%rax), %r12
	testq	%r12, %r12
	je	.L84
	movq	%r13, 192(%rsp)
.L85:
	movq	24(%r12), %rsi
	testq	%rsi, %rsi
	je	.L86
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rdi
	movq	192(%rsp), %rbp
	movq	%r12, 56(%rsp)
.L87:
	movq	24(%rsi), %r15
	testq	%r15, %r15
	je	.L88
.L89:
	movq	24(%r15), %rdx
	movq	%rbp, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E
	movq	48(%r15), %r12
	movq	40(%r15), %rbx
	movq	16(%r15), %r13
	cmpq	%rbx, %r12
	je	.L90
	.p2align 4,,10
.L94:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%r14, %rcx
	jne	.L225
.L92:
	addq	$8, %rbx
	cmpq	%rbx, %r12
	jne	.L94
	movq	40(%r15), %rbx
.L90:
	testq	%rbx, %rbx
	je	.L95
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%r15, %rcx
	call	_ZdlPv
	testq	%r13, %r13
	je	.L88
.L96:
	movq	%r13, %r15
	jmp	.L89
	.p2align 4,,10
.L225:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L92
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L92
	.p2align 4,,10
.L95:
	movq	%r15, %rcx
	call	_ZdlPv
	testq	%r13, %r13
	jne	.L96
.L88:
	movq	48(%rsi), %r13
	movq	40(%rsi), %rbx
	movq	16(%rsi), %r15
	cmpq	%rbx, %r13
	je	.L97
	.p2align 4,,10
.L101:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rdi, %rcx
	jne	.L226
.L99:
	addq	$8, %rbx
	cmpq	%rbx, %r13
	jne	.L101
	movq	40(%rsi), %rbx
.L97:
	testq	%rbx, %rbx
	je	.L102
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%rsi, %rcx
	call	_ZdlPv
	testq	%r15, %r15
	je	.L223
.L103:
	movq	%r15, %rsi
	jmp	.L87
	.p2align 4,,10
.L226:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L99
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L99
	.p2align 4,,10
.L102:
	movq	%rsi, %rcx
	call	_ZdlPv
	testq	%r15, %r15
	jne	.L103
.L223:
	movq	56(%rsp), %r12
.L86:
	movq	48(%r12), %rsi
	movq	40(%r12), %rbx
	movq	16(%r12), %r15
	cmpq	%rbx, %rsi
	je	.L104
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rdi
	.p2align 4,,10
.L108:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rdi, %rcx
	jne	.L227
.L106:
	addq	$8, %rbx
	cmpq	%rbx, %rsi
	jne	.L108
	movq	40(%r12), %rbx
.L104:
	testq	%rbx, %rbx
	je	.L109
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	%r12, %rcx
	call	_ZdlPv
	testq	%r15, %r15
	je	.L224
.L110:
	movq	%r15, %r12
	jmp	.L85
	.p2align 4,,10
.L227:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L106
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L106
	.p2align 4,,10
.L109:
	movq	%r12, %rcx
	call	_ZdlPv
	testq	%r15, %r15
	jne	.L110
.L224:
	movq	192(%rsp), %r13
	movq	40(%rsp), %rax
.L84:
	movq	48(%rax), %rsi
	movq	40(%rax), %rbx
	movq	16(%rax), %r12
	cmpq	%rbx, %rsi
	je	.L111
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rdi
	.p2align 4,,10
.L115:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rdi, %rcx
	jne	.L228
.L113:
	addq	$8, %rbx
	cmpq	%rbx, %rsi
	jne	.L115
	movq	40(%rsp), %rax
	movq	40(%rax), %rbx
.L111:
	testq	%rbx, %rbx
	je	.L116
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	40(%rsp), %rcx
	call	_ZdlPv
	testq	%r12, %r12
	je	.L82
.L117:
	movq	%r12, 40(%rsp)
	movq	%r12, %rax
	jmp	.L83
.L228:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L113
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L113
.L116:
	movq	40(%rsp), %rcx
	call	_ZdlPv
	testq	%r12, %r12
	jne	.L117
.L82:
	movq	64(%rsp), %rax
	movq	48(%rax), %rdi
	movq	40(%rax), %rbx
	movq	16(%rax), %rsi
	cmpq	%rbx, %rdi
	je	.L118
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rbp
	.p2align 4,,10
.L122:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rbp, %rcx
	jne	.L229
.L120:
	addq	$8, %rbx
	cmpq	%rbx, %rdi
	jne	.L122
	movq	64(%rsp), %rax
	movq	40(%rax), %rbx
.L118:
	testq	%rbx, %rbx
	je	.L123
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	64(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	je	.L80
.L124:
	movq	%rsi, 64(%rsp)
	movq	%rsi, %rax
	jmp	.L81
.L229:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L120
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L120
.L123:
	movq	64(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	jne	.L124
.L80:
	movq	88(%rsp), %rax
	movq	48(%rax), %rdi
	movq	40(%rax), %rbx
	movq	16(%rax), %rsi
	cmpq	%rbx, %rdi
	je	.L125
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rbp
.L129:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rbp, %rcx
	jne	.L230
.L127:
	addq	$8, %rbx
	cmpq	%rbx, %rdi
	jne	.L129
	movq	88(%rsp), %rax
	movq	40(%rax), %rbx
.L125:
	testq	%rbx, %rbx
	je	.L130
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	88(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	je	.L78
.L131:
	movq	%rsi, 88(%rsp)
	movq	%rsi, %rax
	jmp	.L79
.L230:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L127
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L127
.L130:
	movq	88(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	jne	.L131
.L78:
	movq	80(%rsp), %rax
	movq	48(%rax), %rsi
	movq	40(%rax), %rbx
	movq	16(%rax), %rdi
	cmpq	%rbx, %rsi
	je	.L132
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rbp
.L136:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rbp, %rcx
	jne	.L231
.L134:
	addq	$8, %rbx
	cmpq	%rbx, %rsi
	jne	.L136
	movq	80(%rsp), %rax
	movq	40(%rax), %rbx
.L132:
	testq	%rbx, %rbx
	je	.L137
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	80(%rsp), %rcx
	call	_ZdlPv
	testq	%rdi, %rdi
	je	.L76
.L138:
	movq	%rdi, 80(%rsp)
	movq	%rdi, %rax
	jmp	.L77
.L231:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L134
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L134
.L137:
	movq	80(%rsp), %rcx
	call	_ZdlPv
	testq	%rdi, %rdi
	jne	.L138
.L76:
	movq	72(%rsp), %rax
	movq	48(%rax), %rbp
	movq	40(%rax), %rbx
	movq	16(%rax), %rsi
	cmpq	%rbx, %rbp
	je	.L139
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rdi
.L143:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rdi, %rcx
	jne	.L232
.L141:
	addq	$8, %rbx
	cmpq	%rbx, %rbp
	jne	.L143
	movq	72(%rsp), %rax
	movq	40(%rax), %rbx
.L139:
	testq	%rbx, %rbx
	je	.L144
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	72(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	je	.L74
.L145:
	movq	%rsi, 72(%rsp)
	movq	%rsi, %rax
	jmp	.L75
.L144:
	movq	72(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	jne	.L145
.L74:
	movq	200(%rsp), %rax
	movq	48(%rax), %rbp
	movq	40(%rax), %rbx
	movq	16(%rax), %rsi
	cmpq	%rbx, %rbp
	je	.L146
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rdi
.L150:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rdi, %rcx
	jne	.L233
.L148:
	addq	$8, %rbx
	cmpq	%rbx, %rbp
	jne	.L150
	movq	200(%rsp), %rax
	movq	40(%rax), %rbx
.L146:
	testq	%rbx, %rbx
	je	.L151
	movq	%rbx, %rcx
	call	_ZdlPv
	movq	200(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	je	.L71
.L152:
	movq	%rsi, 200(%rsp)
	movq	%rsi, %rax
	jmp	.L73
.L232:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L141
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L141
	.p2align 4,,10
.L151:
	movq	200(%rsp), %rcx
	call	_ZdlPv
	testq	%rsi, %rsi
	jne	.L152
.L71:
	addq	$120, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L233:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L148
	movq	48(%rsp), %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L148
	.seh_endproc
	.section	.text$_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_
	.def	_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_
_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_:
.LFB2826:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	movq	8(%rcx), %rax
	movq	%rdx, %rsi
	movq	(%rcx), %rdx
	movq	%rcx, %rbp
	movq	%rsi, %rbx
	movq	%r8, %r13
	subq	%rdx, %rax
	subq	%rdx, %rbx
	sarq	$3, %rax
	testq	%rax, %rax
	je	.L262
	leaq	(%rax,%rax), %r12
	cmpq	%r12, %rax
	jbe	.L281
.L264:
	movq	$-8, %r12
.L236:
	movq	%r12, %rcx
.LEHB0:
	call	_Znwm
.LEHE0:
	movq	%rax, %rdi
.L237:
	addq	%rdi, %rbx
	je	.L241
	movq	%r13, %rdx
	movq	%rbx, %rcx
.LEHB1:
	call	_ZNSsC1ERKSs
.LEHE1:
.L241:
	movq	0(%rbp), %rcx
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rbx
	movq	%rdi, %rdx
	movq	8(%rbp), %r13
	cmpq	%rsi, %rcx
	movq	%rcx, %rax
	leaq	24(%rbx), %r9
	je	.L282
	.p2align 4,,10
.L239:
	testq	%rdx, %rdx
	je	.L283
.L244:
	movq	(%rax), %r8
	addq	$8, %rax
	addq	$8, %rdx
	movq	%r8, -8(%rdx)
	movq	%r9, -8(%rax)
	cmpq	%rax, %rsi
	jne	.L239
.L243:
	leaq	8(%rcx), %rbx
	movq	%rsi, %rax
	subq	%rbx, %rax
	cmpq	%r13, %rsi
	leaq	16(%rdi,%rax), %r14
	je	.L245
.L261:
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rbx
	movq	%r14, %rdx
	movq	%rsi, %rax
	leaq	24(%rbx), %r9
	.p2align 4,,10
.L247:
	testq	%rdx, %rdx
	je	.L284
.L249:
	movq	(%rax), %r8
	movq	%r9, (%rax)
	addq	$8, %rax
	addq	$8, %rdx
	movq	%r8, -8(%rdx)
	cmpq	%r13, %rax
	jne	.L247
.L248:
	addq	$8, %rsi
	movq	%r13, %rax
	subq	%rsi, %rax
	shrq	$3, %rax
	cmpq	%r13, %rcx
	leaq	8(%r14,%rax,8), %r14
	je	.L250
	leaq	8(%rcx), %rbx
.L245:
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rsi
	leaq	47(%rsp), %r15
	jmp	.L254
	.p2align 4,,10
.L286:
	addq	$8, %rbx
.L254:
	movq	(%rcx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rsi, %rcx
	jne	.L285
.L252:
	cmpq	%r13, %rbx
	movq	%rbx, %rcx
	jne	.L286
	movq	0(%rbp), %r13
.L250:
	testq	%r13, %r13
	je	.L255
	movq	%r13, %rcx
	call	_ZdlPv
.L255:
	movq	%rdi, 0(%rbp)
	addq	%r12, %rdi
	movq	%r14, 8(%rbp)
	movq	%rdi, 16(%rbp)
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
	.p2align 4,,10
.L262:
	movl	$1, %r12d
.L235:
	salq	$3, %r12
	jmp	.L236
	.p2align 4,,10
.L285:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L252
	movq	%r15, %rdx
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	jmp	.L252
	.p2align 4,,10
.L281:
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %r12
	ja	.L264
	testq	%r12, %r12
	jne	.L235
	xorl	%edi, %edi
	jmp	.L237
	.p2align 4,,10
.L282:
	cmpq	%r13, %rsi
	leaq	8(%rdi), %r14
	jne	.L261
	jmp	.L250
.L284:
	addq	$8, %rax
	cmpq	%r13, %rax
	je	.L248
	movl	$8, %edx
	jmp	.L249
.L283:
	addq	$8, %rax
	cmpq	%rax, %rsi
	je	.L243
	movl	$8, %edx
	jmp	.L244
.L269:
	movq	%rax, %rcx
	call	__cxa_begin_catch
	testq	%rdi, %rdi
	je	.L287
	movq	%rdi, %rcx
	call	_ZdlPv
.L260:
.LEHB2:
	call	__cxa_rethrow
.LEHE2:
.L287:
	movq	(%rbx), %rcx
	subq	$24, %rcx
	cmpq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rcx
	je	.L260
	leaq	47(%rsp), %rdx
	call	_ZNSs4_Rep10_M_disposeERKSaIcE.part.1
	jmp	.L260
.L270:
	movq	%rax, %rbx
	call	__cxa_end_catch
	movq	%rbx, %rcx
.LEHB3:
	call	_Unwind_Resume
	nop
.LEHE3:
	.def	__gxx_personality_seh0;	.scl	2;	.type	32;	.endef
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA2826:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT2826-.LLSDATTD2826
.LLSDATTD2826:
	.byte	0x1
	.uleb128 .LLSDACSE2826-.LLSDACSB2826
.LLSDACSB2826:
	.uleb128 .LEHB0-.LFB2826
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB2826
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L269-.LFB2826
	.uleb128 0x1
	.uleb128 .LEHB2-.LFB2826
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L270-.LFB2826
	.uleb128 0
	.uleb128 .LEHB3-.LFB2826
	.uleb128 .LEHE3-.LEHB3
	.uleb128 0
	.uleb128 0
.LLSDACSE2826:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT2826:
	.section	.text$_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_,"x"
	.linkonce discard
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC0:
	.ascii "er\0"
.LC2:
	.ascii "STL:\0"
.LC3:
	.ascii "ms\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2419:
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$184, %rsp
	.seh_stackalloc	184
	movaps	%xmm6, 160(%rsp)
	.seh_savexmm	%xmm6, 160
	.seh_endprologue
	call	__main
	movq	.refptr._ZSt3cin(%rip), %rcx
	leaq	76(%rsp), %rdx
	leaq	112(%rsp), %rdi
	leaq	104(%rsp), %r15
	leaq	80(%rsp), %r13
.LEHB4:
	call	_ZNSirsERi
.LEHE4:
	call	clock
	leaq	.LC0(%rip), %rdx
	movq	%rax, 48(%rsp)
	leaq	8(%rdi), %rax
	movq	%r15, %r8
	movq	%r13, %rcx
	movl	$0, 120(%rsp)
	movq	$0, 128(%rsp)
	movq	%rax, 136(%rsp)
	movq	%rax, 144(%rsp)
	movq	$0, 152(%rsp)
.LEHB5:
	call	_ZNSsC1EPKcRKSaIcE
.LEHE5:
	movl	76(%rsp), %edx
	movq	.refptr._ZNSs4_Rep20_S_empty_rep_storageE(%rip), %rax
	movl	$0, 104(%rsp)
	testl	%edx, %edx
	movq	%rax, 40(%rsp)
	jle	.L324
	leaq	88(%rsp), %rsi
	leaq	24(%rax), %r14
	movq	%rsi, 32(%rsp)
	.p2align 4,,10
.L368:
	leaq	8(%rdi), %rbp
	xorl	%esi, %esi
	.p2align 4,,10
.L300:
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L343
	movl	104(%rsp), %edx
	movq	%rbp, %rbx
	jmp	.L292
	.p2align 4,,10
.L371:
	movq	%rax, %rbx
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L293
.L292:
	cmpl	%edx, 32(%rax)
	jge	.L371
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L292
.L293:
	cmpq	%rbp, %rbx
	je	.L291
	cmpl	32(%rbx), %edx
	jge	.L296
.L291:
	movq	32(%rsp), %r8
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	movq	%r15, 88(%rsp)
.LEHB6:
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83
	movq	%rax, %rbx
.L296:
	movq	48(%rbx), %rcx
	cmpq	56(%rbx), %rcx
	je	.L297
	testq	%rcx, %rcx
	je	.L298
	movq	%r13, %rdx
	call	_ZNSsC1ERKSs
	movq	48(%rbx), %rcx
.L298:
	addq	$8, %rcx
	movq	%rcx, 48(%rbx)
.L299:
	addl	$1, %esi
	cmpl	%esi, 76(%rsp)
	jg	.L300
	movq	128(%rsp), %rax
	testq	%rax, %rax
	je	.L345
.L377:
	movl	104(%rsp), %edx
	leaq	8(%rdi), %rbx
	jmp	.L302
	.p2align 4,,10
.L372:
	movq	%rax, %rbx
	movq	16(%rax), %rax
	testq	%rax, %rax
	je	.L303
.L302:
	cmpl	%edx, 32(%rax)
	jge	.L372
	movq	24(%rax), %rax
	testq	%rax, %rax
	jne	.L302
.L303:
	leaq	8(%rdi), %rax
	cmpq	%rax, %rbx
	je	.L301
	cmpl	32(%rbx), %edx
	jge	.L306
.L301:
	leaq	96(%rsp), %r8
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	movq	%r15, 96(%rsp)
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83
.LEHE6:
	movq	%rax, %rbx
.L306:
	movq	48(%rbx), %rsi
	movq	40(%rbx), %rbp
	movq	56(%rbx), %rax
	movq	%rsi, %r12
	movq	%rbp, %r9
	movq	%rsi, %r8
	subq	%rbp, %r12
	subq	%rbp, %rax
	movq	%r12, %rdx
	sarq	$3, %rax
	sarq	$3, %rdx
	cmpq	%rdx, %rax
	je	.L307
	xorl	%eax, %eax
	testq	%rdx, %rdx
	je	.L309
	movabsq	$2305843009213693951, %rax
	cmpq	%rax, %rdx
	ja	.L373
	movq	%r12, %rcx
.LEHB7:
	call	_Znwm
.LEHE7:
	movq	40(%rbx), %r9
	movq	48(%rbx), %r8
.L309:
	addq	%rax, %r12
	cmpq	%rsi, %rbp
	je	.L347
	movq	%rax, %rcx
	movq	%rbp, %rdx
	.p2align 4,,10
.L313:
	testq	%rcx, %rcx
	je	.L374
.L315:
	movq	(%rdx), %r10
	addq	$8, %rdx
	addq	$8, %rcx
	movq	%r10, -8(%rcx)
	movq	%r14, -8(%rdx)
	cmpq	%rdx, %rsi
	jne	.L313
.L314:
	addq	$8, %rbp
	subq	%rbp, %rsi
	shrq	$3, %rsi
	leaq	8(%rax,%rsi,8), %rdx
.L311:
	cmpq	%r8, %r9
	movq	%rax, 40(%rbx)
	movq	%rdx, 48(%rbx)
	movq	%r12, 56(%rbx)
	je	.L316
	movq	40(%rsp), %rbp
	leaq	96(%rsp), %rsi
	movq	%r9, %rbx
	movq	%r9, %r12
	.p2align 4,,10
.L317:
	movq	(%rbx), %rax
	leaq	-24(%rax), %rcx
	cmpq	%rbp, %rcx
	jne	.L375
.L320:
	addq	$8, %rbx
	cmpq	%rbx, %r8
	jne	.L317
	movq	%r12, %r9
.L316:
	testq	%r9, %r9
	je	.L307
	movq	%r9, %rcx
	call	_ZdlPv
.L307:
	movl	104(%rsp), %eax
	leal	1(%rax), %edx
	movl	76(%rsp), %eax
	movl	%edx, 104(%rsp)
	cmpl	%edx, %eax
	jle	.L376
	testl	%eax, %eax
	jg	.L368
	movq	128(%rsp), %rax
	testq	%rax, %rax
	jne	.L377
.L345:
	leaq	8(%rdi), %rbx
	jmp	.L301
	.p2align 4,,10
.L297:
	addq	$40, %rbx
	movq	%rcx, %rdx
	movq	%r13, %r8
	movq	%rbx, %rcx
.LEHB8:
	call	_ZNSt6vectorISsSaISsEE17_M_realloc_insertIJRKSsEEEvN9__gnu_cxx17__normal_iteratorIPSsS1_EEDpOT_
	jmp	.L299
	.p2align 4,,10
.L343:
	movq	%rbp, %rbx
	jmp	.L291
.L375:
	movl	$-1, %edx
	lock xaddl	%edx, -8(%rax)
	testl	%edx, %edx
	jg	.L320
	movq	%rsi, %rdx
	movq	%r8, 56(%rsp)
	call	_ZNSs4_Rep10_M_destroyERKSaIcE
	movq	56(%rsp), %r8
	jmp	.L320
	.p2align 4,,10
.L328:
	leaq	8(%rdi), %rcx
	cmpq	%rcx, %rax
	je	.L326
	cmpl	32(%rax), %edx
	jge	.L331
.L326:
	movq	%r15, %r8
	movq	%rax, %rdx
	movq	%rdi, %rcx
	movq	%r14, 104(%rsp)
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE22_M_emplace_hint_uniqueIJRKSt21piecewise_construct_tSt5tupleIJRS1_EESG_IJEEEEESt17_Rb_tree_iteratorIS5_ESt23_Rb_tree_const_iteratorIS5_EDpOT_.isra.83
.L331:
	movq	40(%rax), %rax
	movq	%r13, %rcx
	movq	(%rax,%r12), %rdx
	movq	-24(%rdx), %r8
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	%rax, %rsi
	movq	(%rax), %rax
	movq	-24(%rax), %rax
	movq	240(%rsi,%rax), %rbx
	testq	%rbx, %rbx
	je	.L378
	cmpb	$0, 56(%rbx)
	je	.L333
	movsbl	67(%rbx), %edx
.L334:
	movq	%rsi, %rcx
	call	_ZNSo3putEc
	movq	%rax, %rcx
	call	_ZNSo5flushEv
	movl	76(%rsp), %eax
	addl	$1, %ebp
	addq	$8, %r12
	cmpl	%ebp, %eax
	jg	.L335
	movl	96(%rsp), %edx
.L325:
	addl	$1, %edx
	cmpl	%eax, %edx
	movl	%edx, 96(%rsp)
	jl	.L336
.L324:
	call	clock
	subq	48(%rsp), %rax
	js	.L337
	pxor	%xmm6, %xmm6
	cvtsi2sdq	%rax, %xmm6
.L338:
	movsd	.LC1(%rip), %xmm0
	movq	.refptr._ZSt4cout(%rip), %rcx
	leaq	.LC2(%rip), %rdx
	movl	$4, %r8d
	mulsd	%xmm0, %xmm6
	divsd	%xmm0, %xmm6
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	.refptr._ZSt4cout(%rip), %rcx
	movapd	%xmm6, %xmm1
	call	_ZNSo9_M_insertIdEERSoT_
	leaq	.LC3(%rip), %rdx
	movl	$2, %r8d
	movq	%rax, %rcx
	movq	%rax, %rbx
	call	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l
	movq	%rbx, %rcx
	call	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movq	80(%rsp), %rax
	leaq	-24(%rax), %rcx
	cmpq	40(%rsp), %rcx
	jne	.L379
.L339:
	movq	128(%rsp), %rdx
	movq	%rdi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E
	nop
	movaps	160(%rsp), %xmm6
	xorl	%eax, %eax
	addq	$184, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%rbp
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	ret
.L376:
	testl	%eax, %eax
	movl	$0, 96(%rsp)
	jle	.L324
	leaq	_ZNKSt5ctypeIcE8do_widenEc(%rip), %rsi
	movq	.refptr._ZSt4cout(%rip), %r13
	xorl	%edx, %edx
	movq	%rsi, 32(%rsp)
	.p2align 4,,10
.L336:
	testl	%eax, %eax
	jle	.L325
	leaq	96(%rsp), %r14
	xorl	%r12d, %r12d
	xorl	%ebp, %ebp
	.p2align 4,,10
.L335:
	movq	128(%rsp), %rcx
	testq	%rcx, %rcx
	je	.L349
	movl	96(%rsp), %edx
	leaq	8(%rdi), %rax
	jmp	.L327
	.p2align 4,,10
.L380:
	movq	%rcx, %rax
	movq	16(%rcx), %rcx
.L330:
	testq	%rcx, %rcx
	je	.L328
.L327:
	cmpl	%edx, 32(%rcx)
	jge	.L380
	movq	24(%rcx), %rcx
	jmp	.L330
	.p2align 4,,10
.L333:
	movq	%rbx, %rcx
	call	_ZNKSt5ctypeIcE13_M_widen_initEv
	movq	(%rbx), %rax
	movl	$10, %edx
	movq	48(%rax), %rax
	cmpq	32(%rsp), %rax
	je	.L334
	movq	%rbx, %rcx
	call	*%rax
	movsbl	%al, %edx
	jmp	.L334
	.p2align 4,,10
.L349:
	leaq	8(%rdi), %rax
	jmp	.L326
.L347:
	movq	%rax, %rdx
	jmp	.L311
.L337:
	movq	%rax, %rdx
	pxor	%xmm6, %xmm6
	shrq	%rdx
	andl	$1, %eax
	orq	%rax, %rdx
	cvtsi2sdq	%rdx, %xmm6
	addsd	%xmm6, %xmm6
	jmp	.L338
.L374:
	addq	$8, %rdx
	cmpq	%rdx, %rsi
	je	.L314
	movl	$8, %ecx
	jmp	.L315
.L379:
	movq	%r15, %rdx
	call	_ZNSs4_Rep10_M_disposeERKSaIcE.part.1
	jmp	.L339
.L378:
	call	_ZSt16__throw_bad_castv
.LEHE8:
.L353:
	movq	%rax, %rbx
	movq	80(%rsp), %rax
	leaq	-24(%rax), %rcx
	cmpq	40(%rsp), %rcx
	je	.L342
	leaq	75(%rsp), %rdx
	call	_ZNSs4_Rep10_M_disposeERKSaIcE.part.1
.L342:
	movq	128(%rsp), %rdx
	movq	%rdi, %rcx
	call	_ZNSt8_Rb_treeIiSt4pairIKiSt6vectorISsSaISsEEESt10_Select1stIS5_ESt4lessIiESaIS5_EE8_M_eraseEPSt13_Rb_tree_nodeIS5_E
	movq	%rbx, %rcx
.LEHB9:
	call	_Unwind_Resume
.LEHE9:
.L354:
	movq	%rax, %rcx
	call	__cxa_begin_catch
	call	__cxa_end_catch
	jmp	.L307
.L373:
.LEHB10:
	call	_ZSt17__throw_bad_allocv
.LEHE10:
.L352:
	movq	%rax, %rbx
	jmp	.L342
	.seh_handler	__gxx_personality_seh0, @unwind, @except
	.seh_handlerdata
	.align 4
.LLSDA2419:
	.byte	0xff
	.byte	0x9b
	.uleb128 .LLSDATT2419-.LLSDATTD2419
.LLSDATTD2419:
	.byte	0x1
	.uleb128 .LLSDACSE2419-.LLSDACSB2419
.LLSDACSB2419:
	.uleb128 .LEHB4-.LFB2419
	.uleb128 .LEHE4-.LEHB4
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB5-.LFB2419
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L352-.LFB2419
	.uleb128 0
	.uleb128 .LEHB6-.LFB2419
	.uleb128 .LEHE6-.LEHB6
	.uleb128 .L353-.LFB2419
	.uleb128 0
	.uleb128 .LEHB7-.LFB2419
	.uleb128 .LEHE7-.LEHB7
	.uleb128 .L354-.LFB2419
	.uleb128 0x1
	.uleb128 .LEHB8-.LFB2419
	.uleb128 .LEHE8-.LEHB8
	.uleb128 .L353-.LFB2419
	.uleb128 0
	.uleb128 .LEHB9-.LFB2419
	.uleb128 .LEHE9-.LEHB9
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB10-.LFB2419
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L354-.LFB2419
	.uleb128 0x1
.LLSDACSE2419:
	.byte	0x1
	.byte	0
	.align 4
	.long	0

.LLSDATT2419:
	.section	.text.startup,"x"
	.seh_endproc
	.p2align 4,,15
	.def	_GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
	.seh_proc	_GLOBAL__sub_I_main
_GLOBAL__sub_I_main:
.LFB3147:
	subq	$40, %rsp
	.seh_stackalloc	40
	.seh_endprologue
	leaq	_ZStL8__ioinit(%rip), %rcx
	call	_ZNSt8ios_base4InitC1Ev
	movq	.refptr.__dso_handle(%rip), %r8
	leaq	_ZStL8__ioinit(%rip), %rdx
	leaq	_ZNSt8ios_base4InitD1Ev(%rip), %rcx
	addq	$40, %rsp
	jmp	__cxa_atexit
	.seh_endproc
	.section	.ctors,"w"
	.align 8
	.quad	_GLOBAL__sub_I_main
.lcomm _ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 8
.LC1:
	.long	0
	.long	1083129856
	.ident	"GCC: (GNU) 7.3.0"
	.def	_ZNSs4_Rep10_M_destroyERKSaIcE;	.scl	2;	.type	32;	.endef
	.def	__real__Znwm;	.scl	2;	.type	32;	.endef
	.def	_Znwm;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_decrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	_ZSt29_Rb_tree_insert_and_rebalancebPSt18_Rb_tree_node_baseS0_RS_;	.scl	2;	.type	32;	.endef
	.def	_ZSt18_Rb_tree_incrementPSt18_Rb_tree_node_base;	.scl	2;	.type	32;	.endef
	.def	__real__ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZdlPv;	.scl	2;	.type	32;	.endef
	.def	_ZNSsC1ERKSs;	.scl	2;	.type	32;	.endef
	.def	__cxa_begin_catch;	.scl	2;	.type	32;	.endef
	.def	__cxa_rethrow;	.scl	2;	.type	32;	.endef
	.def	__cxa_end_catch;	.scl	2;	.type	32;	.endef
	.def	_Unwind_Resume;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERi;	.scl	2;	.type	32;	.endef
	.def	clock;	.scl	2;	.type	32;	.endef
	.def	_ZNSsC1EPKcRKSaIcE;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_l;	.scl	2;	.type	32;	.endef
	.def	_ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	_ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_ZNSo9_M_insertIdEERSoT_;	.scl	2;	.type	32;	.endef
	.def	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	_ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	_ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	_ZSt17__throw_bad_allocv;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
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
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZNSs4_Rep20_S_empty_rep_storageE, "dr"
	.globl	.refptr._ZNSs4_Rep20_S_empty_rep_storageE
	.linkonce	discard
.refptr._ZNSs4_Rep20_S_empty_rep_storageE:
	.quad	_ZNSs4_Rep20_S_empty_rep_storageE
