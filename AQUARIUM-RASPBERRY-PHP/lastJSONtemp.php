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
$lim=urldecode($_GET['num_val']);
$query="SELECT time,temperatura FROM(SELECT * FROM valori where temperatura is not null order by idValore desc limit $lim)tab ORDER BY tab.idValore ASC";
$risultato=mysql_query($query);
if(!$risultato)
die("errore nel comando");

//Recupera i dati
$dataPointsTemp = array();

//prepara struttura json
while ($row = mysql_fetch_assoc($risultato)) {
    $jsonArrayItemTemp = array();
    $jsonArrayItemTemp['x'] = strtotime($row['time'])*1000;
    $jsonArrayItemTemp['y'] = $row['temperatura'];
    array_push($dataPointsTemp,$jsonArrayItemTemp);
}

//stampa dati codificati in json
print json_encode($dataPointsTemp,JSON_NUMERIC_CHECK);
mysql_close($conn);
?>
