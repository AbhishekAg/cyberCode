
import re

find_list = []
for member in dir(re):
    if "find" in member:
      find_list.append(member)

print(sorted(find_list))
