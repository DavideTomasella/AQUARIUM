<!DOCTYPE html>
<!--
    @ACQUARIUM
    @VERSION 1.2
    @REVIEW 16 August 2018
    @TOMASELLA DAVIDE
    Interphase by TEMPLATED
    templated.co @templatedco
    Released for free under the Creative Commons Attribution 3.0 license (templated.co/license)
    -->
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>History - AQUARIUM</title>
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
    <!--[if lte IE 8]><link rel="stylesheet" href="css/ie/v8.css" /><![endif]-->
    <script>
        window.onload = function() {

            var back = "#eeeeee";
            var title = "#101010";
            var colorGridX = "#505050"
            //TEMPERATURA
            var colorGridTemp = "#ffd6cc";//"#4d79ff";
            var lineTemp = "#e60000";
            var pointTemp = "#990000";
            //PH
            var colorGridPh = "#b3ffe0";//"#4d79ff";
            var linePh = "#00cc66";
            var pointPh = "#008040";
            //LIVELLO
            var colorGridLev = "#b3ccff";//"#4d79ff";
            var lineLev = "#1a75ff";
            var pointLev = "#003cb3";
            var chartTemp = new CanvasJS.Chart("chartContainerTemp", {
                theme: "light2",
                backgroundColor: back,
                animationEnable: true,
                zoomEnabled: true,
                zoomType: "x",
                toolTip:{
                    borderThickness: 2,
                },
                title: {
                    text: "STATISTICS",
                    fontWeight: "normal",
                    fontColor: title,
                },
                axisX:{
                    title: "Time",
                    tickColor: colorGridX,
                    lineColor: colorGridX,
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
                axisY2:[{
                    gridColor: colorGridTemp,
                    tickColor: pointTemp,
                    gridThickness: 1,
                    labelFontColor: pointTemp,
                    includeZero: false,
                    suffix: "°C"
                },{
                    gridColor: colorGridPh,
                    tickColor: pointPh,
                    gridThickness: 1,
                    labelFontColor: pointPh,
                    includeZero: false,
                    suffix: ""
                },{
                    gridColor: colorGridLev,
                    tickColor: pointLev,
                    gridThickness: 1,
                    labelFontColor: pointLev,
                    includeZero: true,
                    suffix: "mm"
                }],
                axisY:[{
                    //title: "ventole",
                    gridColor: colorGridPh,
                    tickColor: pointPh,
                    gridThickness: 0,
			interval: 1,
			maximum: 1.2,
                    labelFontColor: pointPh,
                    includeZero: true,
                    suffix: ""
                },{
                    //title: "luci",
                    gridColor: colorGridTemp,
                    tickColor: pointTemp,
                    gridThickness: 0,
                    labelFontColor: pointTemp,
                    includeZero: true,
                    suffix: "%"
                },{
                    //title: "co2",
                    gridColor: colorGridLev,
                    tickColor: pointLev,
                    gridThickness: 0,
			interval: 1,
			maximum: 1.2,
                    labelFontColor: pointLev,
                    includeZero: true,
                    suffix: ""
                }],
                data: [{
                    type: "area",
                    lineColor: lineLev,
                    lineThickness: 1,
                    color: colorGridLev,
                    markerType: "none",
                    showInLegend: true,
                    legendText: "Co2",
                    axisYIndex: 2,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "CO2<br/>{y}<br/> {x}",
                    dataPoints: null//dataPointsLev
                },{
                    type: "area",
                    lineColor: lineTemp,
                    lineThickness: 1,
                    color: colorGridTemp,
                    markerType: "none",
                    showInLegend: true,
                    legendText: "Luci",
                    axisYIndex: 1,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "LUCI<br/>{y}%<br/> {x}",
                    dataPoints: null//dataPointsTemp
                },{
                    type: "area",
                    lineColor: linePh,
                    lineThickness: 1,
                    color: colorGridPh,
                    markerType: "none",
                    showInLegend: true,
                    legendText: "Ventole",
                    axisYIndex: 0,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "VENTOLE<br/>{y}<br/> {x}",
                    dataPoints: null//dataPointsPh
                },{
                    type: "line",
                    lineColor: lineTemp,
                    lineThickness: 2,
                    color: pointTemp,
                    showInLegend: true,
                    legendText: "Temperatura",
                    axisYType: "secondary",
                    axisYIndex: 0,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "TEMPERATURA<br/>{y}°C<br/> {x}",
                    dataPoints: null//dataPointsTemp
                },{
                    type: "line",
                    lineColor: linePh,
                    lineThickness: 2,
                    color: pointPh,
                    showInLegend: true,
                    legendText: "PH",
                    axisYType: "secondary",
                    axisYIndex: 1,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "PH<br/>{y}<br/> {x}",
                    dataPoints: null//dataPointsPh
                },{
                    type: "line",
                    lineColor: lineLev,
                    lineThickness: 2,
                    color: pointLev,
                    showInLegend: true,
                    legendText: "Livello",
                    axisYType: "secondary",
                    axisYIndex: 2,
                    yValueFormatString: "#,##0.0#",
                    xValueFormatString: "hh:mm TT",
                    xValueType: "dateTime",
                    toolTipContent: "LIVELLO<br/>{y}mm<br/> {x}",
                    dataPoints: null//dataPointsLev
                }]
            });
            chartTemp.render();

            //INSERIMENTO EFFETTIVO DEI DATI NEI GRAFICI
            updateChart();

            var updateInterval = 1500;
            //setInterval(function () { updateChart() }, updateInterval);

            function updateChart() {

                var num=20000;
                var num_t=num;
                var num_p=num;
                var num_l=num;

                $.getJSON("lastJSON.php?type=co2&limit="+num_l, function (result) {
                    chartTemp.options.data[0].dataPoints = result;
                    chartTemp.render();
                });

                $.getJSON("lastJSON.php?type=luci&limit="+num_t, function (result) {
                    chartTemp.options.data[1].dataPoints = result;
                    chartTemp.render();
                });

                $.getJSON("lastJSON.php?type=ventole&limit="+num_p, function (result) {
                    chartTemp.options.data[2].dataPoints = result;
                    chartTemp.render();
                });


                $.getJSON("lastJSON.php?type=temperatura&limit="+num_t, function (result) {
                    chartTemp.options.data[3].dataPoints = result;
                    chartTemp.render();
                });

                $.getJSON("lastJSON.php?type=ph&limit="+num_p, function (result) {
                    chartTemp.options.data[4].dataPoints = result;
                    chartTemp.render();
                });

                $.getJSON("lastJSON.php?type=livello&limit="+num_l, function (result) {
                    chartTemp.options.data[5].dataPoints = result;
                    chartTemp.render();
                });
            }

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
                <div id="chartContainerTemp" style="height: 700px; width: 100%;"></div>
            </section>
        </div>
</section>
</body>
</html>
