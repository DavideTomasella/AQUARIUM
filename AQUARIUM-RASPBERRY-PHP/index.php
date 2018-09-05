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
        <title>AQUARIUM</title>
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

    <body class="landing">
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
        <!-- Banner -->
        <section id="banner">
            <h2>AQUARIUM</h2>
            <p>Automatic monitoring system.<br>Powered by Davide Tomasella</p>
            <ul class="actions">
                <li>
                    <a href="http://www.itisgalileiconegliano.gov.it/" class="button big">Go To Our School</a>
                </li>
            </ul>
        </section>

        <!-- One -->
        <section id="one" class="wrapper style1 align-center">
            <div class="container">
                <header>
                    <h2>CONTROL SYSTEM</h2>
                    <p>Implemented on ESP32 and RASPBERRY PI 3</p>
                </header>
                <div class="row 200%">
                    <section class="4u 12u$(small)">
                        <a href="acquisition.php" class="icon white big rounded fa-database" aria-hidden="true"></a>
                        <p>Acquiring Data</p>
                    </section>
                    <section class="4u 12u$(small)">
                        <a href="control.php" class="icon white big rounded fa-code" aria-hidden="false"></a>
                        <p>Controlling The System</p>
                    </section>
                    <section class="4u$ 12u$(small)">
                        <a href="statistics.php" class="icon white big rounded fa-bar-chart-o" aria-hidden="false"></a>
                        <p>Creating Statistics</p>
                    </section>
                </div>
            </div>
        </section>
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
        ?>

        <!-- Three -->
        <section id="three" class="wrapper style3 align-center">
            <div class="container">
                <header>
                    <h2>ACQUARIUM STATUS</h2>
                    <?php
                        //estrae i Film del genere prescelto
                        $erroripervalore=$_POST['erroripervalore'];
                        $valori=$_POST['valori'];
                        $query="SELECT errore,time FROM erroripervalore, valori WHERE valore=idValore ORDER BY idErrorePervalore DESC LIMIT 1";
                        $risultato=mysql_query($query);
                        if(!$risultato)
                        die("errore nel comando");
                        //Recupera i dati
                        $riga=mysql_fetch_array($risultato);
                        if(!$riga)
                         print "<font size=5><strong><u>Attenzione non ci sono risultati </u></strong></font>";
                        else{
                         $last_err=$riga['errore'];
                         $last_time=$riga['time'];
                         if($last_err=="0")
                          print "<p><b>The system is correctly working...</b><br>";
                         else
                          print "<p><b>ATTENTION: An error has occurred!</b><br>";
                         print "Last Update: $last_time<p>";
                        }
                        ?>
                </header>
                <footer>
                    <ul class="actions">
                        <li>
                            <a href="control.php" class="button big">Learn More</a>
                        </li>
                    </ul>
                </footer>
            </div>
        </section>

        <!-- Two -->
        <section id="two" class="wrapper style2 align-center">
            <div class="container">
                <header>
                    <h2>IMMEDIATE MEASUREMENTS</h2>
                    <p>The website can show the latest values collected from the several probes connected to the Aquarium.
                        The data is acquired by ESP32 and sent to RASPEBERRY PI 3 to be processed.
                        The automatic control is performed and the results can be analyzed in every moment.
                    </p>
                    <?php
                        //estrae i Film del genere prescelto
                        $valori=$_POST['valori'];
                        $query="SELECT time,temperatura,ph,livello,luci,ventole,potassio,co2 FROM valori WHERE temperatura IS NOT NULL ORDER BY idValore DESC LIMIT 1";
                        $risultato=mysql_query($query);
                        if(!$risultato)
                        die("errore nel comando");
                        //Recupera i dati
                        $riga=mysql_fetch_array($risultato);
                        if(!$riga)
                         print "<font size=5><strong><u>Attenzione non ci sono risultati </u></strong></font>";
                        else{
                         $last_measure=$riga['time'];
                         $last_temp=round($riga['temperatura'],1);
                         $last_ph=$riga['ph'];
                         $last_level=$riga['livello'];
                         $last_light=round($riga['luci']);
                         $last_fans=$riga['ventole'];
                         $last_pot=$riga['potassio'];
                         $last_co2=$riga['co2'];
                        }
                    ?>
                </header>
                <div class="row content">
                    <section class="feature 6u 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/status.php?nome=$last_measure\" alt=\"\" />";
                            ?>
                        <h3 class="title">GLOBAL STATE</h3>
                        <p>The latest data received from the Aquarium is shown to keep the global state of the system under control.
                            If an error has occurred here you can check the parameters out of the range.
                        </p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/temp.php?nome=$last_temp\" alt=\"\" />";
                            ?>
                        <h3 class="title">TEMPERATURE</h3>
                        <p>The temperature of Aquarium must be taken under control because fish and plants cannot live in a too hot environment.
                            If the temperature rises too much, the system should start some fans up to make the water cooler.
                        </p>
                    </section>
                    <section class="feature 6u 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/ph.php?nome=$last_ph\" alt=\"\" />";
                            ?>
                        <h3 class="title">ACIDITY</h3>
                        <p>The water acidity is a parameter that shows the health of the Aquarium.
                            If everything works correctly pH should be about 7.
                        </p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/level.php?nome=$last_level\" alt=\"\" />";
                            ?>
                        <h3 class="title">WATER LEVEL</h3>
                        <p>Since the water evaporates it is important to provide an amount of extra water every day to keep the water level constant.
                            This parameter shows the level of the tank under the Aquarium to know when the water stock has run out.
                        </p>
                    </section>
                    <section class="feature 6u 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/light.php?nome=$last_light\" alt=\"\" />";
                            ?>
                        <h3 class="title">ENLIGHTENMENT</h3>
                        <p>Some RGB leds replace the solar light and provide plants with the necessary energy to the photosynthesis.
                            We can set sunrise and sunset times to manage the alternation of day and night.
                        </p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/fans.php?nome=$last_fans\" alt=\"\" />";
                            ?>
                        <h3 class="title">COOLING FANS</h3>
                        <p>If the temperature grows too much, some fans improve the evaporation rate and the heat exchange, thus cooling the water.</p>
                    </section>
                    <section class="feature 6u 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/co2.php?nome=$last_co2\" alt=\"\" />";
                            ?>
                        <h3 class="title">CO2 EMISSION</h3>
                        <p>The carbon dioxide rate is important for the plants photosynthesis.
                            During the day CO2 must be added to increase oxygen production while during the night the plants produce it.
                        </p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <?php
                            print"<img class=\"image fit\" src=\"images/pot.php?nome=$last_pot\" alt=\"\" />";
                            ?>
                        <h3 class="title">POTASSIUM ADDITION</h3>
                        <p>The potassium is used as fertilizer for the plants and must be added every day to maintain the amount of vegetation necessary for the fish life.</p>
                    </section>
                    <section class="feature 12u$ 12u$(small)"/><!--risolto bug-->
                </div>
                <footer>
                    <ul class="actions">
                        <li>
                            <a href="acquisition.php" class="button alt big">Learn More</a>
                        </li>
                    </ul>
                </footer>
            </div>
        </section>
        <?php
            mysql_close($conn);
        ?>

        <!-- Four -->
        <section id="four" class="wrapper style3 align-center">
            <div class="container">
                <header>
                    <h2>DATA TREND</h2>
                    <p>All Aquarium data are memorized in a database and are ready to be visualized.
                        Several graphes have been realized to present the trend in a simple visual way.
                    </p>
                </header>
                <footer>
                    <ul class="actions">
                        <li>
                            <a href="statistics.php" class="button big">Learn More</a>
                        </li>
                    </ul>
                </footer>
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
