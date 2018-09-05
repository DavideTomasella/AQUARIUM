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
$SQL="SELECT time,descrizione FROM valori, erroripervalore, errori where idValore=valore and idErrore=errore order by idErrorePerValore desc limit 30";
//Eseguo la query
$query = mysql_query($SQL) or die (mysql_error()); 
$rows = array();
//estraggo i record

while($record = mysql_fetch_array($query)){
	 $rows[] = $record;

}
print json_encode(array('errori' =>$rows));
//echo "<hr>";

}

	?>

