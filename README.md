### Introduction

An Image Resizer using Seam Carving alogrithm.

See:

Avidan, Shai, and Ariel Shamir. *Seam carving for content-aware image resizing.* SIGGRAPH2007

Dong, Weiming, et al. *Optimized image resizing using seam carving and scaling.* SIGGRAPH2009

### Compile

Dependencies:

* gcc >= 4.7
* [Magick++](http://www.imagemagick.org/Magick++/)


Compile:

```
$ make
```

### Usage:
See help:

```
$ ./image_resize
-i   [Required] Input image.
-o   [Required] Output image.
-w   Width, can be pixel number in integer, or a relative number in (0, 1]
-h   Height, same as above
-e   Output energy image.
-m   Maks image, red to discard, green to keep.
-c   Convolution type. can be one of prewitt, vsquare, sobel, laplacian
-p   Use Optimized Seam Carving(slow).
-f   Use feature as mask. every line is "r c"
-v   Output images with carved path for video generation.
```

### Example:
```
./image_resize -i ../data/city.jpg -o city-resized.jpg -w 0.6
```

![city](https://github.com/ppwwyyxx/ImageResizer/raw/master/data/city.jpg)
![city-resized](https://github.com/ppwwyyxx/ImageResizer/raw/master/result/city.jpg)
