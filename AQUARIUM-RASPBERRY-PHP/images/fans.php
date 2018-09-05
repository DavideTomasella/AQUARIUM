<?php
// Set the content-type
header('Content-Type: image/jpeg');

// Create the image
$im = ImageCreateFromJPEG("source/img_fan.jpg");

// Create some colors
$white = imagecolorallocate($im, 255, 255, 255);
$grey = imagecolorallocate($im, 128, 0, 128);
$black = imagecolorallocate($im, 0, 0, 0);
$cor = imagecolorallocate($im, 0, 0, 0);
$black50 = imagecolorallocatealpha($im, 0, 0, 0, 63);
$shadow = imagecolorallocate($im, 255, 212, 128);//0 123 255
$fore = imagecolorallocate($im, 255, 255, 140);//0 123 255
//imagefilledrectangle($im, 0, 600, 1800, 900, $black50);

// The text to draw
$ciao = 'OFF';
if(urldecode($_GET['nome'])=='1')
	$ciao = 'ON';
//$ciao .= '%';
// Replace path by your own font path
$font = 'source/arial.ttf';

// Add some shadow to the text
imagettftext($im, 180, 0, 983, 695, $shadow, $font, $ciao);
// Add some shadow to the text
imagettftext($im, 180, 0, 990, 690, $fore, $font, $ciao);
// Add the text
imagettftext($im, 180, 0, 1000, 690, $fore, $font, $ciao);

// Using imagepng() results in clearer text compared with imagejpeg()
imagejpeg($im,NULL,100);
imagedestroy($im);
?>