import cv2
video=cv2.VideoCapture(0)

while True:
	ret,frame=video.read()
	
	x_offset=frame.shape[0]/2-50
	y_offset=frame.shape[1]/2-50
	frame2=frame[0:100,0:100]
	#cv2.rectangle(frame,(x_offset, y_offset), (x_offset+frame2.shape[1], y_offset+frame2.shape[0]), (255, 255, 255), 2)
	
	frame[y_offset:y_offset+frame2.shape[0], x_offset:x_offset+frame2.shape[1]] = frame2
	
	cv2.imshow("Video",frame)
	
	if cv2.waitKey(1) & 0xFF == ord('q'):
		break
video.release()
cv2.destroyAllWindows()