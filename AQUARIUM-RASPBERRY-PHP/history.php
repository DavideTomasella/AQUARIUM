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
        <title>History- AQUARIUM</title>
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
            //setInterval(function () { updateChart() }, updateInterval);
            
            function updateChart() {
            
            var num=100000;
            var num_t=num;
            var num_p=num;
            var num_l=num;
             
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
        <!-- Main -->
        <section id="main" class="wrapper style2 align-center">
            <div class="container">
            <header class="major">
                <h2>HISTORY</h2>
                <p></p>
            </header>
            <div class="row content">
                <!-- CHARTS -->
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerTemp" style="height: 370px; width: 100%;"></div>
                </section>
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerPh" style="height: 370px; width: 100%;"></div>
                </section>
                <section class="feature 12u$ 12u$">
                    <div id="chartContainerLev" style="height: 370px; width: 100%;"></div>
               </section>
            </div>
        </section>
    </body>
</html>
