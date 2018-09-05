package org.hopto.raspberryddns.aquarium;

import android.app.Activity;
import android.app.ProgressDialog;
import android.os.AsyncTask;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.Toast;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeMap;

/**
 * Created by Tomasella on 19/05/2018.
 */

public class JSONParse extends AsyncTask<String, String, JSONObject> {

    //JSON Dichiarare nome dei campi
    private static final String TAG_TIME = "time";
    private static final String TAG_TEMP = "temperatura";
    private static final String TAG_PH = "ph";
    private static final String TAG_LEV = "livello";
    private static final String TAG_LIG = "luci";
    private static final String TAG_FAN = "ventole";
    private static final String TAG_POT = "potassio";
    private static final String TAG_CO2 = "co2";
    private static final String TAG_ERR = "descrizione";

    //apposto
    private final Activity context;
    private final ListView list;
    private ProgressDialog pDialog;
    private final String urlName;
    private final String TAG_NAME_ARRAY_JSON;
    private final TypeConnection connection;
    //URL to get JSON Array

    public JSONParse(Activity context, TypeConnection connection, ListView list, String whatToGet) {
        this.context = context;
        this.list = list;
        this.connection = connection;
        urlName = "JSON_" + whatToGet + ".php";
        TAG_NAME_ARRAY_JSON = whatToGet;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
        //Show a waiting screen
        pDialog = ProgressDialog.show(context, "Please wait", "Getting data.........");
    }

    //esecuzione in background
    @Override
    protected JSONObject doInBackground(String... args) {

        String availableUrl;
        if(connection == TypeConnection.WIFI_SCHOOL) availableUrl = context.getResources().getString(R.string.urlPre1);
        else if(connection == TypeConnection.WIFI_HOME) availableUrl = context.getResources().getString(R.string.urlPre2);
        else if(connection == TypeConnection.INTERNET) availableUrl = context.getResources().getString(R.string.urlPre2);
        else availableUrl = context.getResources().getString(R.string.urlPre2);
        availableUrl += urlName;
        //availableUrls.add(urlPre1 + urlName);
        //availableUrls.add(urlPre2 + urlName);
        return getJSONFromUrl(availableUrl);
    }

    @Override
    protected void onPostExecute(JSONObject json) {
        String resultMessage = "";
        try {
            // Assegna a tabella JSONArray prelevato da URL
            JSONArray tabella = json.getJSONArray(TAG_NAME_ARRAY_JSON);
            //ricavo i dati dalla tabella
            createListViewFromJSONArray(list, tabella);
            resultMessage = "DATA READY";
        } catch (JSONException e) {
            e.printStackTrace();
            resultMessage = "IMPOSSIBLE TO GET DATA";
        } catch (NullPointerException e) {
            resultMessage = "IMPOSSIBLE TO GET DATA";
        } finally {
            //Chiudo la finestra di processing
            if (pDialog != null && pDialog.isShowing()) {
                pDialog.dismiss();
            }
            Toast.makeText(context, resultMessage, Toast.LENGTH_LONG).show();
        }
    }

    private JSONObject getJSONFromUrl(String url) {
        //istanzia un oggetto JSONParser
        JSONRequest jParser = new JSONRequest();

        try {
            JSONObject json = jParser.getJSONFromUrl(url);
            if (json != null) return json; //ritorna l'oggetto json
        } catch (Exception e1) {
        }

        return new JSONObject();
    }

    private void createListViewFromJSONArray(ListView list, JSONArray tabella) {

        ArrayAdapter adapter = createAdapterFromJSONArray(tabella, TAG_NAME_ARRAY_JSON);
        list.setAdapter(adapter);
    }

    private ArrayAdapter createAdapterFromJSONArray(JSONArray tabella, String TAG_NAME_ARRAY_JSON){
        switch(TAG_NAME_ARRAY_JSON){
            case "misure":
                TreeMap<String,MisureElemMinute> misureDic = new TreeMap<>();
                //cicla su tutti i record della tabella JSONArray
                for (int i = 0; i < tabella.length(); i++) {
                    try {
                        JSONObject c = tabella.getJSONObject(i);
                        String time = c.getString(TAG_TIME);
                        String time_min=time.substring(0,time.length()-4);
                        if(!misureDic.containsKey(time_min)){
                            misureDic.put(time_min, new MisureElemMinute(time_min));
                        }
                        misureDic.get(time_min)
                                .addMisure(c.getString(TAG_TEMP),
                                c.getString(TAG_PH),
                                c.getString(TAG_LEV),
                                c.getString(TAG_LIG),
                                c.getString(TAG_FAN),
                                c.getString(TAG_POT),
                                c.getString(TAG_CO2));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
                //ora gli array di stringhe con i campi sono stati "riempiti"
                return new CustomListMisure(context, new ArrayList(misureDic.values()));

            case "errori":
                ArrayList<String> alErr = new ArrayList<String>();
                ArrayList<String> alTime = new ArrayList<String>();
                for (int i = 0; i < tabella.length(); i++) {
                    try {
                        JSONObject c = tabella.getJSONObject(i);

                        alTime.add(c.getString(TAG_TIME));
                        alErr.add(c.getString(TAG_ERR));
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }
                }
                return new CustomListErrori(context, alTime, alErr);
            default:
                return null;
        }
    }

}
