import matplotlib.pyplot as plt
import numpy as np
from scipy.spatial import Delaunay

# Define the points
points = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])

# Perform Delaunay triangulation
triangulation = Delaunay(points)

print("Simplices (трикутники):")
print(triangulation.simplices)

# Виводимо індекси точок на опуклій оболонці
print("Convex Hull (опукла оболонка):")
print(triangulation.convex_hull)

# Виводимо координати точок
print("Vertices (точки):")
print(triangulation.points)