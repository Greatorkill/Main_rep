; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strdup.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/23 16:26:31 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/23 16:26:32 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global 	_ft_strdup

extern	_ft_strlen
extern	_ft_strcpy
extern	_malloc

section .text

_ft_strdup:
	call	_ft_strlen
	inc 	rax

	push	rdi
	mov		rdi, rax
	call	_malloc

	cmp 	rax, 0
	je 		error

	pop 	rdi
	mov		rsi, rdi
	mov		rdi, rax
	call	_ft_strcpy

	ret

error:
	pop rdi
	ret
