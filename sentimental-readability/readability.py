from cs50 import get_int, get_string, get_float
import math

text = get_string('text: ')
sentences, letters, words = 0, 0, 0


for i in range(len(text)):
    # formula for sentences
    if text[i] == '.' or text[i] == '!' or text[i] == '?':
        sentences += 1
    # formula for letters
    if text[i].isalpha():
        letters += 1
    # formula for words
    if (i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text[i + 1] != ' '):
        words += 1
    i += 1

# Coleman-Liau index formula
S = sentences / words * 100
L = letters / words * 100

# print expected grade level
index = round(0.0588 * L - 0.296 * S - 15.8)
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
