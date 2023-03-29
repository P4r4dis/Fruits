G++						=	g++
###############################################
PART0_PATH 				= 	./part0_Fruit
PART0_SRC_PATH			=	./part0_Fruit/src
PART0_TST_PATH			=	./part0_Fruit/tests
PART0_INC_PATH			=	./part0_Fruit/include
NAME_FRUIT				=	Fruit
PART0_SRC				=	$(PART0_SRC_PATH)/Fruit.cpp

PART0_SRC_TEST			=	$(PART0_TST_PATH)/$(NAME_FRUIT)_test.cpp
TEST_NAME_FRUIT 		= 	test_$(NAME_FRUIT)

###############################################
PART1_PATH 				= 	./part1_Fruit
PART1_SRC_PATH			=	./part1_Fruit/src
PART1_TST_PATH			=	./part1_Fruit/tests
PART1_INC_PATH			=	./part1_Fruit/include
NAME_FRUIT				=	Fruit
PART1_SRC				=	$(PART1_SRC_PATH)/Fruit.cpp

PART1_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_FRUIT)_test.cpp
TEST_NAME_FRUIT 		= 	test_$(NAME_FRUIT)

###############################################
PART2_PATH 				= 	./part2_Fruit
PART2_SRC_PATH			=	./part2_Fruit/src
PART2_TST_PATH			=	./part2_Fruit/tests
PART2_INC_PATH			=	./part2_Fruit/include
NAME_FRUIT				=	Fruit
PART2_SRC				=	$(PART1_SRC_PATH)/Fruit.cpp

PART2_SRC_TEST			=	$(PART1_TST_PATH)/$(NAME_FRUIT)_test.cpp
TEST_NAME_FRUIT 		= 	test_$(NAME_FRUIT)

###############################################
BIN_PATH				=	./bin

NAME					=	Fruit
TEST_NAME 				= 	test_$(NAME)

INCFLAGS				+=	-I $(PART6_INC_PATH)

CPPFLAGS				+= 	-Wall -Wextra -Werror $(INCFLAGS) -std=c++20

SRCS 					= 	$(PART0_SRC) \
							$(BIN_PATH)/main.cpp							

OBJS					=	$(SRCS:.cpp=.o)
CLEAN					=	clean
FCLEAN					=	fclean

all						:	$(NAME)

$(NAME)					:	$(OBJS)
							$(G++) $(OBJS) $(CPPFLAGS) -o $(NAME)

RM						=	rm -rf

clean					:
							$(RM) $(OBJS)
							@$(MAKE) $(CLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(CLEAN) -C $(PART2_TST_PATH)

fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART1_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART2_PATH)

re						: 	fclean all

part0 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_FRUIT)

tests_run_part0			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_FRUIT)

part1 					: 	fclean
							@$(MAKE) -C $(PART1_PATH)
							$(PART1_PATH)/$(NAME_FRUIT)

tests_run_part1			:	fclean
							@$(MAKE) -C $(PART1_TST_PATH)
							$(PART1_TST_PATH)/$(TEST_NAME_FRUIT)

part2 					: 	fclean
							@$(MAKE) -C $(PART2_PATH)
							$(PART2_PATH)/$(NAME_FRUIT)

tests_run_part2			:	fclean
							@$(MAKE) -C $(PART2_TST_PATH)
							$(PART2_TST_PATH)/$(TEST_NAME_FRUIT)

tests_run				:	fclean
							@$(MAKE) tests_run_part0
							@$(MAKE) tests_run_part1
							@$(MAKE) tests_run_part2

.PHONY					: 	all clean fclean re part0 tests_run_part0 part1 tests_run_part1 tests_run
