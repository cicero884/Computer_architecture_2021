SHELL := /bin/bash

gcc:=riscv-none-embed-gcc
flags:=-march=rv32i -mabi=ilp32 -nostdlib

main:
	$(gcc) $(flags) -O0 main.c -o main

objdump:
	riscv-none-embed-objdump -d main

elf:
	riscv-none-embed-readelf -h main

size:
	riscv-none-embed-size main

optimize:
	$(gcc) $(flags) -O3 main.c -o main

env:
	source ~/code/example_reference/riscv-none-gcc/setenv
