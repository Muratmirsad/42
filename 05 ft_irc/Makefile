FILES = Channel.cpp Client.cpp commands.cpp commands1.cpp operatorCommands.cpp receiveFunct.cpp Server.cpp serverUtils.cpp main.cpp connection.cpp
COMPILER = c++
FLAGS = -std=c++98 -Wall -Wextra -Werror 
OUTPUT_NAME = ircserv

.PHONY: all clean

all: $(OUTPUT_NAME)

$(OUTPUT_NAME): $(FILES)
	$(COMPILER) $(FLAGS) $^ -o $@
	
re: clean all

clean:
	rm -f $(OUTPUT_NAME)
