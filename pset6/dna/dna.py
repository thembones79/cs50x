from sys import argv, exit
import csv
import re


def main():
    basic_input_validation()
    dna_database = argv[1]
    dna_sequence_file = argv[2]
    list_of_STR = list_of_STRs(dna_database)
    dna_sequence = textfile_to_string(dna_sequence_file)
    suspect = create_suspect(list_of_STR, dna_sequence)
    match = find_suspect_in_dna_base(suspect, dna_database)
    print(match)
    exit(0)


def basic_input_validation():
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)


def list_of_STRs(csv_filename):
    with open(csv_filename, "r") as file:
        reader = csv.DictReader(file)
        first_row = file.readline()
        first_row = first_row.strip()  # removes '\n' at the end of the line
        str_list = re.split(",", first_row)
        del str_list[0]  # we want just "STRs" columns (no "name" column)
        return str_list


def textfile_to_string(filename):
    f = open(filename, "r")
    contents = f.read()
    f.close()
    return contents


def longest_run_of_consecutive_repeats(sought_str, dna_sequence):
    # just for more straightforward counting
    x = re.sub(sought_str, "*", dna_sequence)
    count = 0
    list_of_counts = []

    for i in x:
        if i == "*":
            count += 1
        else:
            list_of_counts.append(count)
            count = 0
    list_of_counts.append(count)
    return max(list_of_counts)


def find_suspect_in_dna_base(suspect, csv_filename):
    with open(csv_filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            count = 0
            for x in row:
                if (row[x] == suspect[x]):
                    count += 1
            if count == len(suspect)-1:  # we don't count "name" column (first column)
                return row["name"]
    return "No match"


def create_suspect(list_of_STR, dna_sequence):
    suspect = {'name': '_suspect'}
    for i in list_of_STR:
        suspect[i] = str(longest_run_of_consecutive_repeats(i, dna_sequence))
    return suspect


main()
