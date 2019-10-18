	.file ""
	.section .rodata.cst8,"a",@progbits
	.align	16
caml_negf_mask:
	.quad	0x8000000000000000
	.quad	0
	.align	16
caml_absf_mask:
	.quad	0x7fffffffffffffff
	.quad	-1
	.data
	.globl	camlLista2__data_begin
camlLista2__data_begin:
	.text
	.globl	camlLista2__code_begin
camlLista2__code_begin:
	.data
	.align	8
	.quad	4864
	.globl	camlLista2
camlLista2:
	.quad	1
	.quad	1
	.quad	1
	.quad	1
	.data
	.align	8
	.globl	camlLista2__gc_roots
camlLista2__gc_roots:
	.quad	camlLista2
	.quad	0
	.text
	.align	16
	.globl	camlLista2__fib_80
camlLista2__fib_80:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_adjust_cfa_offset 24
.L104:
	cmpq	$1, %rax
	je	.L102
	cmpq	$3, %rax
	je	.L103
	movq	%rax, (%rsp)
	addq	$-2, %rax
	call	camlLista2__fib_80@PLT
.L100:
	movq	%rax, 8(%rsp)
	movq	(%rsp), %rax
	addq	$-4, %rax
	call	camlLista2__fib_80@PLT
.L101:
	movq	8(%rsp), %rbx
	addq	%rbx, %rax
	decq	%rax
	addq	$24, %rsp
	.cfi_adjust_cfa_offset -24
	ret
	.cfi_adjust_cfa_offset 24
	.align	4
.L103:
	movq	$3, %rax
	addq	$24, %rsp
	.cfi_adjust_cfa_offset -24
	ret
	.cfi_adjust_cfa_offset 24
	.align	4
.L102:
	movq	$1, %rax
	addq	$24, %rsp
	.cfi_adjust_cfa_offset -24
	ret
	.cfi_adjust_cfa_offset 24
	.cfi_adjust_cfa_offset -24
	.cfi_endproc
	.type camlLista2__fib_80,@function
	.size camlLista2__fib_80,. - camlLista2__fib_80
	.text
	.align	16
	.globl	camlLista2__fib_t_82
camlLista2__fib_t_82:
	.cfi_startproc
.L106:
	movq	$1, %rbx
	jmp	camlLista2__ins_84@PLT
	.cfi_endproc
	.type camlLista2__fib_t_82,@function
	.size camlLista2__fib_t_82,. - camlLista2__fib_t_82
	.text
	.align	16
	.globl	camlLista2__ins_84
camlLista2__ins_84:
	.cfi_startproc
	subq	$24, %rsp
	.cfi_adjust_cfa_offset 24
.L112:
	cmpq	$1, %rax
	je	.L110
	cmpq	$3, %rax
	je	.L111
	movq	%rbx, 8(%rsp)
	movq	%rax, (%rsp)
	addq	$-2, %rax
	call	camlLista2__ins_84@PLT
.L108:
	movq	%rax, 16(%rsp)
	movq	(%rsp), %rax
	addq	$-4, %rax
	movq	8(%rsp), %rbx
	call	camlLista2__ins_84@PLT
.L109:
	movq	16(%rsp), %rbx
	addq	%rbx, %rax
	decq	%rax
	addq	$24, %rsp
	.cfi_adjust_cfa_offset -24
	ret
	.cfi_adjust_cfa_offset 24
	.align	4
.L111:
	movq	$3, %rbx
	movq	$1, %rax
	jmp	.L112
	.align	4
.L110:
	movq	%rbx, %rax
	addq	$24, %rsp
	.cfi_adjust_cfa_offset -24
	ret
	.cfi_adjust_cfa_offset 24
	.cfi_adjust_cfa_offset -24
	.cfi_endproc
	.type camlLista2__ins_84,@function
	.size camlLista2__ins_84,. - camlLista2__ins_84
	.text
	.align	16
	.globl	camlLista2__abs_88
camlLista2__abs_88:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_adjust_cfa_offset 8
.L114:
	movq	%rax, %rbx
	xorpd	%xmm0, %xmm0
	movsd	(%rbx), %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L113
