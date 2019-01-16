#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	const char* string = "\nhello, world!\n";

	/*
	 	1. System call with direct sys call 
	*/
	
	//syscall(SYS_write, 1, "hello, world!\n", 14);
	/*
		2. System call using assembly code 
	*/
	  register int    syscall_no  asm("rax") = 1; // System call no is 1
	  register int    arg1        asm("rdi") = 1; // fd 
	  register char*  arg2        asm("rsi") = "hello, test!\n"; // buffer to print
	  register int    arg3        asm("rdx") = 10; // number of characters to print 
	  asm volatile("syscall");
	  //printf("%d is d",SYS_write); // SYS_write code for system call 
	
	/*
		3. Using inline 
	*/
	asm volatile(
		"movq $1, %%rax\n"
		"movq $2, %%rdi\n"
		"movq %0, %%rsi\n"
		"movq $14, %%rdx\n"
		"syscall\n"
		: 
		: "r"(string)
		: "%rax", "%rdi", "%rsi", "%rdx"
	);
	  return 0;
	
	
}