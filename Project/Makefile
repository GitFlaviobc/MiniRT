NAME = miniRT

MLX_DIR = mlx
MLX = $(MLX_DIR)/libmlx.a

VALGRIND = valgrind --leak-check=full --track-origins=yes -q

CAMERA = camera/
COLOR = color/
ERROR = error/
FREE = free_end/
LIGHT = light/
MAIN = main/
MATERIAL = material/
PARSER = parser/
RAY = ray/
SHAPES = shapes/
VECTOR = vector/
SRC_DIR = src
OBJ_DIR = obj

INCLUDE_DIR = includes

SRC_FILES = $(CAMERA)ft_camera.c \
			$(COLOR)ft_colors.c $(COLOR)ft_pixel.c $(COLOR)ft_color_math.c \
			$(ERROR)ft_errors.c \
			$(FREE)ft_end_rt.c $(FREE)ft_frees.c $(FREE)ft_obj_free.c \
			$(LIGHT)ft_light.c $(LIGHT)ft_light_check.c \
			$(LIGHT)ft_light_list.c $(LIGHT)ft_shadow.c \
			$(MAIN)ft_canvas.c $(MAIN)ft_minirt.c \
			$(MAIN)ft_minirt_utils.c $(MAIN)ft_start_rt.c \
			$(MATERIAL)ft_material.c \
			$(PARSER)ft_elements_to_scene.c $(PARSER)ft_get_next_line.c \
			$(PARSER)ft_get_next_line_utils.c $(PARSER)ft_obj_to_scene.c \
			$(PARSER)ft_parser.c $(PARSER)ft_parser_open_read.c $(PARSER)ft_parser_limits.c \
			$(PARSER)ft_parser_utils.c $(PARSER)ft_parse_values.c $(PARSER)ft_split.c \
			$(RAY)ft_hit.c $(RAY)ft_ray.c $(RAY)ft_ray_shooter.c \
			$(SHAPES)ft_check_cylinder.c $(SHAPES)ft_check_pick.c $(SHAPES)ft_check_plane.c \
			$(SHAPES)ft_check_sphere.c $(SHAPES)ft_check_utils.c $(SHAPES)ft_obj.c \
			$(SHAPES)ft_obj_intersect.c $(SHAPES)ft_obj_list.c $(SHAPES)ft_obj_set.c \
			$(VECTOR)ft_vector_float_math.c $(VECTOR)ft_vector_math.c $(VECTOR)ft_vector_dot_cross.c \
			$(VECTOR)ft_vector_math_new.c $(VECTOR)ft_vector_normal.c $(VECTOR)ft_vectors.c \

SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

CFLAGS = -g3 -Wall -Werror -Wextra
CC = clang $(CFLAGS)
LIBFLAGS = -lXext -lX11 -lmlx -lm
RM = rm -rf

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	$(CC) $(OBJ) -L$(MLX_DIR) $(LIBFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/$(CAMERA)
	@mkdir -p $(OBJ_DIR)/$(COLOR)
	@mkdir -p $(OBJ_DIR)/$(ERROR)
	@mkdir -p $(OBJ_DIR)/$(FREE)
	@mkdir -p $(OBJ_DIR)/$(LIGHT)
	@mkdir -p $(OBJ_DIR)/$(MAIN)
	@mkdir -p $(OBJ_DIR)/$(MATERIAL)
	@mkdir -p $(OBJ_DIR)/$(PARSER)
	@mkdir -p $(OBJ_DIR)/$(RAY)
	@mkdir -p $(OBJ_DIR)/$(SHAPES)
	@mkdir -p $(OBJ_DIR)/$(VECTOR)
	$(CC) -c -I$(INCLUDE_DIR) -o $@ $<

$(MLX):
	make -C $(MLX_DIR)

run: $(NAME)
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_DIR)

fclean: clean
	@make -C $(MLX_DIR) clean
	$(RM) $(NAME)

errors: $(NAME)
	./miniRT scenes/2_ambient.rt ; \
	./miniRT scenes/2_camera.rt ; \
	./miniRT scenes/2_light.rt ; \
	./miniRT scenes/no_ambient.rt ; \
	./miniRT scenes/no_camera.rt ; \
	./miniRT scenes/no_light.rt ; \
	./miniRT scenes/invalid.rt ; \
	./miniRT scenes/invalid.rtyyrtrtr ; \
	./miniRT scenes/notfound.rt ; \
	./miniRT

re: fclean all

.PHONY: all clean fclean re errors