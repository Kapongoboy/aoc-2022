with open('./input.txt', 'r') as file:
    data = [i.strip('\n') for i in file.readlines()]

# data = ["nznrnfrfntjfmvfwmzdfjlvtqnbhcprsg"]

def find_marker(message):
    for i in range(len(message)):
        if i > 13:
            check_string = message[i-14:i]
            if len(check_string) == len(set(check_string)):
                return i
                

if __name__ == "__main__":
    marker = find_marker(data[0])
    print(marker)
