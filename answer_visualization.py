from random import random

import matplotlib.pyplot as plt

colors = [(random(), random(), random()) for i in range(100)]

with open('cmake-build-debug/output.txt', 'r') as f:
    plt.title('Components', fontsize=15)
    lines = f.readlines()
    id_color = 0
    for line in lines:
        if line[0] == 'C':
            id_color += 1
            continue
        points = line.split()
        xs = []
        ys = []
        for point in points:
            x, y = point[1:-1].split(';')
            xs.append(int(x))
            ys.append(int(y))
        xs.append(xs[0])
        ys.append(ys[0])
        plt.plot(xs, ys, color=colors[id_color])
    plt.show()

f.close()
