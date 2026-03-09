	.file	"\346\272\220.cpp"
	.text
	.section	.text$_ZN5ShapeC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN5ShapeC2Ev
	.def	_ZN5ShapeC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN5ShapeC2Ev
_ZN5ShapeC2Ev:
.LFB2197:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	leaq	16+_ZTV5Shape(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9RectangleC2Edd,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9RectangleC2Edd
	.def	_ZN9RectangleC2Edd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9RectangleC2Edd
_ZN9RectangleC2Edd:
.LFB2199:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN5ShapeC2Ev
	leaq	16+_ZTV9Rectangle(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	movq	16(%rbp), %rax
	movsd	32(%rbp), %xmm0
	movsd	%xmm0, 16(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9RectangleC1Edd,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9RectangleC1Edd
	.def	_ZN9RectangleC1Edd;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9RectangleC1Edd
_ZN9RectangleC1Edd:
.LFB2200:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movsd	%xmm2, 32(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN5ShapeC2Ev
	leaq	16+_ZTV9Rectangle(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	movq	16(%rbp), %rax
	movsd	32(%rbp), %xmm0
	movsd	%xmm0, 16(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN9Rectangle7getAreaEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9Rectangle7getAreaEv
	.def	_ZN9Rectangle7getAreaEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9Rectangle7getAreaEv
_ZN9Rectangle7getAreaEv:
.LFB2201:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm1
	movq	16(%rbp), %rax
	movsd	16(%rax), %xmm0
	mulsd	%xmm1, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6CircleC1Ed,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6CircleC1Ed
	.def	_ZN6CircleC1Ed;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6CircleC1Ed
_ZN6CircleC1Ed:
.LFB2204:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN5ShapeC2Ev
	leaq	16+_ZTV6Circle(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm0
	movsd	%xmm0, 8(%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6Circle7getAreaEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6Circle7getAreaEv
	.def	_ZN6Circle7getAreaEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6Circle7getAreaEv
_ZN6Circle7getAreaEv:
.LFB2205:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm1
	movsd	.LC0(%rip), %xmm0
	mulsd	%xmm0, %xmm1
	movq	16(%rbp), %rax
	movsd	8(%rax), %xmm0
	mulsd	%xmm1, %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section	.text$_ZN6SquareC1Ed,"x"
	.linkonce discard
	.align 2
	.globl	_ZN6SquareC1Ed
	.def	_ZN6SquareC1Ed;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN6SquareC1Ed
_ZN6SquareC1Ed:
.LFB2208:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movq	%rcx, 16(%rbp)
	movsd	%xmm1, 24(%rbp)
	movq	16(%rbp), %rax
	movsd	24(%rbp), %xmm1
	movsd	24(%rbp), %xmm0
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN9RectangleC2Edd
	leaq	16+_ZTV6Square(%rip), %rdx
	movq	16(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC1:
	.ascii "\307\353\312\344\310\353\276\330\320\316\265\304\263\244\272\315\277\355\243\272\0"
.LC2:
	.ascii "\307\353\312\344\310\353\324\262\265\304\260\353\276\266\243\272\0"
.LC3:
	.ascii "\307\353\312\344\310\353\325\375\267\275\320\316\265\304\261\337\263\244\243\272\0"
.LC4:
	.ascii "\276\330\320\316\265\304\303\346\273\375\243\272\0"
.LC5:
	.ascii "\324\262\265\304\303\346\273\375\243\272\0"
.LC6:
	.ascii "\325\375\267\275\320\316\265\304\303\346\273\375\243\272\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB2209:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$136, %rsp
	.seh_stackalloc	136
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	call	__main
	leaq	.LC1(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-8(%rbp), %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERd
	movq	%rax, %rcx
	leaq	-16(%rbp), %rax
	movq	%rax, %rdx
	call	_ZNSirsERd
	movsd	-16(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	leaq	-48(%rbp), %rax
	movapd	%xmm1, %xmm2
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN9RectangleC1Edd
	leaq	.LC2(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-24(%rbp), %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERd
	movsd	-24(%rbp), %xmm0
	leaq	-64(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN6CircleC1Ed
	leaq	.LC3(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	leaq	-72(%rbp), %rdx
	movq	.refptr._ZSt3cin(%rip), %rax
	movq	%rax, %rcx
	call	_ZNSirsERd
	movsd	-72(%rbp), %xmm0
	leaq	-96(%rbp), %rax
	movapd	%xmm0, %xmm1
	movq	%rax, %rcx
	call	_ZN6SquareC1Ed
	leaq	.LC4(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	leaq	-48(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Rectangle7getAreaEv
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	.LC5(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN6Circle7getAreaEv
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	leaq	.LC6(%rip), %rdx
	movq	.refptr._ZSt4cout(%rip), %rax
	movq	%rax, %rcx
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rbx
	leaq	-96(%rbp), %rax
	movq	%rax, %rcx
	call	_ZN9Rectangle7getAreaEv
	movq	%xmm0, %rax
	movq	%rax, %xmm1
	movq	%rbx, %rcx
	call	_ZNSolsEd
	movq	%rax, %rcx
	movq	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_(%rip), %rax
	movq	%rax, %rdx
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.globl	_ZTV6Square
	.section	.rdata$_ZTV6Square,"dr"
	.linkonce same_size
	.align 8
_ZTV6Square:
	.quad	0
	.quad	_ZTI6Square
	.quad	_ZN9Rectangle7getAreaEv
	.globl	_ZTV6Circle
	.section	.rdata$_ZTV6Circle,"dr"
	.linkonce same_size
	.align 8
_ZTV6Circle:
	.quad	0
	.quad	_ZTI6Circle
	.quad	_ZN6Circle7getAreaEv
	.globl	_ZTV9Rectangle
	.section	.rdata$_ZTV9Rectangle,"dr"
	.linkonce same_size
	.align 8
_ZTV9Rectangle:
	.quad	0
	.quad	_ZTI9Rectangle
	.quad	_ZN9Rectangle7getAreaEv
	.globl	_ZTV5Shape
	.section	.rdata$_ZTV5Shape,"dr"
	.linkonce same_size
	.align 8
_ZTV5Shape:
	.quad	0
	.quad	_ZTI5Shape
	.quad	__cxa_pure_virtual
	.globl	_ZTI6Square
	.section	.rdata$_ZTI6Square,"dr"
	.linkonce same_size
	.align 8
_ZTI6Square:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS6Square
	.quad	_ZTI9Rectangle
	.globl	_ZTS6Square
	.section	.rdata$_ZTS6Square,"dr"
	.linkonce same_size
	.align 8
_ZTS6Square:
	.ascii "6Square\0"
	.globl	_ZTI6Circle
	.section	.rdata$_ZTI6Circle,"dr"
	.linkonce same_size
	.align 8
_ZTI6Circle:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS6Circle
	.quad	_ZTI5Shape
	.globl	_ZTS6Circle
	.section	.rdata$_ZTS6Circle,"dr"
	.linkonce same_size
	.align 8
_ZTS6Circle:
	.ascii "6Circle\0"
	.globl	_ZTI9Rectangle
	.section	.rdata$_ZTI9Rectangle,"dr"
	.linkonce same_size
	.align 8
_ZTI9Rectangle:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS9Rectangle
	.quad	_ZTI5Shape
	.globl	_ZTS9Rectangle
	.section	.rdata$_ZTS9Rectangle,"dr"
	.linkonce same_size
	.align 8
_ZTS9Rectangle:
	.ascii "9Rectangle\0"
	.globl	_ZTI5Shape
	.section	.rdata$_ZTI5Shape,"dr"
	.linkonce same_size
	.align 8
_ZTI5Shape:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS5Shape
	.globl	_ZTS5Shape
	.section	.rdata$_ZTS5Shape,"dr"
	.linkonce same_size
_ZTS5Shape:
	.ascii "5Shape\0"
	.section .rdata,"dr"
	.align 8
.LC0:
	.long	1374389535
	.long	1074339512
	.weak	__cxa_pure_virtual
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev8, Built by MSYS2 project) 15.2.0"
	.def	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc;	.scl	2;	.type	32;	.endef
	.def	_ZNSirsERd;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEd;	.scl	2;	.type	32;	.endef
	.def	_ZNSolsEPFRSoS_E;	.scl	2;	.type	32;	.endef
	.def	__cxa_pure_virtual;	.scl	2;	.type	32;	.endef
	.section	.rdata$.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.linkonce	discard
.refptr._ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_:
	.quad	_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	.section	.rdata$.refptr._ZSt3cin, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt3cin
	.linkonce	discard
.refptr._ZSt3cin:
	.quad	_ZSt3cin
	.section	.rdata$.refptr._ZSt4cout, "dr"
	.p2align	3, 0
	.globl	.refptr._ZSt4cout
	.linkonce	discard
.refptr._ZSt4cout:
	.quad	_ZSt4cout
