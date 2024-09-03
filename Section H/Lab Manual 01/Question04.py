def containsVowels(word):
    for letter in word:
        if letter.lower() in "aeiou":
            return True
    return False


readFilePath = "./Input.txt"
writeFilePath = "./Output.txt"

readFile = open(readFilePath, "r")
writeFile = open(writeFilePath, "w")

lines = readFile.readlines()

for line in lines:
    words = line.split()
    for word in words:
        if containsVowels(word):
            word = "".join(reversed(word))
        writeFile.write(word)
        if len(word) < len(line):
            writeFile.write(" ")
