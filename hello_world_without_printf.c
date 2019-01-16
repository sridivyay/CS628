#include <unistd.h>
#include <sys/syscall.h>
#include <stdio.h>
int main(void) {
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
	  asm("syscall");
	  //printf("%d is d",SYS_write); // SYS_write code for system call 
	  return 0;
}