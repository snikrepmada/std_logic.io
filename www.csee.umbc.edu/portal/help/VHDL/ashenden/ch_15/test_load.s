	lbu	r1, b1
	lbu	r1, b2
	lbu	r1, b3
	lbu	r1, b4
	
	lb	r1, b1
	lb	r1, b2
	lb	r1, b3
	lb	r1, b4

	lhu	r1, h1
	lhu	r1, h2
	
	lh	r1, h1
	lh	r1, h2

	lw	r1, w1
	
	trap	0

b1:	.byte	0xf1
b2:	.byte	0xf2
b3:	.byte	0xf3
b4:	.byte	0xf4
h1:	.byte   0xf5
	.byte	0xf5
h2:	.byte	0xf6
	.byte	0xf6
w1:	.word	0xf7f7f7f7
	
	