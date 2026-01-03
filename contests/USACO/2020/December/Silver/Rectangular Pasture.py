def binary(x, a):
    l = 0
    r = len(a) - 1
    while (l <= r):
        mid = (l + r) // 2
        if (x > a[mid]):
            l = mid + 1
        elif (x < a[mid]):
            r = mid - 1
        else:
            return mid


def dcf(a, n):
    b = a[0:]
    b.sort()
    result = [b[0]]
    for i in range(1, len(b)):
        if (b[i] != b[i - 1]):
            result += [b[i]]
    return [binary(a[i], result) for i in range(n)]


n = int(input())
count = 0
dcfPos = []
cowX, cowY = [], []
Map = [[0 for j in range(n)] for i in range(n)]
sumP = [[0 for j in range(n + 1)] for i in range(n + 1)]
for i in range(n):
    pos = list(map(int, input().split()))
    cowX.append(pos[0])
    cowY.append(pos[1])
for x, y in zip(dcf(cowY, n), dcf(cowX, n)):
    dcfPos.append([x, y])
    Map[x][y] += 1
for i in range(n):
    for j in range(n):
        sumP[i + 1][j + 1] = Map[i][j] + sumP[i + 1][j] + sumP[i][j + 1] - sumP[i][j]
dcfPos.sort(key=lambda x: x[0])
for i in range(n):
    for j in range(i, n):
        column1 = dcfPos[i][0]
        column2 = dcfPos[j][0]
        row1 = min(dcfPos[i][1], dcfPos[j][1])
        row2 = max(dcfPos[i][1], dcfPos[j][1])
        count1 = sumP[column2 + 1][row1 + 1] - sumP[column1][row1 + 1] - sumP[column2 + 1][0] + sumP[column1][0]
        count2 = sumP[column2 + 1][n] - sumP[column1][n] - sumP[column2 + 1][row2] + sumP[column1][row2]
        count += count1 * count2
print(count + 1)
