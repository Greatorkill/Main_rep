; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcmp.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/23 16:26:23 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/25 15:17:30 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global	_ft_strcmp

section .text

_ft_strcmp:
	mov		rcx, -1 ; i = 0
	mov 	r8, 0
	mov 	r9, 0
 	mov 	rax, 0; out = 0

while:
	inc		rcx ; i++
	mov		r8b, byte [rdi + rcx]
	mov		r9b, byte [rsi + rcx]
	cmp		r8, 0
	je		end
	cmp		r9, 0
	je		end
	cmp 	r8, r9
	je		while

end:
	mov 	rax, r8
	sub		rax, r9
	ret
