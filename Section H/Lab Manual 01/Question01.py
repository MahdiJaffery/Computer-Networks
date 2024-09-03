def nonAlhpabetical(word):
    for character in word:
        if character.isalpha():
            return False
    return True


readFile_path = "./Input.txt"
writeFile_path = "./Output.txt"

read_file = open(readFile_path, "r")
write_file = open(writeFile_path, "w")

lines = read_file.readlines()

for line in lines:
    words = line.split()
    for word in words:
        if nonAlhpabetical(word):
            write_file.write(word)
        if len(word) < len(line):
            write_file.write(" ")
    write_file.write("\n")
