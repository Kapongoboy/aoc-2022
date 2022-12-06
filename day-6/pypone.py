with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

# data = ["nppdvjthqldpwncqszvftbrmjlhg"]

def find_marker(message):
    for i in range(len(message)):
        if i > 3:
            check_string = message[i-4:i+1]
            if len(check_string) == len(set(check_string)):
                return i
                

if __name__ == "__main__":
    marker = find_marker(data[0])
    print(marker)
