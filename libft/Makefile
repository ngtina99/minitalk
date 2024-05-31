NAME			= libft.a

SRCS			=	ft_split.c ft_strlcat.c \
					ft_substr.c ft_atoi.c \
					ft_strchr.c ft_strlcpy.c  \
					ft_strdup.c  ft_strlen.c \
					ft_strjoin.c ft_strtrim.c \
					ft_printf.c ft_chars.c ft_nums.c ft_strcmp.c

OBJ				= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -Wall -Werror -Wextra

$(NAME):		$(OBJ)
				ar rc $(NAME) $(OBJ) 

all:			$(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)