# **************************************************************************** #
#																			  #
#														 :::	  ::::::::	#
#	Makefile										   :+:	  :+:	:+:	#
#													 +:+ +:+		 +:+	  #
#	By: pcruz <pcruz@student.42.fr>				+#+  +:+	   +#+		 #
#												 +#+#+#+#+#+   +#+			#
#	Created: 2024/10/18 10:37:54 by pbranco-		  #+#	#+#			  #
#	Updated: 2025/01/20 07:58:11 by pcruz			###   ########.fr		#
#																			  #
# **************************************************************************** #

SRCS	= ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_atol.c \
		ft_isdigitplussign.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strdup.c \
		ft_calloc.c \
		ft_lstadd_front.c \
		ft_lstadd_back.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstsize.c \
		ft_lstnew.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_strcmp.c \
		get_next_line.c \
		get_next_line_utils.c \
		ft_print_pointer.c \
		ft_print_unsigned.c \
		ft_printc.c \
		ft_printf.c \
		ft_printhex.c \
		ft_printnbr.c \
		ft_printstr.c \
		ft_put_hex.c \
		ft_uitoa.c \
		ft_strcjoin.c \
		ft_strncpy.c \
		ft_strncat.c \
		ft_strstr.c \
		ft_split_wdelim.c \
		ft_strcat.c \
		ft_arraylen.c \
		ft_strtrim_free.c \
		ft_strdup_free.c \
		ft_strcpy.c \
		ft_split_utils.c \
		ft_strndup.c \
		ft_isspace.c \
		ft_strndup_free.c \
		ft_atolli.c \

OBJS	= ${SRCS:.c=.o}
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
