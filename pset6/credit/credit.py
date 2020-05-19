# include <stdio.h>
# include <cs50.h>

long getPositiveLong(string promptValue)
string validateCardNumber(long cardNumber)

int main(void)
{
    long cardNumber = getPositiveLong("Number: ")
    printf("%s", validateCardNumber(cardNumber))
}

long getPositiveLong(string promptText)
{
    long positive
    do
    {
        positive = get_long("%s", promptText)
    } while (positive < 0)
    return positive
}

int sumOfEvenDigitsMultipliedBy2(long cardNumber)
{
    int counter = 0
    int reminder = 0
    int sumOfDoubleEvens = 0
    int doubleReminder = 0

    while (cardNumber > 0)
    {
        reminder = cardNumber % 10
        cardNumber = cardNumber / 10
        counter++
        if (counter % 2 == 0)
        {
            doubleReminder = reminder * 2
            if (doubleReminder > 9)
            {
                doubleReminder = doubleReminder - 9
            }
            sumOfDoubleEvens = sumOfDoubleEvens + doubleReminder
        }
    }

    return sumOfDoubleEvens
}

int sumOfOddDigits(long cardNumber)
{
    int counter = 0
    int reminder = 0
    int sumOfOdds = 0

    while (cardNumber > 0)
    {
        reminder = cardNumber % 10
        cardNumber = cardNumber / 10
        counter++
        if (counter % 2 != 0)
        {
            sumOfOdds += reminder
        }
    }

    return sumOfOdds
}

int checksum(long cardNumber)
{
    int sum = sumOfEvenDigitsMultipliedBy2(cardNumber) + sumOfOddDigits(cardNumber)
    return sum % 10
}

int countDigits(long cardNumber)
{
    int counter = 0

    while (cardNumber > 0)
    {
        cardNumber = cardNumber / 10
        counter++
    }

    return counter
}

int firstDigit(long cardNumber)
{
    int reminder = 0

    while (cardNumber > 0)
    {
        reminder = cardNumber % 10
        cardNumber = cardNumber / 10
    }

    return reminder
}

long firstTwoDigits(long cardNumber)
{
    while (cardNumber > 99)
    {
        cardNumber = cardNumber / 10
    }

    return cardNumber
}

bool isVisa(long cardNumber)
{
    return ((countDigits(cardNumber) == 13 | | countDigits(cardNumber) == 16) & & firstDigit(cardNumber) == 4)
}

bool isAmEx(long cardNumber)
{
    return (countDigits(cardNumber) == 15 & & (firstTwoDigits(cardNumber) == 34 | | firstTwoDigits(cardNumber) == 37))
}

bool isMasterCard(long cardNumber)
{
    return (countDigits(cardNumber) == 16 & & (firstTwoDigits(cardNumber) >= 51 & & firstTwoDigits(cardNumber) <= 55))
}

string validateCardNumber(long cardNumber)
{
    if (checksum(cardNumber))
    {
        return "INVALID\n"
    }

    if (isVisa(cardNumber))
    {
        return "VISA\n"
    }

    if (isAmEx(cardNumber))
    {
        return "AMEX\n"
    }

    if (isMasterCard(cardNumber))
    {
        return "MASTERCARD\n"
    }

    return "INVALID\n"
}
