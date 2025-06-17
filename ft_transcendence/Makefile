all:
	docker-compose down
	docker-compose up --build

down:
		@docker compose -f ./docker-compose.yml down

clean: down
		@docker system prune -a -f

re: clean
	docker-compose down
	docker-compose up --build
	rm ./backend/database.db

.PHONY: clean down tw

