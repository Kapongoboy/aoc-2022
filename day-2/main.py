# choice_map = {'X': 0, 'Y': 3, 'Z': 6}
# rock = 1, paper = 2, scissors = 3
round_map = {
        'A X': 3,
        'A Y': 4,
        'A Z': 8,
        'B X': 1,
        'B Y': 5,
        'B Z': 9,
        'C X': 2,
        'C Y': 6,
        'C Z': 7,
        }
# data = ['A Y', 'B X', 'C Z']
with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

score = 0
for i in data:
    score += round_map[i]

print(f'the total score was: {score}')



