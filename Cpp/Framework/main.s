	.file	"main.cpp"
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
	.p2align 4,,15
	.globl	__Z3sumPhi
	.def	__Z3sumPhi;	.scl	2;	.type	32;	.endef
__Z3sumPhi:
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	20(%esp), %esi
	testl	%esi, %esi
	jle	L6
	movl	16(%esp), %edx
	xorl	%eax, %eax
	xorl	%edi, %edi
	addl	%edx, %esi
	.p2align 4,,10
L5:
	movzbl	(%edx), %ecx
	testb	%cl, %cl
	cmovns	%edi, %ecx
	addl	$1, %edx
	addl	%ecx, %eax
	cmpl	%esi, %edx
	jne	L5
L4:
	popl	%ebx
	popl	%esi
	popl	%edi
	ret
L6:
	xorl	%eax, %eax
	jmp	L4
	.p2align 4,,15
	.globl	__Z12getencodelenPKhi
	.def	__Z12getencodelenPKhi;	.scl	2;	.type	32;	.endef
__Z12getencodelenPKhi:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$8, %esp
	movl	32(%esp), %eax
	movl	28(%esp), %edi
	cmpl	$2, %eax
	jle	L12
	cmpl	$127, %eax
	movl	$127, %edx
	movzbl	(%edi), %ecx
	cmovle	%eax, %edx
	movl	$1, %esi
	movl	$1, %ebp
	leal	-1(%edx), %eax
	movl	%edx, 4(%esp)
	movl	$1, %ebx
	xorl	%edx, %edx
	movl	%eax, (%esp)
	jmp	L16
	.p2align 4,,10
L23:
	addl	$1, %ebx
	movl	$2, %esi
	cmpl	$2, %ebx
	je	L15
	testl	%ebp, %ebp
	je	L21
	movl	%ebx, %esi
	movl	$1, %ebp
L15:
	addl	$1, %edx
	cmpl	(%esp), %edx
	movl	%eax, %ecx
	je	L22
L16:
	movzbl	1(%edi,%edx), %eax
	cmpb	%al, %cl
	je	L23
	cmpl	$2, %esi
	jle	L17
	movl	%esi, %eax
	orl	$-128, %eax
L12:
	addl	$8, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,10
L17:
	xorl	%ebp, %ebp
	addl	$1, %edx
	cmpl	(%esp), %edx
	movl	$1, %ebx
	movl	%eax, %ecx
	jne	L16
L22:
	movl	%ebp, %ecx
	movl	$256, %eax
	sarl	%cl, %eax
	orb	4(%esp), %al
	addl	$8, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L21:
	addl	$8, %esp
	leal	-1(%edx), %eax
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
	.p2align 4,,15
	.globl	__Z10RLE_encodePKhiPhi
	.def	__Z10RLE_encodePKhiPhi;	.scl	2;	.type	32;	.endef
__Z10RLE_encodePKhiPhi:
	pushl	%ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$12, %esp
	movl	36(%esp), %edx
	movl	32(%esp), %edi
	movl	$0, 4(%esp)
	testl	%edx, %edx
	jle	L25
	movl	%edi, %ebp
	jmp	L41
	.p2align 4,,10
L59:
	movzbl	36(%esp), %ebx
L27:
	movl	4(%esp), %eax
	movl	40(%esp), %edx
	addl	%eax, %edx
	testb	%bl, %bl
	leal	1(%eax), %esi
	movl	%edx, 8(%esp)
	movb	%bl, (%edx)
	js	L32
	movzbl	%bl, %eax
	testl	%eax, %eax
	je	L58
	movl	40(%esp), %edi
	movl	4(%esp), %ecx
	addl	%esi, %edi
	movl	%edi, %edx
	movl	%edi, (%esp)
	movl	40(%esp), %edi
	leal	5(%edi,%ecx), %ecx
	cmpl	%ecx, %ebp
	setnb	%cl
	movl	%ecx, %edi
	leal	4(%ebp), %ecx
	cmpl	%ecx, %edx
	setnb	%cl
	orl	%edi, %ecx
	movl	%edx, %edi
	orl	%ebp, %edi
	andl	$3, %edi
	sete	%dl
	testb	%dl, %cl
	je	L46
	cmpb	$9, %bl
	jbe	L46
	leal	-4(%eax), %edx
	movl	%eax, 8(%esp)
	movl	(%esp), %eax
	xorl	%ecx, %ecx
	movb	%bl, 4(%esp)
	shrl	$2, %edx
	addl	$1, %edx
	leal	0(,%edx,4), %edi