.L115:
	subq	$16, %r15
	movq	caml_young_limit@GOTPCREL(%rip), %rax
	cmpq	(%rax), %r15
	jb	.L116
	leaq	8(%r15), %rax
	movq	$1277, -8(%rax)
	movsd	.L118(%rip), %xmm0
	mulsd	(%rbx), %xmm0
	movsd	%xmm0, (%rax)
	addq	$8, %rsp
	.cfi_adjust_cfa_offset -8
	ret
	.cfi_adjust_cfa_offset 8
	.align	4
.L113:
	movq	%rbx, %rax
	addq	$8, %rsp
	.cfi_adjust_cfa_offset -8
	ret
	.cfi_adjust_cfa_offset 8
.L116:
	call	caml_call_gc@PLT
.L117:
	jmp	.L115
	.cfi_adjust_cfa_offset -8
	.cfi_endproc
	.type camlLista2__abs_88,@function
	.size camlLista2__abs_88,. - camlLista2__abs_88
	.text
	.align	16
	.globl	camlLista2__root3_90
camlLista2__root3_90:
	.cfi_startproc
.L120:
	movq	$1, %rsi
	movq	camlLista2__1@GOTPCREL(%rip), %rdi
	jmp	camlLista2__ins_93@PLT
	.cfi_endproc
	.type camlLista2__root3_90,@function
	.size camlLista2__root3_90,. - camlLista2__root3_90
	.text
	.align	16
	.globl	camlLista2__ins_93
camlLista2__ins_93:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_adjust_cfa_offset 8
.L130:
	movq	%rax, %rdx
	xorpd	%xmm0, %xmm0
	movsd	(%rdx), %xmm1
	comisd	%xmm1, %xmm0
	jbe	.L129
	movsd	.L118(%rip), %xmm1
	mulsd	(%rdx), %xmm1
.L129:
	mulsd	(%rbx), %xmm1
	movsd	(%rdi), %xmm0
	mulsd	(%rdi), %xmm0
	mulsd	(%rdi), %xmm0
	subsd	(%rdx), %xmm0
	xorpd	%xmm2, %xmm2
	comisd	%xmm0, %xmm2
	jbe	.L128
	movsd	.L118(%rip), %xmm2
	mulsd	%xmm0, %xmm2
	jmp	.L127
	.align	4
.L128:
	movapd	%xmm0, %xmm2
.L127:
	comisd	%xmm2, %xmm1
	jb	.L126
	movq	%rdi, %rax
	addq	$8, %rsp
	.cfi_adjust_cfa_offset -8
	ret
	.cfi_adjust_cfa_offset 8
	.align	4
.L126:
	cmpq	$1, %rsi
	jne	.L124
	movsd	.L131(%rip), %xmm0
	movsd	(%rdx), %xmm1
	comisd	%xmm0, %xmm1
	jbe	.L125
.L132:
	subq	$16, %r15
	movq	caml_young_limit@GOTPCREL(%rip), %rax
	cmpq	(%rax), %r15
	jb	.L133
	leaq	8(%r15), %rdi
	movq	$1277, -8(%rdi)
	movsd	.L135(%rip), %xmm0
	movsd	(%rdx), %xmm1
	divsd	%xmm0, %xmm1
	movsd	%xmm1, (%rdi)
	movq	$3, %rsi
	movq	%rdx, %rax
	jmp	.L130
	.align	4
.L125:
	movq	$3, %rsi
	movq	%rdx, %rax
	movq	%rdx, %rdi
	jmp	.L130
	.align	4
.L124:
.L136:
	subq	$16, %r15
	movq	caml_young_limit@GOTPCREL(%rip), %rax
	cmpq	(%rax), %r15
	jb	.L137
	leaq	8(%r15), %rcx
	movq	$1277, -8(%rcx)
	movsd	.L135(%rip), %xmm0
	movsd	(%rdi), %xmm1
	mulsd	(%rdi), %xmm1
	movsd	(%rdx), %xmm2
	divsd	%xmm1, %xmm2
	subsd	(%rdi), %xmm2
	divsd	%xmm0, %xmm2
	addsd	(%rdi), %xmm2
	movsd	%xmm2, (%rcx)
	addq	$2, %rsi
	movq	%rdx, %rax
	movq	%rcx, %rdi
	jmp	.L130
.L137:
	call	caml_call_gc@PLT
.L138:
	jmp	.L136
