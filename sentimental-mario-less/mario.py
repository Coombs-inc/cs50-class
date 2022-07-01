from cs50 import get_int

# promptuser for positive number
while True:
    n = get_int('height: ')
    if n >= 1 and n <= 8:
        break

# print row and column
for i in range(n):
    for c in range(n):
        if i + c >= n - 1:
            print('#', end='')
        else:
            print(' ', end='')
    print()