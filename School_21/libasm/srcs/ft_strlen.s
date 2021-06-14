; **************************************************************************** ;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    ft_strlen.s                                        :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2021/04/23 16:26:35 by kgeorgia          #+#    #+#              ;
;    Updated: 2021/04/23 16:26:36 by kgeorgia         ###   ########.fr        ;
;                                                                              ;
; **************************************************************************** ;

global _ft_strlen

section .text

_ft_strlen:
	mov 	rax, -1

while:
	inc 	rax
	cmp		byte [rdi + rax], 0
	jne		while
	ret
