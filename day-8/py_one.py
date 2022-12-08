import numpy as np

with open('./example.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

border_trees = 2*(len(data[0])) + 2*(len(data)) - 4

# check the trees that appear in the rows
matrix_: np.array = np.array([[int(tree) for tree in row] for row in data])
row_max_index = matrix_.argmax(1)
col_max_index = matrix_.argmax(0)
print('\nMatrix: ')
print(matrix_)
print('\nindex of row max: ')
print(row_max_index)
# print(col_max_index)
row_max_val = matrix_.max(1)
col_max_val = matrix_.max(0)

# print('\n')
# print(col_max_val)
# print('\n')
# print(row_max_val)

# print('\ncolumns')
# for row in matrix_:
#     print(row[0])
# print("end")

print('\n')
# check left, right, top, bottom

total = 0
for row in matrix_:
    # if row != matrix_[0] and row != matrix_[-1]:
    tree = max(row)
    top = np.array_equal(row, matrix_[0])
    bot = np.array_equal(row, matrix_[-1])
    if not top and not bot and tree != row[0] and tree != row[-1]:
        if len(np.nonzero(row == tree)[0]) > 1:
            print("counted two")
            total += 2
        else:
            print("counted one")
            total += 1
    else:
        print("failed check")
        print(tree, row)
print(total)
    # for tree in range(len(row)):
        # print(row[:tree+1])
        # check_left = row[:tree+1]
        # print(max(row[:tree+1]))
        # print(row[tree:])
        # check_right = row[tree:]
        # print(max(row[tree:]))


