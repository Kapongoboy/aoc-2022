from pprint import pprint

with open('./example.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]
    data = data[1:]

file_tree = {"/":{}}

path = ["/"]

for line in data:
    part = line.split(" ")
    if part[0] == '$':
        if part[1] == "cd":
            if part[2] == "..":
                path.pop()
            else:
                path.append(part[2])
    else:
        file_branch = file_tree
        for i in path:
            file_branch = file_branch[i]
            cwd = file_branch
        try:
            cwd[part[1]] = int(part[0])
        except ValueError:
            cwd[part[1]] = {}

# pprint(file_tree)

root = [file_tree["/"]]
# branches = []
# count = 0
# for item in root:
#     if type(root[item]) == dict:
#         branches.append(root[item])
#     else:
#         count += root[item]
# print(f"sum: {count}")
# print(branches)
# print("\n")

def sum_files(directory, sum_list, count, branch):
    pprint(f"sum list: {sum_list}")
    pprint(f"directories: {directory}")
    for item in directory:
        for i in item:
            if type(item[i]) == dict:
                branch.append(item[i])
            else:
                count += item[i]
        print(f"sum: {count}")
        if count <= 100000:
            sum_list.append(count)
            count = 0
    print(branch)
    if len(branch) != 0:
        sum_files(directory=branch, sum_list=sum_list, count=0, branch=[])
    else:
        print(sum(sum_list))
        return 0

cheese = sum_files(root, [], 0, [])
# print(sum_files(branches, [], 0, []))
# sum = 0
# new_branch = []
# for item in branches:
#     for i in item:
#         if type(item[i]) == dict:
#             new_branch.append(item[i])
#         else:
#             sum += item[i]
# print(f"sum: {sum}")
# print(new_branch)

# sum = 0
# lx = []
# for item in new_branch:
#     for i in item:
#         if type(item[i]) == dict:
#             new_branch.append(item[i])
#         else:
#             sum += item[i]
# print(f"sum: {sum}")
# print(lx)