L37:
	movl	0(%ebp,%ecx,4), %ebx
	movl	%ebx, (%eax,%ecx,4)
	addl	$1, %ecx
	cmpl	%ecx, %edx
	ja	L37
	movl	8(%esp), %eax
	movzbl	4(%esp), %ebx
	leal	(%esi,%edi), %ecx
	movl	%edi, (%esp)
	cmpl	%eax, %edi
	je	L40
	movzbl	0(%ebp,%edx,4), %edx
	movl	40(%esp), %edi
	movb	%dl, (%edi,%ecx)
	movl	(%esp), %edi
	leal	1(%edi), %edx
	cmpl	%eax, %edx
	jge	L40
	movzbl	1(%ebp,%edi), %edx
	movl	40(%esp), %edi
	movb	%dl, 1(%edi,%ecx)
	movl	(%esp), %edi
	leal	2(%edi), %edx
	cmpl	%edx, %eax
	jle	L40
	movzbl	2(%ebp,%edi), %edx
	movl	40(%esp), %edi
	movb	%dl, 2(%edi,%ecx)
L40:
	addl	%esi, %eax
	movl	%eax, 4(%esp)
L33:
	andl	$127, %ebx
	subl	%ebx, 36(%esp)
	movl	36(%esp), %eax
	addl	%ebx, %ebp
	testl	%eax, %eax
	jle	L25
L41:
	cmpl	$2, 36(%esp)
	jle	L59
	cmpl	$127, 36(%esp)
	movl	$127, %eax
	movzbl	0(%ebp), %ecx
	cmovle	36(%esp), %eax
	movl	$1, %ebx
	movl	$1, %edi
	movl	$1, %esi
	movl	%eax, 8(%esp)
	subl	$1, %eax
	movl	%eax, (%esp)
	xorl	%eax, %eax
	jmp	L31
	.p2align 4,,10
L62:
	leal	1(%esi), %ebx
	movl	$2, %esi
	cmpl	$2, %ebx
	je	L30
	testl	%edi, %edi
	je	L60
	movl	%ebx, %esi
	movl	$1, %edi
L30:
	addl	$1, %eax
	cmpl	(%esp), %eax
	movl	%edx, %ecx
	je	L61
L31:
	movzbl	1(%ebp,%eax), %edx
	cmpb	%dl, %cl
	je	L62
	cmpl	$2, %ebx
	jle	L43
	orl	$-128, %ebx
	jmp	L27
	.p2align 4,,10
L43:
	xorl	%edi, %edi
	addl	$1, %eax
	cmpl	(%esp), %eax
	movl	$1, %esi
	movl	%edx, %ecx
	jne	L31
	.p2align 4,,10
L61:
	movl	$256, %ebx
	movl	%edi, %ecx
	sarl	%cl, %ebx
	orb	8(%esp), %bl
	jmp	L27
	.p2align 4,,10
L32:
	movzbl	0(%ebp), %eax
	movl	40(%esp), %edi
	addl	$2, 4(%esp)
	movb	%al, (%edi,%esi)
	jmp	L33
	.p2align 4,,10
L46:
	movl	8(%esp), %edx
	xorl	%ecx, %ecx
	movl	%ebx, %edi
	.p2align 4,,10
L35:
	movzbl	0(%ebp,%ecx), %ebx
	movb	%bl, 1(%edx,%ecx)
	addl	$1, %ecx
	cmpl	%ecx, %eax
	jne	L35
	movl	%edi, %ebx
	jmp	L40
L60:
	leal	-1(%eax), %ebx
	jmp	L27
	.p2align 4,,10
L25:
	movl	4(%esp), %eax
	addl	$12, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	ret
L58:
	movl	%esi, 4(%esp)
	jmp	L33
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii ".\\main.cpp\0"
LC1:
	.ascii "Orz framework Start...\0"
LC2:
	.ascii "rb\0"
LC3:
	.ascii "rle.png\0"
LC4:
	.ascii "wb\0"
LC5:
	.ascii "out.rle\0"
LC6:
	.ascii "A()\0"
LC7:
	.ascii "foo()\0"
LC8:
	.ascii "10:43:33\0"
