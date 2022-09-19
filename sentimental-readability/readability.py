# TODO
from cs50 import get_string

letters = 0
words = 1
sentences = 0

text = get_string("Text: ")

for i in text:
    if i.isalpha():
        letters += 1

    elif i == " ":
        words += 1

    elif i == "." or i == "!" or i == "?":
        sentences += 1

L = (letters/words*100)
S = (sentences/words*100)

index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")

print(f"Grade: {index}")
