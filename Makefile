##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## NanoTekSpice
##

SRC= src/main.cpp \
	src/AComponent.cpp \
	src/Circuit.cpp \
	src/ElementaryComponents/AndComponent.cpp \
	src/ElementaryComponents/OrComponent.cpp \
	src/ElementaryComponents/XorComponent.cpp \
	src/ElementaryComponents/NotComponent.cpp \
	src/SpecialComponents/ClockComponent.cpp \
	src/SpecialComponents/FalseComponent.cpp \
	src/SpecialComponents/TrueComponent.cpp \
	src/SpecialComponents/OutputComponent.cpp \
	src/SpecialComponents/InputComponent.cpp \
	src/GatesComponents/NorComponent.cpp \
	src/GatesComponents/NandComponent.cpp \
	src/GatesComponents/Component4001.cpp \
	src/GatesComponents/Component4011.cpp \
	src/GatesComponents/Component4030.cpp \
	src/GatesComponents/Component4069.cpp \
	src/GatesComponents/Component4071.cpp \
	src/GatesComponents/Component4081.cpp \
	src/Parsing/Parsing.cpp  			  \
	src/Parsing/ReadFile.cpp 			  \
	src/Simulator.cpp					  \
	src/LoopOn.cpp

OBJ=$(SRC:.cpp=.o)

NAME=nanotekspice

CPPFLAGS=-iquote ./include

CFLAGS=-Wall -Wextra -Werror -std=c++20

RM?=rm -f

all: $(NAME)

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re all