.L133:
	call	caml_call_gc@PLT
.L134:
	jmp	.L132
	.cfi_adjust_cfa_offset -8
	.cfi_endproc
	.type camlLista2__ins_93,@function
	.size camlLista2__ins_93,. - camlLista2__ins_93
	.data
	.align	8
	.quad	4087
camlLista2__15:
	.quad	caml_curry4
	.quad	9
	.quad	camlLista2__ins_93
	.data
	.align	8
	.quad	4087
camlLista2__16:
	.quad	caml_curry2
	.quad	5
	.quad	camlLista2__ins_84
	.data
	.align	8
	.quad	2045
	.globl	camlLista2__1
camlLista2__1:
	.quad	0
	.data
	.align	8
	.quad	2045
	.globl	camlLista2__2
camlLista2__2:
	.quad	0xbff0000000000000
	.data
	.align	8
	.quad	2045
camlLista2__3:
	.quad	0x3ff0000000000000
	.data
	.align	8
	.quad	2045
camlLista2__4:
	.quad	0x4008000000000000
	.data
	.align	8
	.quad	2044
camlLista2__5:
	.ascii	"\12"
	.space	6
	.byte	6
	.data
	.align	8
	.quad	2044
camlLista2__6:
	.ascii	"\12"
	.space	6
	.byte	6
	.data
	.align	8
	.quad	2044
camlLista2__7:
	.ascii	"\12"
	.space	6
	.byte	6
	.data
	.align	8
	.quad	2045
camlLista2__8:
	.quad	0x4034000000000000
	.data
	.align	8
	.quad	2045
camlLista2__9:
	.quad	0x34b8851a0b548ea4
	.data
	.align	8
	.quad	2044
camlLista2__10:
	.ascii	"\12"
	.space	6
	.byte	6
	.data
	.align	8
	.quad	4087
camlLista2__11:
	.quad	caml_curry2
	.quad	5
	.quad	camlLista2__root3_90
	.data
	.align	8
	.quad	3063
camlLista2__12:
	.quad	camlLista2__abs_88
	.quad	3
	.data
	.align	8
	.quad	3063
camlLista2__13:
	.quad	camlLista2__fib_t_82
	.quad	3
	.data
	.align	8
	.quad	3063
camlLista2__14:
	.quad	camlLista2__fib_80
	.quad	3
	.text
	.align	16
	.globl	camlLista2__entry
camlLista2__entry:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_adjust_cfa_offset 8
.L152:
	movq	camlLista2__14@GOTPCREL(%rip), %rax
	movq	camlLista2@GOTPCREL(%rip), %rbx
	movq	%rax, (%rbx)
	movq	camlLista2__13@GOTPCREL(%rip), %rax
	movq	%rax, 8(%rbx)
	movq	camlLista2__12@GOTPCREL(%rip), %rax
	movq	%rax, 16(%rbx)
	movq	camlLista2__11@GOTPCREL(%rip), %rax
	movq	%rax, 24(%rbx)
	movq	camlLista2__5@GOTPCREL(%rip), %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L139:
	movq	$21, %rax
	call	camlLista2__fib_80@PLT
.L140:
	call	camlStdlib__string_of_int_161@PLT
.L141:
	movq	%rax, %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L142:
	movq	camlLista2__6@GOTPCREL(%rip), %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L143:
	movq	$21, %rax
	call	camlLista2__fib_t_82@PLT
.L144:
	call	camlStdlib__string_of_int_161@PLT
.L145:
	movq	%rax, %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L146:
	movq	camlLista2__7@GOTPCREL(%rip), %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L147:
	movq	camlLista2__9@GOTPCREL(%rip), %rbx
	movq	camlLista2__8@GOTPCREL(%rip), %rax
	call	camlLista2__root3_90@PLT
.L148:
	call	camlStdlib__string_of_float_172@PLT
.L149:
	movq	%rax, %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L150:
	movq	camlLista2__10@GOTPCREL(%rip), %rbx
	movq	camlStdlib@GOTPCREL(%rip), %rax
	movq	304(%rax), %rax
	call	camlStdlib__output_string_224@PLT
