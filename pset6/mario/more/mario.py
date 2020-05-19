def validate_input(min, max):
    height = 0
    while height < int(min) or height > int(max):
        height = int(input("Height: "))
    return height


def draw_line_of_characters(character_to_draw, number_of_characters):
    for i in range(1, number_of_characters+1):
        print(character_to_draw, end="")


def draw_pyramid(height):
    for i in range(1, height+1):
        draw_line_of_characters(" ", height - i)
        draw_line_of_characters("#", i)
        print(" ", end="")
        draw_line_of_characters("#", i)
        print("")


draw_pyramid(validate_input(1, 8))
