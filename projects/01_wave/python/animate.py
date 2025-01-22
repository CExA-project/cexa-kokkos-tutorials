# ______________________________________________________________________________
#
# Read and generate an animation of the grid for all iterations
#
# ______________________________________________________________________________

import sys
import glob
import numpy as np
import json
from matplotlib import *
from matplotlib.pyplot import *
import matplotlib.animation as animation
import re

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

iter_number_re = re.compile(r"{}/grid_(\d+).json".format(file_path))
file_list = sorted(file_list, key=lambda p: int(iter_number_re.match(p).group(1)))

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

    im = ax.pcolormesh(x_axis,y_axis,grid.T,cmap='coolwarm',shading='auto')

    # set the color limits
    im.set_clim(-1, 1)
    
    ax.set_xlabel("x")
    ax.set_ylabel("y")

    ax.set_title("Grid for {}".format(file_list[i]))

    return im

# ______________________________________________________________________________
# Figure and plot

fig = figure(figsize=(10, 8))
gs = GridSpec(2, 2)
ax = subplot(gs[:,:])

animate(0)

nt = len(file_list)

ani = animation.FuncAnimation(fig, animate, np.arange(0, nt),
                              interval=500, blit=False)

fig.tight_layout()

show()
