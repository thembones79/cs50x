from sys import argv, exit
import cs50
import csv


def main():
    basic_input_validation()
    insert_csv_into_db(argv[1])
    exit(0)


def basic_input_validation():
    if len(argv) != 2:
        print("Usage: python import.py characters.csv")
        exit(1)


def insert_csv_into_db(csv_filename):
    db = cs50.SQL("sqlite:///students.db")
    with open(csv_filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            name = row["name"]
            name_list = name.split(" ")
            if len(name_list) == 2:
                name_list.insert(1, None)
            row["first"] = name_list[0]
            row["middle"] = name_list[1]
            row["last"] = name_list[2]
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       row["first"], row["middle"], row["last"], row["house"], row["birth"])


main()
