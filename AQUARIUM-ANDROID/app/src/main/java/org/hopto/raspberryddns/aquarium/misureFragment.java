package org.hopto.raspberryddns.aquarium;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ListView;
import android.widget.TextView;

import org.json.JSONArray;

import java.util.ArrayList;
import java.util.HashMap;

public class misureFragment extends Fragment {

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        //returning our layout file
        //change R.layout.yourlayoutfilename for each of your fragments
        return inflater.inflate(R.layout.fragment_misure, container, false);
    }
    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
    //protected void loadContents(MainActivity activity){
        ListView listaMisure = (ListView)view.findViewById(R.id.listMisure);
        //All'avvio carica i dati da un JSON Array
        //ArrayList<HashMap<String, String>> oslist = new ArrayList<HashMap<String,String>>();

        //Lancio il task che si occupa di prelevare i dati
        //delle misure in formato JSON dal server remoto
        String fileMisure = "misure";
        new JSONParse(super.getActivity(), MainActivity.connessione, listaMisure, fileMisure).execute();
    }
}
