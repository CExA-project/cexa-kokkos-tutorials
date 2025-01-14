# ______________________________________________________________________________
#
# Read and generate an animation of the grid for all iterations in 3D
#
# ______________________________________________________________________________

import sys
import glob
import json
import numpy as np
from matplotlib import *
from matplotlib.pyplot import *
import matplotlib.animation as animation
from mpl_toolkits.mplot3d import Axes3D

# ______________________________________________________________________________
# RCParams - personalize the figure output

rcParams['figure.facecolor'] = 'w'
rcParams['font.size'] = 15
rcParams['xtick.labelsize'] = 15
rcParams['ytick.labelsize'] = 15
rcParams['axes.labelsize'] = 15

rcParams['xtick.major.size'] = 10
rcParams['ytick.major.size'] = 10

rcParams['xtick.minor.size'] = 5
rcParams['ytick.minor.size'] = 5

rcParams['axes.linewidth'] = 1.5

rcParams['xtick.major.width'] = 2
rcParams['ytick.major.width'] = 2

rcParams['xtick.minor.width'] = 1.5
rcParams['ytick.minor.width'] = 1.5

# ______________________________________________________________________________
# Read command line arguments

file_path = ""

if len(sys.argv) > 1:
    file_path = sys.argv[1]
else:
    sys.exit("Please, specify a valid path to a charge hdf5 file as a first command line argument.")

# ______________________________________________________________________________
# Get the list of files

file_list = glob.glob("{}/grid_*.json".format(file_path))

file_list = sorted(file_list)

# ______________________________________________________________________________
# Animation function

def animate(i):

    ax.cla()

    # Open and read the JSON file
    with open(file_list[i], 'r') as file:
        json_diag = json.load(file)

    Nx = json_diag["parameters"]["Nx"]
    Ny = json_diag["parameters"]["Ny"]

    dx = json_diag["parameters"]["dx"]
    dy = json_diag["parameters"]["dy"]

    Lx = Nx * dx
    Ly = Ny * dy

    data = json_diag["data"]

    grid = np.array(data).reshape(Nx, Ny)

    x_axis = np.linspace(0,Lx,Nx)
    y_axis = np.linspace(0,Ly,Ny)

    x_mesh, y_mesh = np.meshgrid(x_axis, y_axis)

    # Plot the surface.
    surf = ax.plot_surface(x_mesh, y_mesh, grid.T, cmap=cm.coolwarm,
                           linewidth=0, antialiased=True)

    ax.set_zlim(-1, 1)

    ax.set_xlabel("x")
    ax.set_ylabel("y")

    t = ax.set_title("Grid at {}".format(file_list[i]))
    t.set_y(1.05)

    return surf

# ______________________________________________________________________________
# Figure and plot

fig = figure(figsize=(12, 8))
ax = fig.add_subplot(111, projection='3d')

animate(0)

nt = len(file_list)

ani = animation.FuncAnimation(fig, animate, np.arange(0, nt),
                              interval=500, blit=False)

fig.tight_layout()

show()
