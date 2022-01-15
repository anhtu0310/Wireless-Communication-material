
import matplotlib.pyplot as plt
from numpy import float64
import numpy
time_out_points = 35
from scipy.io import wavfile
samplerate, data = wavfile.read('/home/anhtu/Documents/GNU_RADIO/result.wav')
# samplerate, data0 = wavfile.read('/home/anhtu/Documents/GNU_RADIO/1bit0.wav')
time_out = 0
state = 0 
decoded = []
for point in data:
    if state!= 1 and point == 255:
        state = 1
        time_out = 30#26
        decoded.append(1)
    elif state != -1 and point == 0:
        state = -1
        time_out = 39
        decoded.append(0)
    if time_out != 0:
        time_out -=1
    elif  time_out == 0:
        state = 0
k = 0
for i in range(0,len(decoded),8):
    print(k,decoded[i:i+8],"\n")
    k+=1

# window = data[:points]
# for i in range(points,data.size):
#     window = numpy.roll(window,shift = -1)
#     window[points-1] = data[i]
#     sum = window.sum()
#     # print(i)
#         # print(data)
#         # print(window,"\n")
#     if (sum< 0):
#         print(sum)

# plt.plot(data)
# plt.ylabel('some numbers')
# plt.show()
# print(len(data1))
# print(len(data0))
# print(data[:1000])
# data = numpy.roll(data0,shift = -1)
# print(data)

