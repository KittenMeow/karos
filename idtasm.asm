%macro isr_good 1
	global _isr%1
	_isr%1:
        extern _isr_%1_handler
        cli
		pushad
        cld
        call _isr_%1_handler
        popad
        iret
%endmacro

%macro isr_bad 1
	global _isr%1
	_isr%1:
        extern _isr_%1_handler
        cli
		pushad
        cld
        call _isr_%1_handler
        popad
        iret
%endmacro


%macro irq 1
	global _irq%1
	_irq%1:
        extern _irq_%1_handler
        cli
		pushad
        cld
        call _irq_%1_handler
        popad
        iret
%endmacro

isr_good 0
isr_good 1
isr_good 2
isr_good 3
isr_good 4
isr_good 5
isr_good 6
isr_good 7
isr_bad   8
isr_good 9
isr_bad   10
isr_bad   11
isr_bad   12
isr_bad   13
isr_bad   14
isr_good 15
isr_good 16
isr_good 17
isr_good 18
isr_good 19
isr_good 20
isr_good 21
isr_good 22
isr_good 23
isr_good 24
isr_good 25
isr_good 26
isr_good 27
isr_good 28
isr_good 29
isr_good 30
isr_good 31


; Interrupt Requests
irq 0
irq 1
irq 2
irq 3
irq 4
irq 5
irq 6
irq 7
irq 8
irq 9
irq 10
irq 11
irq 12
irq 13
irq 14
irq 15
