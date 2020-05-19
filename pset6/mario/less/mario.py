height = 0
while height < 1 or height > 8:
    height = int(input("Height: "))

for i in range(1, height+1):
    k = height
    while k > i:
        print(" ", end="")
        k -= 1
    for j in range(1, i+1):
        print("#", end="")
    print("")
