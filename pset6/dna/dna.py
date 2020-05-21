from sys import argv, exit
import csv

# for i in range(len(argv)):
#   print(argv[i])

# for arg in argv:
#   print(arg)


# if len(argv) != 2:
#   print("missing command-line argument")
#    exit(1)

print(f"hello, {argv[1]}")
print(f"hello, {argv[2]}")

# print("hi")


counts = {}

with open(argv[1], "r") as file:
    reader = csv.DictReader(file)

    for row in reader:
        title = row["name"]
        if title in counts:
            counts[title] += 1
        else:
            counts[title] = 1

for title, count in counts.items():
    print(title, count, sep=" | ")


f = open(argv[2], "r")
contents = f.read()

print(contents)


exit(0)


# read csv

# read txt

# count STRs in txt file

# search in csv for STRs counts from txt

# print result
