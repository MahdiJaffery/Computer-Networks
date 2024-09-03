readFilePath = "./Input.txt"

readFile = open(readFilePath, "r")

lines = readFile.readlines()

for line in lines:
    print(line)
