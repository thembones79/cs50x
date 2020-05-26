from sys import argv, exit
import cs50
import csv


def main():
    basic_input_validation()
    students_of_the_house(argv[1])
    exit(0)


def basic_input_validation():
    if len(argv) != 2:
        print("Usage: python roster.py HouseName")
        exit(1)


def students_of_the_house(house_name):
    db = cs50.SQL("sqlite:///students.db")
    rows = db.execute(
        "SELECT * FROM students WHERE house=? ORDER BY last, first", house_name)
    for row in rows:
        first = row["first"]
        middle = " "+row["middle"]+" " if row["middle"] else " "
        last = row["last"]
        house = row["house"]
        birth = row["birth"]
        print(f"{first}{middle}{last}, born {birth}")


main()
