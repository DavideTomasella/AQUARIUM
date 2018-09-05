package org.hopto.raspberryddns.aquarium;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

/**
 * Created by android on 12/04/2018.
 */

//Classe per personalizzare l'ArrayAdapter
public class CustomListErrori extends ArrayAdapter<String> {
    private final Activity context;
    private final ArrayList<String> time;
    private final ArrayList<String> err;

    public CustomListErrori(Activity context, ArrayList<String> time, ArrayList<String> err) {
        super(context, R.layout.row_misure, time);
        this.context = context;
        this.time = time;
        this.err = err;
    }

    @Override
    public View getView(int position, View view, ViewGroup parent) {

        LayoutInflater inflater = context.getLayoutInflater();
        // Subito dopo, quindi, passiamo a tale oggetto un riferimento al layout da usare
        // per le view degli item (che personalizzeremo a nostro piacimento).
        View rowView = inflater.inflate(R.layout.row_errori, null, true);

        //Ora possiamo assegnare ai widget i valori desiderati alla posizione
        //in cui si trovano nella ListView
        //Recupera i riferimenti alle widget inserite nel layout della riga
        TextView txtTime = (TextView) rowView.findViewById(R.id.txtTime2);
        TextView txtErr = (TextView) rowView.findViewById(R.id.txtErr);

        //Assegna i valori testo e immagine
        txtTime.setText("TIME: " + time.get(position));
        txtErr.setText("ERR: " + err.get(position));
        return rowView;
    }
}