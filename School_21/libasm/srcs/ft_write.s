; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_write.s                                         :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/19 17:50:16 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/19 17:59:34 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global 	_ft_write
extern ___error

section .text

_ft_write:
	mov 	rax, 0x2000004
	syscall
	jc 		error_write
	ret

error_write:
	push 	rax
	call 	___error
	pop 	qword [rax]
	mov 	rax, -1
	ret
