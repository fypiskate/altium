import matplotlib.pyplot as plt

with open('cmake-build-debug/input.txt', 'r') as f:
    plt.title('Figure', fontsize=15)
    n = f.readline()
    for i in range(int(n)):
        m = f.readline()
        xs = []
        ys = []
        for j in range(int(m)):
            x, y = f.readline().split()
            xs.append(int(x))
            ys.append(int(y))
        xs.append(xs[0])
        ys.append(ys[0])
        plt.plot(xs, ys, color='black')
    plt.show()

f.close()
