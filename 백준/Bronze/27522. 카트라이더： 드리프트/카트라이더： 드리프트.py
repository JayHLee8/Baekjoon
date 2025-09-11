alllaptime = {}
 
for i in range(8):
    laptime, team = input().split()
    m, s, ms = laptime.split(":")
    result = float(str(int(m) * 60 + int(s)) + "." + ms)
    alllaptime[result] = team
 
alllaptime = sorted(alllaptime.items())
 
point = [10, 8, 6, 5, 4, 3, 2, 1]
R=0
B=0
 
for i in range(8):
    if alllaptime[i][1] == "R":
        R += point[i]
    else:
        B += point[i]
 
if R > B:
    print("Red")
else:
    print("Blue")