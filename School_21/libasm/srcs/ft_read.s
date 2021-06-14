; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_read.s                                          :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/23 16:26:17 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/25 15:19:30 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global 	_ft_read
extern ___error

section .text

_ft_read:
	mov 	rax, 0x2000003
	syscall
	jc 		error_read
	ret

error_read:
	push 	rax
	call 	___error
	pop 	qword [rax]
	mov 	rax, -1
	ret
