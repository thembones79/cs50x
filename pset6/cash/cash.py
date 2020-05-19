def get_positive_float(prompt_value):
    positive = -1.0
    while (positive < 0):
        positive = float(input(prompt_value))
    return positive


dollars = get_positive_float("Change owed: ")


def returned_coins(dollars):
    cents = round(dollars * 100)
    quarters = cents // 25
    remaining = cents % 25
    dimes = remaining // 10
    remaining = remaining % 10
    nickels = remaining // 5
    pennies = remaining % 5
    return quarters + dimes + nickels + pennies


coins = returned_coins(dollars)
print(coins)
