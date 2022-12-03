import math

# data = ['vJrwpWtwJgWrhcsFMMfFFhFp', 'jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL', 'PmmdzqPrVvPwwTWBwg', 'wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn', 'ttgJtRGJQctTZtZT', 'CrZsJsPPZsGzwwsLwLmpwMDw']
with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

# packing = [[i[:math.floor(len(i)/2)], i[math.floor(len(i)/2):]] for i in data]
packing = [[data[i], data[i+1], data[i+2]] for i in range(0, len(data), 3)]

# Character range function
def range_char(start, stop):
    return (chr(n) for n in range(ord(start), ord(stop) + 1))
        
# Example run
priority = 1
priority_map = {}
for character in range_char("a", "z"):
    priority_map[character] = priority
    priority += 1

for character in range_char("A", "Z"):
    priority_map[character] = priority
    priority += 1
# print(priority_map)

priority_sum = 0
for rucksack in packing:
    elfone = rucksack[0]
    elftwo = rucksack[1]
    elfthree = rucksack[2]
    # print(f'compartmenta: {compartment_a}, compartmentb: {compartment_b}')
    first_run = True
    for i in elfone:
        # print(f'the value of of i is: {i}')
        if i in elftwo and i in elfthree and first_run:
            priority_sum += priority_map[i]
            first_run = False

print(priority_sum)

