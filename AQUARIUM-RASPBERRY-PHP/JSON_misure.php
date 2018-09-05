<?PHP

// hostname 
$host = "localhost";    
// utente per la connessione a MySQL   
$user = "interfacciaApp"; 
// password per l'autenticazione dell'utente  
$pass = "sql_app"; 
// connessione tramite mysql_connect() 
$connessione = mysql_connect($host,$user,$pass); 
if (!$connessione) {

echo "Connessione non stabilita";
}
else
{
//echo "Connessione stabilita";
//nome database
$nomedb = "misureacquario";
  // selezione del database
$selezione = mysql_select_db($nomedb,$connessione) or die (mysql_error());  

//Query = 90 minuti di dati
$SQL = "SELECT time,temperatura,ph,livello,luci,ventole,potassio,co2 FROM valori WHERE temperatura IS NOT NULL ORDER BY idValore DESC LIMIT 1080";
//Eseguo la query
$query = mysql_query($SQL) or die (mysql_error()); 
$rows = array();
//estraggo i record

while($record = mysql_fetch_array($query)){
	 $rows[] = $record;

}
print json_encode(array('misure' =>$rows));
//echo "<hr>";

}

	?>

