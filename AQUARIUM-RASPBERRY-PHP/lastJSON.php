<?php
/**
 * Created by PhpStorm.
 * User: Davide
 * Date: 16/08/2018
 * Time: 10:44
 */

$hostname="localhost";
$username="interfacciaWeb";
$password="sql_web";
$dbname="misureacquario";
//connessione a server sql
$mysqli=new mysqli($hostname,$username,$password,$dbname);
if(!$mysqli)
    die("errore nella connessione");

$type=urldecode($_GET['type']);
$limit=urldecode($_GET['limit']);
$query="SELECT time,$type FROM(SELECT * FROM valori where temperatura is not null order by idValore desc limit $limit)tab ORDER BY tab.idValore ASC";
$risultato=$mysqli->query($query);
if(!$risultato)
    die("errore nel comando");

//Recupera i dati
$dataPointsTemp = array();

//prepara struttura json
while ($row = $risultato->fetch_array(MYSQLI_ASSOC)) {
    $jsonArrayItemTemp = array();
    $jsonArrayItemTemp['x'] = strtotime($row['time'])*1000;
    $jsonArrayItemTemp['y'] = $row[$type];
    array_push($dataPointsTemp,$jsonArrayItemTemp);
}

//stampa dati codificati in json
print json_encode($dataPointsTemp,JSON_NUMERIC_CHECK);

$mysqli->close();
