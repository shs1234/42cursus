# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hoseoson <hoseoson@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/03 22:35:13 by hoseoson          #+#    #+#              #
#    Updated: 2024/01/18 20:22:39 by hoseoson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

up : 
	docker-compose -f ./srcs/docker-compose.yml up -d

down :
	docker-compose -f ./srcs/docker-compose.yml down

clean_images :
	docker image prune

clean_containers :
	docker container prune

clean_volumes :
	docker volume prune

clean_networks :
	docker network prune

clean : clean_containers clean_volumes clean_networks

re : down up

fclean : clean clean_images

.PHONY : up down clean_images clean_containers clean_volumes clean_networks clean re fclean