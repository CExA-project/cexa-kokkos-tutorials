# ______________________________________________________________________________
#
# Read and plot the grid at a specific iteration
#
# ______________________________________________________________________________

import sys
import numpy as np
import json
from matplotlib import *
from matplotlib.pyplot import *

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
    sys.exit("Please, specify a valid path to the file as a first command line argument.")


# ______________________________________________________________________________
# Read the hdf5 file

with open(file_path, 'r') as file:
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

# ______________________________________________________________________________
# Figure and plot

fig = figure(figsize=(10, 8))
gs = GridSpec(2, 2)
ax = subplot(gs[:,:])

im = ax.pcolormesh(x_axis,y_axis,grid.T,cmap='coolwarm',shading='auto')

im.set_clim(-1, 1)

ax.set_xlabel("x")
ax.set_ylabel("y")

ax.set_title("Grid from {}".format(file_path))

cb = colorbar(im)

fig.tight_layout()

show()
