# Score categories
# Change the values as you see fit
YACHT = 0
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 12


def score(dice, category):
    dice_sum = 0
    count = [0, 0, 0, 0, 0, 0]
    if category >= ONES and category <= SIXES:
        for i in range(5):
            if dice[i] == category:
                dice_sum += category
    else:
        for i in range(5):
            count[dice[i]-1] += 1
        for i in range(6):
            if category == FULL_HOUSE and 2 in count and 3 in count:
                dice_sum = sum(dice)
            if category == FOUR_OF_A_KIND and 4 in count:
                dice_sum = (count.index(4)+1) * 4
            if category == FOUR_OF_A_KIND and 5 in count:
                dice_sum = (count.index(5)+1) * 4
            if category == LITTLE_STRAIGHT and sorted(dice) == [1, 2, 3, 4, 5]:
                dice_sum = 30
            if category == BIG_STRAIGHT and sorted(dice) == [2, 3, 4, 5, 6]:
                dice_sum = 30
            if category == CHOICE:
                dice_sum = sum(dice)
            if category == YACHT and 5 in count:
                dice_sum = 50

    return(dice_sum)
