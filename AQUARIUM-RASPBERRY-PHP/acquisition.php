<!DOCTYPE html>
<!--
    @ACQUARIUM
    @VERSION 2.4
    @REVIEW 01 May 2018
    @TOMASELLA DAVIDE      
    Interphase by TEMPLATED
    templated.co @templatedco
    Released for free under the Creative Commons Attribution 3.0 license (templated.co/license)
    -->
<html lang="en">
    <head>
        <meta charset="UTF-8">
        <title>Acquisition - AQUARIUM</title>
        <meta http-equiv="content-type" content="text/html; charset=utf-8" />
        <meta name="description" content="" />
        <meta name="keywords" content="" />
        <!--[if lte IE 8]><script src="css/ie/html5shiv.js"></script><![endif]-->
        <script src="js/jquery.min.js"></script>
        <script src="js/skel.min.js"></script>
        <script src="js/skel-layers.min.js"></script>
        <script src="js/init.js"></script>
        <noscript>
            <link rel="stylesheet" href="css/skel.css" />
            <link rel="stylesheet" href="css/style.css" />
            <link rel="stylesheet" href="css/style-xlarge.css" />
        </noscript>
        <!--[if lte IE 8]>
        <link rel="stylesheet" href="css/ie/v8.css" />
        <![endif]-->
    </head>

    <body>
        <!-- Header -->
        <header id="header">
            <h1><a href="index.php">HOME</a></h1>
            <nav id="nav">
                <ul>
                    <li><a href="index.php">HOME</a></li>
                    <li><a href="acquisition.php">ACQUIRING DATA</a></li>
                    <li><a href="control.php">CONTROLLING THE SYSTEM</a></li>
                    <li><a href="statistics.php">CREATING STATISTICS</a></li>
                </ul>
            </nav>
        </header>
        <!-- Main -->
        <section id="main" class="wrapper">
            <div class="container">
                <header class="major">
                    <h2>ACQUIRING DATA</h2>
                    <p>The Aquarium is a complex ecosystem that has to be monitored. The acquisition of the data from the probes is the most important step to make the system work correctly.</p>
                </header>
                <a href="#" class="image fit"><img src="images/img_4.jpg" alt="" /></a>
                <p></p>
            </div>
        </section>

        <!-- Two -->
        <section id="two" class="wrapper style2 align-center">
            <div class="container">
                <header>
                    <h2>ESP32 BOARD</h2>
                    <p>The acquisition of the Aquarium data exploits an ESP32 board that controls the inputs and the outputs of the automatic system.
                         The instant measurements are accessible by the Raspberry Pi 3 through an UDP server realized on the ESP32.</p>
                </header>
                <div class="row content">
                    <section class="feature 6u 12u$(small)">
                        <img class="image fit" src="images/img_a_1.jpg" alt="ESP1" />
                        <h3 class="title">THE MICRO</h3>
                        <p>A powerful microcontroller transforms the electrical signals into values ready to be used from the control system.
                            The micro also provides a wifi interface to communicate with the Raspberry Pi 3 from every part of the school.</p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <img class="image fit" src="images/img_a_2.jpg" alt="ESP2" />
                        <h3 class="title">THE BOARD</h3>
                        <p>All the probes and the actuators are connected to a main board that receives and sends the monitored data.
                            Some circuites create the interface with the ESP32 increasing or decreasing the signals coming from the Aquarium.</p>
                    </section>
                    <section class="feature 6u 12u$(small)">
                        <img class="image fit" src="images/img_a_3.jpg" alt="MONITOR" />
                        <h3 class="title">THE DATA</h3>
                        <p>The ESP32 filters in real time the values of the probes connected in order to reduce the noise and the errors occurred during the acquisition process.
                            A serial monitor with the in-out state has also been realized in order to provide an efficient debug tool.</p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <img class="image fit" src="images/img_2.jpg" alt="AQUARIUM" />
                        <h3 class="title">MALFUNCTIONS CONTROL</h3>
                        <p>All the most important parameters for the life are kept under control in order to prevent any malfunction that could threaten the Aquarium.
                            In case of a probe's damage, some specific instructions in the code regulate the output until the equipment is repaired.</p>
                    </section>
                </div>
            </div>
        </section>

        <!-- Footer -->
        <footer id="footer">
            <div class="container">
                <div class="row">
                    <!--section class="4u 6u(medium) 12u$(small)">
                        <h3>Lorem ipsum</h3>
                        <p>Lorem ipsum dolor sit amet, consectetur adipisicing elit. Assumenda, cumque!</p>
                        <ul class="alt">
                            <li><a href="#">Lorem ipsum dolor sit amet.</a></li>
                            <li><a href="#">Quod adipisci perferendis et itaque.</a></li>
                            <li><a href="#">Itaque eveniet ullam, veritatis reiciendis?</a></li>
                            <li><a href="#">Accusantium repellat accusamus a, soluta.</a></li>
                        </ul>
                        </section>
                        <section class="4u 6u$(medium) 12u$(small)">
                        <h3>Nostrum, repellat!</h3>
                        <p>Tenetur voluptate exercitationem eius tempora! Obcaecati suscipit, soluta earum blanditiis.</p>
                        <ul class="alt">
                            <li><a href="#">Lorem ipsum dolor sit amet.</a></li>
                            <li><a href="#">Id inventore, qui necessitatibus sunt.</a></li>
                            <li><a href="#">Deleniti eum odit nostrum eveniet.</a></li>
                            <li><a href="#">Illum consectetur quibusdam eos corporis.</a></li>
                        </ul>
                        </section-->
                    <section class="4u$ 12u$(medium) 12u$(small)">
                        <h2 style="font-weight: 400">Contact Us</h2>
                        <!--ul class="icons">
                            <li><a href="#" class="icon rounded fa-github"><span class="label">Github</span></a></li>
                            <li><a href="#" class="icon rounded fa-"><span class="label"></span></a></li>
                            <li><a href="#" class="icon rounded fa-"><span class="label"></span></a></li>    
                            <li><a href="#" class="icon rounded fa-google-plus"><span class="label">Google+</span></a></li>
                            <li><a href="#" class="icon rounded fa-"><span class="label"></span></a></li>
                            </ul-->
                        <ul class="tabular">
                            <li>
                                <h3>WebSite</h3>
                                <a href="http://www.itisgalileiconegliano.gov.it/">www.itisgalileiconegliano.gov.it</a>
                            <li>
                                <h3>Address</h3>
                                Via Galilei 16<br>
                                31015 Conegliano (TV)<br>
                                ITALY
                            </li>
                            <li>
                                <h3>Mail</h3>
                                <a href="mailto:tvis026004@istruzione.it">TVIS026004@istruzione.it</a>
                            </li>
                            <li>
                                <h3>Phone</h3>
                                (+39) 0438 61649
                            </li>
                        </ul>
                    </section>
                </div>
                <ul class="copyright">
                    <li>&copy; Aquarium. All rights reserved.</li>
                    <li>Powered by: <a href="https://github.com/DavideTomasella">Davide Tomasella</a></li>
                    <li>Design: <a href="http://templated.co">TEMPLATED</a></li>
                    <li>Images: <a href="http://unsplash.com">Unsplash</a></li>
                </ul>
            </div>
        </footer>
    </body>
</html>
