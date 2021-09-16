import re

def count_overlapping(text, search_for):
    return sum(1 for _ in re.finditer('(?='+search_for+')',text))

s = raw_input()
al = raw_input()

print count_overlapping(al, s)
# haha
# ahahahahashes