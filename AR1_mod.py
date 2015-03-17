import cv2
video=cv2.VideoCapture(0)

while True:
	ret,frame=video.read()
	
	
	#frame2=frame[0:frame.shape[0],0:frame.shape[1]]
	#cv2.rectangle(frame,(x_offset, y_offset), (x_offset+frame2.shape[1], y_offset+frame2.shape[0]), (255, 255, 255), 2)
	r=250.0/frame.shape[1]
	d=(250,int(r*frame.shape[0]))
	frame2= cv2.resize(frame,d,interpolation = cv2.INTER_AREA) 
	frame[frame.shape[0]-frame2.shape[0]:frame.shape[0],frame.shape[1]-frame2.shape[1]:frame.shape[1]] = frame2
	
	cv2.imshow("Video",frame)
	
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
video.release()
cv2.destroyAllWindows()
