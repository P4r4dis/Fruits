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

fclean					:	clean
							$(RM) $(NAME) $(TEST_NAME)
							@$(MAKE) $(FCLEAN) -C $(PART0_TST_PATH)
							@$(MAKE) $(FCLEAN) -C $(PART0_PATH)

re						: 	fclean all

part0 					: 	fclean
							@$(MAKE) -C $(PART0_PATH)
							$(PART0_PATH)/$(NAME_FRUIT)

tests_run_part0			:	fclean
							@$(MAKE) -C $(PART0_TST_PATH)
							$(PART0_TST_PATH)/$(TEST_NAME_FRUIT)

tests_run				:	fclean
							@$(MAKE) tests_run_part0

.PHONY					: 	all clean fclean re part0 tests_run_part0 tests_run
