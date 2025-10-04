.section .text
.global sortNumbers

# Функция сортировки пузырьком
# rdi - array, rsi - count
# возвращает rax - количество перемещенных элементов

sortNumbers:
    pushq %rbp
    movq %rsp, %rbp
    pushq %rbx
    pushq %r12
    pushq %r13
    pushq %r14
    
    movq %rdi, %rbx        # сохраняем указатель на массив
    movl %esi, %r12d       # сохраняем количество элементов
    movl $0, %r13d         # счетчик перемещений = 0
    
    # Если элементов меньше 2, возвращаем 0
    cmpl $2, %r12d
    jl .done
    
    # Внешний цикл: i от n-1 до 1
    movl %r12d, %eax
    decl %eax              # eax = i = n-1
    movl %eax, %r14d       # r14 = i
    
.outer_loop:
    cmpl $0, %r14d         # while (i > 0)
    jle .done
    
    # Внутренний цикл: j от 0 до i-1
    movl $0, %ecx          # j = 0
    
.inner_loop:
    cmpl %r14d, %ecx       # j < i?
    jge .inner_done
    
    # Загружаем array[j] и array[j+1]
    movl (%rbx, %rcx, 4), %eax    # eax = array[j]
    movl 4(%rbx, %rcx, 4), %edx   # edx = array[j+1]
    
    # Сравниваем
    cmpl %edx, %eax
    jle .no_swap
    
    # Меняем местами
    movl %edx, (%rbx, %rcx, 4)    # array[j] = array[j+1]
    movl %eax, 4(%rbx, %rcx, 4)   # array[j+1] = array[j]
    
    # Увеличиваем счетчик перемещений
    incl %r13d
    
.no_swap:
    incl %ecx              # j++
    jmp .inner_loop
    
.inner_done:
    decl %r14d             # i--
    jmp .outer_loop
    
.done:
    movl %r13d, %eax       # возвращаем количество перемещений
    
    popq %r14
    popq %r13
    popq %r12
    popq %rbx
    popq %rbp
    ret
