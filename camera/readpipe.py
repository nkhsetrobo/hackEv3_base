while True:
    f = open('/home/pi/RasPike-ART/sdk/workspace/cam2run', 'r', encoding="ascii")
    line = f.readline()
    print(line)
    f.close()

