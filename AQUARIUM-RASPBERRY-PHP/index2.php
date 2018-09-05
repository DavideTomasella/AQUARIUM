<html><head><title>MISURE ACQUARIO</title></head>
<body>
<p align="center"><font size="3"><strong><u>MISUREE ACQUARIO</u></strong></font></p>
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
$query="SELECT time,temperatura,ph,livello,luci,ventole,potassio,co2 FROM(SELECT * FROM valori where temperatura is not null order by idValore desc limit 10)tab ORDER BY tab.idValore ASC";
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
print "<table align='center' border = ‘1’>";
print "<TR>";
print "<td align='center'><strong>TIME</strong></td>";
print "<td align='center'><strong>TEMPERATURA</strong></td>";
print "<td align='center'><strong>PH</strong></td>";
print "<td align='center'><strong>LIVELLO</strong></td>";
print "<td align='center'><strong>LUCI</strong></td>";
print "<td align='center'><strong>VENTOLE</strong></td>";
print "<td align='center'><strong>POTASSIO</strong></td>";
print "<td align='center'><strong>CO2</strong></td>";
print "</tr>";
while($riga)
{
//Vengono scritti i valori dei campi del record corrente
$time=$riga['time'];
$temperatura=$riga['temperatura'];
$ph=$riga['ph'];
$livello=$riga['livello'];
$luci=$riga['luci'];
$ventole=$riga['ventole'];
$potassio=$riga['potassio'];
$co2=$riga['co2'];

print "<tr>";
print "<td>$time</td>";
print "<td>$temperatura</td>";
print "<td>$ph</td>";
print "<td>$livello</td>";
print "<td>$luci</td>";
print "<td>$ventole</td>";
print "<td>$potassio</td>";
print "<td>$co2</td>";
print "</tr>";
//Si sposta sulla riga successiva
$riga=mysql_fetch_array($risultato);
}
print"</table>";
}
mysql_close($conn);
?>
</center></body>
</html>
