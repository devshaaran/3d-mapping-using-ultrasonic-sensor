import serial
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d, Axes3D


def normalcursor():

    ser = serial.Serial('COM15',9600)

    x_axis = []
    y_axis = []
    z_axis = []

    for i in range(0,180):

        try:
            raw_dat = ser.readline().decode().strip('\r\n')
            print(raw_dat)
            data_list = raw_dat.split(',')
            x_val = int(data_list[0])
            z_val = int(data_list[1])
            y_val = int(data_list[2])

            x_axis.append(x_val)
            y_axis.append(y_val)
            z_axis.append(z_val)


        except Exception as e :
            print(e)

    print(x_axis)
    print(y_axis)
    print(z_axis)

    fig = plt.figure()

    ax = Axes3D(fig)

    ax.scatter(x_axis, y_axis, z_axis, c='r', marker='o')

    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')
    plt.show()
def ploter():


    fig = plt.figure()
    ax = Axes3D(fig)

    x = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    y = [5, 6, 2, 3, 13, 4, 1, 2, 4, 8]
    z = [2, 3, 3, 3, 5, 7, 9, 11, 9, 10]

    ax.scatter(x, y, z, c='r', marker='o')

    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')

    plt.show()


normalcursor()
