import cv2 as cv

def video_slow_motion(video_path, slow_factor=0.4):
  cap = cv.VideoCapture(video_path)
  if not cap.isOpened():
    print("Error opening video file.")
    return

  fps = cap.get(cv.CAP_PROP_FPS)
  width = int(cap.get(cv.CAP_PROP_FRAME_WIDTH))
  height = int(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

  fourcc = cv.VideoWriter_fourcc(*'mp4v')
  out = cv.VideoWriter('slow_motion.mp4', fourcc, fps * slow_factor, (width, height))

  while True:
    ret, frame = cap.read()
    if not ret:
      break
    out.write(frame)
    if cv.waitKey(int(1000 / (fps * slow_factor))) & 0xFF == ord('q'):
        break

  cap.release()
  out.release()
  cv.destroyAllWindows()
  print("Slow motion video saved as slow_motion.mp4")

def video_fast_motion(video_path, fast_factor=2):
  cap = cv.VideoCapture(video_path)
  if not cap.isOpened():
    print("Error opening video file.")
    return

  fps = cap.get(cv.CAP_PROP_FPS)
  width = int(cap.get(cv.CAP_PROP_FRAME_WIDTH))
  height = int(cap.get(cv.CAP_PROP_FRAME_HEIGHT))

  fourcc = cv.VideoWriter_fourcc(*'mp4v')
  out = cv.VideoWriter('fast_motion.mp4', fourcc, fps * fast_factor, (width, height))

  while True:
    ret, frame = cap.read()
    if not ret:
        break
    out.write(frame)
    if cv.waitKey(int(1000/(fps * fast_factor))) & 0xFF == ord('q'):
        break

  cap.release()
  out.release()
  cv.destroyAllWindows()
  print("Fast motion video saved as fast_motion.mp4")

video_slow_motion('sample.mp4')
video_fast_motion('sample.mp4')
