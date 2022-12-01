with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

def sum_calories(data, sum=0):
    calories = []
    for items in data:
        try:
            sum += int(items)
        except ValueError:
            calories.append(sum)
            sum = 0
            continue
    return calories

def max_elf(data, top_three=0, top_one=0):
    for i in range(3):
        highest = max(data)
        if i == 0:
            top_one += highest
        top_three += highest
        data.remove(highest)

    return f'top three total = {top_three}, top individual calories = {top_one}'

elf_calories = sum_calories(data)
elf_most = max_elf(elf_calories)
print(elf_most)