LC9:
	.ascii "Orz framework End  ...\0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	movl	$8360, %eax
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	call	___chkstk_ms
	subl	%eax, %esp
	call	___main
	movl	$10, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	leal	-8325(%ebp), %eax
	movl	$1, 8(%esp)
	movl	$__ZSt4cout, (%esp)
	movb	$32, -8325(%ebp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$22, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L83
	cmpb	$0, 28(%ebx)
	je	L65
	movzbl	39(%ebx), %eax
L66:
	movsbl	%al, %eax
	movl	$__ZSt4cout, %ecx
	leal	-8320(%ebp), %edi
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	xorl	%eax, %eax
	movl	$1024, %ecx
	rep stosl
	movl	$LC2, 4(%esp)
	movl	$LC3, (%esp)
	movb	$1, -8316(%ebp)
	movb	$1, -8315(%ebp)
	movb	$1, -8314(%ebp)
	movb	$2, -8313(%ebp)
	movb	$2, -8312(%ebp)
	movb	$2, -8311(%ebp)
	movb	$3, -8310(%ebp)
	movb	$3, -8309(%ebp)
	movb	$4, -8308(%ebp)
	movb	$5, -8307(%ebp)
	movb	$6, -8306(%ebp)
	call	_fopen
	movl	$LC4, 4(%esp)
	movl	$LC5, (%esp)
	movl	%eax, -8356(%ebp)
	call	_fopen
	movl	%eax, -8360(%ebp)
	.p2align 4,,10
L82:
	movl	-8356(%ebp), %eax
	movl	$4096, 8(%esp)
	movl	$1, 4(%esp)
	movl	%eax, 12(%esp)
	leal	-8320(%ebp), %eax
	movl	%eax, (%esp)
	call	_fread
	cmpl	$0, %eax
	movl	%eax, -8340(%ebp)
	je	L67
	jle	L87
	leal	-8320(%ebp), %eax
	movl	$0, -8344(%ebp)
	movl	%eax, -8332(%ebp)
	leal	-4224(%ebp), %eax
	movl	%eax, -8348(%ebp)
	movl	-8340(%ebp), %eax
	.p2align 4,,10
L81:
	cmpl	$2, %eax
	movl	%eax, %edx
	jle	L70
	movl	%eax, %edi
	movl	$127, %eax
	movl	$1, %edx
	cmpl	$127, %edi
	movl	$1, %esi
	cmovle	%edi, %eax
	movl	$1, %edi
	movl	%eax, -8352(%ebp)
	subl	$1, %eax
	movl	%eax, -8336(%ebp)
	movl	-8332(%ebp), %eax
	movzbl	(%eax), %ecx
	xorl	%eax, %eax
	jmp	L74
	.p2align 4,,10
L110:
	leal	1(%esi), %edx
	movl	$2, %esi
	cmpl	$2, %edx
	je	L73
	testl	%edi, %edi
	je	L108
	movl	%edx, %esi
	movl	$1, %edi
L73:
	addl	$1, %eax
	cmpl	%eax, -8336(%ebp)
	movl	%ebx, %ecx
	je	L109
L74:
	movl	-8332(%ebp), %ebx
	movzbl	1(%ebx,%eax), %ebx
	cmpb	%cl, %bl
	je	L110
	cmpl	$2, %edx
	jle	L88
	orl	$-128, %edx
L70:
	movl	-8344(%ebp), %eax
	testb	%dl, %dl
	leal	1(%eax), %ebx
	movb	%dl, -4224(%ebp,%eax)
	js	L75
	je	L111
	movl	-8348(%ebp), %edi
	movzbl	%dl, %eax
	cmpl	$4, %eax
	leal	(%edi,%ebx), %esi
	jnb	L78
	testl	%eax, %eax
	je	L79
	movl	-8332(%ebp), %edi
	testb	$2, %al
	movzbl	(%edi), %ecx
	movb	%cl, (%esi)
	jne	L112
L79:
	addl	%ebx, %eax
	movl	%eax, -8344(%ebp)
L76:
	andl	$127, %edx
	subl	%edx, -8340(%ebp)
	addl	%edx, -8332(%ebp)
	movl	-8340(%ebp), %eax
	testl	%eax, %eax
	jg	L81
	movl	-8344(%ebp), %eax
L68:
	movl	-8360(%ebp), %edi
	movl	%eax, 8(%esp)
	movl	-8348(%ebp), %eax
	movl	$1, 4(%esp)
	movl	%edi, 12(%esp)
	movl	%eax, (%esp)
	call	_fwrite
	jmp	L82
	.p2align 4,,10
L88:
	xorl	%edi, %edi
	addl	$1, %eax
	cmpl	%eax, -8336(%ebp)
	movl	$1, %esi
	movl	%ebx, %ecx
	jne	L74
	.p2align 4,,10
L109:
	movl	$256, %edx
	movl	%edi, %ecx
	sarl	%cl, %edx
	orb	-8352(%ebp), %dl
	jmp	L70
	.p2align 4,,10
L78:
	movl	-8332(%ebp), %edi
	movl	(%edi), %ecx
	movl	%ecx, (%esi)
	movl	%edi, -8332(%ebp)
	movl	-4(%edi,%eax), %ecx
	leal	4(%esi), %edi
	andl	$-4, %edi
	movl	%ecx, -4(%esi,%eax)
	movl	%esi, %ecx
	movl	-8332(%ebp), %esi
	subl	%edi, %ecx
	subl	%ecx, %esi
	addl	%eax, %ecx
	shrl	$2, %ecx
	rep movsl
	jmp	L79
	.p2align 4,,10
L75:
	movl	-8332(%ebp), %eax
	addl	$2, -8344(%ebp)
	movzbl	(%eax), %eax
	movb	%al, -4224(%ebp,%ebx)
	jmp	L76
L108:
	leal	-1(%eax), %edx
	jmp	L70
L111:
	movl	%ebx, -8344(%ebp)
	jmp	L76
L112:
	movl	-8332(%ebp), %edi
	movzwl	-2(%edi,%eax), %ecx
	movw	%cx, -2(%esi,%eax)
	jmp	L79
L67:
	movl	-8356(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	-8360(%ebp), %eax
	movl	%eax, (%esp)
	call	_fclose
	movl	$3, 8(%esp)
	movl	$LC6, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$__ZSt4cout, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$5, 8(%esp)
	movl	$LC7, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$__ZSt4cout, (%esp)
	call	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	movl	$8, 8(%esp)
	movl	$LC8, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	leal	-8324(%ebp), %eax
	movl	$1, 8(%esp)
	movl	$__ZSt4cout, (%esp)
	movb	$32, -8324(%ebp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$22, 8(%esp)
	movl	$LC9, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	leal	-8323(%ebp), %eax
	movl	$1, 8(%esp)
	movl	$__ZSt4cout, (%esp)
	movb	$32, -8323(%ebp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$__ZSt4cout, %ecx
	movl	$1, (%esp)
	call	__ZNSolsEi
	leal	-8322(%ebp), %eax
	subl	$4, %esp
	movb	$32, -8322(%ebp)
	movl	$1, 8(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	fldl	LC10
	movl	$__ZSt4cout, %ecx
	fstpl	(%esp)
	call	__ZNSo9_M_insertIdEERSoT_
	leal	-8321(%ebp), %eax
	subl	$8, %esp
	movb	$32, -8321(%ebp)
	movl	$1, 8(%esp)
	movl	$__ZSt4cout, (%esp)
	movl	%eax, 4(%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$3, (%esp)
	movl	$__ZSt4cout, %ecx
	call	__ZNSolsEi
	movl	__ZSt4cout, %eax
	subl	$4, %esp
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L83
	cmpb	$0, 28(%ebx)
	je	L84
	movzbl	39(%ebx), %eax
L85:
	movsbl	%al, %eax
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	leal	-16(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	popl	%ebx
	popl	%esi
	popl	%edi
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
L87:
	leal	-4224(%ebp), %edi
	xorl	%eax, %eax
	movl	%edi, -8348(%ebp)
	jmp	L68
L65:
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L66
	movl	%ebx, %ecx
	movl	$10, (%esp)
	call	*%edx
	pushl	%ecx
	jmp	L66
L84:
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L85
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	pushl	%edx
	jmp	L85
L83:
	call	__ZSt16__throw_bad_castv
	.p2align 4,,15
	.def	__GLOBAL__sub_I__Z3sumPhi;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I__Z3sumPhi:
	subl	$28, %esp
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	ret
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I__Z3sumPhi
.lcomm __ZStL8__ioinit,1,1
	.section .rdata,"dr"
	.align 8
LC10:
	.long	-1531069942
	.long	1073863217
	.ident	"GCC: (tdm-1) 5.1.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	_fopen;	.scl	2;	.type	32;	.endef
	.def	_fread;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_fclose;	.scl	2;	.type	32;	.endef
	.def	__ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZNSo9_M_insertIdEERSoT_;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
