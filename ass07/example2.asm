section .data
sys_call  dq 60

section .text
    global _start
_start:
    mov rax, 60
    mov rdi, [sys_call]
    syscall