.L151:
	movq	$1, %rax
	addq	$8, %rsp
	.cfi_adjust_cfa_offset -8
	ret
	.cfi_adjust_cfa_offset 8
	.cfi_adjust_cfa_offset -8
	.cfi_endproc
	.type camlLista2__entry,@function
	.size camlLista2__entry,. - camlLista2__entry
	.data
	.align	8
	.section .rodata.cst8,"a",@progbits
.L135:
	.quad	0x4008000000000000
.L131:
	.quad	0x3ff0000000000000
.L118:
	.quad	0xbff0000000000000
	.text
	.globl	camlLista2__code_end
camlLista2__code_end:
	.data
				/* relocation table start */
	.align	8
				/* relocation table end */
	.data
	.quad	0
	.globl	camlLista2__data_end
camlLista2__data_end:
	.quad	0
	.align	8
	.globl	camlLista2__frametable
camlLista2__frametable:
	.quad	20
	.quad	.L151
	.word	17
	.word	0
	.align	8
	.quad	.L153
	.quad	.L150
	.word	17
	.word	0
	.align	8
	.quad	.L154
	.quad	.L149
	.word	17
	.word	0
	.align	8
	.quad	.L155
	.quad	.L148
	.word	17
	.word	0
	.align	8
	.quad	.L156
	.quad	.L147
	.word	17
	.word	0
	.align	8
	.quad	.L153
	.quad	.L146
	.word	17
	.word	0
	.align	8
	.quad	.L157
	.quad	.L145
	.word	17
	.word	0
	.align	8
	.quad	.L158
	.quad	.L144
	.word	17
	.word	0
	.align	8
	.quad	.L159
	.quad	.L143
	.word	17
	.word	0
	.align	8
	.quad	.L153
	.quad	.L142
	.word	17
	.word	0
	.align	8
	.quad	.L157
	.quad	.L141
	.word	17
	.word	0
	.align	8
	.quad	.L158
	.quad	.L140
	.word	17
	.word	0
	.align	8
	.quad	.L160
	.quad	.L139
	.word	17
	.word	0
	.align	8
	.quad	.L153
	.quad	.L138
	.word	16
	.word	4
	.word	3
	.word	5
	.word	7
	.word	9
	.align	8
	.quad	.L134
	.word	16
	.word	2
	.word	3
	.word	9
	.align	8
	.quad	.L117
	.word	16
	.word	1
	.word	3
	.align	8
	.quad	.L109
	.word	33
	.word	1
	.word	16
	.align	8
	.quad	.L161
	.quad	.L108
	.word	33
	.word	2
	.word	0
	.word	8
	.align	8
	.quad	.L162
	.quad	.L101
	.word	33
	.word	1
	.word	8
	.align	8
	.quad	.L163
	.quad	.L100
	.word	33
	.word	1
	.word	0
	.align	8
	.quad	.L164
	.align	8
.L162:
	.long	(.L165 - .) + -1744830464
	.long	49584
	.quad	0
	.align	8
.L159:
	.long	(.L165 - .) + 1342177280
	.long	147616
	.quad	0
	.align	8
.L155:
	.long	(.L166 - .) + -268435456
	.long	1979024
	.quad	0
	.align	8
.L161:
	.long	(.L165 - .) + 1610612736
	.long	49360
	.quad	0
	.align	8
.L157:
	.long	(.L166 - .) + -536870912
	.long	1974560
	.quad	0
	.align	8
.L164:
	.long	(.L165 - .) + 1879048192
	.long	16704
	.quad	0
	.align	8
.L156:
	.long	(.L165 - .) + 2080374784
	.long	155840
	.quad	0
	.align	8
.L163:
	.long	(.L165 - .) + 1140850688
	.long	16528
	.quad	0
	.align	8
.L158:
	.long	(.L166 - .) + -536870912
	.long	1974896
	.quad	0
	.align	8
.L160:
	.long	(.L165 - .) + 1207959552
	.long	139424
	.quad	0
	.align	8
.L154:
	.long	(.L166 - .) + -268435456
	.long	1978688
	.quad	0
	.align	8
.L153:
	.long	(.L166 - .) + -1409286144
	.long	1966416
	.quad	0
.L166:
	.ascii	"stdlib.ml\0"
	.align	8
.L165:
	.ascii	"lista2.ml\0"
	.align	8
	.section .note.GNU-stack,"",%progbits
