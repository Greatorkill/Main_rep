; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strcpy.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/23 16:26:27 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/23 16:26:28 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strcpy

section .text

_ft_strcpy:
	mov 	rcx, -1
	mov 	rdx, 0

while:
	inc 	rcx
	cmp 	byte [rsi + rcx], 0
	je 		end
	mov 	dl, byte [rsi + rcx]
	mov 	byte [rdi + rcx], dl
	jmp 	while

end:
	mov 	dl, byte [rsi + rcx]
	mov 	byte [rdi + rcx], dl
	mov 	rax, rdi
	ret
