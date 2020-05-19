def main():
    cardNumber = getPositiveLong("Number: ")
    print(validateCardNumber(cardNumber))


def getPositiveLong(promptText):
    positive = -1
    while (positive < 0):
        positive = int(input(promptText))
    return positive


def sumOfEvenDigitsMultipliedBy2(cardNumber):
    counter = 0
    reminder = 0
    sumOfDoubleEvens = 0
    doubleReminder = 0
    while (cardNumber > 0):
        reminder = cardNumber % 10
        cardNumber = cardNumber // 10
        counter += 1
        if (counter % 2 == 0):
            doubleReminder = reminder * 2
            if (doubleReminder > 9):
                doubleReminder = doubleReminder - 9
            sumOfDoubleEvens = sumOfDoubleEvens + doubleReminder
    return sumOfDoubleEvens


def sumOfOddDigits(cardNumber):
    counter = 0
    reminder = 0
    sumOfOdds = 0
    while (cardNumber > 0):
        reminder = cardNumber % 10
        cardNumber = cardNumber // 10
        counter += 1
        if (counter % 2 != 0):
            sumOfOdds += reminder
    return sumOfOdds


def checksum(cardNumber):
    sum = sumOfEvenDigitsMultipliedBy2(cardNumber) + sumOfOddDigits(cardNumber)
    return sum % 10


def countDigits(cardNumber):
    counter = 0
    while (cardNumber > 0):
        cardNumber = cardNumber // 10
        counter += 1
    return counter


def firstDigit(cardNumber):
    reminder = 0
    while (cardNumber > 0):
        reminder = cardNumber % 10
        cardNumber = cardNumber // 10
    return reminder


def firstTwoDigits(cardNumber):
    while (cardNumber > 99):
        cardNumber = cardNumber // 10
    return cardNumber


def isVisa(cardNumber):
    return ((countDigits(cardNumber) == 13 or countDigits(cardNumber) == 16) and firstDigit(cardNumber) == 4)


def isAmEx(cardNumber):
    return (countDigits(cardNumber) == 15 and (firstTwoDigits(cardNumber) == 34 or firstTwoDigits(cardNumber) == 37))


def isMasterCard(cardNumber):
    return (countDigits(cardNumber) == 16 and (firstTwoDigits(cardNumber) >= 51 and firstTwoDigits(cardNumber) <= 55))


def validateCardNumber(cardNumber):
    if (checksum(cardNumber)):

        return "INVALID\n"

    if (isVisa(cardNumber)):

        return "VISA\n"

    if (isAmEx(cardNumber)):

        return "AMEX\n"

    if (isMasterCard(cardNumber)):

        return "MASTERCARD\n"

    return "INVALID\n"


main()
