	.file	"main.cpp"
	.text
	.def	__main;	.scl	2;	.type	32;	.endef
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	cmpl	$1, -4(%rbp)
	je	.L10
	cmpl	$2, -4(%rbp)
	jmp	.L5
.L10:
	nop
.L5:
	cmpl	$1, -4(%rbp)
	jne	.L6
	movl	$1, -4(%rbp)
	jmp	.L7
.L6:
	cmpl	$2, -4(%rbp)
	jne	.L8
	movl	$2, -4(%rbp)
	jmp	.L7
.L8:
	movl	$3, -4(%rbp)
.L7:
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.ident	"GCC: (x86_64-win32-sjlj-rev0, Built by MinGW-W64 project) 8.1.0"
