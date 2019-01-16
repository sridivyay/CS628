all: hello_world_without_printf

CFLAGS=-O3 -fno-stack-protector -Wno-format-security

hello_world_without_printf: hello_world_without_printf.c
	gcc  -o hello_world_without_printf hello_world_without_printf.c