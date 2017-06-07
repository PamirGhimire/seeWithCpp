# seeWithCpp

GUI based computer vision toolbox developed using Qt(5.7) and OpenCv(3.2).

Requirements:
-OpenCV 3.2 core and non-free (contrib) modules.
-Qt (5.7)
-Ubuntu (make changes to the project file (.pro) to have it running on windows)

The GUI offers following functionalities:

(a) Add salt and pepper noise.

(b) Show a logo at a corner of the input (ROI).

(c) Convert to a new colorspace.

(d) Compute the histogram.

(e) Equalize the histogram.

(f ) Apply morphological operations (Dilate, Erode, Open, Close).

(g) Blur.

(h) Apply Sobel and Laplacian operators.

(i) Sharpen by applying a kernel.

(j) Edge detection using Canny.

(k) Extract lines and circles using Hough transform.

(l) Find contours of connected objects and draw them.

(m) Apply components' shape descriptors (bounding box, minimum en-
closing circle).

(n) Extract corners using Harris and apply non-maximal suppression.

(o) Extract FAST, SURF, and SIFT.

(p) Find matches between two different views.

(q) Calibrate the attached camera, show the extracted corners of the
calibration pattern in each image, and undistort the input image
given the calibration results.

(r) Attach two cameras (or take two images from the same camera after
moving the camera to a new position), compute the fundamental
matrix using: (only one of the following in MATLAB project, and
all of them in the OpenCV project)
7 point method, 8 point method, and RANSAC.

(s) Draw the epipolar lines and show the epipole in the two images.

(t) Compute the homography between two images (capture an image
then apply a pure rotation to the camera, then capture another im-
age).

(u) Add the two images connected by the found homography in one image
(mosaic).

(v) Stitch two or more images (use the stitching module).

(w) Deep learn a set of faces and recognize them using this code.

(x) Save the result.

