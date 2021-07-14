import os

def Parse(line):
  line = line.strip("( )")
  p = line.split(" ")
  if len(p) < 3:
    return (0, 0)
  return float(p[1]), float(p[2])

def ReadFile(name):
  print("'%s':" % name)
  coords = []
  try:
    f = open(name, "r")
    lines = f.read().split("\n")
    f.close()
    #print("read %d lines" % len(lines))
    for i in range(0, len(lines) - 1):
      if lines[i].find("module MountingHole") == -1:
        continue
      if lines[i + 1].find("(at ") == -1:
        continue
      #print("Found hole at line:", i, lines[i + 1])
      point = Parse(lines[i + 1])
      coords.append(point)
      #print(point)

    spoint = sorted(coords, key = lambda p: (p[0], p[1])) # wtf?! ;)
    CheckHoles(spoint)
  except IOError:
    print("Can't open file")
    return

def CheckHoles(p):
  if len(p) != 4:
    print("**** Should check only 4 holes PCB")
    return
  #print(p)

  # is it square?
  x = 0
  y = 1
  if p[0][x] != p[1][x]:
    print("**** Left edge wrong")
  if p[2][x] != p[3][x]:
    print("**** Right edge wrong")
  if p[0][y] != p[2][y]:
    print("**** Top edge wrong")
  if p[1][y] != p[3][y]:
    print("**** Top edge wrong")

  # check sizes
  w = p[2][x] - p[0][x]
  h = p[1][y] - p[0][y]
  print("%3.2f x %3.2f" % (w, h))

def Holes(name):
  holes = ReadFile(name)

items = os.listdir(".")
#py = pathlib.Path().glob("*.kicad_pcb")
for i in items:
  if os.path.isdir(i):
    sub = os.listdir(i)
    for s in sub:
      if s.find(".kicad_pcb") != -1 and s.find("-bak") == -1:
        Holes(i + os.sep + s)
