package org.hopto.raspberryddns.aquarium;

/**
 * Created by Tomasella on 19/05/2018.
 */

import android.util.Log;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;
import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.UnsupportedEncodingException;


public class JSONRequest {

    public JSONObject getJSONFromUrl(String url) {

        InputStream instream = getStreamFromUrl(url);
        String JSONStringReceived = getStringFromStream(instream);
        JSONObject JSONObjectCreated = getJSONObjectFromString(JSONStringReceived);

        return JSONObjectCreated;
    }

    private InputStream getStreamFromUrl(String url){
        //richiesta HTTP dall'url passato come parametro
        try {
            //definisco client
            DefaultHttpClient httpClient = configClientWithTimeout();
            //metodo httpPost
            HttpPost httpPost = new HttpPost(url);
            //richiesta http
            HttpResponse httpResponse = httpClient.execute(httpPost);
            //creazione stream dati
            HttpEntity httpEntity = httpResponse.getEntity();
            return httpEntity.getContent();

        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (ClientProtocolException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return null;
    }

    private String getStringFromStream(InputStream instream){
        try {
            //leggo i dati contenuti nell'oggetto is=httpEntity.getContent(
            BufferedReader reader = new BufferedReader(new InputStreamReader(
                    instream, "iso-8859-1"), 8);
            //costruisco la stringa
            StringBuilder sb = new StringBuilder();
            String line = null;
            //ciclo su tutte le righe
            while ((line = reader.readLine()) != null) {
                sb.append(line + "\n");
            }
            instream.close();
            //al termine ho costruito una stringa sb
            //json contiene la stringa con i dati
            return sb.toString();
        } catch (Exception e) {
            Log.e("Buffer Error", "Error converting result " + e.toString());
        }
        return "";
    }

    private JSONObject getJSONObjectFromString(String JSONStringRecieved){
        try {
            return new JSONObject(JSONStringRecieved);
        } catch (JSONException e) {
            Log.e("JSON Parser", "Error parsing data " + e.toString());
        }
        return null;
    }

    private DefaultHttpClient configClientWithTimeout() {
        HttpParams httpParameters = new BasicHttpParams();
        // Set the timeout in milliseconds until a connection is established.
        // The default value is zero, that means the timeout is not used.
        int timeoutConnection = 1000;
        HttpConnectionParams.setConnectionTimeout(httpParameters, timeoutConnection);
        // Set the default socket timeout (SO_TIMEOUT)
        // in milliseconds which is the timeout for waiting for data.
        int timeoutSocket = 2000;
        HttpConnectionParams.setSoTimeout(httpParameters, timeoutSocket);
        // defaultHttpClient
        return new DefaultHttpClient(httpParameters);
    }
}
