DC := docker-compose -f ./srcs/docker-compose.yml

all:
	@sudo mkdir -p /home/data/wordpress
	@sudo mkdir -p /home/data/mysql
	@sudo $(DC) up -d --build

down:
	@sudo $(DC) down

re: clean all

clean:
	@sudo $(DC) down -v --remove-orphans

.PHONY: all down re clean