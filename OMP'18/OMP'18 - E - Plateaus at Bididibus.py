import re


casos = input()
casos = int(casos)
for i in range(casos):

    s = input()

    s = re.sub("////*", "a", s)
    s = re.sub("_+", "b", s)
    s = re.sub(r"\\\\\\\\*", "c", s)

    print(len(re.findall("abc", s)))
