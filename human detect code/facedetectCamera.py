import cv2
import time
def face():
    cascade=cv2.CascadeClassifier('haarcascade_frontalface_alt2.xml')
    #cascade=cv2.CascadeClassifier('face.xml')
    cap=cv2.VideoCapture(0)
    cap.set(3,320)
    cap.set(4,240) 
    while True:
        ret,img=cap.read()
        gray=cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)

        faces=cascade.detectMultiScale(gray,1.1,4)

        for(x,y,w,h) in faces:
            cv2.rectangle(img,(x,y),(x+h,y+h),(0,255,0),2)
            cv2.imshow('human',img)    
            k=cv2.waitKey(30) & 0xFF
            if (k==27):
                break
            else:
                pass
    cap.release()
    
face()

