"""
实时特征点检测例程
"""
# 导入相应的库
import sensor, image, time
from pyb import UART

import json
import struct


# 初始化摄像头
sensor.reset()

# 设置相机对比度
sensor.set_contrast(3)

# 设定摄像头增益上限
sensor.set_gainceiling(16)

# 设置采集到照片的大小
sensor.set_framesize(sensor.VGA)

# 设置相机分辨率
sensor.set_windowing((320, 240))

# 设置采集到照片的格式：灰色图像
sensor.set_pixformat(sensor.GRAYSCALE)

# 等待一段时间2s，等摄像头设置好
sensor.skip_frames(time = 2000)

# 关闭摄像头自动增益并设定固定增益值为100
sensor.set_auto_gain(False, value = 100)

"""
定义画特征点函数
"""
def draw_keypoints(img, kpts):
    if kpts:
        print(kpts)
        img.draw_keypoints(kpts)
        img = sensor.snapshot()
        time.sleep(1000)

uart = UART(3, 115200)

def sending_data(cx,cy):
    data =struct.pack("<bbhhb",              #格式为俩个字符俩个短整型(2字节)
                   0x2C,                       #帧头1
                   0x12,                       #帧头2
                   int(cx), # up sample by 4    #数据1,低位在前
                   int(cy), # up sample by 4    #数据2
                   )
    uart.write(data);   #必须要传入一个字节数组


# 初始化特征点
kpts0 = None
kpts1 = None
kpts2 = None
kpts3 = None

kpts21 = None
kpts22 = None
kpts23 = None
kpts24 = None
kpts25 = None
kpts26 = None
kpts27 = None
kpts28 = None
kpts29 = None

kptst=[0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
#FILE_NAME[20]={"s30","s31","s32","s33","s34","s35","s36","s37","s38","s39"}

cx=None
cy=None
stata=None
learn=None
#文件名
#FILE_NAME = "S2"

"""
我们也可以从文件中导入特征点
kpts1 = image.load_descriptor("/face_track/S2.orb")
img = sensor.snapshot()
draw_keypoints(img, kpts1)
"""
kpts1 = image.load_descriptor("/face_track/S1.orb")
kpts2 = image.load_descriptor("/face_track/S2.orb")
kpts3 = image.load_descriptor("/face_track/S3.orb")
while(True):
    # 拍摄图片并返回img
    img = sensor.snapshot()
    if uart.any():
        stata = uart.readline().decode()
        print(stata)
    if(stata=='A'):
        kpts0 = img.find_keypoints(max_keypoints=150, threshold=10, normalized=True)
        if(kpts0):
            match = image.match_descriptor(kpts1, kpts0, threshold=85)
            if(match.count()>10):
                cx=1
                cy=0
                sending_data(cx,cy)
                print('1')
        if(kpts0):
            match = image.match_descriptor(kpts2, kpts0, threshold=85)
            if(match.count()>10):
                cx=2
                cy=0
                sending_data(cx,cy)
                print('2')
        if(kpts0):
            match = image.match_descriptor(kpts3, kpts0, threshold=85)
            if(match.count()>10):
                cx=3
                cy=0
                sending_data(cx,cy)
                print('3')
    if(stata=='B'):
        kpts0 = img.find_keypoints(max_keypoints=150, threshold=10, normalized=True)
        if(kpts0):
            match = image.match_descriptor(kpts21, kpts0, threshold=85)
            if(match.count()>10):
                cx=1
                cy=0
                sending_data(cx,cy)
                print('1')
            else:
                cx=0
                cy=0
                sending_data(cx,cy)
                print('0')
        if(kpts0):
            match = image.match_descriptor(kpts22, kpts0, threshold=85)
            if(match.count()>10):
                cx=1
                cy=0
                sending_data(cx,cy)
                print('1')
            else:
                cx=0
                cy=0
                sending_data(cx,cy)
                print('0')
        if(kpts0):
            match = image.match_descriptor(kpts23, kpts0, threshold=85)
            if(match.count()>10):
                cx=1
                cy=0
                sending_data(cx,cy)
                print('1')
            else:
                cx=0
                cy=0
                sending_data(cx,cy)
                print('0')
    if(stata=='C'):
        kpts0 = img.find_keypoints(max_keypoints=150, threshold=10, normalized=True)
        if(learn==None):
            for i in range(5):
                img = sensor.snapshot()
                kptst[i] =img.find_keypoints(max_keypoints=150, threshold=10, normalized=True)
                draw_keypoints(img,kptst[i])
            learn=1
        else:
            if(kpts0):
                for i in range(5):
                    match = image.match_descriptor(kptst[i], kpts0, threshold=85)
                    if(match.count()>15):
                        cx=1
                        cy=0
                        sending_data(cx,cy)
                        print('1')
                #else:
                    #print('0')
