import sys

lines = []

def ReadFile(name):
  print("Try to move holes in '%s'" % name)
  holes_idx = []
  try:
    f = open(name, "r")
    global lines
    lines = f.read().split("\n")
    f.close()
    print("read %d lines" % len(lines))
    for i in range(0, len(lines) - 1):
      if lines[i].find("module MountingHole") == -1:
        continue
      if lines[i + 1].find("(at ") == -1:
        continue
      print("Found hole at line:", i, lines[i + 1])
      holes_idx.append(i + 1)
    return holes_idx
  except IOError:
    print("Can't open file")
    return []

def WriteFile(name):
  try:
    f = open(name, "w")
    pcb = "\n".join(lines)
    f.write(pcb)
    f.close()
  except IOError:
    print("Can't open file")

  return

def Parse(line):
  line = line.strip("( )")
  p = line.split(" ")
  if len(p) != 3:
    return (0, 0)
  return float(p[1]), float(p[2])

def ProcessHoles(holes_idx):
  global lines
  print("holes: ", holes_idx)
  print("read %d lines" % len(lines))
  coords = []
  for idx in holes_idx:
    x, y = Parse(lines[idx])
    print(x, y)
    coords.append((x, y, idx))

  print(coords)
  p = sorted(coords, key = lambda p: (p[0], p[1])) # wtf?! ;)
  print(p)

  # now points is placed like:
  # p[0]  p[2]
  # p[1]  p[3]
  # move it!
  d = -1.345  # make it narrow
  x = 0
  y = 1

  idx = 2
  res = []

  res.append((p[0][x] - d, p[0][y] - d, p[0][idx]))
  res.append((p[1][x] - d, p[1][y] + d, p[1][idx]))
  res.append((p[2][x] + d, p[2][y] - d, p[2][idx]))
  res.append((p[3][x] + d, p[3][y] + d, p[3][idx]))
  print(res)

  for r in res:
    l = "    (at %.4f %.4f)" % (r[0], r[1])
    lines[r[2]] = l
    print(l)

  return

def main():
  args = sys.argv
  if len(args) < 2:
    print("To use type:\n moveholes.py pcb.kicad_pcb")
    return

  holes_idx = ReadFile(args[1])
  if len(holes_idx) != 4:
    print("Can process 4 holes exactly")
    return
  ProcessHoles(holes_idx)
  WriteFile(args[1] + ".enlarge")

main()
