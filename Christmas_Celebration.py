# Define the function
def space(a, b, c):
    return (a - 1) + b * (c - 1)

condition = True

# Allow user to enter parameter
layers = int(input("Enter the number of layers (2 to 5) = "))
top_length = int(input("Enter the side length of the top layer = "))
growth = int(input("Enter the growth of each layer = "))
width = int(input("Enter the trunk width (odd number, 3 to 9) = "))
height = int(input("Enter the trunk height (4 to 10) = "))

# Allow Money Test
while condition:
    if (layers < 2) or (layers > 5):
        print("***The layers is invalid, please try again***")
        layers = int(input("Enter the number of layers (2 to 5) = "))
        continue
    elif ((width < 3) or (width > 9)) or (width % 2 == 0):
        print("***The trunk width is invalid, please try again***")
        width = int(input("Enter the trunk width (odd number, 3 to 9) = "))
        continue
    elif (height < 4) or (height > 10):
        print("***The trunk height is invalid, please try again***")
        height = int(input("Enter the trunk height (4 to 10) = "))
        continue
    else:
        condition = False

# Print out Christmas Tree
# First layer
print(" " * space(top_length, growth, layers) + "#")
for index in range(1, top_length - 1):
    print(" " * (space(top_length, growth, layers) - index) + "#" + "@" * (2 * index - 1) + "#")
print(" " * (space(top_length, growth, layers) - (top_length - 1)) + "#" * (2 * (top_length - 1) + 1))

# Other layers
for index1 in range(1, layers):
    for index2 in range(1, top_length + growth * index1 - 1):
        print(" " * (space(top_length, growth, layers) - index2) + "#" + "@" * (2 * index2 - 1) + "#")
    print(" " * (space(top_length, growth, layers) - (index2 + 1)) + "#" * (2 * (index2 + 1) + 1))

# Print out the trunks
for index in range(height):
    print(" " * (space(top_length, growth, layers) - (width - 1) // 2) + "|" * width)
