# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jikwon <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/13 22:13:22 by jikwon            #+#    #+#              #
#    Updated: 2020/02/13 22:14:31 by jikwon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc -Werror -Wextra -Wall -c *.c 
ar rc libft.a *.c