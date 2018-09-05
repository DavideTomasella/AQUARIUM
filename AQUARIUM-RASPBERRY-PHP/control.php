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
        <title>Control - AQUARIUM</title>
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
                    <h2>CONTROLLING THE SYSTEM</h2>
                    <p>The control system is completely automated and in the following table the latest performed actions
                         and the errors detected by the Raspberry Pi 3 are reported.</p>
                </header>
                <!-- Table -->
                <section>
                    <h3>LATEST ERRORS OCCURRED</h3>
                    <div class="table-wrapper">
                        <table>
                            <thead>
                                <tr>
                                    <th><strong>TIME</strong></th>
                                    <th><strong>ERROR</strong></th>
                                </tr>
                            </thead>
                            <tbody>
                                <?php
                                    $hostname="localhost";
                                    $username="interfacciaWeb";
                                    $password="sql_web";
                                    //connessione a server sql
                                    $conn=mysql_connect($hostname,$username,$password);
                                    if(!$conn)
                                    die("errore nella connessione");
                                    //selezione database
                                    $dbname="misureacquario";
                                    $db=mysql_select_db($dbname);
                                    //estrae i Film del genere prescelto
                                    $valori=$_POST['valori'];
                                    $query="SELECT time,descrizione FROM valori, erroripervalore, errori where idValore=valore and idErrore=errore order by idErrorePerValore desc limit 10";
                                    //$query="Select time,temperatura,ph,livello,luci,ventole,potassio,co2 From valori  where 1";
                                    $risultato=mysql_query($query);
                                    if(!$risultato)
                                    die("errore nel comando");
                                    //print "<font size='3'><center><strong>valori : $valori";
                                    //print "</strong></font>";
                                    print "<br> <br>";
                                    //Recupera i dati
                                    $riga=mysql_fetch_array($risultato);
                                    //Se $riga = false non ci sono righe di risultato
                                    if(!$riga)
                                     print "<font size=5><strong><u>Attenzione non ci sono film </u></strong></font>";
                                    else
                                     {
                                     while($riga)
                                      {
                                      //Vengono scritti i valori dei campi del record corrente
                                      $time=$riga['time'];
                                      $errore=$riga['descrizione'];
                                      print "<tr>";
                                      print "<td>$time</td>";
                                      print "<td>$errore</td>";
                                      print "</tr>";
                                      $riga=mysql_fetch_array($risultato);
                                     }
                                    }
                                    mysql_close($conn);
                                ?>
                            </tbody>
                            <!--tfoot></tfoot-->
                        </table>
                    </div>
                </section>
            </div>
        </section>

        <!-- Two -->
        <section id="two" class="wrapper style2 align-center">
            <div class="container">
                <header>
                    <h2>RASPBERRY PI 3</h2>
                    <p>The automation is realized through a C++ program running on a Raspberry Pi 3 Model B. The program gets the measurements
                         from the ESP32, controls an LCD display showing the global state of the Aquarium and saves the data into a MySQL Database.</p>
                </header>
                <div class="row content">
                    <section class="feature 6u 12u$(small)">
                        <img class="image fit" src="images/img_b_1.jpg" alt="RASP1" />
                        <h3 class="title">INSTANT DATA</h3>
                        <p>The current measurements are always present on the display with a colorful graphics in order to show how the system is working.
                              All the input and output devices are kept under control by an intelligent system.</p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <img class="image fit" src="images/img_b_2.jpg" alt="RASP2" />
                        <h3 class="title">ERROR REPORT</h3>
                        <p>A flashing button provides a visual alarm in case of malfunction.
                              All the errors detected and the actions performed by the Raspberry Pi 3 are saved and can be shown at any time.</p>
                    </section>
                    <section class="feature 6u 12u$(small)">
                        <img class="image fit" src="images/img_b_3.jpg" alt="RASP3" />
                        <h3 class="title">CONTROL THE THRESHOLDS</h3>
                        <p>A clean and interactive interface makes the user able to change the thresholds and customize the system following his/her necessities, without stopping the program or turning off the device.</p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <img class="image fit" src="images/img_b_4.jpg" alt="RASP4" />
                        <h3 class="title">CALIBRATION</h3>
                        <p>Connecting a keyboard to the Raspberry Pi 3, it is possible to calibrate the system and the probes.
                        If a wrong adjustment has been done, a message makes the user able to discard the operation and return to the main window.</p>
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
