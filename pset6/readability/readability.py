def count_letters(text):
    counter = 0
    for i in text:
        if ((i >= "a" and i <= "z") or (i >= "A" and i <= "Z")):
            counter += 1
    return counter


def count_words(text):
    counter = 1
    for i in text:
        if (i == " "):
            counter += 1
    return counter


def count_sentences(text):
    counter = 0
    for i in text:
        if (i == "." or i == "!" or i == "?"):
            counter += 1
    return counter


def coleman_liau_index(text):
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    L = 100 * letters / words
    S = 100 * sentences / words
    return 0.0588 * L - 0.296 * S - 15.8


def get_grade(text):
    index = coleman_liau_index(text)
    if (index < 1):
        print("Before Grade 1")
    elif (index >= 16):
        print("Grade 16+")
    else:
        grade = int(round(index))
        print(f"Grade {grade}")


text = input("Text: ")
get_grade(text)
