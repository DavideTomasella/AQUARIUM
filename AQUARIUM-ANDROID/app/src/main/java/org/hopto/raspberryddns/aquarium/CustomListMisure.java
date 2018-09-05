package org.hopto.raspberryddns.aquarium;

import android.app.Activity;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Dictionary;
import java.util.Enumeration;
import java.util.HashMap;

/**
 * Created by android on 12/04/2018.
 */

//Classe per personalizzare l'ArrayAdapter
public class CustomListMisure extends ArrayAdapter<MisureElemMinute> {
    private final Activity context;

    private final ArrayList<MisureElemMinute> misure;
    private final int NMisure;

    public CustomListMisure(Activity context, ArrayList<MisureElemMinute> misure) {
        super(context, R.layout.row_misure, misure);
        this.context = context;
        this.misure = misure;
        this.NMisure = misure.size();
    }

    @Override
    public View getView(int position, View view, ViewGroup parent) {

        LayoutInflater inflater = context.getLayoutInflater();
        // Subito dopo, quindi, passiamo a tale oggetto un riferimento al layout da usare
        // per le view degli item (che personalizzeremo a nostro piacimento).
        View rowView = inflater.inflate(R.layout.row_misure, null, true);

        //Ora possiamo assegnare ai widget i valori desiderati alla posizione
        //in cui si trovano nella ListView
        //Recupera i riferimenti alle widget inserite nel layout della riga
        TextView txtTime = (TextView) rowView.findViewById(R.id.txtTime1);
        TextView txtTemp = (TextView) rowView.findViewById(R.id.txtErr);
        TextView txtPh = (TextView) rowView.findViewById(R.id.txtPh);
        TextView txtLev = (TextView) rowView.findViewById(R.id.txtLev);
        TextView txtLig = (TextView) rowView.findViewById(R.id.txtLig);
        TextView txtFan = (TextView) rowView.findViewById(R.id.txtFan);
        TextView txtPot = (TextView) rowView.findViewById(R.id.txtPot);
        TextView txtCo2 = (TextView) rowView.findViewById(R.id.txtCo2);

        //MisureElemMinute actualMisure = misure.get(position);

        //Assegna i valori testo e immagine
        try {
            int index = NMisure-position-1;
            txtTime.setText("TIME: " + misure.get(index).time_min);
            txtTemp.setText(String.format("Temp: \n%4.1f°C",misure.get(index).temp_min));
            txtPh.setText(String.format("PH: \n%4.2f", misure.get(index).ph_min));
            txtLev.setText(String.format("Level: \n%3.0fmm", misure.get(index).lev_min));
            txtLig.setText(String.format("Light: \n%5.1f%%", misure.get(index).lig_min));
            txtFan.setText("Fans: \n" + (misure.get(index).fan_min ? "ON" : "OFF"));
            txtPot.setText("Potassium: \n" + (misure.get(index).pot_min ? "ON" : "OFF"));
            txtCo2.setText("CO2: \n" + (misure.get(index).co2_min ? "ON" : "OFF"));
        }
        catch(Exception ignored){
        }
        return rowView;
    }

}