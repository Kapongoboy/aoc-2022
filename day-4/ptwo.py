# data = ["2-4,6-8", "2-3,4-5", "5-7,7-9", "2-8,3-7", "6-6,4-6", "2-6,4-8"]
from pprint import pprint

with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

pairs = [i.split(",") for i in data]

# print(pairs)
def pair_counting(pairs):
    elfone = pairs[0].split("-")
    elftwo = pairs[1].split("-")
    assignment_one = [i for i in range(int(elfone[0]), int(elfone[1])+1)]
    assignment_two = [i for i in range(int(elftwo[0]), int(elftwo[1])+1)]
    if len(assignment_one) <= len(assignment_two):
        for i in assignment_one:
            if i in assignment_two:
                return 1
        return 0
    else:
        for i in assignment_two:
            if i in assignment_one:
                return 1
        return 0
        
sum = 0
for i in range(len(data)):
    sum += pair_counting(pairs[i])

print(f"the sum of ones completely incapsulated is: {sum}")

