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
        <title>Statistics - AQUARIUM</title>
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
        <script src="https://canvasjs.com/assets/script/canvasjs.min.js"></script>
        <!--[if lte IE 8]>
        <link rel="stylesheet" href="css/ie/v8.css" />
        <![endif]-->
        <script>
           window.onload = function() {

            //TEMPERATURA
            var colorGridTemp = "#737373";//"#4d79ff";
	    var backTemp = "#ffd6cc";
            var lineTemp = "#e60000";
            var pointTemp = "#990000"; 
            var chartTemp = new CanvasJS.Chart("chartContainerTemp", {
             theme: "light2",
             backgroundColor: backTemp,
             animationEnable: true,
             zoomEnabled: true,
             zoomType: "x",
             toolTip:{
              borderThickness: 2,
             },
             title: {
              text: "TEMPERATURE",
              fontWeight: "normal",
              fontColor: pointTemp,
             },
             axisX:{
              title: "Time",
              tickColor: colorGridTemp,
              lineColor: colorGridTemp,
              labelFontColor: "black",
              titleFontColor: "black",
              crosshair: {
               enabled: false,
               snapToDataPoint: true,
              },
            //viewportMinimum: dataPointsTemp[dataPointsTemp.length - 1 - 100].x,
            //viewportMaximum: dataPointsTemp[dataPointsTemp.length - 1].x
            //valueFormatString: "YY/MM/DD hh:mm:ss TT"
             },
             axisY:{
              gridColor: colorGridTemp,
              tickColor: colorGridTemp,
              gridThickness: 0.5,
              labelFontColor: "black",
              includeZero: false,
              suffix: "°C"
             },
             data: [{
              type: "line",
              lineColor: lineTemp,
              lineThickness: 2,
              color: pointTemp,
              yValueFormatString: "#,##0.0#",
              xValueFormatString: "hh:mm TT",
              xValueType: "dateTime",
              toolTipContent: "{y}°C<br/> {x}",
              dataPoints: null//dataPointsTemp
             }]
            });
            chartTemp.render();
            
            //PH
            var colorGridPh = "#737373";//"#4d79ff";
	    var backPh = "#b3ffe0";
            var linePh = "#00cc66";
            var pointPh = "#008040"; 
            var chartPh = new CanvasJS.Chart("chartContainerPh", {
             theme: "light2",
             backgroundColor: backPh,
             animationEnable: true,
             zoomEnabled: true,
             zoomType: "x",
             toolTip:{
              borderThickness: 2,
             },
             title: {
              text: "PH",
              fontWeight: "normal",
              fontColor: pointPh,
             },
             axisX:{
              title: "Time",
              tickColor: colorGridPh,
              lineColor: colorGridPh,
              labelFontColor: "black",
              titleFontColor: "black",
              crosshair: {
               enabled: false,
               snapToDataPoint: true,
              },
            //viewportMinimum: dataPointsPh[dataPointsPh.length - 1 - 100].x,
            //viewportMaximum: dataPointsPh[dataPointsPh.length - 1].x
            //valueFormatString: "YY/MM/DD hh:mm:ss TT"
             },
             axisY:{
              gridColor: colorGridPh,
              tickColor: colorGridPh,
              gridThickness: 0.5,
              labelFontColor: "black",
              includeZero: false,
              suffix: ""
             },
             data: [{
            type: "line",
              lineColor: linePh,
              lineThickness: 2,
              color: pointPh,
              yValueFormatString: "#,##0.0#",
              xValueFormatString: "hh:mm TT",
              xValueType: "dateTime",
              toolTipContent: "{y}<br/> {x}",
              dataPoints: null//dataPointsPh
             }]
            });
            chartPh.render();
            
            var colorGridLev = "#737373";//"#4d79ff";
	    var backLev = "#b3ccff";
            var lineLev = "#1a75ff";
            var pointLev = "#003cb3"; 
            var chartLev = new CanvasJS.Chart("chartContainerLev", {
             theme: "light2",
             backgroundColor: backLev,
             animationEnable: true,
             zoomEnabled: true,
             zoomType: "x",
             toolTip:{
              borderThickness: 2,
             },
             title: {
              text: "WATER LEVEL",
              fontWeight: "normal",
              fontColor: pointLev,
             },
             axisX:{
              title: "Time",
              tickColor: colorGridLev,
              lineColor: colorGridLev,
              labelFontColor: "black",
              titleFontColor: "black",
              crosshair: {
               enabled: false,
               snapToDataPoint: true,
              },
            //viewportMinimum: dataPointsLev[dataPointsLev.length - 1 - 100].x,
            //viewportMaximum: dataPointsLev[dataPointsLev.length - 1].x
            //valueFormatString: "YY/MM/DD hh:mm:ss TT"
             },
             axisY:{
              gridColor: colorGridLev,
              tickColor: colorGridLev,
              gridThickness: 0.5,
              labelFontColor: "black",
              includeZero: false,
              suffix: "mm"
             },
             data: [{
            type: "line",
              lineColor: lineLev,
              lineThickness: 2,
              color: pointLev,
              yValueFormatString: "#,##0.0#",
              xValueFormatString: "hh:mm TT",
              xValueType: "dateTime",
              toolTipContent: "{y}mm<br/> {x}",
            dataPoints: null//dataPointsLev
             }]
            });
            chartLev.render();
            
            
            //INSERIMENTO EFFETTIVO DEI DATI NEI GRAFICI
            updateChart();
            
            var updateInterval = 1500;
            setInterval(function () { updateChart() }, updateInterval);
            
            function updateChart() {
          
             if(document.getElementById('tminute').checked){
                 var num_t=200;}
             else if(document.getElementById('thour').checked){
                 var num_t=1200;}
             else if(document.getElementById('tday').checked){
                 var num_t=30000;}
             else{
                 var num_t=400;}

             if(document.getElementById('pminute').checked){
                 var num_p=200;}
             else if(document.getElementById('phour').checked){
                 var num_p=1200;}
             else if(document.getElementById('pday').checked){
                 var num_p=30000;}
             else{
                 var num_p=400;}

             if(document.getElementById('lminute').checked){
                 var num_l=200;}
             else if(document.getElementById('lhour').checked){
                 var num_l=1200;}
             else if(document.getElementById('lday').checked){
                 var num_l=30000;}
             else{
                 var num_l=400;}
             
             $.getJSON("lastJSONtemp.php?num_val="+num_t, function (result) {
              chartTemp.options.data[0].dataPoints = result;
              chartTemp.options.axisX.viewportMinimum = result[result.length - num_t/2].x;
              chartTemp.options.axisX.viewportMaximum = result[result.length - 1].x;            
              chartTemp.render();	
             });

             $.getJSON("lastJSONph.php?num_val="+num_p, function (result) {
              chartPh.options.data[0].dataPoints = result;
              chartPh.options.axisX.viewportMinimum = result[result.length - num_p/2].x;
              chartPh.options.axisX.viewportMaximum = result[result.length - 1].x;            
              chartPh.render();	
             });

             $.getJSON("lastJSONlev.php?num_val="+num_l, function (result) {
              chartLev.options.data[0].dataPoints = result;
              chartLev.options.axisX.viewportMinimum = result[result.length - num_l/2].x;
              chartLev.options.axisX.viewportMaximum = result[result.length - 1].x;            
              chartLev.render();	
             });
            };

           }
        </script>
    </head>

    <body>
        <!-- Header -->
        <header id="header">
            <h1><a href="index.php">HOME</a></h1>
            <nav id="nav">
                <ul>
                    <li><a href="index.php">HOME</a></li>
                    <li><a href="acquisition.php">ACQUIRING DATAS</a></li>
                    <li><a href="control.php">CONTROLLING THE SYSTEM</a></li>
                    <li><a href="statistics.php">CREATING STATISTICS</a></li>
                </ul>
            </nav>
        </header>
        <!-- Main -->
        <section id="main" class="wrapper style2 align-center">
            <div class="container">
            <header class="major">
                <h2>CREATING STATISTICS</h2>
                <p>The following graphs related to temperature, pH and water level show the trend of the three parameters during different time ranges
                    by selecting "10 minutes", "1 hour" or "1 day".
                </p>
            </header>
            <div class="row content">
                <!-- CHARTS -->
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerTemp" style="height: 370px; width: 100%;"></div>
                    <div class="row feature" style="background: #ffd6cc;">
                        <!--style="float:right"-->
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="tminute" name="t" checked>
                            <label for="tminute">10 minutes</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="thour" name="t">
                            <label for="thour">1 hour</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="tday" name="t">
                            <label for="tday">1 day</label>
                        </div>
                    </div>
                </section>
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerPh" style="height: 370px; width: 100%;"></div>
                    <div class="row feature" style="background: #b3ffe0;">
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="pminute" name="p" checked>
                            <label for="pminute">10 minutes</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="phour" name="p">
                            <label for="phour">1 hour</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="pday" name="p">
                            <label for="pday">1 day</label>
                        </div>
                    </div>
                </section>
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerLev" style="height: 370px; width: 100%;"></div>
                    <div class="row feature" style="background: #b3ccff;">
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="lminute" name="l" checked>
                            <label for="lminute">10 minutes</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="lhour" name="l">
                            <label for="lhour">1 hour</label>
                        </div>
                        <div class="4u 4u(medium) 4u(small)">
                            <input type="radio" id="lday" name="l">
                            <label for="lday">1 day</label>
                        </div>
                    </div>
                </section>
            </div>
        </section>

        <!-- Two -->
        <section id="two" class="wrapper style2 align-center">
            <div class="container">
                <header>
                    <h2>DATA PRESENTATION</h2>
                    <p>The data monitored by the system is saved into a MySQL Database and an Apache 2 Web Server realized on the Raspberry Pi 3 makes them available from everywhere.
                        Javascript and Php make the website dynamic in order to show the latest measurements.
                    </p>
                </header>
                <div class="row content">
                    <section class="feature 6u 12u$(small)">
                        <img class="image fit" src="images/img_c_1.jpg" alt="WEB SITE" />
                        <h3 class="title">WEB SITE</h3>
                        <p>The website, realized both for desktop and mobile browsers, presents the project with small tips that 
                           report the main phases and show how the system globally works.</p>
                    </section>
                    <section class="feature 6u$ 12u$(small)">
                        <img class="image fit" src="images/img_c_2.jpg" alt="ANDROID" />
                        <h3 class="title">ANDROID APP</h3>
                        <p>The data is also present in a nice application for Android Systems to stay connected with the Aquarium from the smartphone at any time.</p>
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
                    <section class="6u$ 12u$(medium) 12u$(small)">
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
