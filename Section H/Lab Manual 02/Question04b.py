readFilePath = "./Input.txt"
writeFilePath = "./Output.txt"

readFile = open(readFilePath, "r")
writeFile = open(writeFilePath, "w")

lines = readFile.readlines()

for line in lines:
    words = line.split()
    for word in words:
        if word.isdigit() and not word.isalpha():
            writeFile.write(word)
            if len(word) < len(line):
                writeFile.write(" ")