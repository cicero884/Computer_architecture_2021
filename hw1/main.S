.data
input:		.word 1,3,3,4,5
input_size: .word 5
trueStr:	.string "true\n"
falseStr:	.string "false\n"

.text
main:
la		a0, input  
lw		a1, input_size
jal		isMonotonic

#set message
bnez	a0, trueMsg
la 		a1, falseStr 	#false
j		print	
trueMsg:
la 		a1, trueStr 	#true

print:
li 		a0, 1		# 1 = StdOut
li  	a2, 13	# length of our string
li  	a7, 64	# linux write system call
ecall            	# Call linux to output the string

#exit
li    a0, 0   # Use 0 return code
li    a7, 93  # Service command code 93 terminates
ecall               # Call linux to terminate the program


isMonotonic:
addi	t0, a1, -3	#input_size < 3
bgez	t0 sizeOver3
li 		a0, 0
ret

sizeOver3:
addi	s0, a0, 4	#i
lw		s1, 0(a0)	#prev(first element)
lw		s2, 4(a0)	#next(second element)
slli	s3, a1, 2
add 	s3, s3, a0 	#max_address
li		s4, 0		#result

lw		t0, -4(s3) 	#last element
bgt		s1, t0, decreaseCheckLoop

increaseCheckLoop:
ble		s3, s0, return
slt 	t0, s2, s1 	#next<prev
or 		s4, s4, t0

mv 		s1, s2
addi 	s0, s0, 4
lw 		s2, 0(s0)
j increaseCheckLoop

decreaseCheckLoop:
ble		s3, s0, return
slt 	t0, s1, s2 	#prev<next
or 		s4, s4, t0

mv 		s1, s2
addi 	s0, s0, 4
lw 		s2, 0(s0)
j decreaseCheckLoop

return:
seqz 	a0, s4
ret

