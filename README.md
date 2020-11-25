# Image-Processing-in-CPP
Implemented image reading writing and enhancing of images(bmp format) using c++
programming languages to analyse how images behave when go through certain manipulation in
bit level.

### Dataset
We will perform following operation with images extracted from Dataset of 183 lowlighting underwater images from underwater sites in the Northeast Pacific Ocean. 1400x1000
pixels, varying lighting and recording conditions (Ocean Networks Canada)  
link:  https://sites.google.com/view/oceandark/home  
These images are converted to BMP format as its less complex and no compression and also capable to read image through program via byte stream 

### Image-Negative

Enhancing an image provides better contrast and a more detailed image as compare to
non enhanced image  
T(r)= ~r  
Or, T(r)= 255-r ; given 8-bit bmp format

#### Input
<img src="/screenshots/original_image_image_negative.png" width="500" height="300" />

#### Output (with c=127)
<img src="/screenshots/image_negative.png" width="500" height="300" /> 

### Log Transformation

The log transformations can be defined by this formula
s = c log(r + 1).
Where s and r are the pixel values of the output and the input image and c is a constant

#### Input
<img src="/screenshots/log.png" width="500" height="300" />

#### Output 
<img src="/screenshots/log2.png" width="500" height="300" /> 

### Bit-Plane Slicing

Bit plane slicing is a method of representing an image with one or more bits of the byte used
for each pixel. One can use only MSB to represent the pixel, which reduces the original gray
level to a binary image

#### Input
<img src="/screenshots/bp.png" width="500" height="300" />  

#### Output (with bit slice 8(MSB))
<img src="/screenshots/bp2.png" width="500" height="300" /> 


### Image Averaging

Image averaging works on the assumption that the noise in your image is truly random. This
way, random fluctuations above and below actual image data will gradually even out as one
averages more and more images

#### Input
##### Image1
<img src="/screenshots/x1.png" width="500" height="300" />  

##### Image2
<img src="/screenshots/x2.png" width="500" height="300" />  

##### Image3
<img src="/screenshots/x3.png" width="500" height="300" />  

#### Output (Final Averaged Image)
<img src="/screenshots/x4.png" width="500" height="300" /> 

### References  

[1] https://abhijitnathwani.github.io/blog/  
[2] http://www.fastgraph.com/help/bmp_header_format.html  
[3] https://www.cambridgeincolour.com/tutorials/image-averaging-noise.htm  
[4] https://www.ft.unicamp.br/docentes/magic/khoros/html-dip/c4/s12/front-page.html  
[5] http://www.fastgraph.com/help/bmp_header_format.html  
[6] https://www.tutorialspoint.com/dip/gray_level_transformations.htm  
[7] http://adaptiveart.eecs.umich.edu/2011/wp-content/uploads/2011/09/The-pocket-handbook-of-imageprocessing-algorithms-in-C.pdf  
[8] http://homepages.inf.ed.ac.uk/rbf/BOOKS/PHILLIPS/cips2ed.pdf  
[9] http://paulbourke.net/dataformats/bitmaps/   

