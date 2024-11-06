def calc(punto_a, punto_b):
    x1, y1, z1 = punto_a
    x2, y2, z2 = punto_b

    # Vector director de la recta
    v = (x2 - x1, y2 - y1, z2 - z1)

    # Parámetro t para encontrar el punto de intersección con z=0
    t = -z1 / v[2]

    # Calcular las coordenadas x e y del punto de intersección
    x = x1 + t * v[0]
    y = y1 + t * v[1]

    return x, y

def punto_en_poligono(x, y, poligono):
    num_puntos = len(poligono)
    j = num_puntos - 1
    dentro = False

    for i in range(num_puntos):
        xi, yi = poligono[i]
        xj, yj = poligono[j]
        
        if (yi > y) != (yj > y) and (x < (xj - xi) * (y - yi) / (yj - yi) + xi):
            dentro = not dentro
            
        j = i

    return dentro

N = int(input())
ax,ay,az = map(int,input().split(" "))
sx,sy,sz = map(int,input().split(" "))
base = []
for _ in range(N):
    x,y = map(int,input().split(" "))
    base.append([x,y])

punto_a = (ax, ay, az)
punto_b = (sx, sy, sz)

punto = calc(punto_a, punto_b)

res = punto_en_poligono(punto[0], punto[1], base)

if res:
    print("N")
else:
    print("S")
