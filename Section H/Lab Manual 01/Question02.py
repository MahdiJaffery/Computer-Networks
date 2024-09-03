readFilePath = "./Input.txt"
writeFilePath = "./Output.txt"

readFile = open(readFilePath, "r")
writeFilePath = open(writeFilePath, "w")

lines = readFile.readlines()

for line in lines:
    words = line.split()
    for letter in words:
        if letter.isdigit() and not letter.isalpha():
            writeFilePath.write(letter)
            if len(letter) < len(line):
                writeFilePath.write(" ")
